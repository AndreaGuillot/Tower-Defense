#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*********************** Clique sur le menuPrincipale  ***********************/
/* action clique menu Principale. Prend en paramètre la position et un pointeur vers nbMenu. Retourne 0 en cas d'erreur et 1 sinon	*/

void clickMenuPrincipal(float x, float y, Menus* nbMenu) {

	//bouton play
	if(x <= 514 && x >= 272 && y <= 352 && y >= 296)
		*nbMenu = play;
	/*bouton aide
	else if(x <= 514 && x >= 272 && y <= 421 && y >= 364)
		*nbMenu = 2;*/
}

/*********************** Clique sur le menu : achat de tour ***********************/
/* Achat d'une tour losqu'on clique sur le menu puis affiche la tour. 	*/

int clickMenuTour(listTower towers, listFileTower fileTower, Joueur joueur, float x, float y) {
	if(towers != NULL && fileTower != NULL && joueur != NULL) {

		towerType type;

		//Vérifie qu'on clique sur le bon bouton : tour hybride
		if(x <= 190 && x >= 10 && y <= 120 && y >= 70)
			type = oceane;

		// Tour rocket
		else if(x <= 190 && x >= 10 && y <= 175 && y >= 125)
			type = jules

		//Si le niveau est suppérieur à 3
		if(interface->lvl >= 3) {
			if(x <= 190 && x >= 10 && y <= 230 && y >= 180)
				type = clara;
		}

		//Si le niveau est suppérieur à 5
		if(interface->lvl >= 5) {
			if(x <= 190 && x >= 10 && y <= 285 && y >= 235)
				type = yoann;
		}


		//Vérifie qu'il y a un type, sinon pas de clique sur l'un des boutons
		if(type != NULL) {

			//Pointeur temporaire pour parcourir la liste
			FileTower* tmp = fileTower.getHead();
	
			//Parcours la liste
			while(tmp != NULL) {
				//Si c'est l'hybride 
				if(type == tmp.getType())
					break;

				tmp = tmp.getNext();
			}

			//S'il le joueur a assez d'argent
			if((joueur.getArgent()) >= tmp.getCost()) {
				//Ajoute une tour
				Position p = mew Position(x, y);
				towers.addTower(tmp.getType(), p);
				//Met a jour l'agent
				joueur.updateMoneyBuildTower(tmp);
				return 1;
			}
		}
		
	}
	else {
		fprintf(stderr, "Erreur : liste de tour, liste de fileTour ou interface non alloué\n");
		return 0;
	}
	return 0;
}

/*********************** Clique sur le menu : fermer ***********************/
/* fermer : retourne 0 si on a cliqué sur le bouton avance rapide sinon retourne 1 	*/
int clickExit(listMonster monsters, listShot shots, listTower towers, listFileTower fileTower, Map* map, Joueur joueur, float x, float y) {
	
	if(x <= 790 && x >= 760 && y <= 45 && y >= 15) {
		freeAll (monsters, shots, towers, fileTower, map, joueur);
		return 0;
	}

	return 1;

}

/*********************** Clique : pour afficher les propriétés d'une tour ***********************/
/* click retour une tour pour afficher ces propriétés. Prend en paramètre la liste de tours,  la 	*
*  position du clique et un pointeur int qui permet de savoir si on affiche ou non des propriétés.	*
*  Retourne NULL s'il y a une erreur, ou si on n'a pas cliquer sur une tour. Sinon retourne la tour.	*/

Tower* clickTower(listTower towers, float x, float y, Propriete* propriete) {
	
	//Vérifie que la liste de tours existe
	if(towers != NULL) {

		//Tour temporaire pour parcourir la liste de tour
		Tower* tmp = towers.getHead();
		
		while(tmp != NULL) {

			//Si on a cliqué sur une tour
			if(x <= (tmp.getPosition().getX() + 20) && x >= (tmp.getPosition().getX() - 20) && y <= (tmp.getPosition().getY() + 20) && y >= (tmp.getPosition().getY() - 20)) {
				*propriete = propTower;
				return tmp;	
			}

			tmp = tmp.getNext();

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

Monster* clickMonster(listMonster monsters, float x, float y, Propriete* propriete) {
	
	//Vérifie que la liste de monstres existe
	if(monsters != NULL) {

		//Tour temporaire pour parcourir la liste de tour
		Monster* tmp = monsters.getHead();
		
		while(tmp != NULL) {

			//Si on a cliqué sur une tour
			if(x <= (tmp.getPosition().getX() + 20) && x >= (tmp.getPosition().getX() - 20) && y <= (tmp.getPosition().getY() + 20) && y >= (tmp.getPosition().getY() - 20)) {
				*propriete = propTower;
				return tmp;	
			}

			tmp = tmp.getNext();

		}
	}
	else {
		fprintf(stderr, "Erreur : cette liste de monstre n'existe pas\n");
		return NULL;
	}

	return NULL;

}
