#ifndef INSTALLATION_H__
#define INSTALLATION_H__

#include "color.h"
#include "draw.h"
#include "joueur.h"
#include "map.h"
#include "monstre.h"
#include "shot.h"
#include "struct.h"
#include "tower.h"
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "enum.h"

class Position;
class Tower;

class Installation {

    private:
	//Position de l'installation
	Position* p;
	//Type de l'installation : radar, usine, stock
	installationType type;
    //Propriétés de l'installation
    uint cost;
	uint range;

    public:
    //Constructeur
    Installation();
    //Accesseurs
    Position* getPosition();
    uint getCost();
    uint getRange();
    uint getType();

    void setPosition(float x, float y);
    void setCost(uint val);
    void setRange(uint val);
    void setType(installationType type);
    void affects(Tower* tower);
};

class Andrea: public Installation{
    Andrea(uint range, uint cost, installationType type);
};

class Margaux: public Installation{
    Margaux(uint range, uint cost, installationType type);
};

class BaptisteEtNicolas: public Installation{
    BaptisteEtNicolas(uint range, uint cost, installationType type);
};

#endif