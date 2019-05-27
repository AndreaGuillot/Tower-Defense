#ifndef ITD_VECTOR_2D___
#define ITD_VECTOR_2D___

#include "geometry/Point2D.h"

typedef struct struct_vector {
	float x;
	float y;
}Vector2D;

Vector2D VectorXY(float, float);
Vector2D Vector(Point2D, Point2D);
Vector2D AddVectors(Vector2D, Vector2D);
Vector2D SubVectors(Vector2D, Vector2D);
Vector2D MultVector(float, Vector2D);
Vector2D DivVector(float, Vector2D);
double DotProduct(Vector2D, Vector2D);
float Norm(Vector2D);
Vector2D Normalize(Vector2D);
Point2D PointPlusVector(Point2D, Vector2D);

#endif
