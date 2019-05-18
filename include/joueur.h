#ifndef JOUEUR_H__
#define JOUEUR_H__

#include "draw.h"
#include "filetower.h"
#include "installation.h"
#include "color.h"
#include "map.h"
#include "monstre.h"
#include "shot.h"
#include "struct.h"
#include "tower.h"
#include <string.h>
#include <iostream>

class Installation;

class Joueur {

    private:
	uint argent;
    int nbVagues;
	
    public:
    //Constructeur
    Joueur();
    //Get
    uint getArgent();
    int getNbVagues();
    //Set
    void setArgent(uint argent);
    void setNbVagues(int n);
    //Fonctions
    void updateMonsterKill(Monster m);
    bool updateMoneyBuildTower(Tower* t);
    bool updateMoneyBuildInstallation(Installation i);
    bool drawInterface (GLuint* spriteButton);
};

#endif