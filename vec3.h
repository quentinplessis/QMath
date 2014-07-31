#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <ostream>

namespace qm {

template<typename T> class Vec3;

/**
 * Vector in 3 dimensions.
 */
template<typename T>
class Vec3 {

  public:
    // Constructors
    inline Vec3() {
      v[0] = v[1] = v[2] = T();
    }
    inline Vec3(T v0, T v1, T v2) {
      init(v0, v1, v2);
    }
    inline void init(T v0, T v1, T v2) {
      v[0] = v0;
      v[1] = v1;
      v[2] = v2;
    }
    inline Vec3(const Vec3& V) {
      v[0] = V[0];
      v[1] = V[1];
      v[2] = V[2];
    }
    inline Vec3(Vec3& V) {
      v[0] = V[0];
      v[1] = V[1];
      v[2] = V[2];
    }
    // Operators
    inline T& operator[] (int index) {
        return v[index];
    }
    inline const T& operator[] (int index) const {
        return v[index];
    }
    inline Vec3& operator= (const Vec3& V) {
      v[0] = V[0];
      v[1] = V[1];
      v[2] = V[2];
      return *this;
    }
    inline Vec3& operator+= (const Vec3& V) {
        v[0] += V[0];
        v[1] += V[1];
        v[2] += V[2];
        return *this;
    }
    inline Vec3& operator-= (const Vec3& V) {
        v[0] -= V[0];
        v[1] -= V[1];
        v[2] -= V[2];
        return *this;
    }
    inline Vec3& operator*= (T s) {
        v[0] *= s;
        v[1] *= s;
        v[2] *= s;
        return *this;
    }
    inline Vec3& operator*= (Vec3& V) {
        v[0] *= V[0];
        v[1] *= V[1];
        v[2] *= V[2];
        return *this;
    }
    inline Vec3& operator/= (T s) {
        v[0] /= s;
        v[1] /= s;
        v[2] /= s;
        return *this;
    }
    // Other
    inline T* getArray() const {
      return v;
    }
    inline T squaredLength() const {
      return dotProduct(*this, *this);
    }
    inline T getLength() const {
      return (T) sqrt(squaredLength());
    }
    // Return the length of the vector and then normalize it
    inline T normalize() {
      T length = getLength();
      if (length == 0.0f)
        return 0;
      T lengthInv = 1.0f / length;
      v[0] *= lengthInv;
      v[1] *= lengthInv;
      v[2] *= lengthInv;
      return length;
    }
    // Static methods
    static inline T dotProduct(const Vec3& a, const Vec3& b) {
        return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
    }
    static inline Vec3 crossProduct(const Vec3& a, const Vec3& b) {
        return Vec3(
          a[1] * b[2] - a[2] * b[1],
          a[2] * b[0] - a[0] * b[2],
          a[0] * b[1] - a[1] * b[0]
        );
    }
    static inline T distance(const Vec3& a, const Vec3& b) {
      return (a - b).getLength();
    }
    static inline T squaredDistance(const Vec3& a, const Vec3& b) {
      return (a - b).squaredLength();
    }


  protected:
    T v[3];

};

template<typename T> const Vec3<T> operator+(const Vec3<T>& a, const Vec3<T>& b) {
    return Vec3<T>(a[0] + b[0], a[1] + b[1], a[2] + b[2]);
}

template<typename T> const Vec3<T> operator-(const Vec3<T>& a, const Vec3<T>& b) {
    return Vec3<T>(a[0] - b[0], a[1] - b[1], a[2] - b[2]);
}

template<typename T> const Vec3<T> operator-(const Vec3<T>& v) {
    return Vec3<T>(-v[0], -v[1], -v[2]);
}

template<typename T> const Vec3<T> operator*(const Vec3<T>& v, float scalar) {
    return Vec3<T>(v[0] * scalar, v[1] * scalar, v[2] * scalar);
}

template<typename T> const Vec3<T> operator*(float scalar, const Vec3<T>& v) {
    return Vec3<T> (v[0] * scalar, v[1] * scalar, v[2] * scalar);
}

template<typename T> const Vec3<T> operator/(const Vec3<T>& v, float scalar) {
    return Vec3<T>(v[0] / scalar, v[1] / scalar, v[2] / scalar);
}

template<typename T> bool operator!=(const Vec3<T>& a, const Vec3<T>& b) {
    return (a[0] != b[0] || a[1] != b[1] || a[2] != b[2]);
}

template<typename T> bool operator==(const Vec3<T>& a, const Vec3<T>& b) {
    return (a[0] == b[0] && a[1] == b[1] && a[2] == b[2]);
}

template<typename T> bool operator<(const Vec3<T>& a, const Vec3<T>& b) {
    return (a[0] < b[0] && a[1] < b[1] && a[2] < b[2]);
}

template<typename T> bool operator<=(const Vec3<T>& a, const Vec3<T>& b) {
    return (a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2]);
}

template<typename T> bool operator>(const Vec3<T>& a, const Vec3<T>& b) {
    return (a[0] > b[0] && a[1] > b[1] && a[2] > b[2]);
}

template<typename T> bool operator>=(const Vec3<T>& a, const Vec3<T>& b) {
    return (a[0] >= b[0] && a[1] >= b[1] && a[2] >= b[2]);
}

template<typename T> std::ostream& operator<<(std::ostream& output, const Vec3<T>& V) {
    output << "[" << V[0] << " , " << V[1] << " , " << V[2] << "]\n";
    return output;
}


typedef Vec3<float> Vec3f;

}

#endif // VEC3_H
