#ifndef TOWER_H__
#define TOWER_H__

#include "draw.h"
#include "filetower.h"
#include "installation.h"
#include "color.h"
#include "joueur.h"
#include "map.h"
#include "monstre.h"
#include "shot.h"
#include "struct.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

enum towerType {
    oceane, jules, clara, yoann
};

class Position;
class Joueur;
class listShot;
class listMonster;
class listNode;

class Tower {
    private:
	//Position de la tour
	Position *p;
	//Type de la tour
	towerType type;
    //Propriétés de la tour
    //On a des float pour quand on ajoute les 25%
    float power;
    float rate;
    float range;
    uint cost;

    int compteur;
    
    Tower *prev;
    Tower *next;
    //Savoir les installations near
    bool instNear[3];

    public:
    //Constructeur
    Tower();
    //Get
    Position getPosition();
    virtual towerType getType() = 0;
    float getPower();
    float getRange();
    float getRate();
    uint getCost();
    int getCompteur();
    Tower* getPrev();
    Tower* getNext();

    //Set
    void set(Tower* t);
	void setPower(int p);
	void setRange(float rg);
	void setRate(int rt);
    void setPosition(Position p);
    void setCompteur(int a);
    void setPrev(Tower* t);
    void setNext(Tower* t);	

    //functions

    int drawProprieteTower(GLuint* tower, GLuint* spriteMenu, GLuint* btPlus, Joueur *joueur);
    int reach(listShot *shots, listMonster *monsters);
    bool isSame(Tower* t);
    
};

class Yoann: public Tower{
    public:
    	Yoann(float range=10., float rate=2.0, uint cost=120, float power =70.);
    	towerType getType();
};

class Clara: public Tower{
    public:
    	Clara(float range=20., float rate=1.0, uint cost=80, float power =60.);
    	towerType getType();
};

class Jules: public Tower{
    public:
    	Jules(float range=15., float rate=1.5, uint cost=60, float power =30.);
    	towerType getType();
};

class Oceane: public Tower{
    public:
    	Oceane(float range=50., float rate=0.5, uint cost=50, float power =10.);
    	towerType getType();
};

class listTower {

private:
    int length;
    //Pointeur
    Tower* head; //pointeur vers le premier element
    Tower* tail; //pointeur vers le dernier element

public:

    listTower();

    int getLength();
    Tower* getHead();
    Tower* getTail();

    void setLength(int a);
    void setHead(Tower* t);
    void setTail(Tower* t);

    int addTower(towerType type, Position p);
    int moveTower(Tower* tower, listNode list_node, float x, float y);
    void removeTower(Tower* t);
    void removeAllTower();
    void freeAllTower();
};

#endif