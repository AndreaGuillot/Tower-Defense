#ifndef MAP_H__
#define MAP_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "../include/color.h"
#include "../include/node.h"

class Map {

private:
	//Image ppm
	char image;
	//Noeuds
	int nbNode;
	Node listNode;
	//Couleurs de la carte
    Color inColor;
	Color outColor;
	Color pathColor;
	Color nodeColor;
	Color constructColor;

public:
	Map();
	// Vérifie la map
	int verifMap(FILE* fileITD, Map *map);
	// Charge la map
	Map loadMap(char* fileNameITD);

}

#endif