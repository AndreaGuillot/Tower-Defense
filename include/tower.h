#ifndef TOWER_H__
#define TOWER_H__

#include "installation.h"
#include <stdlib.h>

enum towerType {
    yoann, clara, jules, oceane
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
    //Installations à proximité
    bool instNear[3] = {0, 0, 0};
    public:
    //Constructeur
    //Accesseurs
    float getPower();
    float getRange();
    float getRate();
    uint getCost();
	void setPower(int p);
	void setRange(float rg);
	void setRate(int rt);

	virtual towerType getType() = 0;

	void addInstallation(Installation installation);
	void delInstallation(Installation installation);
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

#endif