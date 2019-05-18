#ifndef JOUEUR_H__
#define JOUEUR_H__

#include "monster.h"
#include "tower.h"
#include "installation.h"

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
    void setNbVagues();
    //Fonctions
    void updateMonsterKill(Monster m);
    void updateMoneyBuildTower(Tower t);
    void updateMoneyBuildInstallation(Installation i);
};

#endif