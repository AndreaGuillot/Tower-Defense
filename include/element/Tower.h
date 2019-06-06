#ifndef ITD_TOWER_H_
#define ITD_TOWER_H_

#include "element/Monster.h"
#include "geometry/Point2D.h"
#include "ihm/Node.h"
#include "ihm/Interface.h"

/************* STRUCTURE DE LA TOUR *************/
/* Liste doublement chainée pour pouvoir naviguer dans la liste de tours	*
 * et récupérer facile n'importe quelle tour dans la liste 					*/
typedef struct struct_tower {

	//Position de la tour
	float x;
	float y;

	//Type de la tour : R (rocket) L (laser) M (mitraillette) et H (hybride)
	char* type_tower;

	//Cadence 
	int rate;

	//Compteur
	int compteur;

	//Porté de la tour
	int range;

	//Coût de la tour
	int cost;

	//Puissance de tir de la tour
	int power;

	//Effet des installations
	int affectedByRadar, affectedByUsine, affectedByStock;

	//Pointeur vers l'élément précédent
	struct struct_tower* p_prev;

	//Pointeur vers l'élément suivant
	struct struct_tower* p_next;

}Tower;

/************* STRUCTURE DE LA LISTE DE TOURS *************/
typedef struct struct_ltower {

	//Taille de la liste
	size_t length;

	//Pointeur
	Tower *p_head; //pointeur vers le premier element
	Tower *p_tail; //pointeur vers le dernier element

}LTower;

/************* Prtotypes de fonctions *************/
//Initialisation de la liste de tours
LTower* new_LTower(void);
//Ajout d'une tour à la liste
int addTower(LTower*, int, int, char*, int, int, float, float);
//Vérifie si la tour se trouve sur une zone constructible
int verificationConstruct(LNode*, Point2D, Point2D);
//Supprimer une tour de la liste
LTower* removeTower(LTower*, Tower*);
//Supprimer toutes les tours de la liste
void removeAllTower (LTower*);
//Supprimer la liste de tours
void freeAllTower (LTower*);

#endif