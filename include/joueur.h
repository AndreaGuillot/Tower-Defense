#ifndef JOUEUR_H__
#define JOUEUR_H__

#include "monster.h"
#include "tower.h"
#include "installation.h"

class Joueur {

    private:
	uint argent;
	
    public:
    //Constructeur
    Joueur();
    //Get
    uint getArgent();

    //Set
    void setArgent(uint argent);
    //Fonctions
    void updateMonsterKill(Monster m);
    void updateMoneyBuildTower(Tower t);
    void updateMoneyBuildInstallation(Installation i);
};

#endif