#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/shot.h"

Shot::Shot(){
	this->target = NULL;
	this->tower = NULL;
}

//Get
Shot* Shot::get(){
	return this;
}
float Shot::getX(){
	return this->x;
}
float Shot::getY(){
	return this->y;
}
Monster* Shot::getTarget(){
	return this->target;
}
Tower* Shot::getTower(){
	return this->tower;
}
int Shot::getPower(){
	return this->tower->getPower();
}
towerType Shot::getType(){
	return this->tower->getType();
}

Shot* Shot::getPrev(){
	return this->prev;
}
Shot* Shot::getNext(){
	return this->next;
}

//Set
void Shot::set(Shot* s){
	this->setX(s->getX());
	this->setY(s->getY());
	this->setTarget(s->getTarget());
	this->setTower(s->getTower());
	this->setPrev(s->getPrev());
	this->setNext(s->getNext());
}
void Shot::setX(float x){
	this->x = x;
}
void Shot::setY(float y){
	this->y = y;
}
void Shot::setTarget(Monster* m){
	this->target = m;
}
void Shot::setTower(Tower* t){
	this->tower = t;
}
void Shot::setPrev(Shot* s){
	this->prev = s;
}
void Shot::setNext(Shot* s){
	this->next = s;
}



listShot::listShot(){
	this->length = 0;
	this->head->set(NULL);
	this->tail->set(NULL);
}
int listShot::getLength(){
	return this->length;
}
Shot* listShot::getHead(){
	return this->head;
}
Shot* listShot::getTail(){
	return this->tail;
}
void listShot::setLength(int l){
	this->length = l;
}
void listShot::setHead(Shot* s){
	this->head = s;
}
void listShot::setTail(Shot* s){
	this->tail = s;
}

