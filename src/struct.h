#ifndef STRUCT
#define STRUCT

#include <stdio.h>
#include <stdlib.h>

typedef struct joueur{
	int largent;
}joueur;

//là pour détruire des monstres
typedef struct towerDefense{
    unsigned int energie;
	unsigned int puissance; //dégats effectués par la tour
	unsigned int portee; //en pixels, la distance à laquelle la tour peut tirer
	unsigned int cadence; //en nb de dixieme de seconde l'intervalle entre deux tirs
	unsigned int cout;
}towerDefense;

typedef struct towerDefenseRouge{ //puissance ++, cadence -
	towerDefense();
}towerDefenseRouge;

typedef struct towerDefenseVert{ //cadence ++, portee -, puissance ~
	towerDefense();
}towerDefenseVert;

typedef struct towerDefenseJaune{ //puissance -, portee --, cadence +
	towerDefense();
}towerDefenseJaune;

typedef struct towerDefenseBleu{ //portee ++, cadence ++, puissance --
	towerDefense();
}towerDefenseBleu;

/*Pour définir les types de tours, on va mettre dans le fichier .cpp :

towerDefenseRouge::towerDefenseRouge()
:   towerDefense { energie, puissance, portee, cadence}
{
}

Regarder dans les TP de Steeve si c'est mieux de prendre class ou struct
*/

typedef struct monstres{
	int pv;
	int resistance;
	int vitesse;
}monstres;

typedef struct vagueMonstres{
	int nbMonstre = 10;
}vagueMonstres;

typedef struct installation{
	unsigned int height;
	unsigned int width;
	unsigned int portee;
	unsigned int cout;
}installation;

typedef struct radar{
	installation();
	//Augmente de 25% la portée des tours autour
}radar;

typedef struct usineArmement{
	installation();
	//Augmente de 25% la puissance des tours autour
}usineArmement;

typedef struct stockMunition{
	installation();
	//Augmente de 25% la cadence des tours autour
}stockMunition;


typedef struct cartes{

}cartes;

#endif