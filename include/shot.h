#ifndef ITD_SHOT_H_
#define ITD_SHOT_H_

#include "draw.h"
#include "filetower.h"
#include "installation.h"
#include "color.h"
#include "joueur.h"
#include "map.h"
#include "monstre.h"
#include "struct.h"
#include "tower.h"
#include <string.h>
#include <iostream>

class Monster;
class listMonster;
class Joueur;

class Shot{

	//position du missile
	float x;
	float y;

	//Ennemie visé
	Monster* target;
	//Tour d'origine
	Tower* tower;
	//Pointer vers l'élément précédent
	Shot* prev;
	//Pointeur vers l'élément suivant
	Shot* next;

public:

	Shot get();
	float getX();
	float getY();
	Monster getTarget();
	Tower* getTower();
	int getPower();
	towerType getType();
	Shot getPrev();
	Shot getNext();

	void set(Shot s);
	void setX(float x);
	void setY(float y);
	void setTarget(Monster m);
	void setTower(Tower* t);
	void setPrev(Shot s);
	void setNext(Shot s);
};

/************* STRUCTURE DE LA LISTE DE TOURS *************/
class listShot{

	int length;
	Shot head; //pointeur vers le premier element
	Shot tail; //pointeur vers le dernier element
public:
	listShot();
	//Get
	int getLength();
	Shot getHead();
	Shot getTail();
	//Set
	void setLength(int l);
	void setHead(Shot s);
	void setTail(Shot s);

	//Fonctions

	int addShot(Monster m, Tower* t);
	int moveShot();
	void removeShot(Shot s);
	void removeAllShot();
	void freeAllShot();
	int draw(GLuint* shot);
};

//Vérifie s'il y a une collision avec le missile
int collisionMissile(listShot, listMonster, Joueur, Monster, int);


#endif
