#include "../header/Matrix3D.h"

Matrix3D Matrix3D::MakeSkew(float t, const Vector3D& a, const Vector3D& b) {
	t = tan(t);
	float x = a.x * t;
	float y = a.y * t;
	float z = a.z * t;

	return (Matrix3D(x * b.x + 1.0f, x * b.y, x * b.z,
		y * b.x, y * b.y + 1.0f, y * b.z,
		z * b.x, z * b.y, z * b.z + 1.0f));

}

float Matrix3D::Determinant(const Matrix3D& M) {
	return(M(0, 0) * ((M(1, 1)) * M(2, 2) - M(1, 2) * M(2, 1))
		+ M(0, 1) * ((M(1, 2)) * M(2, 0) - M(1, 0) * M(2, 2))
		+ M(0, 2) * ((M(1, 0)) * M(2, 1) - M(1, 1) * M(2, 0)));
}

Matrix3D Matrix3D::Inverse(const Matrix3D& M) {
	const Vector3D& a = M[0];
	const Vector3D& b = M[1];
	const Vector3D& c = M[2];

	Vector3D r0 = Cross(b, c);
	Vector3D r1 = Cross(c, a);
	Vector3D r2 = Cross(a, b);

	float invDet = 1.0f / Dot(r2, c);

	return(Matrix3D(r0.x * invDet, r0.y * invDet, r0.z * invDet,
		r1.x * invDet, r1.y * invDet, r1.z * invDet,
		r2.x * invDet, r2.y * invDet, r2.z * invDet));
}

Matrix3D Matrix3D::MakeRotationX(float t) {
	float c = cos(t);
	float s = sin(t);

	return (Matrix3D(1.0f, 0.0f, s,
		0.0f, c, -s,
		0.0f, s, c));
}

Matrix3D Matrix3D::MakeRotationY(float t) {
	float c = cos(t);
	float s = sin(t);

	return (Matrix3D(c, 0.0f, s,
		0.0f, 1.0f, 0.0f,
		-s, 0.0f, c));
}

Matrix3D Matrix3D::MakeRotationZ(float t) {
	float c = cos(t);
	float s = sin(t);

	return (Matrix3D(c, -s, 0.0f,
		s, c, 0.0f,
		0.0f, 0.0f, c));
}

Matrix3D Matrix3D::MakeRotation(float t, const Vector3D& a) {
	float c = cos(t);
	float s = sin(t);
	float d = 1.0f - c;

	float x = a.x * d;
	float y = a.y * d;
	float z = a.z * d;
	float axay = x * a.y;
	float axaz = x * a.z;
	float ayaz = y * a.z;

	return (Matrix3D(c + x * a.x, axay - s * a.z, axaz + s * a.y,
		axay + s * a.z, c + y * a.y, ayaz - s * a.x,
		axaz - s * a.y, ayaz + s * a.x, c + z * a.z));
}

// Planes that contains the origin
Matrix3D Matrix3D::MakeReflection(Vector3D a) {

	float magnitude = Magnitude(a);
	if (magnitude != 1) {
		a.x /= magnitude;
		a.y /= magnitude;
		a.z /= magnitude;
	}

	float x = a.x * -2.0f;
	float y = a.y * -2.0f;
	float z = a.z * -2.0f;
	float axay = x * a.y;
	float axaz = x * a.z;
	float ayaz = y * a.z;

	return (Matrix3D(x * a.x + 1.0f, axay, axaz,
		axay, y * a.y + 1.0f, ayaz,
		axaz, ayaz, z * a.z + 1.0f));
}

Matrix3D Matrix3D::MakeInvolution(const Vector3D& a) {
	float x = a.x * 2.0f;
	float y = a.y * 2.0f;
	float z = a.z * 2.0f;
	float axay = x * a.y;
	float axaz = x * a.z;
	float ayaz = y * a.z;

	return (Matrix3D(x * a.x - 1.0f, axay, axaz,
		axay, y * a.y - 1.0f, ayaz,
		axaz, ayaz, z * a.z - 1.0f));
}

Matrix3D Matrix3D::MakeScale(float sx, float sy, float sz) {
	return (Matrix3D(sx, 0.0f, 0.0f, 0.0f, sy, 0.0f, 0.0f, 0.0f, sz));
}

Matrix3D Matrix3D::MakeScale(float s, const Vector3D& a) {
	s -= 1.0f;
	float x = a.x * s;
	float y = a.y * s;
	float z = a.z * s;
	float axay = x * a.y;
	float axaz = x * a.z;
	float ayaz = y * a.z;

	return (Matrix3D(x * a.x + 1.0f, axay, axaz,
		axay, y * a.y + 1.0f, ayaz,
		axaz, ayaz, z * a.z + 1.0f));
}

Matrix3D operator *(const Matrix3D& A, const Matrix3D& B) {
	return(Matrix3D(
		A(0, 0) * B(0, 0) + A(0, 1) * B(1, 0) + A(0, 2) * B(2, 0),
		A(0, 0) * B(0, 1) + A(0, 1) * B(1, 1) + A(0, 2) * B(2, 1),
		A(0, 0) * B(0, 2) + A(0, 1) * B(1, 2) + A(0, 2) * B(2, 2),
		A(1, 0) * B(0, 0) + A(1, 1) * B(1, 0) + A(1, 2) * B(2, 0),
		A(1, 0) * B(0, 1) + A(1, 1) * B(1, 1) + A(1, 2) * B(2, 1),
		A(1, 0) * B(0, 2) + A(1, 1) * B(1, 2) + A(1, 2) * B(2, 2),
		A(2, 0) * B(0, 0) + A(2, 1) * B(1, 0) + A(2, 2) * B(2, 0),
		A(2, 0) * B(0, 1) + A(2, 1) * B(1, 1) + A(2, 2) * B(2, 1),
		A(2, 0) * B(0, 2) + A(2, 1) * B(1, 2) + A(2, 2) * B(2, 2)));
}

Vector3D operator *(const Matrix3D& M, const Vector3D& v) {
	return (Vector3D(M(0, 0) * v.x + M(0, 1) * v.y + M(0, 2) * v.z,
		M(1, 0) * v.x + M(1, 1) * v.y + M(1, 2) * v.z,
		M(2, 0) * v.x + M(2, 1) * v.y + M(2, 2) * v.z));
}

std::ostream& operator<<(std::ostream& os, const Matrix3D M) {
	os  << M[0][0] << " , " << M[1][0] << " , " << M[2][0] << " \n"
		<< M[0][1] << " , " << M[1][1] << " , " << M[2][1] << " \n"
		<< M[0][2] << " , " << M[1][2] << " , " << M[2][2];
	return os;
}