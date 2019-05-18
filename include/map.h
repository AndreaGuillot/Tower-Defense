#ifndef MAP_H__
#define MAP_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "draw.h"
#include "filetower.h"
#include "installation.h"
#include "color.h"
#include "joueur.h"
#include "monstre.h"
#include "node.h"
#include "shot.h"
#include "struct.h"
#include "tower.h"
#include <string.h>
#include <iostream>

class Map {

private:
	//Image ppm
	string image;
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

	//Liste des zones constructibles
	listNode listConstruct;

	//nombre de monstres sur le plateau
	int nbMontres;

public:
	Map();
	//Get 
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

	//Set
	void setNbMonstres(int a);

	//fonctions
	bool drawRoad();
	bool loadMap(char* fileNameITD);
	int apparitionMonster(listMonster monsters, int j, Joueur joueur);
}

// Vérifie la map
int verifMap(FILE* fileITD, Map map);

#endif