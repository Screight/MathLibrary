#ifndef LINE_H
#define LINE_H

#include "Point3D.h"
#include "Vector3D.h"

struct Line3D {
	Point3D point;
	Vector3D direction;

	Line3D() = default;
	
	Line3D(Point3D point, Vector3D direction) : point(point), direction(direction) {}

};

float DistPointLine(const Point3D& q, const Point3D& p, const Vector3D& v);

float DistPointLine(const Point3D& q, const Line3D& line);

float DistLineLine(const Point3D& p1, const Vector3D& v1,
	const Point3D& p2, const Vector3D& v2);

float DistLineLine(const Line3D& l1, const Line3D& l2);

#endif