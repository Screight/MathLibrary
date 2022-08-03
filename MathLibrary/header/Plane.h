#ifndef PLANE_H
#define PLANE_H

#include "Vector3D.h"
#include "Line3D.h"

struct Plane {
	float x, y, z, w;

	Plane() = default;

	Plane(float nx, float ny, float nz, float d) : x(nx), y(ny), z(nz), w(d) {}
	Plane(const Vector3D& n, float d): x(n.x), y(n.y), z(n.z), w(d) {}

	const Vector3D& GetNormal(void) const {
		return (reinterpret_cast<const Vector3D&>(x));
	}

};

inline float Dot(const Plane& f, const Vector3D& v) {
	return (f.x * v.x + f.y * v.y + f.z * f.z);
}

inline float Dot(const Plane& f, const Point3D& p) {
	return (f.x * p.x + f.y * p.y + f.z * p.z + f.w);
}

float DistancePlanePoint(Plane plane, const Point3D& point);

bool IntersectLinePlane(const Point3D& p, const Vector3D& v, const Plane& f, Point3D* q);

bool IntersectLinePlane(const Line3D& l, const Plane& f, Point3D* q);

bool IntersectThreePlanes(const Plane& f1, const Plane& f2, const Plane& f3, Point3D* p);

bool IntersectTwoPlanes(const Plane& f1, const Plane& f2, Line3D* l);

#endif
