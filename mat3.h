#ifndef MAT3_H
#define MAT3_H

#include <iostream>

#include "vec3.h"

namespace qm {

/**
 * Base class for a three-dimensional matrix.
 */
template<typename T> class Mat3Base {

  public:
    // Constructors
    inline Mat3Base() {
      m[0] = m[1] = m[2] = m[3] = m[4] = m[5] = m[6] = m[7] = m[8] = T();
    }
    inline Mat3Base(T m0, T m1, T m2, T m3, T m4, T m5, T m6, T m7, T m8) {
      m[0] = m0;
      m[1] = m1;
      m[2] = m2;
      m[3] = m3;
      m[4] = m4;
      m[5] = m5;
      m[6] = m6;
      m[7] = m7;
      m[8] = m8;
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
    inline Mat3Base& operator=(const Mat3Base& M) {
      m[0] = M[0];
      m[1] = M[1];
      m[2] = M[2];
      m[3] = M[3];
      m[4] = M[4];
      m[5] = M[5];
      m[6] = M[6];
      m[7] = M[7];
      m[8] = M[8];
      return *this;
    }
    inline Mat3Base& operator+=(const Mat3Base& M) {
      m[0] += M[0];
      m[1] += M[1];
      m[2] += M[2];
      m[3] += M[3];
      m[4] += M[4];
      m[5] += M[5];
      m[6] += M[6];
      m[7] += M[7];
      m[8] += M[8];
      return *this;
    }
    inline Mat3Base& operator-=(const Mat3Base& M) {
      m[0] -= M[0];
      m[1] -= M[1];
      m[2] -= M[2];
      m[3] -= M[3];
      m[4] -= M[4];
      m[5] -= M[5];
      m[6] -= M[6];
      m[7] -= M[7];
      m[8] -= M[8];
      return *this;
    }
    inline Mat3Base& operator*=(T s) {
      m[0] *= s;
      m[1] *= s;
      m[2] *= s;
      m[3] *= s;
      m[4] *= s;
      m[5] *= s;
      m[6] *= s;
      m[7] *= s;
      m[8] *= s;
      return *this;
    }
    inline Mat3Base& operator/=(T s) {
      m[0] /= s;
      m[1] /= s;
      m[2] /= s;
      m[3] /= s;
      m[4] /= s;
      m[5] /= s;
      m[6] /= s;
      m[7] /= s;
      m[8] /= s;
      return *this;
    }

    protected:
    T m[9];

};

template<typename T> const Mat3Base<T>& operator*(const Mat3Base<T>& A, const Mat3Base<T>& B) {
  Mat3Base<T> result;
  int index = 0;
  for (int j = 0 ; j < 3 ; j++) {
    for (int i = 0 ; i < 3 ; i++) {
      T sum = A[i] * B[3*j];
      for (int k = 1 ; k < 3 ; k++)
        sum += A[i + 3*k] * B[k + 3*j];
      result[index] = sum;
      index++;
    }
  }
  return result;
}

template<typename T> const Vec3<T> operator*(const Mat3Base<T>& A, const Vec3<T>& B) {
  Vec3<T> result;
  int index = 0;
  for (int i = 0 ; i < 3 ; i++) {
    T sum = A[i] * B[0];
    for (int k = 1 ; k < 3 ; k++)
      sum += A[i + 3*k] * B[k];
    result[index] = sum;
    index++;
  }
  return result;
}

template<typename T> std::ostream& operator<<(std::ostream& output, const Mat3Base<T>& M) {
    output << "[" << M[0] << "][" << M[3] << "][" << M[6] << "]\n";
    output << "[" << M[1] << "][" << M[4] << "][" << M[7] << "]\n";
    output << "[" << M[2] << "][" << M[5] << "][" << M[8] << "]\n";
    return output;
}

/**
 * Three-dimensional matrix.
 */
template<typename T>
class Mat3 : public Mat3Base<T> {

  public:
    // Constructors
    inline Mat3() : Mat3Base<T>() { }
    inline Mat3(T m0, T m1, T m2, T m3, T m4, T m5, T m6, T m7, T m8) :
      Mat3Base<T>(m0, m1, m2, m3, m4, m5, m6, m7, m8) {}
    inline Mat3(const Mat3Base<T>& M) : Mat3Base<T>(M) {}

};

template<>
class Mat3<float> : public Mat3Base<float> {

  public:
    // Constructors
    inline Mat3<float>() : Mat3Base<float>() { }
    inline Mat3<float>(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8) :
      Mat3Base<float>(m0, m1, m2, m3, m4, m5, m6, m7, m8) {}
    inline Mat3<float>(const Mat3Base<float>& M) : Mat3Base<float>(M) {}

    // Static methods
    static inline Mat3<float> zeroMatrix() {
      return Mat3<float>(
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f
      );
    }

    static inline Mat3<float> identityMatrix() {
      return Mat3<float>(
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
      );
    }

};

typedef Mat3<float> Mat3f;

}


#endif // MAT3_H
