#include "../include/installation.h"
#include "../include/tower.h"
#include "../include/monstre.h"

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
    float getPV(){
        return this->pv;
    }
    float getSpeed(){
        return this->speed;
    }
    //Ce qu'on gagne qd il meurt
    uint getReward(){
        return this->money;
    }
    float getResistance_TDR(){
        return this->resistance_TDR;
    }
    float getResistance_TDV(){
        return this->resistance_TDV;
    }
    float getResistance_TDJ(){
        return this->resistance_TDJ;
    }
    float getResistance_TDB(){
        return this->resistance_TDB;
    }
    //Mutateurs
    void move(){
        float newX, newY;
        //Calculer
        this->p.x = newX;
        this->p.y = newY;
    }

    void hitBy(Tower tower){
        int newPV = this->pv;
        switch (tower.getType()){
            case yoann:
                newPV = int(tower.getPower()*(1-this->resistance_TDR));
                break;
            case clara:
                newPV = int(tower.getPower()*(1-this->resistance_TDV));
                break;
            case jules:
                newPV = int(tower.getPower()*(1-this->resistance_TDJ));
                break;
            case oceanne:
                newPV = int(tower.getPower()*(1-this->resistance_TDB));
                break;
            default:
                break;
        }
        if(newPV>0){
            this->pv = (uint)newPV;
        }else{
            killMonster(this);
        }
    }

    void killMonster(Joueur j){
        j.kill(this);
        delete this;
    }

};

class Lucie: public Monster{
    public:
        Lucie(uint pv=200; uint speed; uint money = 20; float resistance_TDR = 0.5; float resistance_TDV = 0; float resistance_TDJ = 0.3; float resistance_TDB = 0.2){
            this->pv = pv;
            this->speed = speed;
            this->money = money;
            this->resistance_TDR = resistance_TDR;
            this->resistance_TDV = resistance_TDV;
            this->resistance_TDJ = resistance_TDJ;
            this->resistance_TDB = resistance_TDB;
        }
}

class Barbara: public Monster{
    public:
        Barbara(uint pv=100; uint speed; uint money = 15; float resistance_TDR = 0.1; float resistance_TDV = 0.5; float resistance_TDJ = 0.3; float resistance_TDB = 0.1){
            this->pv = pv;
            this->speed = speed;
            this->money = money;
            this->resistance_TDR = resistance_TDR;
            this->resistance_TDV = resistance_TDV;
            this->resistance_TDJ = resistance_TDJ;
            this->resistance_TDB = resistance_TDB;
        }
}


class Julien: public Monster{
    public:
        Julien(uint pv=50; uint speed; uint money = 8; float resistance_TDR = 0.1; float resistance_TDV = 0.8; float resistance_TDJ = 0; float resistance_TDB = 0){
            this->pv = pv;
            this->speed = speed;
            this->money = money;
            this->resistance_TDR = resistance_TDR;
            this->resistance_TDV = resistance_TDV;
            this->resistance_TDJ = resistance_TDJ;
            this->resistance_TDB = resistance_TDB;
        }

}
