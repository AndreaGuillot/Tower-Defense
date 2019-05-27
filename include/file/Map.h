#ifndef LDR_MAP_H_
#define LDR_MAP_H_

#include "geometry/Color3f.h"
#include "file/Image.h"
#include "ihm/Node.h"

/************* STRUCTURE DE LA CARTE *************/
typedef struct struct_map {

	//Image ppm
	Image* img;

	//énergie
	int energie;

	//couleur du chemin
	Color3f road;

	//couleur des noeuds
	Color3f node;

	//couleur à la zone constructible
	Color3f construct;
	//liste des pixels de zone constructible
	LNode* list_pixels;

	//couleur clé de la zone d'entrée
	Color3f in;

	//couleur clé de la zone de sortie
	Color3f out;

	//Nombre de noeud
	int number_node;

	//Liste des noeuds
	LNode* list_node;

}Map;

/************* Prototypes des fonctions *************/
//Initialisation de la map
Map* newMap (char*);
//Vérification de la carte
int verificationMap(Map*, char*);
//Change les couleurs de la carte
int ChangeColor(Image*, unsigned char*, Map*);
//Change les couleurs du chemin de la carte
int changeColorRoad(Image*, unsigned char*, Map*);
//Change les couleur des zones constructibles
int changeColorConstruct(Image*, unsigned char*, Map*);
//Change la couleur des noeuds
int changeColorNode(Image*, unsigned char*, Map*);
//Change la couleur de l'entrée
int changeColorIn(Image*, unsigned char*, Map*);
//Change la couleur de la sortie
int changeColorOut(Image*, unsigned char*, Map*);
//Libère la mémoire alloué pour la carte
void freeMap (Map*);

#endif
