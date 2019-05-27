#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "geometry/Point3D.h"
#include "geometry/Color3f.h"
#include "geometry/Vector3D.h"
#include "geometry/Ray3D.h"
#include "geometry/Sphere.h"
#include "geometry/Union.h"
#include "geometry/Intersection.h"
#include "geometry/Cube.h"
#include "geometry/Shape.h"

/* Cube */
Cube CubeInit(Point3D A, Point3D B, Color3f color) {

	Cube new_cube;

	new_cube.type = CUBE_SHAPE;
	new_cube.point1 = A;
	new_cube.point2 = B;
	new_cube.color = color;

	return new_cube;
}
