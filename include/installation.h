#ifndef INSTALLATION_H__
#define INSTALLATION_H__

#include "color.h"
#include "filetower.h"
#include "draw.h"
#include "joueur.h"
#include "map.h"
#include "monstre.h"
#include "node.h"
#include "shot.h"
#include "struct.h"
#include "tower.h"
#include <string.h>

enum installationType {
    radar, usine, stock
};

class Installation {

    private:
	//Position de l'installation
	Position p;
	//Type de l'installation : radar, usine, stock
	uint type;
    //Propriétés de l'installation
    uint cost;
	uint range;

    public:
    //Constructeur
    Installation();
    //Accesseurs
    int getPosition();
    uint getCost();
    uint getRange();
    uint getType();

    void setPosition(float x, float y);
    void affects(Tower tower);
};

class Andrea: public Installation{
    Andrea(uint range = 10; uint cost = 80; type = radar);
}

class Margaux: public Installation{
    Margaux(uint range = 5; uint cost = 150; type = usine);
}

class BaptisteEtNicolas: public Installation{
    BaptisteEtNicolas(uint range = 20; uint cost = 70; type = stock);
}

#endif