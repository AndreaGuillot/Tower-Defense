#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "element/Monster.h"
#include "ihm/Node.h"

/************* Création d'une nouvelle liste de monstres *************/
/* Initialisation de la liste de monstres et allocation de mémoire pour la liste de monstres	*
*  Retourne le pointeur sur la liste de monstres						*/

ListMonsters* new_ListMonsters(void) {
	
	//Alloue de la mémoire 
	ListMonsters *p_lmonster = malloc(sizeof(ListMonsters));
	if (p_lmonster != NULL) {
		p_lmonster->length = 0;
		p_lmonster->p_head = NULL;
		p_lmonster->p_tail = NULL;
	}
	else {
		fprintf(stderr, "Erreur lors de l'allocation memoire de la liste de monstres\n");
		return NULL;
	}

	return p_lmonster;
}

/************* Ajouter un monstre en fin de liste *************/
/* Ajoute un monstre à la liste. Alloue la place mémoire pour le monstre et attribue les valeurs	*
*  Prend en paramètre la liste de monstres, le type de monstre, les points de vie, la résistance	*
*  un type de tour et la vitesse de déplacement, les points gagnés et le gain d'argent si le monstre	*
*  est tué. Retourne 0 en cas d'erreur et 1 sinon.							*/

int addMonster(ListMonsters* list_monster, char* type, int pvMax, int resistanceY, int resistanceC, int resistanceJ, int resistanceO, char* type_tower, int pace, int points, int gain, Node* p_head) {

	// On vérifie si notre liste a été allouée
	if (list_monster != NULL) {

		//Création d'un nouveau monstre
		Monster* new_monster = malloc(sizeof(Monster)); 
		
		// On vérifie si le malloc n'a pas échoué
		if (new_monster != NULL) {

			//Initialisation des valeurs du monstre
			new_monster->type = type; //type
			new_monster->pvMax = pvMax; //Points de vie maximum
			new_monster->pv = pvMax; //Points de vie
			new_monster->resistanceY = resistanceY; //La résistance
			new_monster->resistanceC = resistanceC; //La résistance
			new_monster->resistanceJ = resistanceJ; //La résistance
			new_monster->resistanceO = resistanceO; //La résistance
			new_monster->type_tower = type_tower; //Le type de tour dont elle est résistante
			new_monster->pace = pace; //La vitesse de déplacement
			new_monster->points = points; //Nombre de points gagner pour le score
			new_monster->gain = gain; //argent gagne
			new_monster->x = p_head->x; //position x
			new_monster->y = p_head->y; //position y
			new_monster->node_prev = p_head; //Pointeur vers le premier noeud
			new_monster->node_next = p_head->p_next; //Pointeur vers le second noeud

			//Vérifie le déplacement pour savoir dans quelle sens il se déplace et pour donner l'erreur
			calculErreur(new_monster);
	
			//Pointer vers le monstre suivant à NULL car on rajoute à la fin de la liste	
			new_monster->p_next = NULL; 

			// Cas où notre liste est vide (pointeur vers fin de liste à  NULL)
			if (list_monster->p_tail == NULL) {

				// Pointe la tête de la liste sur le nouveau monstre
				list_monster->p_head = new_monster; 

				//Pointe p_prev du nouveau monstre à NULL
				new_monster->p_prev = NULL;
			}
			// Cas où des éléments sont déjà présents dans la  liste
			else {
				// Pointe p_prev du nouveau monstre sur le dernier monstre de la liste
				new_monster->p_prev = list_monster->p_tail; 

				// Relie le dernier monstre de la liste au nouveau monstre
				list_monster->p_tail->p_next = new_monster;  
			}
			
			// Pointe la fin de la liste sur le nouveau monstre
			list_monster->p_tail = new_monster; 

			// On augmente de 1 la taille de la liste
			list_monster->length++; 
		}
		else {
			fprintf(stderr, "Problème dans la creation du nouveau monstre\n");
			return 0;
		}

	}
	else {
		fprintf(stderr, "Cette liste de monstres n'existe pas\n");
		return 0;
	}

	return 1; 
}

/************* Deplacer les monstres *************/
/* Deplace les monstre : Vérifie s'il se déplace à l'horizontal, vertical ou autrement puis le déplace. Prend en paramètre la liste de	*
*  monstres et et le dernier noeud de la carte.	Retourne 0 en cas d'erreur et 1 sinon et 2 s'il est arrivé à la fin. 			*/