/* Ajoute tirs */
int listShot::addShot(Monster* monster, Tower* tower) {
	if(this != NULL) {
		if(monster != NULL) {
			if(tower != NULL) {

				Shot* shot;
				shot->setTower(tower);
				shot->setTarget(monster); 
		
				shot->setNext(NULL); 

					if (this->tail == NULL) {
						this->setHead(shot); 
						shot->setPrev(NULL);
					}
					//Cas où des éléments sont déjà présents dans la  liste
					else {
						//Pointe p_prev du nouveau missile sur le dernier missile de la liste
						shot->setPrev(this->tail); 

						//Relie le dernier missile de la liste au nouveau missile
						this->tail->setNext(shot);  
					}

					//Pointe la fin de la liste sur le nouveau missile
					this->tail->set(shot); 

					//On augmente de 1 la taille de la liste
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
/* Déplacements tirs */
int listShot::moveShot() {
	if(this != NULL) {
		Shot* tmp = this->head;

		//Parcourt la liste de missiles
		while(tmp != NULL){

			Position point_target;
			if(tmp->getTarget() != NULL) {

				point_target.set(tmp->getTarget()->getX(), tmp->getTarget()->getY());
			}
			else {
				point_target.set(810, 100);
			}

			Position point_shot;
			point_shot.set(tmp->getX(), tmp->getY());

			//Créer un vecteur avec la position du missile et la position de l'ennemi
			Vector vector = Vector(point_shot, point_target);
			//Normalise le vecteur pour avoir une norme de 1
			vector.normalize();
			//Ajoute le vecteur normalisé au point qui représente la position du missile pour le déplacer
			point_shot.addVector(vector);

			tmp->setX(point_shot.getX());
			tmp->setY(point_shot.getY());

			tmp = tmp->getNext();
		}

	}
	else {
		fprintf(stderr, "La liste de missiles n'existe pas ou est vide\n");
		return 0;
	}

	return 1;
}
/* Supprime tirs */
void listShot::removeShot(Shot* shot) {
	if (this != NULL) {
		if(shot != NULL) {
			if (shot->getNext() == NULL) {
				
				this->setTail(shot->getPrev());
				if(this->getTail() != NULL) {
					//Lien de le dernier missile vers le missile suivant est NULL
					this->getTail()->setNext(NULL);
				}
				else 
					this->setHead(NULL);
					
			}else if (shot->getPrev() == NULL) {
				//Pointe la tête de la liste vers le missile suivant
				this->setHead(shot->getPrev());
				if(this->getHead() != NULL) {
					//Le lien vers de le deuxième missile vers le missile précédent est NULL
			 		this->getHead()->setPrev(NULL);
				}
				else 
					this->setTail(NULL);
			}
			else {
				//Relie le missile suivant au missile précédent du missile que l'on veut supprmer 
				shot->getNext()->setPrev(shot->getPrev());
				//Relie le missile précédent au missile suivant du missile que l'on veut supprmer 
				shot->getPrev()->setNext(shot->getNext());
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
/* Supprime tous les tirs */
void listShot::removeAllShot () {
	//Si la liste n'est pas vide
	if (this->length != 0) {

		//Tant que la liste n'est pas vide
		while (this->head != NULL) {
			this->removeShot(this->head);
		}
		
	}
}
/* Libère espace mémoire */
void listShot::freeAllShot () {
		//Si la liste n'est pas vide
		if (this->length != 0) {

			//Tant que la liste n'est pas vide
			while (this->head != NULL) {
				this->removeShot(this->head);
			}
			
		}
		free(this);
}
/* Dessine tirs */
int listShot::draw(GLuint* shot) {
	if(shot != NULL && this != NULL) {

		Shot* tmp = this->head;

		while(tmp != NULL) {
		
			//Active le texturage 2D
			glEnable(GL_TEXTURE_2D);
			//Appel de la texture
			glBindTexture(GL_TEXTURE_2D, *shot);

				int xm1, xm2, ym1, ym2;
				xm1 = tmp->getX() + 5;
				xm2 = tmp->getX() - 5;
				ym1 = tmp->getY() + 5;
				ym2 = tmp->getY() - 5;

				glPushMatrix();
					glBegin(GL_QUADS);
					//Coordonée de la texture
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

			tmp = tmp->getNext();
		}
	}
	else {
		fprintf(stderr, "Erreur : al texture du shot ou la liste de shot n'existe pas\n");
		return 0;
	}
	return 1;
}
								
/************* Collision entre le missile et l'ennemi *************/
/* Vérifie si le missile entre en collision avec le missile. Si oui supprime le missile et   	*
*  déduit les points de vie du monstre. Prend en paramètre la liste de monstre et le monstre.   *
*  Retourne 0 en cas d'erreur et 1 sinon.														*/
bool collisionMissile(listShot* shots, listMonster* monsters, Joueur* joueur, Monster *monster, Propriete *propriete) {

	//On vérifie si notre liste a été allouée
	if(shots != NULL) {

		Shot* shotSuppr = NULL;
			
		//Créer un pointeur missile temporaire pour parcourir la liste de missiles
		Shot *tmp = shots->getHead();

		//Parcourt la liste de missiles
		while(tmp != NULL){

			//Vérifie s'il y a une intersection pour les quatres coté du quads du monstre
			Position point1;
			Position point2;
			Position pointC1; 
			Position pointC2;

			pointC1.set(tmp->getX()+5, tmp->getY()+5);
			pointC2.set(tmp->getX()-5, tmp->getY()-5);
				
			if(tmp->getTarget() == NULL) {

				if(tmp->getX() < 180 || tmp->getX() > 800 || tmp->getY() < 40 || tmp->getY() > 660)
					shots->removeShot(tmp);
	
				tmp = tmp->getNext();
			}
			else {
			
				point1.set(tmp->getTarget()->getX() + 20, tmp->getTarget()->getY() + 20);
				point2.set(tmp->getTarget()->getX() - 20, tmp->getTarget()->getY() - 20);

				//Vérifie s'il y a une intersection
				if(intersectionCarres(point1, point2, pointC1, pointC2)) {
					
					uint new_PV;
					towerType type = tmp->getType();

					//On change les dégats selon la tour et la resistance
					switch(type){
						case oceane:
							new_PV = tmp->getPower()*(1-tmp->getTarget()->getResistance_TDR());
							break;

						case clara:
							new_PV = tmp->getPower()*(1-tmp->getTarget()->getResistance_TDV());
							break;

						case jules:
							new_PV = tmp->getPower()*(1-tmp->getTarget()->getResistance_TDJ());
							break;

						case yoann:
							new_PV = tmp->getPower()*(1-tmp->getTarget()->getResistance_TDB());
							break;

						default:break;
					}

					tmp->getTarget()->setPV(new_PV); //Changer les points de vie

					if(tmp->getTarget()->getPV() <= 0){
					
						tmp->getTarget()->setPV(0);

						//Met à jours l'interface (money, score, nbmonstre tués)
						joueur->updateMonsterKill(tmp->getTarget());

						//Créer un pointeur missile temporaire pour parcourir la liste de missiles
						Shot *tmp_shot = shots->getHead();

						//Parcourt la liste de missiles
						while(tmp_shot != NULL){

							if(tmp_shot != tmp) {
								if(tmp_shot->getTarget()->isSame(tmp->getTarget())) 
									tmp_shot->setTarget(NULL);
							}

							tmp_shot = tmp_shot->getNext();

						}

						if(monster->isSame(tmp->getTarget())){
							monster->set(NULL);
							*propriete = aucune;
						}
						//Retire le monstre de la liste de monstre
						monsters->removeMonster(tmp->getTarget());
						tmp->setTarget(NULL);
					
					}

					shotSuppr = tmp;
					tmp = tmp->getNext();

					if(shotSuppr != NULL)
						shots->removeShot(shotSuppr); //Retire le missile de la liste
			
				}
				else
					tmp = tmp->getNext();
			}
	
		}

	}
	else {
		fprintf(stderr, "Cette liste de missiles n'existe pas\n");
		return 0;
	}
	return 1;
}