#ifndef INSTALLATION_H__
#define INSTALLATION_H__

#include "joueur.h"
#include "enum.h"
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/************* Classes Position et Tower *************/
//Gère position des éléments du jeu
class Position;
//Gère informations des tours
class Tower;

/************* Classe installation : gère les bâtiments *************/
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
        //Get
        Position* getPosition();
        uint getCost();
        uint getRange();
        uint getType();
        //Set
        void setPosition(float x, float y);
        void setCost(uint val);
        void setRange(uint val);
        void setType(installationType type);
        void affects(Tower* tower);
};

//Type radar
class Andrea: public Installation{
    Andrea(uint range, uint cost, installationType type);
};
//Type usine
class Margaux: public Installation{
    Margaux(uint range, uint cost, installationType type);
};
//Type stock
class BaptisteEtNicolas: public Installation{
    BaptisteEtNicolas(uint range, uint cost, installationType type);
};

#endif