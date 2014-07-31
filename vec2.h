#ifndef VEC2_H
#define VEC2_H

#include <cmath>
#include <ostream>

namespace qm {

template<typename T> class Vec2;

/**
 * Vector in 3 dimensions.
 */
template<typename T>
class Vec2 {

  public:
    // Constructors
    inline Vec2() {
      v[0] = v[1] = T();
    }
    inline Vec2(T v0, T v1) {
      v[0] = v0;
      v[1] = v1;
    }
    // Operators
    inline T& operator[] (int index) {
        return v[index];
    }
    inline const T& operator[] (int index) const {
        return v[index];
    }
    inline Vec2& operator= (const Vec2& V) {
      v[0] = V[0];
      v[1] = V[1];
      return *this;
    }
    inline Vec2& operator+= (const Vec2& V) {
        v[0] += V[0];
        v[1] += V[1];
        return *this;
    }
    inline Vec2& operator-= (const Vec2& V) {
        v[0] -= V[0];
        v[1] -= V[1];
        return *this;
    }
    inline Vec2& operator*= (T s) {
        v[0] *= s;
        v[1] *= s;
        return *this;
    }
    inline Vec2& operator/= (T s) {
        v[0] /= s;
        v[1] /= s;
        return *this;
    }
    // Other
    inline T* getArray() const {
      return v;
    }
    inline double squaredLength() const {
      return dotProduct(*this, *this);
    }
    inline double getLength() const {
      return (double) sqrt((double) squaredLength());
    }
    // Return the length of the vector and then normalize it
    inline T normalize() {
      T length = getLength();
      if (length == 0.0f)
        return 0;
      T lengthInv = 1.0f / length;
      v[0] *= lengthInv;
      v[1] *= lengthInv;
      return length;
    }
    // Static methods
    static inline T dotProduct(const Vec2& a, const Vec2& b) {
        return (a[0] * b[0] + a[1] * b[1]);
    }
    static inline T distance(const Vec2& a, const Vec2& b) {
      return (a - b).getLength();
    }
    static inline T squaredDistance(const Vec2& a, const Vec2& b) {
      return (a - b).squaredLength();
    }


  protected:
    T v[3];

};

template<typename T> const Vec2<T> operator+(const Vec2<T>& a, const Vec2<T>& b) {
    return Vec2<T>(a[0] + b[0], a[1] + b[1]);
}

template<typename T> const Vec2<T> operator-(const Vec2<T>& a, const Vec2<T>& b) {
    return Vec2<T>(a[0] - b[0], a[1] - b[1]);
}

template<typename T> const Vec2<T> operator-(const Vec2<T>& v) {
    return Vec2<T>(-v[0], -v[1]);
}

template<typename T> const Vec2<T> operator*(const Vec2<T>& v, float scalar) {
    return Vec2<T>(v[0] * scalar, v[1] * scalar);
}

template<typename T> const Vec2<T> operator*(float scalar, const Vec2<T>& v) {
    return Vec2<T> (v[0] * scalar, v[1] * scalar);
}

template<typename T> const Vec2<T> operator/(const Vec2<T>& v, float scalar) {
    return Vec2<T>(v[0] / scalar, v[1] / scalar);
}

template<typename T> bool operator!=(const Vec2<T>& a, const Vec2<T>& b) {
    return (a[0] != b[0] || a[1] != b[1]);
}

template<typename T> bool operator==(const Vec2<T>& a, const Vec2<T>& b) {
    return (a[0] == b[0] && a[1] == b[1]);
}

template<typename T> std::ostream& operator<<(std::ostream& output, const Vec2<T>& V) {
    output << "[" << V[0] << " , " << V[1] << "]\n";
    return output;
}


typedef Vec2<float> Vec2f;
typedef Vec2<int> Vec2i;

}

#endif // VEC2_H
