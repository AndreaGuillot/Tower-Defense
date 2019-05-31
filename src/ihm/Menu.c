#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "element/Monster.h"
#include "element/Tower.h"
#include "element/Shot.h"
#include "ihm/Interface.h"
#include "file/FileTower.h"
#include "ihm/Menu.h"

/*********************** Clique sur le menuPrincipale  ***********************/
/* action clique menu Principale. Prend en paramètre la position et un pointeur vers nbMenu. Retourne 0 en cas d'erreur et 1 sinon	*/

void clickMenuPrincipal(float x, float y, int* nbMenu, int* nbTexture) {

	if(*nbMenu == 1 || *nbMenu == 4 || *nbMenu == 5) {

		//bouton play
		if(x <= 514 && x >= 272 && y <= 352 && y >= 296)
			*nbMenu = 3;
		//bouton aide
		else if(x <= 514 && x >= 272 && y <= 421 && y >= 364)
			*nbMenu = 2;
	}
	else if(*nbMenu == 2) {
	
		//bouton menu
		if(x <= 310 && x >= 68 && y <= 627 && y >= 570)
			*nbMenu = 1;
		//bouton play
		else if(x <= 732 && x >= 490 && y <= 627 && y >= 570)
			*nbMenu = 3;		
		
	}

}

/*********************** Clique sur le menu : achat de tour ***********************/
/* Achat d'une tour losqu'on clique sur le menu puis affiche la tour. 	*/

int clickMenuTour(LTower* p_ltower, LFileTower* p_lfileTower, Joueur* joueur, float x, float y) {

	//Vérifie si les elements ont été alloué
	if(p_ltower != NULL && p_lfileTower != NULL && joueur != NULL) {

		char* type = "None";

		//Vérifie qu'on clique sur le bon bouton : tour hybride
		if(x <= 100 && x >= 10 && y <= 120 && y >= 70)
			type = "H";

		// Tour rocket
		if(x <= 190 && x >= 100 && y <= 120 && y >= 70)
			type = "M";

		if(x <= 100 && x >= 10 && y <= 175 && y >= 125)
				type = "L";
		
		if(x <= 190 && x >= 100 && y <= 175 && y >= 125)
				type = "R";



		//Vérifie qu'il y a un type, sinon pas de clique sur l'un des boutons
		if(strcmp("None", type) != 0) {

			//Pointeur temporaire pour parcourir la liste
			FileTower* tmp = p_lfileTower->p_head;
	
			//Parcours la liste
			while(tmp != NULL) {
				//Si c'est l'hybride 
				if(strcmp(type, tmp->type_tower) == 0)
					break;

				tmp = tmp->p_next;
			}

			//S'il le joueur a assez d'argent
			if((joueur->money) >= tmp->cost) {
				//Ajoute une tour
				addTower(p_ltower, tmp->power, tmp->rate, tmp->type_tower, tmp->range, tmp->cost, x, y);
				//Met a jour l'agent
				updateMoney(joueur, tmp->cost);
				return 1;
			}
		}
		
	}
	else {
		fprintf(stderr, "Erreur : liste de tour, liste de fileTour ou joueur non alloué\n");
		return 0;
	}

	return 0;

}

/*********************** Clique sur le menu : achat d'installation ***********************/
/* Achat d'une installation losqu'on clique sur le menu puis affiche l'installation. 	*/

