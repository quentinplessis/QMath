#ifndef VEC4_H
#define VEC4_H

#include <ostream>

namespace qm {

template<typename T> class Vec4;

/**
 * Vector in 4 dimensions.
 */
template<typename T>
class Vec4 {

  public:
    // Constructors
    inline Vec4() {
      v[0] = v[1] = v[2] = v[3] = T();
    }
    inline Vec4(T v0, T v1, T v2, T v3) {
      init(v0, v1, v2, v3);
    }
    inline void init(T v0, T v1, T v2, T v3) {
      v[0] = v0;
      v[1] = v1;
      v[2] = v2;
      v[3] = v3;
    }
    // Operators
    inline T& operator[](int index) {
        return v[index];
    }
    inline const T& operator[](int index) const {
        return v[index];
    }
    inline Vec4& operator=(const Vec4& V) {
      v[0] = V[0];
      v[1] = V[1];
      v[2] = V[2];
      v[3] = V[3];
      return *this;
    }
    inline Vec4& operator+=(const Vec4& V) {
        v[0] += V[0];
        v[1] += V[1];
        v[2] += V[2];
        v[3] += V[3];
        return *this;
    }
    inline Vec4& operator-=(const Vec4& V) {
        v[0] -= V[0];
        v[1] -= V[1];
        v[2] -= V[2];
        v[3] -= V[3];
        return *this;
    }
    inline Vec4& operator*=(T s) {
        v[0] *= s;
        v[1] *= s;
        v[2] *= s;
        v[3] *= s;
        return *this;
    }
    inline Vec4& operator/=(T s) {
        v[0] /= s;
        v[1] /= s;
        v[2] /= s;
        v[3] /= s;
        return *this;
    }
    // Other
    inline T* getArray() const {
      return v;
    }

  protected:
    T v[4];

};

template<typename T> const Vec4<T> operator-(const Vec4<T>& v) {
    return Vec4<T>(-v[0], -v[1], -v[2], -v[3]);
}

template<typename T> std::ostream& operator<<(std::ostream& output, const Vec4<T>& V) {
    output << "[" << V[0] << " , " << V[1] << " , " << V[2] << " , " << V[3] << "]\n";
    return output;
}

template<typename T> const Vec4<T> operator/(const Vec4<T>& v, float scalar) {
    return Vec4<T>(v[0] / scalar, v[1] / scalar, v[2] / scalar, v[3] / scalar);
}

typedef Vec4<float> Vec4f;

}

#endif // VEC4_H
