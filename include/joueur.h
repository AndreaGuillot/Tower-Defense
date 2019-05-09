#ifndef JOUEUR_H__
#define JOUEUR_H__

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

    void kill(Monster m){
        this->argent += m.money;
    }

    void buildTower(Tower t){
        int new_argent = this->argent -= t.cost;
        if(new_argent<0){
            //Impossible de construire
        }else{
            this->argent = new_argent;
        }
    }

    void buildInstallation(Installation i){
        int new_argent = this->argent -= i.cost;
        if(new_argent<0){
            //Impossible de construire
        }else{
            this->argent = new_argent;
        }
    }

};

#endif