int clickMenuInstallation(LTower* p_ltower, LFileTower* p_lfileTower, Joueur* joueur, float x, float y) {

	//Vérifie si les elements ont été alloué
	if(p_ltower != NULL && p_lfileTower != NULL && joueur != NULL) {

		char* type = "None";

		//Vérifie qu'on clique sur le bon bouton : tour hybride
		if(x <= 100 && x >= 10 && y <= 230 && y >= 180)
			type = "R";

		// Tour rocket
		if(x <= 190 && x >= 100 && y <= 230 && y >= 180)
			type = "U";

		//Si le niveau est suppérieur à 3

		if(x <= 145 && x >= 55 && y <= 285 && y >= 235)
				type = "S";
		



		//Vérifie qu'il y a un type, sinon pas de clique sur l'un des boutons
		if(strcmp("None", type) != 0) {

			//Pointeur temporaire pour parcourir la liste
			FileTower* tmp = p_lfileTower->p_head;
	
			//Parcours la liste
			while(tmp != NULL) {
				//Si c'est l'hybride 
				if(strcmp(type, tmp->type_tower) == 0)
					break;

				tmp = tmp->p_next;
			}

			//S'il le joueur a assez d'argent
			if((joueur->money) >= tmp->cost) {
				//Ajoute une tour
				addTower(p_ltower, tmp->power, tmp->rate, tmp->type_tower, tmp->range, tmp->cost, x, y);
				//Met a jour l'agent
				updateMoney(joueur, tmp->cost);
				return 1;
			}
		}
		
	}
	else {
		fprintf(stderr, "Erreur : liste de tour, liste de fileTour ou joueur non alloué\n");
		return 0;
	}

	return 0;

}

/*********************** Clique sur le menu : supprimer tour ***********************/
/* supprimer tour lorsqu'on clique sur le bouton supprimer. Prend en paramètre un pointeur vers la liste de tour, un pointeur	*
*  vers la liste de shot, la tour courant, la position et un pointeur vers propriete. Retourne 0 en cas d'erreur sinon 1. 	*/

int clickTourDelete(LTower* p_ltower, LShot* p_lshot, Tower* p_courant, Joueur* joueur, float x, float y, int* propriete) {

	if(p_ltower != NULL) {

		if(p_courant != NULL) {

			if(*propriete == 1) {

				if(x <= 190 && x >= 10 && y <= 540 && y >= 490) {

					Shot* p_tmp = p_lshot->p_head;
					while(p_tmp != NULL) {

						if(p_tmp->tower == p_courant)
							p_tmp->tower = NULL;

						p_tmp = p_tmp->p_next;

					}
					joueur->money += p_courant->cost;
					p_ltower = removeTower(p_ltower, p_courant);
					*propriete = 0;
				}
			}

		}
		else {
			fprintf(stderr, "Erreur la tour courante\n");
			return 0;
		}

	}
	else {
		fprintf(stderr, "Erreur avec la liste de tours\n");
		return 0;
	}

	return 1;

}

/*********************** Clique sur le menu : monter de lvl une tour ***********************/
/* monter de lvl une tour lorsqu'on clique sur le bouton upgrate. Prend en paramètre 			*
*  la tour courant, la position et un pointeur vers propriete. Retourne 0 en cas d'erreur sinon 1. 	*/

int clickTourUpgrate(Tower* p_courant, Joueur* joueur, float x, float y, int* propriete) {

	if(joueur != NULL) {

		if(p_courant != NULL) {

			if(*propriete == 1) {

				//Monter de niveau la tour
				if(x <= 190 && x >= 10 && y <= 595 && y >= 545)
					upgrateTower(p_courant, joueur);
				//Monter la cadence de la tour
				else if(x <= 190 && x >= 165 && y <= 395 && y >= 372)
					upgradeRateT(p_courant, joueur);
				//Monter le périmètre d'action de la tour
				else if(x <= 190 && x >= 165 && y <= 420 && y >= 397)
					upgradeRangeT(p_courant, joueur);
				//Monter la puissance de la tour
				else if(x <= 190 && x >= 165 && y <= 445 && y >= 422)
					upgradePowerT(p_courant, joueur);					

				*propriete = 1;
			}

		}
		else {
			fprintf(stderr, "Erreur la tour courante\n");
			return 0;
		}

	}
	else {
		fprintf(stderr, "Erreur avec l'joueur\n");
		return 0;
	}

	return 1;

}

