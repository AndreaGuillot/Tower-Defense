#ifndef MAP_H__
#define MAP_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "../include/color.h"
#include "../src/node.cpp"

typedef struct Map {

	//Image ppm
	char* image;
	//Noeuds
	int nbNode;
	Node* listNode;
	//Couleurs de la carte
    Color inColor;
	Color outColor;
	Color pathColor;
	Color nodeColor;
	Color constructColor;

}Map;

int verifMap(FILE* fileITD, Map *map);

#endif