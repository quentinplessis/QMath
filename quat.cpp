#include "quat.h"

using namespace qm;

const Quat slerp(Quat& A, Quat& B, float t) {
  // angle between A0-A1
  float cosHalfTheta = Quat::dotProduct(A, B);
  // as found here http://stackoverflow.com/questions/2886606/flipping-issue-when-interpolating-rotations-using-quaternions
  // if dot product is negative then one quaternion should be negated, to make
  // it take the short way around, rather than the long way
  if (cosHalfTheta < 0.0f) {
    for (int i = 0 ; i < 4 ; i++)
      A[i] *= -1.0f;
    cosHalfTheta = Quat::dotProduct(A, B);
  }
  // if qa=qb or qa=-qb then theta = 0 and we can return qa
  if (fabs(cosHalfTheta) >= 1.0f)
    return A;
  // Calculate temporary values
  float sinHalfTheta = sqrt(1.0f - cosHalfTheta * cosHalfTheta);
  // if theta = 180 degrees then result is not fully defined
  // we could rotate around any axis normal to qa or qb
  Quat result;
  if (fabs(sinHalfTheta) < 0.001f) {
    for (int i = 0 ; i < 4 ; i++)
      result[i] = (1.0f - t) * A[i] + t * B[i];
    return result;
  }
  float halfTheta = acos(cosHalfTheta);
  float a = sin((1.0f - t) * halfTheta) / sinHalfTheta;
  float b = sin(t * halfTheta) / sinHalfTheta;
  for (int i = 0 ; i < 4 ; i++)
    result[i] = A[i] * a + B[i] * b;
  return result;
}
