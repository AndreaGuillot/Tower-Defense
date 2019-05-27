#ifndef ITD_TOWER_H_
#define ITD_TOWER_H_

#include "element/Monster.h"
#include "geometry/Point2D.h"
#include "ihm/Node.h"
#include "ihm/Interface.h"

/************* STRUCTURE DU TOUR *************/
/* Liste doublement chainée pour pouvoir naviger dans la liste de tours	*
*  et récupérer facile n'importe quelle tour dans la liste 		*/
typedef struct struct_tower {

	//position de la tour
	float x;
	float y;

	//Type de la tour : R (rocket) L (laser), M (mitraillette) et H (hybride)
	char* type_tower;

	//niveau de la tour
	int lvl;

	//cadence 
	int rate;

	//compteur
	int compteur;

	//porté de la tour
	int range;

	//cout de la tour
	int cost;

	//puissance de tir de la tour
	int power;

	//Pointer vers l'élément précédent
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
//Augmenter le niveau d'une tour
int upgrateTower(Tower*, Interface*);
//Augmenter l'attaque d'une tour
int upgradePowerT(Tower*, Interface*);
//Augmenter la vitesse de tir d'une tour
int upgradeRateT(Tower*, Interface*);
//Augmenter le périmètre d'action d'une tour
int upgradeRangeT(Tower*, Interface*);
//Vérifie si la tour se trouve sur une zone constructible
int verificationConstruct(LNode*, Point2D, Point2D);
//Déplacer une tour
int moveTower(LTower*, Tower*, LNode*, float, float);
//Supprimer une tour de la liste
LTower* removeTower(LTower*, Tower*);
//Suprime la liste de tours
void freeAllTower (LTower*);

#endif
