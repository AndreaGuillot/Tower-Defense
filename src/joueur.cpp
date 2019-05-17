#include "../include/installation.h"
#include "../include/tower.h"
#include "../include/monstre.h"

class Joueur {

    private:
	uint argent;
	
    public:
    //Constructeur
        Joueur(argent=100){
            this->argent = argent;
        }
        //Accesseurs
        uint getArgent(){
            return this->argent;
        }

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