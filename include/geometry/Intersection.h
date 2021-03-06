#ifndef ITD_INTERSECTION_H_
#define ITD_INTERSECTION_H_

#include "geometry/Point2D.h"
#include "geometry/Vector2D.h"

/************* Prototypes des fonctions  *************/
//Vérifie s'il y a une intersection entre un point et un segment
int intersectionPointSegment (Point2D, Point2D, Point2D);
//Vérifie s'il y a une intersection entre deux segments
int intersectionSegments (Point2D, Point2D, Point2D, Point2D);
//Vérifie s'il y a une intersection entre un cercle et un segment
int intersectionSegmentCercle (Point2D, Point2D, Point2D, float);
//Vérifie s'il y a une intersection entre deux carrés
int intersectionCarres (Point2D, Point2D, Point2D, Point2D);
//Vérifie s'il y a une intersection entre un carré et un disque
int intersectionCarreDisque (Point2D, Point2D, float, Point2D);

#endif