#include "../include/installation.h"
#include "../include/tower.h"
#include "../include/monstre.h"

class Joueur {

    private:
	uint argent;
	
    public:
    //Constructeur
        Joueur(){
            this->argent = 100;
        }

        //Get
        uint getArgent(){
            return this->argent;
        }

        //Set
        void setArgent(uint argent){
            this->argent = argent;
        }

        //Fonctions
        void updateMoneyKill(Monster m){
            this->argent += m.getReward();
        }

        void updateMoneyBuildTower(Tower t){
            int new_argent -= t.getCost();
            if(new_argent<0){
                //Impossible de construire
            }else{
                this->argent = new_argent;
            }
        }

        void updateMoneyBuildInstallation(Installation i){
            int new_argent -= i.getCost();
            if(new_argent<0){
                //Impossible de construire
            }else{
                this->argent = new_argent;
            }
        }

};