#ifndef JOUEUR_H__
#define JOUEUR_H__

class Joueur {

    private:
	uint argent;
	
    public:
    //Constructeur
    Joueur(argent=100);
    //Accesseurs
    uint getArgent();
    void kill(Monster m);
    void buildTower(Tower t);
    void buildInstallation(Installation i);
};

#endif