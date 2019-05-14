#ifndef MAP_H__
#define MAP_H__

#include "../include/colors.h"

class Map {

    private:
	//Image ppm
	Map* map;
	//Noeuds
	Node* listNode;
	int nbNode;
	//Couleurs de la carte
    Color colorIn;
	Color colorOut;
	Color colorPath;
	Color colorNode;
	Color colorConstruct;

	public:
	//Vérifie la map
	int createMap(char *cheminITD);
	//Crée la couleur (r, g, b)
	Color createColor(float r, float g, float b);
};

#endif