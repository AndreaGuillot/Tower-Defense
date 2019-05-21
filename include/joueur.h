#ifndef JOUEUR_H__
#define JOUEUR_H__

#include "installation.h"
#include "map.h"
#include "shot.h"
#include "tower.h"
#include <string.h>
#include <iostream>

class Installation;
class Map;

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
    void updateMonsterKill(Monster* m);
    bool updateMoneyBuildTower(float cost);
    bool updateMoneyBuildInstallation(Installation* i);
    bool drawInterface (GLuint* spriteButton);
    void initInterface();
};

void initAll (listMonster monsters, listShot shots, listTower towers, Joueur joueur);
void freeAll (listMonster monsters, listShot shots, listTower towers, Map map, Joueur joueur);

#endif