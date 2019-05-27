#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "geometry/Point2D.h"

/* PointXYZ : Contruit un point à partir de x, y */
Point2D PointXY(float x, float y) {

	Point2D new_point;

	new_point.x = x;
	new_point.y = y;

	return new_point;
}
