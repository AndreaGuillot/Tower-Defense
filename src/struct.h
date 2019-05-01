#ifndef STRUCT
#define STRUCT

#include <stdio.h>
#include <stdlib.h>

struct joueur{
	int largent;
};

//là pour détruire des monstres
struct towerDefense{
	unsigned int puissance; //dégats effectués par la tour
	unsigned int portee; //en pixels, la distance à laquelle la tour peut tirer
	unsigned int cadence; //en nb de dixieme de seconde l'intervalle entre deux tirs
	unsigned int cout;

	towerDefense(uint puissance, uint portee, uint cadence){
		this->puissance = puissance;
		this->portee = portee;
		this->cadence = cadence;
	}

	uint getPuissance(){
		return this->puissance;
	}

	uint getPortee(){
		return this->portee;
	}

	uint getCadence(){
		return this->cadence;
	}

	uint getCout(){
		return this->cout;
	}
};

struct towerDefenseRouge{ //puissance ++, cadence -
	towerDefense();
};

struct towerDefenseVert{ //cadence ++, portee -, puissance ~
	towerDefense();
};

struct towerDefenseJaune{ //puissance -, portee --, cadence +
	towerDefense();
};

struct towerDefenseBleu{ //portee ++, cadence ++, puissance --
	towerDefense();
};

struct monstres{
	int pv;
	int resistance;
	int vitesse;
};

struct vagueMonstres{
	int nbMonstre = 10;
};

struct installation{
	unsigned int height;
	unsigned int width;
	unsigned int portee;
	unsigned int cout;

	installation(uint portee, uint cout){
		this->portee = portee;
		this->cout = cout;
	}

	uint getPortee(){
		return this->portee;
	}

	uint getPortee(){
		return this->portee;
	}
};

struct radar{
	installation();
	//Augmente de 25% la portée des tours autour
};

struct usineArmement{
	installation();
	//Augmente de 25% la puissance des tours autour
};

struct stockMunition{
	installation();
	//Augmente de 25% la cadence des tours autour
};


#endif