int moveMonster(ListMonsters* p_lmonster, Node* p_tail, int k){

	// On vérifie si notre liste a été allouée
	if (p_lmonster != NULL) {	

		//Création d'un pointeur monstre temporaire pour parcourir la liste de monstres
		Monster *p_tmp = p_lmonster->p_head;

		//Parcours la liste de monstres
		while(p_tmp != NULL){

			//Vitesse de déplacement du monstre
			if(k%(p_tmp->pace) == 0) {

				//S'il avance selon l'axe des y
				if(p_tmp->node_prev->x == p_tmp->node_next->x) {
			
					//S'il va vers le bas
					if(p_tmp->sens == 3)
						(p_tmp->y)++; //Fait avancer le monstre vers le haut
					//Sinon il avance vers le haut
					else
						(p_tmp->y)--; //Fait avancer le monstre vers le haut
				}
				//S'il avance selon l'axe des x
				else if(p_tmp->node_prev->y == p_tmp->node_next->y) {

					//S'il va vers la droite
					if(p_tmp->sens == 2)
						(p_tmp->x)++; //Fait avancer le monstre vers le haut
					//Sinon il avance vers la gauche
					else
						(p_tmp->x)--; //Fait avancer le monstre vers le haut

				}
				//S'il avance sur l'axe des x et des y
				else {

					float dx, dy;
					dx = ((p_tmp->node_next->x) - (p_tmp->node_prev->x))*2;
					dy = ((p_tmp->node_next->y) - (p_tmp->node_prev->y))*2;
				

					if(dx > 0) {

						if(dy > 0) {
							//Si la longueur entre les deux points et plus grande que la hauteur entre les deux points
							if(dx >= dy) {

								(p_tmp->x)++;
								p_tmp->e -= dy;
						
								if(p_tmp->e <= 0) {
									(p_tmp->y)++;
									p_tmp->e += dx;
								}

							}
							//Si la hauteur entre les deux points et plus grande que la longueur entre les deux points
							else {
								(p_tmp->y)++;
								p_tmp->e -= dx;

								if(p_tmp->e <= 0) {
									(p_tmp->x)++;
									p_tmp->e += dy;
								}

							}
						}
						else {
				
							if(dx >= -dy){
								(p_tmp->x)++;
								p_tmp->e += dy;

								if(p_tmp->e <= 0) {
									(p_tmp->y)--;
									p_tmp->e += dx;
								}

							}
							else {
								(p_tmp->y)--;
								p_tmp->e += dx;

								if(p_tmp->e > 0) {
									(p_tmp->x)++;
									p_tmp->e += dy;
								}
							}

						}
					}
					// dx < 0
					else {

						if(dy > 0) {

							if(-dx >= dy) {

								(p_tmp->x)--;
								p_tmp->e += dy;

								if(p_tmp->e >= 0) {
									(p_tmp->y)++;
									p_tmp->e += dx;
								}

							}
							else {
								(p_tmp->y)++;
								p_tmp->e += dx;

								if(p_tmp->e <= 0) {
									(p_tmp->x)--;
									p_tmp->e += dy;
								}

							}
						}
						else {


							if(dx <= dy) {

								(p_tmp->x)--;
								p_tmp->e -= dy;

								if(p_tmp->e >= 0) {
									(p_tmp->y)--;
									p_tmp->e += dx;
								}

							}
							else {
								(p_tmp->y)--;
								p_tmp->e -= dy;

								if(p_tmp->e >= 0) {
									(p_tmp->x)--;
									p_tmp->e += dy;
								}

							}

						}

					}

				}

				//S'il est arrivé au noeud suivant change les noeuds précédent et suivant
				if(p_tmp->x == p_tmp->node_next->x && p_tmp->y == p_tmp->node_next->y) {

					if(p_tmp->x == p_tail->x && p_tmp->y == p_tail->y)
						return 2;
					else {
						p_tmp->node_prev = p_tmp->node_next;
						p_tmp->node_next = p_tmp->node_next->p_next;

						calculErreur(p_tmp);
					}
				}
			}

			p_tmp = p_tmp->p_next;

		}
	}
	else {
		fprintf(stderr, "Cette liste de monstres n'existe pas");
		return 0;
	}

	return 1;
}

