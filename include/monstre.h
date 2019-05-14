#ifndef MONSTER_H__
#define MONSTER_H__

#include "installation.h"
#include "tower.h"

class Monster {

    private:
	//Position du monstre
	Position p;
    //Propriétés du monstre
	uint pv;
	uint speed;
    uint money;
	float resistance_TDR;
    float resistance_TDV;
    float resistance_TDJ;
    float resistance_TDB;
	
    public:
    //Constructeur
    //Accesseurs
    float getPV();
    float getSpeed();
    //Ce qu'on gagne qd il meurt
    uint getReward();
    float getResistance_TDR();
    float getResistance_TDV();
    float getResistance_TDJ();
    float getResistance_TDB();
    //Mutateurs
    void move();
    void hitBy(Tower tower);
    void killMonster();
};

class Lucie: public Monster{
    public:
        Lucie(uint pv=200; uint speed; uint money = 20; float resistance_TDR = 0.5; float resistance_TDV = 0; float resistance_TDJ = 0.3; float resistance_TDB = 0.2);
}

class Barbara: public Monster{
    public:
        Barbara(uint pv=100; uint speed; uint money = 15; float resistance_TDR = 0.1; float resistance_TDV = 0.5; float resistance_TDJ = 0.3; float resistance_TDB = 0.1);
}


class Julien: public Monster{
    public:
        Julien(uint pv=50; uint speed; uint money = 8; float resistance_TDR = 0.1; float resistance_TDV = 0.8; float resistance_TDJ = 0.; float resistance_TDB = 0.);
}

#endif