#ifndef QUAT_H
#define QUAT_H

#include <iostream>
#include "mat4.h"

#define ONE_DEG_IN_RAD (2.0 * M_PI) / 360.0

namespace qm {

class Quat {

  public:
    // Constructors
    inline Quat() { q[0] = q[1] = q[2] = q[3] = 0.f; }
    inline Quat(float degAngle, float x, float y, float z) {
      init(degAngle, x, y, z);
    }
    // Operators
    inline float& operator[](int index) {
      return q[index];
    }
    inline const float& operator[](int index) const {
      return q[index];
    }
    // Others
    inline void init(float degAngle, float x, float y, float z) {
      float radAngle = degAngle * ONE_DEG_IN_RAD;
      q[0] = cos(radAngle * 0.5f);
      q[1] = sin(radAngle * 0.5f) * x;
      q[2] = sin(radAngle * 0.5f) * y;
      q[3] = sin(radAngle * 0.5f) * z;
    }
    inline Quat normalize() {
      float sum = q[0]*q[0] + q[1]*q[1] + q[2]*q[2] + q[3]*q[3];
      // floats have mion 6 digits of precision
      const float threshold = 0.0001f;
      if (fabs(1.0f - sum) < threshold)
        return *this;
      float norm = sqrt(sum);
      q[0] /= norm;
      q[1] /= norm;
      q[2] /= norm;
      q[3] /= norm;
      return *this;
    }
    const Quat operator*(const Quat& Q) {
      Quat result;
      result[0] = Q[0]*q[0] - Q[1]*q[1] - Q[2]*q[2] - Q[3]*q[3];
      result[1] = Q[0]*q[1] + Q[1]*q[0] - Q[2]*q[3] + Q[3]*q[2];
      result[2] = Q[0]*q[2] + Q[1]*q[3] + Q[2]*q[0] - Q[3]*q[1];
      result[3] = Q[0]*q[3] - Q[1]*q[2] + Q[2]*q[1] + Q[3]*q[0];
      result.normalize();
      return result;
    }
    // Convert the quaternion to a 4x4 matrix. The quaternion has to be normalized first.
    inline const qm::Mat4f toMatrix() const {
      float w = q[0];
      float x = q[1];
      float y = q[2];
      float z = q[3];
      return qm::Mat4f(
        1.0f - 2.0f*y*y - 2.0f*z*z, 2.0f*x*y + 2.0f*w*z, 2.0f*x*z - 2.0f*w*y, 0.0f,
        2.0f*x*y - 2.0f*w*z, 1.0f - 2.0f*x*x - 2.0f*z*z, 2.0f*y*z + 2.0f*w*x, 0.0f,
        2.0f*x*z + 2.0f*w*y, 2.0f*y*z - 2.0f*w*x, 1.0f - 2.0f*x*x - 2.0f*y*y, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
      );
    }

    // Static methods
    static inline float dotProduct(const Quat& A, const Quat& B) {
        return (A[0] * B[0] + A[1] * B[1] + A[2] * B[2] + A[3] * B[3]);
    }

  private:
    float q[4];

};

const Quat& slerp(Quat& A, Quat& B, float t);

}

#endif // QUAT_H
