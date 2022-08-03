#include "../header/Vector3D.h"
#include "../header/Point3D.h"

Vector3D::operator Point3D() { return Point3D(x, y, z); }
Vector3D::operator const Point3D() const { return Point3D(x, y, z); }