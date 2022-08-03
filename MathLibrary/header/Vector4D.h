#ifndef VECTOR4D_H
#define VECTOR4D_H

#include <math.h>
#include <ostream>
#include "Vector3D.h"

struct Vector4D {
	float x, y, z, w;

	Vector4D() = default;

	Vector4D(float a, float b, float c, float d) {
		x = a;
		y = b;
		z = c;
		w = d;
	}

	float& operator [](int i) {
		return ((&x)[i]);
	}

	const float& operator [](int i) const {
		return ((&x)[i]);
	}

	Vector4D& operator *=(float s) {
		x *= s;
		y *= s;
		z *= s;
		w *= s;
		return (*this);
	}

	Vector4D& operator /=(float s) {
		x /= s;
		y /= s;
		z /= s;
		w /= s;
		return (*this);
	}

	Vector4D& operator +=(const Vector4D& v) {
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;
		return (*this);
	}

	Vector4D& operator -=(const Vector4D& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;
		return (*this);
	}

	operator Vector3D() { return Vector3D(x, y, z); }
	operator const Vector3D() const { return Vector3D(x, y, z); }

};

inline Vector4D operator *(const Vector4D& v, float s) {
	return (Vector4D(v.x * s, v.y * s, v.z * s, v.w * s));
}

inline Vector4D operator /(const Vector4D& v, float s) {
	return (Vector4D(v.x / s, v.y / s, v.z / s, v.w / s));
}

inline Vector4D operator -(const Vector4D& v) {
	return (Vector4D(-v.x, -v.y, -v.z, -v.w));
}

inline float Magnitude(const Vector4D& v) {
	return (sqrt(v.x * v.x + v.y + v.y + v.z * v.z + v.w * v.w));
}

inline Vector4D Normalize(const Vector4D& v) {
	return (v / Magnitude(v));
}

inline Vector4D operator +(const Vector4D& a, const Vector4D& b) {
	return (Vector4D(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w));
}

inline Vector4D operator -(const Vector4D& a, const Vector4D& b) {
	return (Vector4D(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w));
}

inline float Dot(const Vector4D& a, const Vector4D& b) {
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}

inline std::ostream& operator<<(std::ostream& os, const Vector4D V) {
	os << V[0] << " , " << V[1] << " , " << V[2] << " , " << V[3];
	return os;
}

#endif
