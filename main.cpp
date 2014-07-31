#include <iostream>

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat3.h"
#include "mat4.h"
#include "quat.h"

using namespace std;
using namespace qm;

int main() {
  cout << "--------------- QMath ---------------" << endl << endl;
  //
  // Vectors
  //
  Vec2f vec2(1.0, 1.0);
  Vec3f vec3(1.0, 1.0, 1.0);
  Vec4f vec4(1.0, 1.0, 1.0, 1.0);

  cout << "------------------" << endl;
  cout << "Vectors" << endl;
  cout << "------------------" << endl;
  cout << vec2 << endl;
  cout << vec3 << endl;
  cout << vec4 << endl;
  cout << endl;

  //
  // Matrices
  //
  Mat3f mat3 = Mat3f::identityMatrix();
  Mat4f mat4 = Mat4f::identityMatrix();

  cout << "------------------" << endl;
  cout << "Matrices" << endl;
  cout << "------------------" << endl;
  cout << mat3 << endl;
  cout << mat4 << endl;
  cout << endl;

  //
  // Quaternions
  //
  Quat quat(45.f, 0.f, 1.f, 0.f);
  Quat quat2(45.f, 0.f, 1.f, 0.f);
  Quat quat3 = quat * quat2;

  cout << "------------------" << endl;
  cout << "Quaternions" << endl;
  cout << "------------------" << endl;
  cout << quat3[0] << endl;
  cout << endl;

  return 0;
}

