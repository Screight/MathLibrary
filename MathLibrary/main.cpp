#include <iostream>
#include "header/Matrix4D.h"
#include "header/Plane.h"

int main()
{
    Plane p1 = Plane(1,0,0,0);
    Plane p2 = Plane(0,1,0,1);
    Plane p3 = Plane(0,0,1,3);

    Point3D p;

    IntersectThreePlanes (p1, p2, p3, &p);

    std::cout << p << std::endl;

}
