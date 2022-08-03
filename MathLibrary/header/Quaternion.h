#ifndef QUATERNION_H
#define QUATERNION_H

#include "Matrix3D.h"

struct Quaternion {
	float x, y, z, w;

	Quaternion() = default;
	
	Quaternion(float a, float b, float c, float s): 
		x(a), y(b), z(c), w(s) {}

	Quaternion(const Vector3D& v, float s) : w(s) {
		x = v.x; y = v.y; z = v.z;
	}

	const Vector3D& GetVectorPart(void) const {
		return (reinterpret_cast<const Vector3D&>(x));
	}

	Matrix3D GetRotationMatrix(void);
	void SetRotationMatrix(const Matrix3D& m);

	Quaternion operator +(const Quaternion& q1) {
		x += q1.x;
		y += q1.y;
		z += q1.z;
		w += q1.w;
		return (*this);
	}

	Quaternion operator -(const Quaternion& q1) {
		x -= q1.x;
		y -= q1.y;
		z -= q1.z;
		w -= q1.w;
		return (*this);
	}

	Quaternion operator *(const float& f) {
		x *= f;
		y *= f;
		z *= f;
		w *= f;
		return (*this);
	}

	Quaternion operator /(const float& f) {
		x /= f;
		y /= f;
		z /= f;
		w /= f;
		return (*this);
	}

	// It is assumed that q is a unity quaternion
	static Vector3D Transform(const Vector3D& v, const Quaternion q);
	static Quaternion Inverse(const Quaternion& q);
	static Quaternion Conjugate(const Quaternion& q);
	static float Magnitude(const Quaternion& q);

	Quaternion Inverse() { return Inverse(*this); }
	Quaternion Conjugate() { return Conjugate(*this); }
	float Magnitude() { return Magnitude(*this); }
};

Quaternion operator *(const Quaternion& q1, const Quaternion& q2);

inline Quaternion operator +(const Quaternion& q1, const Quaternion& q2) {
	return(Quaternion(
		q1.x + q2.x, q1.y + q2.y, q1.z + q2.z, q1.w + q2.w));
}

inline Quaternion operator -(const Quaternion& q1, const Quaternion& q2) {
	return(Quaternion(
		q1.x - q2.x, q1.y - q2.y, q1.z - q2.z, q1.w - q2.w));
}

inline Quaternion operator *(const float& f, const Quaternion& q1) {
	return(Quaternion(
		q1.x * f, q1.y * f, q1.z * f , q1.w * f));
}

inline Quaternion operator /(const Quaternion& q1, const float& f) {
	return(Quaternion(
		q1.x / f, q1.y / f, q1.z / f, q1.w / f));
}

#endif