#ifndef ITD_SHOT_H_
#define ITD_SHOT_H_

#include "element/Monster.h"
#include "element/Tower.h"
#include "geometry/Point2D.h"
#include "geometry/Vector2D.h"
#include "ihm/Interface.h"

/************* STRUCTURE DU SHOT *************/
/* Liste doublement chainée pour pouvoir naviger dans la liste de tours	*
*  et récupérer facile n'importe quelle tour dans la liste 		*/
typedef struct struct_shot {

	//position du missile
	float x;
	float y;

	//Ennemie visé
	Monster* target;
	
	//Tour d'origine
	Tower* tower;

	//puissance
	int power;

	//Type tower
	char* type_tower;

	//Pointer vers l'élément précédent
	struct struct_shot* p_prev;

	//Pointeur vers l'élément suivant
	struct struct_shot* p_next;

}Shot;

/************* STRUCTURE DE LA LISTE DE TOURS *************/
typedef struct struct_lshot {

	//Taille de la liste
	size_t length;

	//Pointeur
	Shot *p_head; //pointeur vers le premier element
	Shot *p_tail; //pointeur vers le dernier element
}LShot;

/************* Prototypes des fonctions *************/
//Initialisation de la liste de missiles
LShot* new_LShot(void);
//Ajout d'un missile à la liste
int addShot(LShot*, Monster*, Tower*);
//Vérifie si un monstre entre dans le périmètre d'action de la tour
int inSight (LShot*, ListMonsters*, Tower*);
//Bouger le missile
int moveShot(LShot*);
//Vérifie s'il y a une collision avec le missile
int collisionMissile(LShot*, ListMonsters*, Joueur* joueur, Monster*, int*);
//Supprimer un missile à la liste
LShot* removeShot(LShot*, Shot*);
//Supprime tous les missiles de la liste
void removeAllShot (LShot*);
//Supprimer la liste de missiles
void freeAllShot (LShot*);

#endif
