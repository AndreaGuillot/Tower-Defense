#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "element/Tower.h"
#include "element/Monster.h"
#include "element/Shot.h"
#include "geometry/Intersection.h"
#include "ihm/Interface.h"

/************* Création d'une nouvelle liste de missiles *************/
/* Initialisation de la liste de missiles et allocation de mémoire pour la liste de missiles		*
*  Retourne la liste de missiles									*/

LShot* new_LShot(void) {
	
	//Alloue de la mémoire 
	LShot *tmp = malloc(sizeof(LShot));
	if (tmp != NULL) {
		tmp->length = 0;
		tmp->p_head = NULL;
		tmp->p_tail = NULL;
	}
	else {
		fprintf(stderr, "Erreur lors de l'allocation memoire de la liste des missiles\n");
		return NULL;
	}

	return tmp;
}

/************* Ajouter un missile en fin de liste *************/
/* Ajoute un missile à la liste. Alloue la place mémoire pour le missile et attribue les valeurs	*
*  Prend en paramètre la liste de missiles, le monstre visé, la tour qui envoie le missile. 		*
*  Retourne 0 en cas d'erreur et 1 sinon								*/

int addShot(LShot* list_shot, Monster* target, Tower* tower) {

	// On vérifie si notre liste a été allouée
	if(list_shot != NULL) {

		//On vérifie que le monstre a été alloué
		if(target != NULL) {

			if(tower != NULL) {

				//Création d'un nouveau missile
				Shot* tmp = malloc(sizeof(Shot)); 
		
				// On vérifie si le malloc n'a pas échoué
				if (tmp != NULL) {

					tmp->x = tower->x;
					tmp->y = tower->y;
					tmp->target = target;
					tmp->tower = tower;
					tmp->type_tower = tower->type_tower;
					tmp->power = tower->power;
	
					//Pointer vers le missile suivant à NULL car on rajoute à la fin de la liste	
					tmp->p_next = NULL; 

					// Cas où notre liste est vide (pointeur vers fin de liste à  NULL)
					if (list_shot->p_tail == NULL) {

						// Pointe la tête de la liste sur le nouveau missile
						list_shot->p_head = tmp; 

						//Pointe p_prev de le nouveau missile à NULL
						tmp->p_prev = NULL;
					}
					// Cas où des éléments sont déjà présents dans la  liste
					else {
						// Pointe p_prev du nouveau missile sur le dernier missile de la liste
						tmp->p_prev = list_shot->p_tail; 

						// Relie le dernier missile de la liste au nouveau missile
						list_shot->p_tail->p_next = tmp;  
					}

					// Pointe la fin de la liste sur le nouveau missile
					list_shot->p_tail = tmp; 

					// On augmente de 1 la taille de la liste
					list_shot->length++; 
				}
				else {
					fprintf(stderr, "Problème dans la creation du nouveau missile\n");
					return 0;
				}

			}
			else {
				fprintf(stderr, "Cette tour n'existe pas\n");
				return 0;
			}
		}
		else {
			fprintf(stderr, "Ce monstre n'existe pas\n");
			return 0;
		}
	}
	else {
		fprintf(stderr, "Cette liste de missiles n'existe pas\n");
		return 0;
	}

	return 1; 
}

/************* Vérification si un monstre entre dans le périmètre d'action de la tour *************/
/* Vérifie si un monstre entre dans le périmètre d'action => vérifie l'équation :		*
*  (x - x1)² + (y - y1)² <= R² avec (x1, y1) pour centre du cercle et R son rayon	 	*
*  x et y sont les coordonées des 4 points du quadrilatère qui contient le monstre.		*
*  Prend en paramètre la liste de shot, la liste de monstre, la tour. Retourne 0 s'il n'y a 	*
*  pas d'intersection, ou en cas d'erreur et retourne 1 sinon					*/

