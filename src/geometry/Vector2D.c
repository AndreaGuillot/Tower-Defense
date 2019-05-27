#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "geometry/Vector2D.h"
#include "geometry/Point2D.h"

/* Vector XYZ : Contruit un vecteur à partir de x, y */
Vector2D VectorXY(float x, float y) {

	Vector2D new_vector;

	new_vector.x = x;
	new_vector.y = y;

	return new_vector;
}

/* Vector : Contruit un vecteur à partir de deux points */
Vector2D Vector(Point2D A, Point2D B) {
	
	Vector2D new_vector;

	new_vector.x = (B.x) - (A.x);
	new_vector.y = (B.y) - (A.y);

	return new_vector;

}


/*AddVectors : La fonction d’addition de vecteurs */
Vector2D AddVectors(Vector2D V1, Vector2D V2){

	Vector2D new_vector;

	new_vector.x = (V1.x) + (V2.x);
	new_vector.y = (V1.y) + (V2.y);

	return new_vector;
}

/*SubVectors : La fonction de soustraction de vecteurs */
Vector2D SubVectors(Vector2D V1, Vector2D V2){

	Vector2D new_vector;

	new_vector.x = (V1.x) - (V2.x);
	new_vector.y = (V1.y) - (V2.y);

	return new_vector;
}

/* MultVector : La fonction de la multiplication d’un vecteur par un scalaire */
Vector2D MultVector(float lamba, Vector2D V){

	if(lamba == 1) 
		return V;

	Vector2D new_vector;

	new_vector.x = lamba * (V.x);
	new_vector.y = lamba * (V.y);

	return new_vector;

}

/* DivVector : La fonction de la division d’un vecteur par un scalaire */
Vector2D DivVector(float lambda, Vector2D V){

	Vector2D new_vector;

	if(lambda == 0) {
		fprintf(stderr, "Erreur impossible de faire une division par 0");
		return new_vector;
	}
	else if(lambda == 1)
		return V;

	lambda = 1/lambda;

	new_vector.x = lambda * (V.x);
	new_vector.y = lambda * (V.y);

	return new_vector;

}


/* La fonction Norm calculant la norme d’un vecteur */
double DotProduct(Vector2D V1, Vector2D V2){

	float result = (V1.x * V2.x) + (V1.y * V2.y);
	return result;
}


/* La fonction Norm calculant la norme d’un vecteur */
float Norm(Vector2D V) {
	float norme;

	norme = ((V.x) * (V.x)) + ((V.y) * (V.y));
	norme = sqrt(norme);

	return norme;
}

/* Normalize : calcule le normalisé d’un vecteur */
Vector2D Normalize(Vector2D V){

	Vector2D new_vector;
	float norme = Norm(V);
	
	new_vector.x = (V.x) / norme;
	new_vector.y = (V.y) / norme;

	return new_vector;
}

/* PointPlusVector : Fonction d'addition d'un point et d'un vecteur = translation */
Point2D PointPlusVector(Point2D P, Vector2D V) {
	
	Point2D new_point;

	new_point.x = (P.x) + (V.x);
	new_point.y = (P.y) + (V.y);

	return new_point;

}

