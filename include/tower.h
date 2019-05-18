#ifndef TOWER_H__
#define TOWER_H__

#include "installation.h"
#include "struct.h"
#include <stdlib.h>

enum towerType {
    oceane, jules, clara, yoann
};

class Tower {
    private:
	//Position de la tour
	Position p;
	//Type de la tour
	towerType type;
    //Propriétés de la tour
    //On a des float pour quand on ajoute les 25%
    float power;
    float rate;
    float range;
    uint cost;

    int compteur;
    
    Tower prev;
    Tower next;
    //Savoir les installations near
    bool instNear[3];

    public:
    //Constructeur
    //Get
    Position getPosition();
    float getPower();
    float getRange();
    float getRate();
    uint getCost();
    int getCompteur();
    Tower getPrev();
    Tower getNext();

    //Set
    void set(Tower t);
	void setPower(int p);
	void setRange(float rg);
	void setRate(int rt);
    void setPosition(Position p);
    void setPrev(Tower t);
    void setNext(Tower t);

	virtual towerType getType() = 0;
};

class Yoann: public Tower{
    public:
    	Yoann(float range=10.; float rate=2.0; uint cost=120; float power =70.);
    	towerType getType();
}

class Clara: public Tower{
    public:
    	Clara(float range=20.; float rate=1.0; uint cost=80; float power =60.);
    	towerType getType();
}

class Jules: public Tower{
    public:
    	Jules(float range=15.; float rate=1.5; uint cost=60; float power =30.);
    	towerType getType();
}

class Oceane: public Tower{
    public:
    	Oceane(float range=50.; float rate=0.5; uint cost=50; float power =10.);
    	towerType getType();
}

class listTower {

private:
    int length;
    //Pointeur
    Tower head; //pointeur vers le premier element
    Tower tail; //pointeur vers le dernier element

public:

    listTower();

    Tower getHead();
    Tower getTail();
    void setHead(Tower t);
    void setTail(Tower t);
    int addTower(towerType type, Position p);
    int moveTower(Tower tower, listNode list_node, float x, float y);
    void removeTower(Tower t);
}

#endif