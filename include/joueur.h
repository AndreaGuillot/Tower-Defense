#ifndef JOUEUR_H__
#define JOUEUR_H__

#include "installation.h"
#include "map.h"
#include "shot.h"
#include "tower.h"
#include <string.h>
#include <iostream>

/************* Classes Installation, listFileTower et Map *************/
//Gère les bâtiments
class Installation;
<<<<<<< HEAD
//Gère liste tours
class listFileTower;
//Gère la map
=======
>>>>>>> master
class Map;

/************* Classe Joueur : gère les informations du joueur *************/
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
        //Fonctions :
        /* Monstre tué */
        void updateMonsterKill(Monster* m);
        /* Achat tour */
        bool updateMoneyBuildTower(float cost);
        /* Achat bâtiment */
        bool updateMoneyBuildInstallation(Installation* i);
        /* Dessine interface */
        bool drawInterface (GLuint* spriteButton);
        /* Innitialise interface */
        void initInterface();
};

//Innitialise tous les éléments
void initAll (listMonster monsters, listShot shots, listTower towers, Joueur joueur);
//Libère mémoire
void freeAll (listMonster monsters, listShot shots, listTower towers, Map map, Joueur joueur);

#endif