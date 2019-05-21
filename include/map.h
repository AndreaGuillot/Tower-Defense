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

/************* Classes Color et listNode *************/
//Gère les couleurs
class Color;
//Gère liste noeuds
class listNode;
class Image;
class Joueur;

/************* Classe Map : gère la map *************/
class Map {

<<<<<<< HEAD
	private:
		//Image ppm
		std::string image;
		Image img;
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
		//Nombre de monstres sur le plateau
		int nbMonstres;

	public:
		Map();
		//Get : image
		std::string getImage();
		Image getImg();
		//Get : noeuds
		int getNbNode();
		listNode* getListNode();
		//Get : couleurs de la carte
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
		//Fonctions
		/* Dessine chemin */
		bool drawRoad();
		/* Charge la map */
		bool loadMap(char* fileNameITD);
		/* Affiche monstre */
		bool apparitionMonster(listMonster* monsters, int j, Joueur joueur);
		/* Vérifie la map */
		int verifMap(FILE* fileITD);
=======
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
>>>>>>> master
};

#endif