/*********************** Clique sur le menu : pause/play/avanceRapide ***********************/
/* Pause : retourne 2 si on a cliqué sur le bouton avance rapide, 0 sur play ou 1 sur pause sinon retourne 0 	*/
int clickTime(float x, float y, int play, int* nbMonster, int* j) {
	
	if(*nbMonster > 10) {

		//Si clique sur play
		if(play == 0) {
			//Si clique sur pause	
			if(x <= 720 && x >= 690 && y <= 45 && y >= 15)
				return 1;
		}
		else {
			if(x <= 720 && x >= 690 && y <= 45 && y >= 15) {
				*nbMonster = 0;
				*j = 0;
				return 0;
			}
		}

	}
	else {

		//si c'est play
		if(play == 0) {
			//Si clique sur pause	
			if(x <= 720 && x >= 690 && y <= 45 && y >= 15)
				return 1;
			//Si clique sur avance rapide
			else if(x <= 685 && x >= 655 && y <= 45 && y >= 15)
				return 2;

		}
		//si c'est en pause
		else if(play == 1) {

			//Si clique sur play
			if(x <= 720 && x >= 690 && y <= 45 && y >= 15) 
				return 0;
			//Si clique sur avance rapide
			else if(x <= 685 && x >= 655 && y <= 45 && y >= 15)
				return 2;
			else
				return 1;
		}
		//sinon avance rapide
		else {
			//Si clique sur play
			if(x <= 720 && x >= 690 && y <= 45 && y >= 15) 
				return 0;
			else
				return 2;
		}
	}

	return 0;
}

/*********************** Clique sur le menu : fermer ***********************/
/* fermer : retourne 0 si on a cliqué sur le bouton avance rapide sinon retourne 1 	*/
int clickExit(ListMonsters* p_lmonster, LShot* p_lshot, LTower* p_ltower, LFileTower* p_lfileTower, Map* map, Joueur* joueur, float x, float y, int aide) {
	
	if(aide == 0) {
		if(x <= 790 && x >= 760 && y <= 45 && y >= 15) {
			freeAll (p_lmonster, p_lshot, p_ltower, p_lfileTower, map, joueur);
			return 0;
		}
	}

	return 1;

}

/*********************** Clique sur le menu : aide ***********************/
/* aide : retourne 1 si on a cliqué sur le bouton avance rapide sinon retourne 0 	*/
int clickAide(float x, float y, int aide) {
	
	if(aide == 0) {
		if(x <= 755 && x >= 725 && y <= 45 && y >= 15)
			return 1;
	}
	else {
		if(x <= 790 && x >= 760 && y <= 45 && y >= 15)
			return 0;
	}

	return 0;

}

/*********************** Clique : pour afficher les propriétés d'une tour ***********************/
/* click retour une tour pour afficher ces propriétés. Prend en paramètre la liste de tours,  la 	*
*  position du clique et un pointeur int qui permet de savoir si on affiche ou non des propriétés.	*
*  Retourne NULL s'il y a une erreur, ou si on n'a pas cliquer sur une tour. Sinon retourne la tour.	*/

Tower* clickTower(LTower* p_ltower, float x, float y, int* propriete) {
	
	//Vérifie que la liste de tours existe
	if(p_ltower != NULL) {

		//Tour temporaire pour parcourir la liste de tour
		Tower* p_tmp = p_ltower->p_head;
		
		while(p_tmp != NULL) {

			//Si on a cliqué sur une tour
			if(x <= (p_tmp->x + 20) && x >= (p_tmp->x - 20) && y <= (p_tmp->y + 20) && y >= (p_tmp->y - 20)) {
				*propriete = 1;
				return p_tmp;	
			}

			p_tmp = p_tmp->p_next;

		}
	}
	else {
		fprintf(stderr, "Erreur : cette liste de tour n'existe pas\n");
		return NULL;
	}

	return NULL;

}

/*********************** Clique : pour afficher les propriétés d'un monstre ***********************/
/* click retour un monstre pour afficher ces propriétés. Prend en paramètre la liste de monstres,  la 	*
*  position du clique et un pointeur int qui permet de savoir si on affiche ou non des propriétés.	*
*  Retourne NULL s'il y a une erreur, ou si on n'a pas cliquer sur une tour. Sinon retourne la tour.	*/

