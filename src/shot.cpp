#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/shot.h"

class Shot{
	public:

	Shot get(){
		return this;
	}
	float getX(){
		return this->x;
	}
	float getY(){
		return this->y;
	}
	Monster getTarget(){
		return this->target;
	}
	Tower* getTower(){
		return this->tower;
	}
	int getPower(){
		return this->tower.getPower();
	}
	towerType getType(){
		return this->tower.getType();
	}

	Shot getPrev(){
		return this->prev;
	}
	Shot getNext(){
		return this->next;
	}


	void set(Shot s){
		this =s;
	}
	void setX(float x){
		this->x = x;
	}
	void setY(float y){
		this->y = y;
	}
	void setTarget(Monster m){
		this->target = m;
	}
	void setTower(Tower* t){
		this->tower = t;
	}
	void setPrev(Shot s){
		this->prev = s;
	}
	void setNext(Shot s){
		this->next = s;
	}
}

class listShot{

	listShots(){
		this->length = 0;
		this->head.set(NULL);
		this->tail.set(NULL);
	}
	int getLength(){
		return this->length;
	}
	Shot getHead(){
		return this->head;
	}
	Shot getTail(){
		return this->tail;
	}
	void setLength(int l){
		this->length = l;
	}
	void setHead(Shot s){
		this->head = s;
	}
	void setTail(Shot s){
		this->tail = s;
	}

	int addShot(Monster monster, Tower* tower) {
		if(this != NULL) {
			if(monster != NULL) {
				if(tower != NULL) {

					Shot shot = new Shot(tower, monster); 
			
					shot.setNext(NULL); 

						if (this->tail == NULL) {
							this.setHead(shot); 
							shot.setPrev(NULL);
						}
						// Cas où des éléments sont déjà présents dans la  liste
						else {
							// Pointe p_prev du nouveau missile sur le dernier missile de la liste
							shot.setPrev(this->tail); 

							// Relie le dernier missile de la liste au nouveau missile
							this->tail.setNext(shot);  
						}

						// Pointe la fin de la liste sur le nouveau missile
						this->tail.set(shot); 

						// On augmente de 1 la taille de la liste
						this->length++; 
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

	int moveShot() {
		if(this != NULL) {
			Shot tmp = this->head;

			//Parcours la liste de missiles
			while(tmp != NULL){

				Position point_target;
				Position point_shot;

				if(tmp.getTarget() != NULL) {

					point_target.set(tmp.getTarget().getX(), tmp.getTarget().getY());
				}
				else {
					point_target.set(810, 100);
				}

				point_shot.set(tmp.getX(), tmp.getY());

				//Créer un vecteur avec le la position du missile et la position de l'ennemie
				Vector vector = Vector(point_shot, point_target);
				//Normalise le vecteur pour avoir une norme de 1
				vector = vector.normalize();
				//Ajoute le vecteur normaliser au point qui représente la position du missile pour le déplacer
				point_shot.addVector(vector);

				tmp.setX(point_shot.getX());
				tmp.setY(point_shot.getY());

				tmp = tmp.getNext();
			}

		}
		else {
			fprintf(stderr, "La liste de missiles n'existe pas ou est vide\n");
			return 0;
		}

		return 1;
	}

	void removeShot(Shot shot) {
		if (this != NULL) {
			if(shot != NULL) {
				if (shot.getNext() == NULL) {
					
					this.setTail(shot.getPrev());
					if(this.getTail() != NULL) {
						//Lien de le dernier missile vers le missile suivant est NULL
						this.getTail().setNext(NULL);
					}
					else 
						this.setHead(NULL);
						
				}else if (shot.getPrev() == NULL) {
					//Pointe la tête de la liste vers le missile suivant
					this.setHead(shot.getPrev());
					if(this.getHead() != NULL) {
						//Le lien vers de le deuxième missile vers le missile précédent est NULL
				 		this.getHead().setPrev(NULL);
					}
					else 
						this.setTail(NULL);
				}
				else {
					//Relie le missile suivant au missile précédent du missile que l'on veut supprmer 
					shot.getNext().setPrev(shot.getPrev());
					//Relie le missile précédent au missile suivant du missile que l'on veut supprmer 
					shot.getPrev().setNext(shot.getNext());
				}
				//Libère espace mémoire : supprime le missile
				free(shot);
				//Décrémente de un la taille de la liste
				this->length--;

			}
			else
				fprintf(stderr, "Ce missile n'existe pas\n");
		}
		else 
			fprintf(stderr, "Cette liste de missiles n'existe pas\n");
	}

	void removeAllShot () {
		//Si la liste n'est pas vide
		if (this->length != 0) {

			//Tant que la liste n'est pas vide
			while (this->head != NULL) {
				this = removeShot(this, this->head);
			}
			
		}
	}

	void freeAllShot () {
		//Si la liste n'est pas vide
		if (this->length != 0) {

			//Tant que la liste n'est pas vide
			while (this->head != NULL) {
				this = removeShot(this, this->head);
			}
			
		}
		free(this);
	}

	int draw(GLuint* shot) {
		if(shot != NULL && this != NULL) {

			Shot tmp = this->head;

			while(tmp != NULL) {
			
				//Active le texturage 2D
				glEnable(GL_TEXTURE_2D);
				//appel de la texture
				glBindTexture(GL_TEXTURE_2D, *shot);

					int xm1, xm2, ym1, ym2;
					xm1 = tmp.getX() + 5;
					xm2 = tmp.getX() - 5;
					ym1 = tmp.getY() + 5;
					ym2 = tmp.getY() - 5;

					glPushMatrix();
						glBegin(GL_QUADS);
						//coordonée de la texture
						glTexCoord2f(1, 0);
						//Cordonnée du quadrilatère 
						glVertex2f(xm1, ym1);

						glTexCoord2f(1, 1);
						glVertex2f(xm1, ym2);

						glTexCoord2f(0, 1);
						glVertex2f(xm2, ym2);

						glTexCoord2f(0, 0);
						glVertex2f(xm2, ym1);

						glEnd();
					glPopMatrix();

				//Déblinder la texture
				glBindTexture(GL_TEXTURE_2D, 0);
				//Désactive le texturage 2D
				glDisable(GL_TEXTURE_2D);

				tmp = tmp.getNext();
			}
		}
		else {
			fprintf(stderr, "Erreur : al texture du shot ou la liste de shot n'existe pas\n");
			return 0;
		}
		return 1;
	}
}								

/************* Collision entre le missile et l'ennemie *************/
/* Vérifie si le missile entre en collision avec le missile. Si oui supprime le missile et   	*
*  déduit les points de vie du monstre. Prend en paramètre la liste de monstre et le monstre.   *
*  Retourne 0 en cas d'erreur et 1 sinon.							*/

int collisionMissile(listShot p_lshot, listMonster p_lmonster, Joueur interface, Monster monster, int propriete) {

	//On vérifie si notre liste a été allouée
	if(p_lshot != NULL) {

		Shot* shotSuppr = NULL;
			
		//Créer un pointeur missile temporaire pour parcourir la liste de missiles
		Shot *p_tmp = p_lshot->p_head;

		//Parcours la liste de missiles
		while(p_tmp != NULL){

			//Vérifie s'il y a une intersection pour les quatres coté du quads du monstre
			Position point1, point2, pointC1, pointC2;

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