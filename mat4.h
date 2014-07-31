#ifndef MAT4_H
#define MAT4_H

#include <iostream>
#include <cmath>

#include "vec4.h"
#include "vec3.h"
#include "mat3.h"

namespace qm {

#define ONE_DEG_IN_RAD (2.0 * M_PI) / 360.0 // 0.017444444

/**
 * Base class for a four-dimensional matrix.
 * Column-order (0->3 first column, 4->7 second column...)
 */
template<typename T> class Mat4Base {

  public:
    // Constructors
    inline Mat4Base() {
      m[0] = m[1] = m[2] = m[3] = m[4] = m[5] = m[6] = m[7] = m[8] = m[9] = m[10] = m[11] = m[12] = m[13] = m[14] = m[15] = T();
    }
    inline Mat4Base(T m0, T m1, T m2, T m3, T m4, T m5, T m6, T m7, T m8, T m9, T m10, T m11, T m12, T m13, T m14, T m15) {
      init(m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15);
    }
    inline void init(T m0, T m1, T m2, T m3, T m4, T m5, T m6, T m7, T m8, T m9, T m10, T m11, T m12, T m13, T m14, T m15) {
      m[0] = m0;
      m[1] = m1;
      m[2] = m2;
      m[3] = m3;
      m[4] = m4;
      m[5] = m5;
      m[6] = m6;
      m[7] = m7;
      m[8] = m8;
      m[9] = m9;
      m[10] = m10;
      m[11] = m11;
      m[12] = m12;
      m[13] = m13;
      m[14] = m14;
      m[15] = m15;
    }
    inline const T* getArray() const {
      return m;
    }
    // Operators
    inline T& operator[](int index) {
      return m[index];
    }
    inline const T& operator[](int index) const {
      return m[index];
    }
    inline Mat4Base& operator=(const Mat4Base& M) {
      m[0] = M[0];
      m[1] = M[1];
      m[2] = M[2];
      m[3] = M[3];
      m[4] = M[4];
      m[5] = M[5];
      m[6] = M[6];
      m[7] = M[7];
      m[8] = M[8];
      m[9] = M[9];
      m[10] = M[10];
      m[11] = M[11];
      m[12] = M[12];
      m[13] = M[13];
      m[14] = M[14];
      m[15] = M[15];
      return *this;
    }
    inline Mat4Base& operator+=(const Mat4Base& M) {
      m[0] += M[0];
      m[1] += M[1];
      m[2] += M[2];
      m[3] += M[3];
      m[4] += M[4];
      m[5] += M[5];
      m[6] += M[6];
      m[7] += M[7];
      m[8] += M[8];
      m[9] += M[9];
      m[10] += M[10];
      m[11] += M[11];
      m[12] += M[12];
      m[13] += M[13];
      m[14] += M[14];
      m[15] += M[15];
      return *this;
    }
    inline Mat4Base& operator-=(const Mat4Base& M) {
      m[0] -= M[0];
      m[1] -= M[1];
      m[2] -= M[2];
      m[3] -= M[3];
      m[4] -= M[4];
      m[5] -= M[5];
      m[6] -= M[6];
      m[7] -= M[7];
      m[8] -= M[8];
      m[9] -= M[9];
      m[10] -= M[10];
      m[11] -= M[11];
      m[12] -= M[12];
      m[13] -= M[13];
      m[14] -= M[14];
      m[15] -= M[15];
      return *this;
    }
    inline Mat4Base& operator*=(T s) {
      m[0] *= s;
      m[1] *= s;
      m[2] *= s;
      m[3] *= s;
      m[4] *= s;
      m[5] *= s;
      m[6] *= s;
      m[7] *= s;
      m[8] *= s;
      m[9] *= s;
      m[10] *= s;
      m[11] *= s;
      m[12] *= s;
      m[13] *= s;
      m[14] *= s;
      m[15] *= s;
      return *this;
    }
    inline Mat4Base& operator/=(T s) {
      m[0] /= s;
      m[1] /= s;
      m[2] /= s;
      m[3] /= s;
      m[4] /= s;
      m[5] /= s;
      m[6] /= s;
      m[7] /= s;
      m[8] /= s;
      m[9] /= s;
      m[10] /= s;
      m[11] /= s;
      m[12] /= s;
      m[13] /= s;
      m[14] /= s;
      m[15] /= s;
      return *this;
    }
    inline bool operator==(const Mat4Base& M) {
      return (m[0] == M[0]
      && m[1] == M[1]
      && m[2] == M[2]
      && m[3] == M[3]
      && m[4] == M[4]
      && m[5] == M[5]
      && m[6] == M[6]
      && m[7] == M[7]
      && m[8] == M[8]
      && m[9] == M[9]
      && m[10] == M[10]
      && m[11] == M[11]
      && m[12] == M[12]
      && m[13] == M[13]
      && m[14] == M[14]
      && m[15] == M[15]);
    }
    // Others
    Mat3Base<T> toMat3() {
      Mat3Base<T> res(
        m[0], m[1], m[2],
        m[4], m[5], m[6],
        m[8], m[9], m[10]
      );
      return res;
    }

  protected:
    T m[16];

};

template<typename T> const Mat4Base<T> operator*(const Mat4Base<T>& A, const Mat4Base<T>& B) {
  Mat4Base<T> result;
  int index = 0;
  for (int j = 0 ; j < 4 ; j++) {
    for (int i = 0 ; i < 4 ; i++) {
      T sum = A[i] * B[4*j];
      for (int k = 1 ; k < 4 ; k++)
        sum += A[i + 4*k] * B[k + 4*j];
      result[index] = sum;
      index++;
    }
  }
  return result;
}

template<typename T> const Vec4<T> operator*(const Mat4Base<T>& A, const Vec4<T>& B) {
  Vec4<T> result;
  int index = 0;
  for (int i = 0 ; i < 4 ; i++) {
    T sum = A[i] * B[0];
    for (int k = 1 ; k < 4 ; k++)
      sum += A[i + 4*k] * B[k];
    result[index] = sum;
    index++;
  }
  return result;
}

template<typename T> std::ostream& operator<<(std::ostream& output, const Mat4Base<T>& M) {
    output << "[" << M[0] << "][" << M[4] << "][" << M[8] << "][" << M[12] << "]\n";
    output << "[" << M[1] << "][" << M[5] << "][" << M[9] << "][" << M[13] << "]\n";
    output << "[" << M[2] << "][" << M[6] << "][" << M[10] << "][" << M[14] << "]\n";
    output << "[" << M[3] << "][" << M[7] << "][" << M[11] << "][" << M[15] << "]\n";
    return output;
}

/**
 * Four-dimensional matrix.
 */
template<typename T>
class Mat4 : public Mat4Base<T> {

