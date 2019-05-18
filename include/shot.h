#ifndef ITD_SHOT_H_
#define ITD_SHOT_H_

#include "./monstre.h"
#include "./tower.h"
#include "./struct.h"

/************* STRUCTURE DU SHOT *************/
/* Liste doublement chainée pour pouvoir naviger dans la liste de tours	*
*  et récupérer facile n'importe quelle tour dans la liste 		*/
class Shot{

	//position du missile
	float x;
	float y;

	//Ennemie visé
	Monster target;
	
	//Tour d'origine
	Tower tower;

	//Pointer vers l'élément précédent
	Shot prev;

	//Pointeur vers l'élément suivant
	Shot next;

public:

	Shot get();
	float getX()
	float getY();
	Monster getTarget();
	Tower getTower();
	int getPower();
	towerType getType();
	Shot getPrev();
	Shot getNext();

	void set(Shot s);
	void setX(float x);
	void setY(float y);
	void setTarget(Monster m);
	void setTower(Tower t);
	void setPrev(Shot s);
	void setNext(Shot s);
}

/************* STRUCTURE DE LA LISTE DE TOURS *************/
class listShot{

	int length;
	Shot head; //pointeur vers le premier element
	Shot tail; //pointeur vers le dernier element

	int getLength();
	Shot getHead();
	Shot getTail();
	void setLength(int l);
	void setHead(Shot s);
	void setTail(Shot s);

	//Fonctions

	int addShot(Monster m, Tower t);
	int moveShot();
	void removeShot(Shot s);
	void removeAllShot();
	void freeAllShot();
}

/************* Prototypes des fonctions *************/
//Initialisation de la liste de missiles
LShot* new_LShot(void);
//Ajout d'un missile à la liste
int addShot(LShot*, Monster*, Tower*);
//Vérifie si un monstre entre dans le périmètre d'action de la tour
int inSight (LShot*, LMonster*, Tower*);
//Bouger le missile
int moveShot(LShot*);
//Vérifie s'il y a une collision avec le missile
int collisionMissile(LShot*, LMonster*, Interface* interface, Monster*, int*);
//Supprimer un missile à la liste
LShot* removeShot(LShot*, Shot*);
//Supprime tous les missiles de la liste
void removeAllShot (LShot*);
//Supprimer la liste de missiles
void freeAllShot (LShot*);

#endif
