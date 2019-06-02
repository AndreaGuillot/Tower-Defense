#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "file/FileTower.h"

/************* Initialisation de la liste de tour (file) *************/
/* Alloue de la mémoire pour la liste puis vérifie le fichier à l'aide de la fonction loadInfoTour	*
*  Prend en paramère le chemin vers le fichier. Retourne le pointeur vers la liste.				*/
LFileTower* newFileTower () {


		//Alloue la memoire
		LFileTower* p_lfileTower = malloc(sizeof(LFileTower));
		if(p_lfileTower != NULL) {

			p_lfileTower->length = 0;
			p_lfileTower->p_head = NULL;
			p_lfileTower->p_tail = NULL;

			if(loadInfoTour(p_lfileTower) == 0) {
				fprintf(stderr, "Erreur au moment de la vérification du fichier pour les tours\n");
				return NULL;
			}
			return p_lfileTower;

		}
		else {
			fprintf(stderr, "Erreur au moment de l'allocation mémoire de la liste\n");
			return NULL;
		}

	
	return NULL;	
	
}

/************* Vérification du fichier *************/
/* Vérifie si le fichier est valide : Présence du bon code (@ITD 2) sur la première ligne 		*
*  Présence de chacun de paramètres et de leurs valeurs, vérifie si ces dernières sont correctes	*
*  Prend en paramètre un pointeur vers une la liste et le chemin vers le fichier ITD.			*
*  Retourne 0 en cas d'erreur sinon retourne 1								*/

int loadInfoTour(LFileTower* p_lfileTower) {

	if(p_lfileTower != NULL) {

			int i;
			int power, rate, range, cost;

			for(i = 0; i < 4; i++) {

				switch(i) {

					case 0 : //La tour Rocket : Yoann
						power = 35;
						rate = 5;
						range = 40;
						cost = 120;

						addFileTower(p_lfileTower, power, rate, "Y", range, cost);
									
						break;

					case 1 : //La tour Laser : Clara
						power = 30;
						rate = 10;
						range = 60;
						cost = 80;									
						
						addFileTower(p_lfileTower, power, rate, "C", range, cost);
									
						break;


					case 2 : // La tour multidirectionnelle : Jules
						power = 15;
						rate = 15;
						range = 50;
						cost = 60;	
						
						addFileTower(p_lfileTower, power, rate, "J", range, cost);
									
						break;


					case 3 : //La tour hybride : Océane
						power = 5;
						rate = 20;
						range = 70;
						cost = 50;

						addFileTower(p_lfileTower, power, rate, "O", range, cost);
						

						break;


				}//End switch

			}//End for
					

	}
	else {
		fprintf(stderr,"Erreur avec la liste de fileTower\n");
		return 0;
	}
	
	return 1;
}

/************* Ajouter une tour en fin de liste tour (file) *************/
/* Ajoute une tour à la liste. Alloue la place mémoire pour la tour et attribue les valeurs	*
*  Prend en paramètre la liste de tours, la puissance d'attaque, la vitesse d'attaque, le type 	*
*  le périmétre d'action et le cout. Retourne 0 en cas d'erreur et 1 sinon			*/

int addFileTower(LFileTower* p_lfileTower, int power, int rate, char* type_tower, int range, int cost) {

	// On vérifie si notre liste a été allouée
	if (p_lfileTower != NULL) {
		//Création d'une nouvelle tour
		FileTower* new_fileTower = malloc(sizeof(FileTower)); 
		
		// On vérifie si le malloc n'a pas échoué
		if (new_fileTower !=  NULL) {

			new_fileTower->rate = rate;
			new_fileTower->range = range;
			new_fileTower->type_tower = type_tower;
			new_fileTower->cost = cost;
			new_fileTower->power = power;
	
			//Pointer vers la tour suivant à NULL car on rajoute à la fin de la liste	
			new_fileTower->p_next = NULL; 

			// Cas où notre liste est vide (pointeur vers fin de liste à  NULL)
			if (p_lfileTower->p_tail == NULL) {

				// Pointe la tête de la liste sur la nouvelle tour
				p_lfileTower->p_head = new_fileTower; 

				//Pointe p_prev de la nouvelle tour à NULL
				new_fileTower->p_prev = NULL;
			}
			// Cas où des éléments sont déjà présents dans la  liste
			else {
				// Pointe p_prev de la nouvelle tour sur la dernière tour de la liste
				new_fileTower->p_prev = p_lfileTower->p_tail; 

				// Relie la dernière tour de la liste à la nouvelle tour
				p_lfileTower->p_tail->p_next = new_fileTower;  
			}

			// Pointe la fin de la liste sur la nouvelle tour
			p_lfileTower->p_tail = new_fileTower; 

			// On augmente de 1 la taille de la liste
			p_lfileTower->length++; 
		}
		else {
			fprintf(stderr, "Problème dans la creation de la nouvelle tour\n");
			return 0;
		}

	}
	else {
		fprintf(stderr, "Cette liste de tours n'existe pas\n");
		return 0;
	}

	return 1; 
}

/************* Supprimer une tour selon sa position *************/
/* Supprime une tour selon sa position, vérifie si c'est le premier, le dernier ou une tour dans la liste puis la supprime 	*
*  Prend en paramètre la liste de tours et la tour à supprimer et retourne la liste de tours.					*/

LFileTower* removeFileTower(LFileTower* p_lfileTower, FileTower* p_courant) {

	// On vérifie si notre liste a été allouée
	if (p_lfileTower != NULL) {

		if(p_courant != NULL) {

			//Si c'est la dernière tour de la liste
			if (p_courant->p_next == NULL) {
				
				//Pointe la fin de la liste sur la tour précédente
				p_lfileTower->p_tail = p_courant->p_prev;

				if(p_lfileTower->p_tail != NULL) {
					//Lien de la dernière tour vers la tour suivante est NULL
					p_lfileTower->p_tail->p_next = NULL;
				}
				else
					p_lfileTower->p_head = NULL;
					
			}
		
			//Si c'est la première de la liste
			else if (p_courant->p_prev == NULL) {
				//Pointe la tête de la liste vers la tour suivante
				p_lfileTower->p_head = p_courant->p_next;

				if(p_lfileTower->p_head != NULL) {
					//Le lien vers de la deuxième tour vers la tour précédente est NULL
			 		p_lfileTower->p_head->p_prev = NULL;
				}
				else
					p_lfileTower->p_tail = NULL;
			}

			else {
				//Relie la tour suivante à la tour précédente de la tour que l'on veut supprmer 
				p_courant->p_next->p_prev = p_courant->p_prev;
				//Relie la tour précédente à la tour suivante de la tour que l'on veut supprmer 
				p_courant->p_prev->p_next = p_courant->p_next;

			}
			//Libère espace mémoire : supprime la tour
			free(p_courant);
			//Décrémente de un la taille de la liste
			p_lfileTower->length--;

		}
		else
			fprintf(stderr, "Cette tour n'existe pas");
	}
	else 
		fprintf(stderr, "Cette liste de tours n'existe pas");

	// on retourne notre nouvelle liste
	return p_lfileTower; 
}


/************* Supprimer la liste de fileTower *************/
/* Supprime la liste de missiles. Prend en paramètre un pointeur vers la liste de missiles 	*/

void freeAllFileTower (LFileTower* p_lfileTower) {
	//Si la liste n'est pas vide
	if (p_lfileTower->length != 0) {

		//Tant que la liste n'est pas vide
		while (p_lfileTower->p_head != NULL) {
			p_lfileTower = removeFileTower(p_lfileTower, p_lfileTower->p_head);
		}
		
	}
	free(p_lfileTower);
}