Monster* clickMonster(ListMonsters* p_lmonster, float x, float y, int* propriete) {
	
	//Vérifie que la liste de monstres existe
	if(p_lmonster != NULL) {

		//Tour temporaire pour parcourir la liste de tour
		Monster* p_tmp = p_lmonster->p_head;
		
		while(p_tmp != NULL) {

			//Si on a cliqué sur une tour
			if(x <= (p_tmp->x + 20) && x >= (p_tmp->x - 20) && y <= (p_tmp->y + 20) && y >= (p_tmp->y - 20)) {
				*propriete = 2;
				return p_tmp;	
			}

			p_tmp = p_tmp->p_next;

		}
	}
	else {
		fprintf(stderr, "Erreur : cette liste de monstre n'existe pas\n");
		return NULL;
	}

	return NULL;

}

/*********************** Click tuto ***********************/
/* Click tutorial. Prend en paramètre un pointeur sur une tour, la position du click, et 3 int (tuto, testMouse et testTower.	*
*  Retourne un valeur pour le tutoriel (avancement dans le tutoriel) et 0 si c'est fini.					*/
int clickTuto(Tower* p_courant, float x, float y, int tuto, int testMouse, int testTower, int* tutoend) {

	if(tuto != 6) {
		//Passer le tutoriel
		if(x <= 780 && x >= 680 && y <= 141 && y >= 80) {
			*tutoend = 1;
			return 0;
		}
	}

	if(tuto == 1) {
			return 2;
	}
	else if(tuto == 2) {
		if(testMouse == 1) 
			return 3;
		else
			return 2;
	}
	else if(tuto == 3) {
		if(testTower == 1)
			return 4;
		else
			return 3;
	}
	else if(tuto == 4) {
		if(p_courant == NULL)
			return 5;
		else
			return 4;
	}
	else if(tuto == 5){
		if(p_courant == NULL)
			return 6;
		else
			return 5;
	}
	else if(tuto == 6) {
		*tutoend = 1;
		return 0;
	}

	return 0;

}

/*********************** Mouvement de la souris ***********************/
/* Au mouvement de la souris regarde si se trouve sur l'un des boutons upgrade, si oui retourne un chiffre.	*/
int mouseInfo(float x, float y, int testMouse, int propriete) {

	if(propriete == 1) {
	
		if(testMouse == 0) {
			//Améliorer power
			if(x <= 190 && x >= 165 && y <= 445 && y >= 422)
				return 1;
			//Améliorer range
			else if(x <= 190 && x >= 165 && y <= 420 && y >= 397) 
				return 2;
			//Améliorer cadence
			else if(x <= 190 && x >= 165 && y <= 395 && y >= 372)
				return 3;
			//Tout améliorer
			else if(x <= 190 && x >= 10 && y <= 595 && y >= 545)
				return 4;
		
		}
	}

	return 0;

}

/*********************** Réinitialise l'joueur ***********************/
/* Supprime tous. Prend en paramètre 	*/

void initAll (ListMonsters* p_lmonster, LShot* p_lshot, LTower* p_ltower, Joueur* joueur) {

	//Retire les missiles de la liste
	removeAllShot(p_lshot);
	//Retire les monstres de la liste
	removeAllMonsters(p_lmonster);
	//Retire les tours de la liste
	removeAllTower(p_ltower);
	//Réinitialise l'joueur
	initInterface(joueur);
}

/*********************** Supprime tous ***********************/
/* Supprime tous. Prend en paramètre 	*/

void freeAll (ListMonsters* p_lmonster, LShot* p_lshot, LTower* p_ltower, LFileTower* p_lfileTower, Map* map, Joueur* joueur) {

	//Liblère la liste de missiles
	freeAllShot (p_lshot);
	//Libère la liste de monstres
	freeAllMonsters (p_lmonster);
	//Libère la liste de tours
	freeAllTower (p_ltower);
	//Libère la liste de fileTower
	freeAllFileTower(p_lfileTower);
	//Libère la map
	freeMap(map);
	//Libère l'joueur
	freeInterface(joueur);
}
