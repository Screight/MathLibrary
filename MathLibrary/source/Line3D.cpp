#include "../header/Line3D.h"

float DistPointLine(const Point3D& q, const Point3D& p, const Vector3D& v) {
	Vector3D a = Cross(q - p, v);
	return (sqrt(Dot(a, a) / Dot(v, v)));
}

float DistPointLine(const Point3D& q, const Line3D& line) {
	Vector3D a = Cross(q - line.point, line.direction);
	return (sqrt(Dot(a, a) / Dot(line.direction, line.direction)));
}

float DistLineLine(const Point3D& p1, const Vector3D& v1,
	const Point3D& p2, const Vector3D& v2) {
	Vector3D dp = p2 - p1;

	float v12 = Dot(v1, v1);
	float v22 = Dot(v2, v2);
	float v1v2 = Dot(v1, v2);

	float det = v1v2 * v1v2 - v12 * v22;

	if (fabs(det) > FLT_MIN) {
		det = 1.0F / det;

		float dpv1 = Dot(dp, v1);
		float dpv2 = Dot(dp, v2);
		float t1 = (v1v2 * dpv2 - v22 * dpv1) * det;
		float t2 = (v12 * dpv2 - v1v2 * dpv1) * det;

		return (Magnitude(dp + v2 * t2 - v1 * t1));
	}

	// lines are nearly parallel
	Vector3D a = Cross(dp, v1);
	return (sqrt(Dot(a, a) / v12));

}

float DistLineLine(const Line3D& l1, const Line3D& l2) {

	Point3D p1 = l1.point;
	Vector3D v1 = l1.direction;
	Point3D p2 = l2.point;
	Vector3D v2 = l2.direction;

	Vector3D dp = p2 - p1;

	float v12 = Dot(v1, v1);
	float v22 = Dot(v2, v2);
	float v1v2 = Dot(v1, v2);

	float det = v1v2 * v1v2 - v12 * v22;

	if (fabs(det) > FLT_MIN) {
		det = 1.0F / det;

		float dpv1 = Dot(dp, v1);
		float dpv2 = Dot(dp, v2);
		float t1 = (v1v2 * dpv2 - v22 * dpv1) * det;
		float t2 = (v12 * dpv2 - v1v2 * dpv1) * det;

		return (Magnitude(dp + v2 * t2 - v1 * t1));
	}

	// lines are nearly parallel
	Vector3D a = Cross(dp, v1);
	return (sqrt(Dot(a, a) / v12));

}