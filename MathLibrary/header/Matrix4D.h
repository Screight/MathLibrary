#ifndef MATRIX4D_H
#define MATRIX4D_H

#include "Vector4D.h"
#include "Matrix3D.h"

struct Matrix4D {
protected:
	float n[4][4];

public:
	Matrix4D() = default;

	Matrix4D(float n00, float n01, float n02, float n03,
			 float n10, float n11, float n12, float n13,
			 float n20, float n21, float n22, float n23,
			 float n30, float n31, float n32, float n33) {

			n[0][0] = n00; n[0][1] = n10; n[0][2] = n20; n[0][3] = n30;
			n[1][0] = n01; n[1][1] = n11; n[1][2] = n21; n[1][3] = n31;
			n[2][0] = n02; n[2][1] = n12; n[2][2] = n22; n[2][3] = n32;
			n[3][0] = n03; n[3][1] = n13; n[3][2] = n23; n[3][3] = n33;
	}

	Matrix4D(const Vector4D& a, const Vector4D& b, const Vector4D& c, const Vector4D& d) {
		n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z; n[0][3] = a.w;
		n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z; n[1][3] = b.w;
		n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z; n[2][3] = c.w;
		n[3][0] = d.x; n[3][1] = d.y; n[3][2] = d.z; n[3][3] = d.w;
	}

	float& operator ()(int i, int j) {
		return (n[j][i]);
	}

	const float& operator ()(int i, int j) const {
		return (n[j][i]);
	}

	Vector4D& operator ()(int i) {
		return (*reinterpret_cast<Vector4D*>(n[i]));
	}

	const Vector4D& operator ()(int i) const {
		return (*reinterpret_cast<const Vector4D*>(n[i]));
	}

	Vector4D& operator[](int j) {
		return (*reinterpret_cast<Vector4D*>(n[j]));
	}

	const Vector4D& operator[](int j) const {
		return (*reinterpret_cast<const Vector4D*>(n[j]));
	}
};

Matrix4D operator *(const Matrix4D& A, const Matrix4D& B);

Vector4D operator *(const Matrix4D& M, const Vector4D& v);

float Determinant(const Matrix4D& M);

Matrix4D Inverse(const Matrix4D& M);

std::ostream& operator<<(std::ostream& os, const Matrix4D M);

#endif // !MATRIX4D_H
