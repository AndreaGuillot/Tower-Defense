#ifndef ITD_SHOT_H_
#define ITD_SHOT_H_

#include "joueur.h"
#include <string.h>
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>

/************* Classes Position et Tower *************/
//Gère monstre
class Monster;
//Gère liste monstres
class listMonster;
//Gère info joueur
class Joueur;
class Tower;

/************* Classe Shot : gère les tirs des tours *************/
class Shot{

	//Position du missile
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
		//Constructeur
		Shot();
		//Get
		Shot* get();
		float getX();
		float getY();
		Monster* getTarget();
		Tower* getTower();
		int getPower();
		towerType getType();
		Shot* getPrev();
		Shot* getNext();
		//Set
		void set(Shot* s);
		void setX(float x);
		void setY(float y);
		void setTarget(Monster* m);
		void setTower(Tower* t);
		void setPrev(Shot* s);
		void setNext(Shot* s);
};

/************* Classe listShot : gère liste tirs *************/
class listShot{

	int length;
	Shot* head; //pointeur vers le premier element
	Shot* tail; //pointeur vers le dernier element

	public:
		//Constructeur
		listShot();
		//Get
		int getLength();
		Shot* getHead();
		Shot* getTail();
		//Set
		void setLength(int l);
		void setHead(Shot* s);
		void setTail(Shot* s);
		//Fonctions
		/* Ajoute tir */
		int addShot(Monster* m, Tower* t);
		/* Deplacement tir */
		int moveShot();
		/* Supprime tir */
		void removeShot(Shot* s);
		/* Supprime tous les tirs */
		void removeAllShot();
		/* Libère espace mémoire */
		void freeAllShot();
		/* Dessine tir */
		int draw(GLuint* shot);
};

//Vérifie s'il y a une collision avec le missile
bool collisionMissile(listShot*, listMonster*, Joueur*, Monster*, Propriete*);


#endif
