#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <math.h>
#include <ostream>

struct Point3D;

struct Vector3D {
public:
	float x, y, z;

	Vector3D() = default;

	Vector3D(float a, float b, float c) {
		x = a;
		y = b;
		z = c;
	}

	float& operator [](int i) {
		return ((&x)[i]);
	}

	const float& operator [](int i) const {
		return ((&x)[i]);
	}

	Vector3D& operator *=(float s) {
		x *= s;
		y *= s;
		z *= s;
		return (*this);
	}

	Vector3D& operator /=(float s) {
		x /= s;
		y /= s;
		z /= s;
		return (*this);
	}

	Vector3D& operator +=(const Vector3D& v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return (*this);
	}

	Vector3D& operator -=(const Vector3D& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return (*this);
	}

	operator Point3D();
	operator const Point3D() const;

};

inline Vector3D operator *(const Vector3D& v, float s) {
	return (Vector3D(v.x * s, v.y * s, v.z * s));
}

inline Vector3D operator /(const Vector3D& v, float s) {
	return (Vector3D(v.x / s, v.y / s, v.z / s));
}

inline Vector3D operator -(const Vector3D& v) {
	return (Vector3D(-v.x, -v.y, -v.z));
}

inline float Magnitude(const Vector3D& v) {
	return (sqrt(v.x * v.x + v.y + v.y + v.z * v.z));
}

inline Vector3D Normalize(const Vector3D& v) {
	return (v / Magnitude(v));
}

inline Vector3D operator +(const Vector3D& a, const Vector3D& b) {
	return (Vector3D(a.x + b.x, a.y + b.y, a.z + b.z));
}

inline Vector3D operator -(const Vector3D& a, const Vector3D& b) {
	return (Vector3D(a.x - b.x, a.y - b.y, a.z - b.z));
}

inline float Dot(const Vector3D& a, const Vector3D& b) {
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

inline Vector3D Cross(const Vector3D& a, const Vector3D& b) {
	return (Vector3D(	a.y * b.z - a.z * b.y,
						a.z * b.x - a.x * b.z, 
						a.x * b.y - a.y * b.x));
}

inline std::ostream& operator<<(std::ostream& os, const Vector3D V) {
	os << V[0] << " , " << V[1] << " , " << V[2];
	return os;
}

#endif