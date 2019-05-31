#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "element/Installation.h"
#include "element/Monster.h"
#include "geometry/Intersection.h"
#include "ihm/Interface.h"

/************* Création d'une nouvelle liste de tours *************/
/* Initialisation de la liste de tours et allocation de mémoire pour la liste de tours		*
*  Retourne la liste de tours									*/

LInstallation* new_LInstallation(void) {
	
	//Alloue de la mémoire 
	LInstallation *p_linstallation = malloc(sizeof(LInstallation));
	if (p_linstallation != NULL) {
		p_linstallation->length = 0;
		p_linstallation->p_head = NULL;
		p_linstallation->p_tail = NULL;
	}
	else {
		fprintf(stderr, "Erreur lors de l'allocation memoire de la liste de tours\n");
		return NULL;
	}
	return p_linstallation;
}

/************* Ajouter une tour en fin de liste *************/
/* Ajoute une tour à la liste. Alloue la place mémoire pour la tour et attribue les valeurs	*
*  Prend en paramètre la liste de tours, la puissance d'attaque, la vitesse d'attaque, le type 	*
*  le périmétre d'action, le cout et la position. Retourne 0 en cas d'erreur et 1 sinon		*/

int addInstallation(LInstallation* p_linstallation, int power, int rate, char* type_installation, int range, int cost, float x, float y) {

	// On vérifie si notre liste a été allouée
	if (p_linstallation != NULL) {
		//Création d'une nouvelle tour
		Installation* new_installation = malloc(sizeof(Installation)); 
		
		// On vérifie si le malloc n'a pas échoué
		if (new_installation !=  NULL) {

			new_installation->rate = rate;
			new_installation->compteur = 0;
			new_installation->range = range;
			new_installation->type_installation = type_installation;
			new_installation->cost = cost;
			new_installation->power = power;
			new_installation->lvl = 1;
			new_installation->x = x;
			new_installation->y = y;
	
			//Pointer vers la tour suivant à NULL car on rajoute à la fin de la liste	
			new_installation->p_next = NULL; 

			// Cas où notre liste est vide (pointeur vers fin de liste à  NULL)
			if (p_linstallation->p_tail == NULL) {

				// Pointe la tête de la liste sur la nouvelle tour
				p_linstallation->p_head = new_installation; 

				//Pointe p_prev de la nouvelle tour à NULL
				new_installation->p_prev = NULL;
			}
			// Cas où des éléments sont déjà présents dans la  liste
			else {
				// Pointe p_prev de la nouvelle tour sur la dernière tour de la liste
				new_installation->p_prev = p_linstallation->p_tail; 

				// Relie la dernière tour de la liste à la nouvelle tour
				p_linstallation->p_tail->p_next = new_installation;  
			}

			// Pointe la fin de la liste sur la nouvelle tour
			p_linstallation->p_tail = new_installation; 

			// On augmente de 1 la taille de la liste
			p_linstallation->length++; 
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

/****************** Vérifier si la tour est sur un zone constructible ***********************/
/* Vérifie si la tour est sur une zone constructible : Vérifie si les coordonnées de chaque 	*
*  extremité fait partie de la liste de point. Prend en paramètre la liste de pixel et les deux	*
*  extremités (deux points). Retourne 1 si c'est valide, sinon 0.		*/

int verificationConstructInstallation(LNode* l_node, Point2D point1, Point2D point2) {

	if(l_node != NULL) {

		int i, test = 0;
		Point2D point;

		for(i = 0; i < 4; i++) {

			//Vérifie avec les quatres points du quad
			switch(i) {
				case 0 : 
					point.x = point1.x; point.y = point1.y;
					break;
				case 1 : 
					point.x = point1.x; point.y = point2.y;
					break;
				case 2 :
					point.x = point2.x; point.y = point2.y;
					break;
				case 3 :
					point.x = point2.x; point.y = point1.y;
					break;
			}

			//Créer un pointeur temporaire node pour parcourir la liste de noeud
			Node* p_tmp = l_node->p_head;

			while(p_tmp != NULL){

				if(point.x == p_tmp->x && point.y == p_tmp->y)
					test++;

				p_tmp = p_tmp->p_next;
			}

		}

		//Si les 4 extremité sont dans la zone constructible
		if(test < 4)
			return 0;

	}
	else {
		fprintf(stderr, "Il y a un probleme avec la liste de points constructible\n");
		return 0;
	}

	return 1;

}

/****************** Faire bouger la tour ***********************/
/* Fait bouger la tour en fonction des positions passé en paramètre. Passe en paramètre la liste de tours, 	*
*  la tour que l'on souhaite bouger, la nouvelle position : x et y. Retourne 0 en cas d'erreur et & sinon	*/
int moveInstallation(LInstallation* p_linstallation, Installation* p_courant, LNode* l_node, float x, float y) {

	if(p_linstallation != NULL) {

		if(p_courant != NULL) {

			p_courant->x = x;
			p_courant->y = y;
		
			Point2D point1, point2;
			point1.x = x + 15; point1.y = y + 15;
			point2.x = x - 15; point2.y = y - 15;

			if(verificationConstruct(l_node, point1, point2) == 1) {

				point1.x = x + 20; point1.y = y + 20;
				point2.x = x - 20; point2.y = y - 20;

				//Si ce n'est pas le premier de la liste
				if(p_courant->p_prev != NULL){

					Point2D point3, point4;
					//Créer un pointeur tour temporaire pour parcourir la liste
					Installation* p_tmp = p_linstallation->p_head;

					//Parcour de la liste
					while(p_tmp->p_next != NULL) {

						point3.x = (p_tmp->x) + 20; point3.y = (p_tmp->y) + 20;
						point4.x = (p_tmp->x) - 20; point4.y = (p_tmp->y) - 20;

						//Vérifie qu'il ne se trouve pas sur une autre tour (pas d'intersection)
						if(intersectionCarres (point1, point2, point3, point4) == 0)
							p_tmp = p_tmp->p_next;
						else
							return 0;
					}
					return 1;
				}
				//Sinon pas besoin de faire la vérification pour les collisions de quads
				else
					return 1;		
			}
		}
		else {
			fprintf(stderr, "Cette tour n'existe pas\n");
			return 0;
		}
	}
	else {
		fprintf(stderr, "Erreur : il y a un problème avec la liste de tours\n");
		return 0;
	}

	return 0;

}

/************* Supprimer une tour selon sa position *************/
/* Supprime une tour selon sa position, vérifie si c'est le premier, le dernier ou une tour dans la liste puis la supprime 	*
*  Prend en paramètre la liste de tours et la tour à supprimer et retourne la liste de tours.					*/

LInstallation* removeInstallation(LInstallation* p_linstallation, Installation* p_courant) {

	// On vérifie si notre liste a été allouée
	if (p_linstallation != NULL) {

		if(p_courant != NULL) {

			//Si c'est la dernière tour de la liste
			if (p_courant->p_next == NULL) {
				
				//Pointe la fin de la liste sur la tour précédente
				p_linstallation->p_tail = p_courant->p_prev;

				if(p_linstallation->p_tail != NULL) {
					//Lien de la dernière tour vers la tour suivante est NULL
					p_linstallation->p_tail->p_next = NULL;
				}
				else
					p_linstallation->p_head = NULL;
					
			}
		
			//Si c'est la première de la liste
			else if (p_courant->p_prev == NULL) {
				//Pointe la tête de la liste vers la tour suivante
				p_linstallation->p_head = p_courant->p_next;

				if(p_linstallation->p_head != NULL) {
					//Le lien vers de la deuxième tour vers la tour précédente est NULL
			 		p_linstallation->p_head->p_prev = NULL;
				}
				else
					p_linstallation->p_tail = NULL;
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
			p_linstallation->length--;

		}
		else
			fprintf(stderr, "Cette tour n'existe pas");
	}
	else 
		fprintf(stderr, "Cette liste de tours n'existe pas");

	// on retourne notre nouvelle liste
	return p_linstallation; 
}

/************* Supprimer toutes les tours de la liste  *************/
/* Supprime la liste de tours. Prend en paramètre un pointeur vers la liste de tours 	*/

void removeAllInstallation (LInstallation* p_linstallation) {
	//Si la liste n'est pas vide
	if (p_linstallation->length != 0) {

		//Tant que la liste n'est pas vide
		while (p_linstallation->p_head != NULL) {
			p_linstallation = removeInstallation(p_linstallation, p_linstallation->p_head);
		}
		
	}
}

/************* Supprimer la liste de tours *************/
/* Supprime la liste de tours. Prend en paramètre un pointeur vers la liste de tours 	*/

void freeAllInstallation (LInstallation* p_linstallation) {
	//Si la liste n'est pas vide
	if (p_linstallation->length != 0) {

		//Tant que la liste n'est pas vide
		while (p_linstallation->p_head != NULL) {
			p_linstallation = removeInstallation(p_linstallation, p_linstallation->p_head);
		}
		
	}
	free(p_linstallation);
}
