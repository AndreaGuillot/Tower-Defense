#ifndef JOUEUR_H__
#define JOUEUR_H__

class Joueur {

    private:
	uint argent;
	
    public:
    //Constructeur
    //Accesseurs
    uint getArgent(Joueur j){
        return j->argent;
    }

};

#endif