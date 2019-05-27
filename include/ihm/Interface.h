#ifndef ITD_INTERFACE_H_
#define ITD_INTERFACE_H_

#include "element/Monster.h"

/************* STRUCTURE DE L'INTERFACE *************/
typedef struct struct_interface {
	
	//argent
	int money;

	//niveau
	int lvl;

}Joueur;

/************* Prtotypes des fonctions *************/
//Initialisation de l'interface
Joueur* newGame (void);
//Mise à jour de l'agent, score et nb de monstre
int updateInterface(Joueur*, Monster*);
//Mise à jour lors d'un changement de niveau
int updateLvl(Joueur*);
//Mise à jour de l'argent
int updateMoney(Joueur*, int);
//Mise à jour du nombre de vie
int udapteLife(Joueur*);
//Réinitialise l'interface
void initInterface (Joueur*);
//Supprime l'interface
void freeInterface (Joueur*);

#endif
