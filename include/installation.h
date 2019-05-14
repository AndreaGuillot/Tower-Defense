#ifndef INSTALLATION_H__
#define INSTALLATION_H__
#include "../include/installation.h"
#include "../include/tower.h"
#include "../include/monstre.h"

enum installationType {
    radar, usine, stock
};

class Position{
    float x;
    float y;
};

class Size{
    float width;
    float height;
};

class Installation {

    private:
	//Position de l'installation
	Position p;
	//Type de l'installation : radar, usine, stock
	uint type;
    //Propriétés de l'installation
    Size size;
    uint cost;
	uint range;

    public:
    //Constructeur
    Installation(uint range, uint cost);
    //Accesseurs
    int getPosition();
    int getSize();
    uint getCost();
    uint getRange();
    uint getType();
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