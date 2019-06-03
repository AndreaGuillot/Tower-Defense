#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

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

int addInstallation(LInstallation* p_linstallation, char* type_installation, int range, int cost, float x, float y) {

	// On vérifie si notre liste a été allouée
	if (p_linstallation != NULL) {
		//Création d'une nouvelle tour
		Installation* new_installation = malloc(sizeof(Installation)); 
		
		// On vérifie si le malloc n'a pas échoué
		if (new_installation !=  NULL) {

			new_installation->range = range;
			new_installation->type_installation = type_installation;
			new_installation->cost = cost;
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
int moveTower(LTower* p_ltower, LInstallation* p_linstallation, Tower* p_courant, LNode* l_node, float x, float y) {

	if(p_ltower != NULL && p_linstallation!=NULL) {

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
					Point2D point5, point6;
					//Créer un pointeur tour temporaire pour parcourir la liste
					Tower* t_tmp = p_ltower->p_head;
					Installation* i_tmp = p_linstallation->p_head;

					//Intersection tour
					while(t_tmp->p_next != NULL) {

						point3.x = (t_tmp->x); point3.y = (t_tmp->y);

						//Vérifie qu'il ne se trouve pas sur une autre tour (pas d'intersection)
						if(intersectionCarreDisque (point1, point2, 20, point3) == 0)
							t_tmp = t_tmp->p_next;
						else
							return 0;
					}

					if(i_tmp != NULL){
					//Intersection installation
						while(i_tmp->p_next != NULL){
							point5.x = (i_tmp->x) + 20; point5.y = (i_tmp->y) + 20;
							point6.x = (i_tmp->x) - 20; point6.y = (i_tmp->y) - 20;

							if(intersectionCarres (point1, point2, point5, point6) == 0)
								i_tmp = i_tmp->p_next;
							else
								return 0;
						}
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

/****************** Faire bouger la tour ***********************/
/* Fait bouger la tour en fonction des positions passé en paramètre. Passe en paramètre la liste de tours, 	*
*  la tour que l'on souhaite bouger, la nouvelle position : x et y. Retourne 0 en cas d'erreur et & sinon	*/
int moveInstallation(LInstallation* p_linstallation, LTower* p_ltower, Installation* p_courant, LNode* l_node, float x, float y) {

	if(p_linstallation != NULL && p_ltower != NULL) {

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
					Point2D point5, point6;
					//Créer un pointeur tour temporaire pour parcourir la liste
					Installation* i_tmp = p_linstallation->p_head;
					Tower* t_tmp = p_ltower->p_head;

					//Parcour de la liste
					while(i_tmp->p_next != NULL) {

						point3.x = (i_tmp->x) + 20; point3.y = (i_tmp->y) + 20;
						point4.x = (i_tmp->x) - 20; point4.y = (i_tmp->y) - 20;

						//Vérifie qu'il ne se trouve pas sur une autre tour (pas d'intersection)
						if(intersectionCarres (point1, point2, point3, point4) == 0)
							i_tmp = i_tmp->p_next;
						else
							return 0;
					}

					//Si on a déjà construit des tours
					if(t_tmp != NULL){
						while(t_tmp->p_next != NULL) {

							point5.x = (t_tmp->x) + 20; point5.y = (t_tmp->y) + 20;
							point6.x = (t_tmp->x) - 20; point6.y = (t_tmp->y) - 20;

							//Vérifie qu'il ne se trouve pas sur une autre tour (pas d'intersection)
							if(intersectionCarres (point1, point2, point5, point6) == 0){
								t_tmp = t_tmp->p_next;
							}
							else
								return 0;
						}
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

LInstallation* removeInstallation(LInstallation* p_linstallation, Installation* p_courant, LTower* list_towers) {

	// On vérifie si notre liste a été allouée
	if (p_linstallation != NULL) {

		if(list_towers !=NULL)
			wontreach (p_linstallation, list_towers, p_courant);

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
			p_linstallation = removeInstallation(p_linstallation, p_linstallation->p_head, NULL);
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
			p_linstallation = removeInstallation(p_linstallation, p_linstallation->p_head, NULL);
		}
		
	}
	free(p_linstallation);
}


int reach (LInstallation* list_installation, LTower* list_towers, Installation* installation) {

	if(list_installation != NULL) {

		if(list_towers != NULL){

			if(installation != NULL) {
				
					//Création d'un monstre temporaire pour parcourir la liste de monstres
					Tower *tmp = list_towers->p_head;

					//Parcours la liste de monstres
					while(tmp != NULL){

						Point2D point, point1, point2;
						point.x = installation->x; point.y = installation->y; //centre

						point1.x = tmp->x + 20; point1.y = tmp->y + 20;
						point2.x = tmp->x - 20; point2.y = tmp->y - 20;

						//Vérifie s'il y a une intersection
						if(intersectionCarreDisque (point1, point2, installation->range, point) == 1)
							affects(tmp, installation); //Ajout d'un shot à la liste

						tmp = tmp->p_next;

					}	
					return 1;
			}
			else {
				fprintf(stderr, "Cette tour n'existe pas\n");
				return 0;
			}

		}
		else {
			fprintf(stderr, "Cette liste de monstre n'existe pas\n");
			return 0;
		}
	}
	else {
		fprintf(stderr, "Cette liste de missiles n'existe pas\n");
		return 0;
	}

	return 0;

}

int affects(Tower* tmp, Installation* installation){
	if(tmp != NULL && installation != NULL){

		int i; 

		if(strcmp(installation->type_installation, "U") == 0){
			i=0;
		}
		if(strcmp(installation->type_installation, "R") == 0){
			i=1;
		}
		if(strcmp(installation->type_installation, "S") == 0){
			i=2;
		}

		switch(i){
			case 0: if(!tmp->affectedByUsine){
						tmp->power = round(tmp->power*1.25);
						tmp->affectedByUsine = 1;
					}
				break;
			case 1: if(!tmp->affectedByRadar){
						tmp->range = round(tmp->range*1.25);
						tmp->affectedByRadar = 1;
					}
				break;
			case 2: if(!tmp->affectedByStock){
						tmp->rate = round(tmp->rate*1.25);
						tmp->affectedByStock = 1;
					}
				break;
		}
		return 1;
	}else{
		printf("Parametre nul\n");
		return 0;
	}
}

int wontreach (LInstallation* list_installation, LTower* list_towers, Installation* installation) {

	if(list_installation != NULL) {

		if(list_towers != NULL){

			if(installation != NULL) {
				
					//Création d'un monstre temporaire pour parcourir la liste de monstres
					Tower *tmp = list_towers->p_head;

					//Parcours la liste de monstres
					while(tmp != NULL){

						Point2D point, point1, point2;
						point.x = installation->x; point.y = installation->y; //centre

						point1.x = tmp->x + 20; point1.y = tmp->y + 20;
						point2.x = tmp->x - 20; point2.y = tmp->y - 20;

						//Vérifie s'il y a une intersection
						if(intersectionCarreDisque (point1, point2, installation->range, point) == 1)
							notaffect(tmp, installation); //Ajout d'un shot à la liste

						tmp = tmp->p_next;

					}	
					return 1;
			}
			else {
				fprintf(stderr, "Cette tour n'existe pas\n");
				return 0;
			}

		}
		else {
			fprintf(stderr, "Cette liste de monstre n'existe pas\n");
			return 0;
		}
	}
	else {
		fprintf(stderr, "Cette liste de missiles n'existe pas\n");
		return 0;
	}

	return 0;

}

int notaffect(Tower* tmp, Installation* installation){

	if(tmp != NULL && installation !=NULL){
		int i; 

		if(strcmp(installation->type_installation, "U") == 0){
			i=0;
		}
		if(strcmp(installation->type_installation, "R") == 0){
			i=1;
		}
		if(strcmp(installation->type_installation, "S") == 0){
			i=2;
		}

		switch(i){
			case 0: if(tmp->affectedByUsine == 1){
						tmp->power = round(tmp->power/1.25);
						tmp->affectedByUsine = 0;
					}
				break;
			case 1: if(tmp->affectedByRadar == 1){
						tmp->range = round(tmp->range/1.25);
						tmp->affectedByRadar = 0;
					}
				break;
			case 2: if(tmp->affectedByStock == 1){
						tmp->rate = round(tmp->rate/1.25);
						tmp->affectedByStock = 0;
					}
				break;
		}
		return 1;
	}else{
		printf("Parametre nul\n");
		return 0;
	}
}