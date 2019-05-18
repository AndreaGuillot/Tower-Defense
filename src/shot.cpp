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
	LShot *p_lshot = malloc(sizeof(LShot));
	if (p_lshot != NULL) {
		p_lshot->length = 0;
		p_lshot->p_head = NULL;
		p_lshot->p_tail = NULL;
	}
	else {
		fprintf(stderr, "Erreur lors de l'allocation memoire de la liste des missiles\n");
		return NULL;
	}

	return p_lshot;
}

/************* Ajouter un missile en fin de liste *************/
/* Ajoute un missile à la liste. Alloue la place mémoire pour le missile et attribue les valeurs	*
*  Prend en paramètre la liste de missiles, le monstre visé, la tour qui envoie le missile. 		*
*  Retourne 0 en cas d'erreur et 1 sinon								*/

int addShot(LShot* p_lshot, Monster* target, Tower* tower) {

	// On vérifie si notre liste a été allouée
	if(p_lshot != NULL) {

		//On vérifie que le monstre a été alloué
		if(target != NULL) {

			if(tower != NULL) {

				//Création d'un nouveau missile
				Shot* new_shot = malloc(sizeof(Shot)); 
		
				// On vérifie si le malloc n'a pas échoué
				if (new_shot != NULL) {

					new_shot->x = tower->x;
					new_shot->y = tower->y;
					new_shot->target = target;
					new_shot->tower = tower;
					new_shot->type_tower = tower->type_tower;
					new_shot->power = tower->power;
	
					//Pointer vers le missile suivant à NULL car on rajoute à la fin de la liste	
					new_shot->p_next = NULL; 

					// Cas où notre liste est vide (pointeur vers fin de liste à  NULL)
					if (p_lshot->p_tail == NULL) {

						// Pointe la tête de la liste sur le nouveau missile
						p_lshot->p_head = new_shot; 

						//Pointe p_prev de le nouveau missile à NULL
						new_shot->p_prev = NULL;
					}
					// Cas où des éléments sont déjà présents dans la  liste
					else {
						// Pointe p_prev du nouveau missile sur le dernier missile de la liste
						new_shot->p_prev = p_lshot->p_tail; 

						// Relie le dernier missile de la liste au nouveau missile
						p_lshot->p_tail->p_next = new_shot;  
					}

					// Pointe la fin de la liste sur le nouveau missile
					p_lshot->p_tail = new_shot; 

					// On augmente de 1 la taille de la liste
					p_lshot->length++; 
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

int inSight (LShot* p_lshot, LMonster* p_lmonster, Tower* p_courant) {

	if(p_lshot != NULL) {

		if(p_lmonster != NULL){

			if(p_courant != NULL) {

				if(strcmp("M", p_courant->type_tower) != 0) {

					Monster *p_proche = NULL;

					//Variables pour savoir qui est le plus proche
					Point2D pointIntersection, pointProche, point1, point2;
					Vector2D vectorIntersection, vectorProche;
					float normeIntersection, normeProche = -1;

					//Création d'un monstre temporaire pour parcourir la liste de monstres
					Monster *p_tmp = p_lmonster->p_head;

					//Parcours la liste de monstres
					while(p_tmp != NULL){

						Point2D point;
						point.x = p_courant->x; point.y = p_courant->y; //centre

						point1.x = p_tmp->x + 20; point1.y = p_tmp->y + 20;
						point2.x = p_tmp->x - 20; point2.y = p_tmp->y - 20;

						//Vérifie s'il y a une intersection
						if(intersectionCarreDisque (point1, point2, p_courant->range, point) == 1) {

							pointIntersection.x = p_tmp->x; pointIntersection.y = p_tmp->y;
							vectorIntersection = Vector(point, pointIntersection);
							normeIntersection = Norm(vectorIntersection);
				
							//S'il n'y a pas de point d'intersection avant
							if(normeProche == -1) {
								vectorProche = Vector(point, pointProche);
								normeProche = Norm(vectorProche);
								p_proche = p_tmp;
							}
							//Si la distance du nouveau point d'intersection est plus proche que celle stocker
							if(normeIntersection < normeProche) {
								vectorProche = vectorIntersection;
								normeProche = normeIntersection;
								p_proche = p_tmp;
							}

						}


						p_tmp = p_tmp->p_next;

					}

					if(p_proche != NULL)
						addShot(p_lshot, p_proche, p_courant); //Ajout d'un shot à la liste

					return 1;

				}
				else {
				
					//Création d'un monstre temporaire pour parcourir la liste de monstres
					Monster *p_tmp = p_lmonster->p_head;

					//Parcours la liste de monstres
					while(p_tmp != NULL){

						Point2D point, point1, point2;
						point.x = p_courant->x; point.y = p_courant->y; //centre

						point1.x = p_tmp->x + 20; point1.y = p_tmp->y + 20;
						point2.x = p_tmp->x - 20; point2.y = p_tmp->y - 20;

						//Vérifie s'il y a une intersection
						if(intersectionCarreDisque (point1, point2, p_courant->range, point) == 1)
							addShot(p_lshot, p_tmp, p_courant); //Ajout d'un shot à la liste

						p_tmp = p_tmp->p_next;

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

int moveShot(LShot* p_lshot) {

	//Vérifie que la liste est allouée
	if(p_lshot != NULL) {

		//Créer un pointeur missile temporaire pour parcourir la liste de missiles
		Shot *p_tmp = p_lshot->p_head;

		//Parcours la liste de missiles
		while(p_tmp != NULL){

			Point2D point_target;
			Point2D point_shot;

			if(p_tmp->target != NULL) {

				point_target.x = p_tmp->target->x;
				point_target.y = p_tmp->target->y;
			}
			else {
				point_target.x = 810;
				point_target.y = 100;
			}

			point_shot.x = p_tmp->x;
			point_shot.y = p_tmp->y;

			//Créer un vecteur avec le la position du missile et la position de l'ennemie
			Vector2D vector = Vector(point_shot, point_target);
			//Normalise le vecteur pour avoir une norme de 1
			vector = Normalize(vector);
			//Ajoute le vecteur normaliser au point qui représente la position du missile pour le déplacer
			Point2D result = PointPlusVector(point_shot, vector);

			p_tmp->x = result.x;
			p_tmp->y = result.y;

			p_tmp = p_tmp->p_next;
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

int collisionMissile(LShot* p_lshot, LMonster* p_lmonster, Interface* interface, Monster* monster, int* propriete) {

	//On vérifie si notre liste a été allouée
	if(p_lshot != NULL) {

		Shot* shotSuppr = NULL;
			
		//Créer un pointeur missile temporaire pour parcourir la liste de missiles
		Shot *p_tmp = p_lshot->p_head;

		//Parcours la liste de missiles
		while(p_tmp != NULL){

			//Vérifie s'il y a une intersection pour les quatres coté du quads du monstre
			Point2D point1, point2, pointC1, pointC2;

			pointC1.x = p_tmp->x + 5; pointC1.y = p_tmp->y + 5;
			pointC2.x = p_tmp->x - 5; pointC2.y = p_tmp->y - 5;
				
			if(p_tmp->target == NULL) {

				if(p_tmp->x < 180 || p_tmp->x > 800 || p_tmp->y < 40 || p_tmp->y > 660)
					p_lshot = removeShot(p_lshot, p_tmp);
	
				p_tmp = p_tmp->p_next;
			}
			else {
			
				point1.x = p_tmp->target->x + 20; point1.y = p_tmp->target->y + 20;
				point2.y = p_tmp->target->x - 20; point2.y = p_tmp->target->y - 20;

				//Vérifie s'il y a une intersection
				if(intersectionCarres(point1, point2, pointC1, pointC2) == 1) {

					//Vériie s'il est plus résistant à ce type de tour
					if(strcmp(p_tmp->type_tower, p_tmp->target->type_tower) == 0) {
						if((p_tmp->power) > (p_tmp->target->resistance))
							p_tmp->target->pv -= ((p_tmp->power) - (p_tmp->target->resistance)); //retire des points de vie en fonction de la résistance
						else 
							p_tmp->target->pv -= ((p_tmp->power) - ((p_tmp->power) - 1));

					}
					else
						p_tmp->target->pv -= p_tmp->power; //retire des points de vie

					if(p_tmp->target->pv <= 0){
					
						p_tmp->target->pv = 0;

						//Mets à jours l'interface (money, score, nbmonstre tués)
						updateInterface(interface, p_tmp->target);

						//Créer un pointeur missile temporaire pour parcourir la liste de missiles
						Shot *p_temp = p_lshot->p_head;

						//Parcours la liste de missiles
						while(p_temp != NULL){

							if(p_temp != p_tmp) {
								if(p_temp->target == p_tmp->target) 
									p_temp->target = NULL;
							}

							p_temp = p_temp->p_next;

						}

						if(monster == p_tmp->target) {
							monster = NULL;
							*propriete = 0;
						}
						//retire le monstre de la liste de monstre
						p_lmonster = removeMonster(p_lmonster, p_tmp->target);
						p_tmp->target = NULL;
					
					}

					shotSuppr = p_tmp;
					p_tmp = p_tmp->p_next;

					if(shotSuppr != NULL)
						p_lshot = removeShot(p_lshot, shotSuppr);//Retire le missile de la liste
			
				}
				else
					p_tmp = p_tmp->p_next;
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

LShot* removeShot(LShot* p_lshot, Shot* p_courant) {

	// On vérifie si notre liste a été allouée
	if (p_lshot != NULL) {

		if(p_courant != NULL) {

			//Si c'est le dernier missile de la liste
			if (p_courant->p_next == NULL) {
				
				//Pointe la fin de la liste sur le missile précédent
				p_lshot->p_tail = p_courant->p_prev;
				if(p_lshot->p_tail != NULL) {
					//Lien de le dernier missile vers le missile suivant est NULL
					p_lshot->p_tail->p_next = NULL;
				}
				else 
					p_lshot->p_head = NULL;
					
			}
		
			//Si c'est le premier de la liste
			else if (p_courant->p_prev == NULL) {
				//Pointe la tête de la liste vers le missile suivant
				p_lshot->p_head = p_courant->p_next;
				if(p_lshot->p_head != NULL) {
					//Le lien vers de le deuxième misiile vers le missile précédent est NULL
			 		p_lshot->p_head->p_prev = NULL;
				}
				else 
					p_lshot->p_tail = NULL;
			}
			else {
				//Relie le missile suivant au missile précédent du missile que l'on veut supprmer 
				p_courant->p_next->p_prev = p_courant->p_prev;
				//Relie le missile précédent au missile suivant du missile que l'on veut supprmer 
				p_courant->p_prev->p_next = p_courant->p_next;
			}
			//Libère espace mémoire : supprime le missile
			free(p_courant);
			//Décrémente de un la taille de la liste
			p_lshot->length--;

		}
		else
			fprintf(stderr, "Ce missile n'existe pas\n");
	}
	else 
		fprintf(stderr, "Cette liste de missiles n'existe pas\n");

	// on retourne notre nouvelle liste
	return p_lshot; 
}

/************* Supprimer tous les missiles de la liste *************/
/* Supprime la liste de missiles. Prend en paramètre un pointeur vers la liste de missiles 	*/

void removeAllShot (LShot* p_lshot) {
	//Si la liste n'est pas vide
	if (p_lshot->length != 0) {

		//Tant que la liste n'est pas vide
		while (p_lshot->p_head != NULL) {
			p_lshot = removeShot(p_lshot, p_lshot->p_head);
		}
		
	}
}

/************* Supprimer la liste de missiles *************/
/* Supprime la liste de missiles. Prend en paramètre un pointeur vers la liste de missiles 	*/

void freeAllShot (LShot* p_lshot) {
	//Si la liste n'est pas vide
	if (p_lshot->length != 0) {

		//Tant que la liste n'est pas vide
		while (p_lshot->p_head != NULL) {
			p_lshot = removeShot(p_lshot, p_lshot->p_head);
		}
		
	}
	free(p_lshot);
}
