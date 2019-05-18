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
	Image* img;
	//Noeuds
	int nbNode;
	listNode listNode;
	//Couleurs de la carte
    Color inColor;
	Color outColor;
	Color pathColor;
	Color nodeColor;
	Color constructColor;
	listNode listConstruct;

/*Color3f road;

	//couleur des noeuds
	Color3f node;

	//couleur à la zone constructible
	Color3f construct;

	//couleur clé de la zone d'entrée
	Color3f in;

	//couleur clé de la zone de sortie
	Color3f out;
*/

public:
	Map();
	// Vérifie la map
	int verifMap(FILE* fileITD, Map *map);
	// Charge la map
	Map loadMap(char* fileNameITD);

	bool drawRoad();

	char getImage();
	Image* getImg();
	//Noeuds
	int getNbNode();
	listNode getListNode();
	//Couleurs de la carte
    Color getInColor();
	Color getOutColor();
	Color getPathColor();
	Color getNodeColor();
	Color getConstructColor();
	listNode getListConstruct();

}

#endif