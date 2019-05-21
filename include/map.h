#ifndef MAP_H__
#define MAP_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "color.h"
#include "joueur.h"
#include "monstre.h"

class Color;
class listNode;
class Image;
class Joueur;

class Map {

private:
	//Image ppm
	std::string image;
	Image* img;
	//Noeuds
	int nbNode;
	listNode* list_node;
	//Couleurs de la carte
    Color* inColor;
	Color* outColor;
	Color* pathColor;
	Color* nodeColor;
	Color* constructColor;

	//Liste des zones constructibles
	listNode* listConstruct;
	listNode* list_pixels;

	//nombre de monstres sur le plateau
	int nbMonstres;

public:
	Map();
	//Get 
	std::string getImage();
	Image* getImg();
	//Noeuds
	int getNbNode();
	listNode* getListNode();
	//Couleurs de la carte
    Color* getInColor();
	Color* getOutColor();
	Color* getPathColor();
	Color* getNodeColor();
	Color* getConstructColor();
	listNode* getListConstruct();
	int getNbMonstres();
	listNode* getList_pixels();

	//Set
	void setNbMonstres(int a);
	void setInColor(Color* color);
	void setOutColor(Color* color);
	void setPathColor(Color* color);
	void setNodeColor(Color* color);
	void setConstructColor(Color* color);

	//fonctions
	bool drawRoad();
	bool loadMap(char* fileNameITD);
	bool apparitionMonster(listMonster* monsters, int j, Joueur* joueur);
	// Vérifie la map
	int verifMap(FILE* fileITD);
};

#endif