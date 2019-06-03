#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "ihm/Interface.h"
#include "element/Monster.h"

/************* Initialisation de l'interface *************/
/* Alloue de la mémoire pour l'interface et initialise les valeurs.	*
*  Retourne le pointeur vers l'interface.				*/
Joueur* newGame (void) {

	//Alloue la memoire
	Joueur* joueur = malloc(sizeof(Joueur));

	//Vérifie que l'joueur a été alloué
	if(joueur != NULL) {
		joueur->money = 100;
		joueur->lvl = 0;
	}
	else {
		fprintf(stderr, "Erreur lors de l'allocation mémoire de l'interace\n");
		return NULL;
	}
	
	return joueur;
}

/************* Mise à jour de l'argent, du score et du nombre de monstres *************/
/* Met à jours les valeurs de money, score et nbMonster. Prend en paramètre un pointeur		*
*  vers l'interface et un pointeur vers le monstre tué.Retourne le pointeur vers l'interface.	*	
*  Retourne 0 en cas d'erreur et 1 sinon. 							*/

int updateInterface(Joueur* joueur, Monster* monster) {

	//Si l'joueur a été alloué
	if(joueur != NULL) {

		//Si le monstre a été alloué
		if(monster != NULL) {
		
			joueur->money += monster->gain;

		}
		else {
			fprintf(stderr, "Erreur avec le monstre\n");
			return 0;
		}

	}
	else {
		fprintf(stderr, "Erreur avec l'joueur\n");
		return 0;
	}	

	return 1;

}

/************* Mise à jour lors d'un changement de niveau  *************/
/* Met à jour le niveau, le score, l'argents. Prend en paramètre un pointeur 	*
*  vers l'interface. Retourne 0 en cas d'erreur et 1 sinon.			*/

int updateLvl(Joueur* joueur) {
	
	//Si l'joueur a été alloué
	if(joueur != NULL) {
	
		joueur->lvl ++;
		
	}
	else {
		fprintf(stderr, "Erreur avec l'interface\n");
		return 0;
	}
	
	return 1;
}

/************* Mise à jour de l'argent  ***********/
/* Met à jour de l'argent. Prend en paramètre un pointeur vers l'interface	*
*  et le prix d'une tour. Retourne 0 en cas d'erreur et 1 sinon.		*/

int updateMoney(Joueur* joueur, int price) {

	//Si l'joueur a été alloué
	if(joueur != NULL) {
	
		joueur->money -= price;
		
	}
	else {
		fprintf(stderr, "Erreur avec l'joueur\n");
		return 0;
	}
	
	return 1;
}

/************* Réinitialise l'joueur  ***********/
/* Réinitialise l'joueur. Prend en paramètre un pointeur vers l'joueur.  	*/

void initInterface (Joueur* joueur) {
	//Si l'joueur existe
	if (joueur != NULL) {
		joueur->money = 100;
		joueur->lvl = 0;
	}
}

/************* Supprimer l'joueur  ***********/
/* Supprime l'joueur. Prend en paramètre un pointeur vers l'joueur  	*/

void freeInterface (Joueur* joueur) {
	//Si l'joueur existe
	if (joueur != NULL) {
		free(joueur);
	}
}