  public:
    // Constructors
    inline Mat4() : Mat4Base<T>() { }
    inline Mat4(T m0, T m1, T m2, T m3, T m4, T m5, T m6, T m7, T m8, T m9, T m10, T m11, T m12, T m13, T m14, T m15) :
      Mat4Base<T>(m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15) {}
    inline Mat4(const Mat4Base<T>& M) : Mat4Base<T>(M) {}
    inline Mat4(Mat4Base<T>& M) : Mat4Base<T>(M) {}

};

template<>
class Mat4<float> : public Mat4Base<float> {

  public:
    // Constructors
    inline Mat4<float>() : Mat4Base<float>() { }
    inline Mat4<float>(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15) :
      Mat4Base<float>(m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15) {}
    inline Mat4<float>(const Mat4Base<float>& M) : Mat4Base<float>(M) {}
    inline Mat4<float>(Mat4Base<float>& M) : Mat4Base<float>(M) {}

    inline const Mat4<float> translate(const qm::Vec3<float>& v) {
      Mat4<float> result = Mat4<float>::translationMatrix(v) * *this;
      return result;
    }

    inline const Mat4<float> rotateY(float deg) {
      float rad = deg * ONE_DEG_IN_RAD;
      Mat4<float> rotation = Mat4<float>::identityMatrix();
      rotation[0] = cos(rad);
      rotation[8] = sin(rad);
      rotation[2] = -sin(rad);
      rotation[10] = cos(rad);
      return rotation * *this;
    }

    // Static methods
    static inline Mat4<float> zeroMatrix() {
      return Mat4<float>(
        0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f
      );
    }

    static inline Mat4<float> identityMatrix() {
      return Mat4<float>(
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
      );
    }

    static inline Mat4<float> translationMatrix(const qm::Vec3<float>& v) {
      Mat4<float> matrix = identityMatrix();
      matrix[12] = v[0];
      matrix[13] = v[1];
      matrix[14] = v[2];
      return matrix;
    }

    static inline Mat4<float> scaleMatrix(const qm::Vec3<float>& s) {
      Mat4<float> matrix = identityMatrix();
      matrix[0] = s[0];
      matrix[5] = s[1];
      matrix[10] = s[2];
      return matrix;
    }

};

typedef Mat4<float> Mat4f;

}

#endif // MAT4_H
