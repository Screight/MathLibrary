#include "../header/Transform4D.h"

Transform4D operator *(const Transform4D& A, const Transform4D& B) {
	return (Transform4D(
		A(0, 0) * B(0, 0) + A(0, 1) * B(1, 0) + A(0, 2) * B(2, 0),
		A(0, 0) * B(0, 1) + A(0, 1) * B(1, 1) + A(0, 2) * B(2, 1),
		A(0, 0) * B(0, 2) + A(0, 1) * B(1, 2) + A(0, 2) * B(2, 2),
		A(0, 0) * B(0, 3) + A(0, 1) * B(1, 3) + A(0, 2) * B(2, 3) + A(0, 3),

		A(1, 0) * B(0, 0) + A(1, 1) * B(1, 0) + A(1, 2) * B(2, 0),
		A(1, 0) * B(0, 1) + A(1, 1) * B(1, 1) + A(1, 2) * B(2, 1),
		A(1, 0) * B(0, 2) + A(1, 1) * B(1, 2) + A(1, 2) * B(2, 2),
		A(1, 0) * B(0, 3) + A(1, 1) * B(1, 3) + A(1, 2) * B(2, 3) + A(1, 3),

		A(2, 0) * B(0, 0) + A(2, 1) * B(1, 0) + A(2, 2) * B(2, 0),
		A(2, 0) * B(0, 1) + A(2, 1) * B(1, 1) + A(2, 2) * B(2, 1),
		A(2, 0) * B(0, 2) + A(2, 1) * B(1, 2) + A(2, 2) * B(2, 2),
		A(2, 0) * B(0, 3) + A(2, 1) * B(1, 3) + A(2, 2) * B(2, 3) + A(2, 3)));
}

Transform4D MakeReflection(Plane f) {

	float magnitude = f.x * f.x + f.y * f.y + f.z * f.z;

	if (magnitude != 1) {
		magnitude = sqrt(magnitude);

		f.x /= magnitude;
		f.y /= magnitude;
		f.z /= magnitude;
		f.w /= magnitude;
	}

	float x = f.x * -2.0f;
	float y = f.y * -2.0f;
	float z = f.z * -2.0f;
	float nxny = x * f.y;
	float nxnz = x * f.z;
	float nynz = y * f.z;

	return (Transform4D(x * f.x + 1.0f, nxny, nxnz, x * f.w,
		nxny, y * f.y + 1.0f, nynz, y * f.w,
		nxnz, nynz, z * f.z + 1.0f, z * f.w));

}

Transform4D Inverse(const Transform4D& H) {
	const Vector3D& a = H[0];
	const Vector3D& b = H[1];
	const Vector3D& c = H[2];
	const Vector3D& d = H[3];

	Vector3D s = Cross(a, b);
	Vector3D t = Cross(c, d);

	float invDet = 1.0f / Dot(s, c);

	s *= invDet;
	t *= invDet;
	Vector3D v = c * invDet;

	Vector3D r0 = Cross(b, v);
	Vector3D r1 = Cross(v, a);

	return (Transform4D(r0.x, r0.y, r0.z, -Dot(b, t),
		r1.x, r1.y, r1.z, -Dot(a, t),
		s.x, s.y, s.z, -Dot(d, s)));
}

Plane operator *(const Plane& f, const Transform4D& H) {
	return (Plane(	f.x * H(0, 0) + f.y * H(1, 0) + f.z * H(2, 0),
					f.x * H(0, 1) + f.y * H(1, 1) + f.z * H(2, 1),
					f.x * H(0, 2) + f.y * H(1, 2) + f.z * H(2, 2),
					f.x * H(0, 3) + f.y * H(1, 3) + f.z * H(2, 3) + f.w
	));
}