int inSight (LShot* list_shot, ListMonsters* list_monster, Tower* tower) {

	if(list_shot != NULL) {

		if(list_monster != NULL){

			if(tower != NULL) {

				if(strcmp("M", tower->type_tower) != 0) {

					Monster *monstre = NULL;

					//Variables pour savoir qui est le plus proche
					Point2D pointIntersection, pointProche, point1, point2;
					Vector2D vectorIntersection, vectorProche;
					float normeIntersection, normeProche = -1;

					//Création d'un monstre temporaire pour parcourir la liste de monstres
					Monster *tmp = list_monster->p_head;

					//Parcours la liste de monstres
					while(tmp != NULL){

						Point2D point;
						point.x = tower->x; point.y = tower->y; //centre

						point1.x = tmp->x + 20; point1.y = tmp->y + 20;
						point2.x = tmp->x - 20; point2.y = tmp->y - 20;

						//Vérifie s'il y a une intersection
						if(intersectionCarreDisque (point1, point2, tower->range, point) == 1) {

							pointIntersection.x = tmp->x; pointIntersection.y = tmp->y;
							vectorIntersection = Vector(point, pointIntersection);
							normeIntersection = Norm(vectorIntersection);
				
							//S'il n'y a pas de point d'intersection avant
							if(normeProche == -1) {
								vectorProche = Vector(point, pointProche);
								normeProche = Norm(vectorProche);
								monstre = tmp;
							}
							//Si la distance du nouveau point d'intersection est plus proche que celle stocker
							if(normeIntersection < normeProche) {
								vectorProche = vectorIntersection;
								normeProche = normeIntersection;
								monstre = tmp;
							}

						}


						tmp = tmp->p_next;

					}

					if(monstre != NULL)
						addShot(list_shot, monstre, tower); //Ajout d'un shot à la liste

					return 1;

				}
				else {
				
					//Création d'un monstre temporaire pour parcourir la liste de monstres
					Monster *tmp = list_monster->p_head;

					//Parcours la liste de monstres
					while(tmp != NULL){

						Point2D point, point1, point2;
						point.x = tower->x; point.y = tower->y; //centre

						point1.x = tmp->x + 20; point1.y = tmp->y + 20;
						point2.x = tmp->x - 20; point2.y = tmp->y - 20;

						//Vérifie s'il y a une intersection
						if(intersectionCarreDisque (point1, point2, tower->range, point) == 1)
							addShot(list_shot, tmp, tower); //Ajout d'un shot à la liste

						tmp = tmp->p_next;

					}	
					return 1;

				}

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

/************* Bouger les missiles en direction de l'ennemi *************/
/* Change la position des missiles pour qu'ils bouge vers l'ennemi. Prend en paramètre la liste de  	*
*  missiles. Retourne 0 en cas d'erreur et 1 sinon.						 	*/

int moveShot(LShot* list_shot) {

	//Vérifie que la liste est allouée
	if(list_shot != NULL) {

		//Créer un pointeur missile temporaire pour parcourir la liste de missiles
		Shot *tmp = list_shot->p_head;

		//Parcours la liste de missiles
		while(tmp != NULL){

			Point2D point_target;
			Point2D point_shot;

			if(tmp->target != NULL) {

				point_target.x = tmp->target->x;
				point_target.y = tmp->target->y;
			}
			else {
				point_target.x = 810;
				point_target.y = 100;
			}

			point_shot.x = tmp->x;
			point_shot.y = tmp->y;

			//Créer un vecteur avec le la position du missile et la position de l'ennemie
			Vector2D vector = Vector(point_shot, point_target);
			//Normalise le vecteur pour avoir une norme de 1
			vector = Normalize(vector);
			//Ajoute le vecteur normaliser au point qui représente la position du missile pour le déplacer
			Point2D result = PointPlusVector(point_shot, vector);

			tmp->x = result.x;
			tmp->y = result.y;

			tmp = tmp->p_next;
		}

	}
	else {
		fprintf(stderr, "La liste de missiles n'existe pas ou est vide\n");
		return 0;
	}

	return 1;
}

/************* Collision entre le missile et l'ennemie *************/
/* Vérifie si le missile entre en collision avec le missile. Si oui supprime le missile et   	*
*  déduit les points de vie du monstre. Prend en paramètre la liste de monstre et le monstre.   *
*  Retourne 0 en cas d'erreur et 1 sinon.							*/

int collisionMissile(LShot* list_shot, ListMonsters* list_monster, Joueur* joueur, Monster* monster, int* propriete) {

	//On vérifie si notre liste a été allouée
	if(list_shot != NULL) {

		Shot* shotSuppr = NULL;
			
		//Créer un pointeur missile temporaire pour parcourir la liste de missiles
		Shot *tmp = list_shot->p_head;

		//Parcours la liste de missiles
		while(tmp != NULL){

			//Vérifie s'il y a une intersection pour les quatres coté du quads du monstre
			Point2D point1, point2, pointC1, pointC2;

			pointC1.x = tmp->x + 5; pointC1.y = tmp->y + 5;
			pointC2.x = tmp->x - 5; pointC2.y = tmp->y - 5;
				
			if(tmp->target == NULL) {

				if(tmp->x < 180 || tmp->x > 800 || tmp->y < 40 || tmp->y > 660)
					list_shot = removeShot(list_shot, tmp);
	
				tmp = tmp->p_next;
			}
			else {
			
				point1.x = tmp->target->x + 20; point1.y = tmp->target->y + 20;
				point2.y = tmp->target->x - 20; point2.y = tmp->target->y - 20;

				//Vérifie s'il y a une intersection
				if(intersectionCarres(point1, point2, pointC1, pointC2) == 1) {

					//Vériie s'il est plus résistant à ce type de tour
					if(strcmp(tmp->type_tower, tmp->target->type_tower) == 0) {
						if((tmp->power) > (tmp->target->resistance))
							tmp->target->pv -= ((tmp->power) - (tmp->target->resistance)); //retire des points de vie en fonction de la résistance
						else 
							tmp->target->pv -= ((tmp->power) - ((tmp->power) - 1));

					}
					else
						tmp->target->pv -= tmp->power; //retire des points de vie

					if(tmp->target->pv <= 0){
					
						tmp->target->pv = 0;

						//Mets à jours l'joueur (money, score, nbmonstre tués)
						updateInterface(joueur, tmp->target);

						//Créer un pointeur missile temporaire pour parcourir la liste de missiles
						Shot *tmp_shot = list_shot->p_head;

						//Parcours la liste de missiles
						while(tmp_shot != NULL){

							if(tmp_shot != tmp) {
								if(tmp_shot->target == tmp->target) 
									tmp_shot->target = NULL;
							}

							tmp_shot = tmp_shot->p_next;

						}

						if(monster == tmp->target) {
							monster = NULL;
							*propriete = 0;
						}
						//retire le monstre de la liste de monstre
						list_monster = removeMonster(list_monster, tmp->target);
						tmp->target = NULL;
					
					}

					shotSuppr = tmp;
					tmp = tmp->p_next;

					if(shotSuppr != NULL)
						list_shot = removeShot(list_shot, shotSuppr);//Retire le missile de la liste
			
				}
				else
					tmp = tmp->p_next;
			}
	
		}

	}
	else {
		fprintf(stderr, "Cette liste de missiles n'existe pas\n");
		return 0;
	}

	return 1;

}

/************* Supprimer un missile selon sa position *************/
/* Supprime une missile selon sa position, vérifie si c'est le premier, le dernier ou un missile dans la liste puis le supprime *
*  Prend en paramètre la liste de missiles et le missile à supprimer et retourne la liste de missiles.				*/

LShot* removeShot(LShot* list_shot, Shot* shot) {

	// On vérifie si notre liste a été allouée
	if (list_shot != NULL) {

		if(shot != NULL) {

			//Si c'est le dernier missile de la liste
			if (shot->p_next == NULL) {
				
				//Pointe la fin de la liste sur le missile précédent
				list_shot->p_tail = shot->p_prev;
				if(list_shot->p_tail != NULL) {
					//Lien de le dernier missile vers le missile suivant est NULL
					list_shot->p_tail->p_next = NULL;
				}
				else 
					list_shot->p_head = NULL;
					
			}
		
			//Si c'est le premier de la liste
			else if (shot->p_prev == NULL) {
				//Pointe la tête de la liste vers le missile suivant
				list_shot->p_head = shot->p_next;
				if(list_shot->p_head != NULL) {
					//Le lien vers de le deuxième misiile vers le missile précédent est NULL
			 		list_shot->p_head->p_prev = NULL;
				}
				else 
					list_shot->p_tail = NULL;
			}
			else {
				//Relie le missile suivant au missile précédent du missile que l'on veut supprmer 
				shot->p_next->p_prev = shot->p_prev;
				//Relie le missile précédent au missile suivant du missile que l'on veut supprmer 
				shot->p_prev->p_next = shot->p_next;
			}
			//Libère espace mémoire : supprime le missile
			free(shot);
			//Décrémente de un la taille de la liste
			list_shot->length--;

		}
		else
			fprintf(stderr, "Ce missile n'existe pas\n");
	}
	else 
		fprintf(stderr, "Cette liste de missiles n'existe pas\n");

	// on retourne notre nouvelle liste
	return list_shot; 
}

/************* Supprimer tous les missiles de la liste *************/
/* Supprime la liste de missiles. Prend en paramètre un pointeur vers la liste de missiles 	*/

void removeAllShot (LShot* list_shot) {
	//Si la liste n'est pas vide
	if (list_shot->length != 0) {

		//Tant que la liste n'est pas vide
		while (list_shot->p_head != NULL) {
			list_shot = removeShot(list_shot, list_shot->p_head);
		}
		
	}
}

/************* Supprimer la liste de missiles *************/
/* Supprime la liste de missiles. Prend en paramètre un pointeur vers la liste de missiles 	*/

void freeAllShot (LShot* list_shot) {
	//Si la liste n'est pas vide
	if (list_shot->length != 0) {

		//Tant que la liste n'est pas vide
		while (list_shot->p_head != NULL) {
			list_shot = removeShot(list_shot, list_shot->p_head);
		}
		
	}
	free(list_shot);
}