/************* Calcule de l'erreur en fonction du noeud précédent et du noeud suivant ******************/
/* Calcule de l'erreur de déplacement en fonction du noeud précédent et du noeud suivant.	*
*  Prend en paramètre un pointeur vers un monstre. Ne retourne rien 				*/
void calculErreur(Monster* monster) {

	if(monster->node_prev != NULL && monster->node_next != NULL) {

		if(monster->node_prev->x == monster->node_next->x) {

			monster->e = 0; //erreur
		
			if(monster->node_prev->y <= monster->node_next->y)
				monster->sens = 3;
			else
				monster->sens = 1;

		}
		else if(monster->node_prev->y == monster->node_next->y) {

			monster->e = 0;//erreur

			if(monster->node_prev->x <= monster->node_next->x)
				monster->sens = 2;
			else
				monster->sens = 4;
		}
		else {

			float dx = (monster->node_next->x) - (monster->node_prev->x);
			float dy = (monster->node_next->y) - (monster->node_prev->y);	

			if(dx > 0) {

				if(dy > 0) {

					if(dx >= dy)
						monster->e = (monster->node_next->x) - (monster->node_prev->x);
					else
						monster->e = (monster->node_next->y) - (monster->node_prev->y);
				}
				else {

					if(dx >= -dy)
						monster->e = (monster->node_next->x) - (monster->node_prev->x);
					else
						monster->e = (monster->node_next->y) - (monster->node_prev->y);

				}

				monster->sens = 2;

			}
			else {
				if(dy > 0) {

					if(-dx >= dy)
						monster->e = (monster->node_next->x) - (monster->node_prev->x);
					else
						monster->e = (monster->node_next->y) - (monster->node_prev->y);

				}
				else {

					if(dx <= dy)
						monster->e = (monster->node_next->x) - (monster->node_prev->x);
					else
						monster->e = (monster->node_next->y) - (monster->node_prev->y);

				}

				monster->sens = 4;
			
			}		

		}

	}
	else
		fprintf(stderr, "Erreur sur le pointeur du monstre\n");

}

/************* Supprimer un monstre selon sa position *************/
/* Supprime un monstre selon sa position, vérifie si c'est le premier, le dernier ou un monstre dans la liste puis le supprime	 	*
*  Prend en paramètre la liste de monstres et le monstre à supprimer et retourne la liste de monstres.					*/

ListMonsters* removeMonster(ListMonsters* p_lmonster, Monster* p_courant) {

	// On vérifie si notre liste a été allouée
	if (p_lmonster != NULL) {

		if(p_courant != NULL) {

			//Si il reste plus que ce dernier element
			/*if(p_courant->p_next == NULL && p_courant->p_prev == NULL) {
				p_lmonster->p_tail = NULL;
				p_lmonster->p_head = NULL;
			}*/
			//Si c'est le dernier monstre de la liste
			if (p_courant->p_next == NULL) {
			
				//Pointe la fin de la liste sur le monstre précédent
				p_lmonster->p_tail = p_courant->p_prev;
			
				if(p_lmonster->p_tail != NULL) {
					//Lien du dernier monstre vers le monstre suivant est NULL
					p_lmonster->p_tail->p_next = NULL;
				}
				else
					p_lmonster->p_head = NULL;
				
			}
			//Si c'est le premier monstre de la liste
			else if (p_courant->p_prev == NULL) {
				//Pointe la tête de la liste vers le monstre suivant
				p_lmonster->p_head = p_courant->p_next;

				if(p_lmonster->p_head != NULL) {
					//Le lien vers du deuxième monstre vers le monstre précédent est NULL
			 		p_lmonster->p_head->p_prev = NULL;
				}
				else
					p_lmonster->p_tail = NULL;
			}

			else {
				//Relie le monstre suivant au monstre précédent du monstre que l'on veut supprimer 
				p_courant->p_next->p_prev = p_courant->p_prev;
				//Relie le monstre précédent au monstre suivant du monstre que l'on veut supprimer 
				p_courant->p_prev->p_next = p_courant->p_next;
			}
			//Libère espace mémoire : supprime le monstre
			free(p_courant);
			//Décrémente de un la taille de la liste
			p_lmonster->length--;

		}
		else {
			fprintf(stderr, "Ce monstre n'existe pas\n");
			return NULL;
		}
	}
	else {
		fprintf(stderr, "Cette liste de monstres n'existe pas\n");
		return NULL;
	}

	// on retourne notre nouvelle liste
	return p_lmonster; 
}

/************* Supprimer tous les monstres de la liste *************/
/* Supprime la liste de monstre et les monstre. Prend en paramètre la liste de monstre.	 	*/

void removeAllMonsters (ListMonsters* p_lmonster) {
	//Si la liste n'est pas vide
	if (p_lmonster->length != 0) {

		//Tant que la liste n'est pas vide
		while (p_lmonster->p_head != NULL) {
			p_lmonster = removeMonster(p_lmonster, p_lmonster->p_head);
		}
		
	}
}

/************* Supprimer la liste de monstres *************/
/* Supprime la liste de monstre et les monstre. Prend en paramètre la liste de monstre.	 	*/

void freeAllMonsters (ListMonsters* p_lmonster) {
	//Si la liste n'est pas vide
	if (p_lmonster->length != 0) {

		//Tant que la liste n'est pas vide
		while (p_lmonster->p_head != NULL) {
			p_lmonster = removeMonster(p_lmonster, p_lmonster->p_head);
		}
		
	}
	free(p_lmonster);
}

