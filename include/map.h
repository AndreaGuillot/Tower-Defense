#ifndef MAP_H__
#define MAP_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "../include/draw.h"
#include "../include/filetower.h"
#include "../include/installation.h"
#include "../include/color.h"
#include "../include/joueur.h"
#include "../include/monstre.h"
#include "../include/shot.h"
#include "../include/struct.h"
#include "../include/tower.h"
#include "image.h"

#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

class Color;
class listNode;

class Map {

private:
	//Image ppm
	std::string image;
	Image* img;
	//Noeuds
	int nbNode;
	listNode list_node;
	//Couleurs de la carte
    Color* inColor;
	Color* outColor;
	Color* pathColor;
	Color* nodeColor;
	Color* constructColor;

	//Liste des zones constructibles
	listNode listConstruct;

	listNode list_pixels;

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
	int getNbMonstres();
	listNode getList_pixels();

	//Set
	void setNbMonstres(int a);

	//fonctions
	bool drawRoad();
	bool loadMap(char* fileNameITD);
	bool apparitionMonster(listMonster monsters, int j, Joueur joueur);
};

// Vérifie la map
int verifMap(FILE* fileITD, Map map);

#endif