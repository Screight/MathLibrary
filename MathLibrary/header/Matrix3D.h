#ifndef MATRIX3D_H
#define MATRIX3D_H

#include "Vector3D.h"
#include <iostream>

struct Matrix3D {
private:
	float n[3][3];

public:
	Matrix3D() = default;

	Matrix3D(float n00, float n01, float n02,
		float n10, float n11, float n12,
		float n20, float n21, float n22) {
		n[0][0] = n00; n[0][1] = n10; n[0][2] = n20;
		n[1][0] = n01; n[1][1] = n11; n[1][2] = n21;
		n[2][0] = n02; n[2][1] = n12; n[2][2] = n22;
	}

	Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c) {
		n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z;
		n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z;
		n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z;
	}

	float& operator ()(int i, int j) {
		return (n[j][i]);
	}

	const float& operator ()(int i, int j) const {
		return (n[j][i]);
	}

	Vector3D& operator ()(int i) {
		return (*reinterpret_cast<Vector3D*>(n[i]));
	}

	const Vector3D& operator ()(int i) const {
		return (*reinterpret_cast<const Vector3D*>(n[i]));
	}

	Vector3D& operator[](int j) {
		return (*reinterpret_cast<Vector3D*>(n[j]));
	}

	const Vector3D& operator[](int j) const {
		return (*reinterpret_cast<const Vector3D*>(n[j]));
	}

	Matrix3D MakeSkew(float t, const Vector3D& a, const Vector3D& b);
	static float Determinant(const Matrix3D& M);
	Matrix3D Inverse(const Matrix3D& M);
	Matrix3D MakeRotationX(float t);
	Matrix3D MakeRotationY(float t);
	Matrix3D MakeRotationZ(float t);
	Matrix3D MakeRotation(float t, const Vector3D& a);
	Matrix3D MakeReflection(Vector3D a);
	Matrix3D MakeInvolution(const Vector3D& a);
	Matrix3D MakeScale(float sx, float sy, float sz);
	Matrix3D MakeScale(float s, const Vector3D& a);

};

std::ostream& operator<<(std::ostream& os, const Matrix3D M);
Vector3D operator *(const Matrix3D& M, const Vector3D& v);
Matrix3D operator *(const Matrix3D& A, const Matrix3D& B);

#endif