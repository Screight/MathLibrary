#include "../header/Plane.h"

float DistancePlanePoint(Plane plane, const Point3D& point) {
	float normalMagnitude = plane.x * plane.x + plane.y * plane.y + plane.z * plane.z;

	if (normalMagnitude != 1) {
		normalMagnitude = sqrt(normalMagnitude);
		plane.x /= normalMagnitude;
		plane.y /= normalMagnitude;
		plane.z /= normalMagnitude;
		plane.w /= normalMagnitude;
	}

	return fabs(Dot(plane, point));
}

bool IntersectLinePlane(const Point3D& p, const Vector3D& v,
	const Plane& f, Point3D* q) {
	float fv = Dot(f, v);
	if (fabs(fv) < FLT_MIN) { return false; }

	*q = p - v * (Dot(f, p) / fv);
	return true;

}

bool IntersectLinePlane(const Line3D& l,
	const Plane& f, Point3D* q) {

	const Point3D& p = l.point;
	const Vector3D& v = l.direction;

	float fv = Dot(f, v);
	if (fabs(fv) < FLT_MIN) { return false; }

	*q = p - v * (Dot(f, p) / fv);
	return true;
}

bool IntersectThreePlanes(const Plane& f1, const Plane& f2,
	const Plane& f3, Point3D* p) {
	const Vector3D& n1 = f1.GetNormal();
	const Vector3D& n2 = f2.GetNormal();
	const Vector3D& n3 = f3.GetNormal();

	Vector3D n1xn2 = Cross(n1, n2);
	float det = Dot(n1xn2, n3);
	if (fabs(det) > FLT_MIN) {
		*p = (Point3D)(Cross(n3, n2) * f1.w + Cross(n1, n3) * f2.w - n1xn2 * f3.w) / det;
		return true;
	}
	return false;
}

bool IntersectTwoPlanes(const Plane& f1, const Plane& f2, Line3D* l) {
	
	const Vector3D& n1 = f1.GetNormal();
	const Vector3D& n2 = f2.GetNormal();

	Vector3D v = Cross(n1, n2);
	(*l).direction = v;


	float det = Dot(v, v);

	if (fabs(det) > FLT_MIN) {
		(*l).point = (Cross(v, n2) * f1.w + Cross(n1, v) * f2.w) / det;
		return true;
	}
	return false;
}