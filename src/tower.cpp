#include "../include/tower.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//Constructeur
Tower::Tower(){
    this->p = NULL;
    this->prev = NULL;
    this->next = NULL;
}
//Get
Position* Tower::getPosition(){
    return this->p;
}

float Tower::getPower(){
	if(instNear[usine])
		return 1.25*this->power;
	else{
		return this->power;
	}
}
float Tower::getRange(){
	if(instNear[radar])
		return 1.25*this->range;
	else{
		return this->range;
	}
}
float Tower::getRate(){
	if(instNear[stock])
		return 1.25*this->rate;
	else
		return this->rate;
}
uint Tower::getCost(){
	return this->cost;
}
int Tower::getCompteur(){
    return this->compteur;
}
Tower* Tower::getNext(){
    return this->next;
}
Tower* Tower::getPrev(){
    return this->prev;
}

//Set
void Tower::set(Tower* t){
    this->setPower(t->getPower());
    this->setRange(t->getRange());
    this->setRate(t->getRate());
    this->setPosition(t->getPosition());
    this->setCompteur(t->getCompteur());
    this->setPrev(t->getPrev());
    this->setNext(t->getNext()); 
}

void Tower::setPower(int p){
	this->power = p;
}
void Tower::setRange(float rg){
	this->range = rg;
}
void Tower::setRate(int rt){
	this->rate=rt;
}
void Tower::setCost(uint cost){
    this->cost = cost;
}
void Tower::setPosition(Position* p){
    this->p = p;
}
void Tower::setCompteur(int a){
    this->compteur = a;
}
void Tower::setNext(Tower* tower){
    this->next = tower;
}
void Tower::setPrev(Tower* tower){
    this->prev = tower;
}
void Tower::setInstNear(installationType a, bool val){
    this->instNear[a] = val;
}
int Tower::drawProprieteTower(GLuint* tower, GLuint* spriteMenu, GLuint* btPlus, Joueur* joueur) {

    int type = this->type;

    float x1 = 0;
    float x2 = 1;
    float y1 = (type * (1.0/4.0));
    float y2 = (type * (1.0/4.0)) + 0.25;

    //Active le texturage 2D
    glEnable(GL_TEXTURE_2D);
    //appel de la texture
    glBindTexture(GL_TEXTURE_2D, *tower);

        glBegin(GL_QUADS);
        //couleur neutre
        glColor3ub(255,255,255);
        //coordonée de la texture
        glTexCoord2f(x2, y1);
        //Cordonnée du quadrilatère 
        glVertex2f(20, 300);

        glTexCoord2f(x2, y2);
        glVertex2f(20, 340);

        glTexCoord2f(x1, y2);
        glVertex2f(60, 340);

        glTexCoord2f(x1, y1);
        glVertex2f(60, 300);


        glEnd();

    //Déblinder la texture
    glBindTexture(GL_TEXTURE_2D, 0);
    //Désactive le texturage 2D
    glDisable(GL_TEXTURE_2D);


    char* machaine;

    /**** Cadence ****/

    glColor4f(255,255,255, 1);
    //Convertie un int en un string
    sprintf(machaine,"%f",this->rate);

    writeString(20, 390,  "Cadence : ");
    //Affiche la chaine de caractère
    writeString(120, 390,  machaine);

    /**** Portée ****/

    glColor4f(255,255,255, 1);
    //Convertie un int en un string
    sprintf(machaine,"%f",this->range);

    writeString(20, 415,  "Range : ");
    //Affiche la chaine de caractère
    writeString(120, 415,  machaine);

    /**** Puissance ****/

    glColor4f(255,255,255, 1);
    //Convertie un int en un string
    sprintf(machaine,"%f",this->power);

    writeString(20, 440,  "Puissance : ");
    //Affiche la chaine de caractère
    writeString(120, 440,  machaine);

    /**** type de la tour ****/
    glColor4f(255,255,255, 1);
    char* typeTour = "";

    //Choisir le bon monstre dans le sprite
    if(this->type == oceane) 
        typeTour = "Océane (Archer)";
    else if(this->type == jules) 
        typeTour = "Jules (Multidirectionnelle)";
    else if(this->type == clara) 
        typeTour = "Clara (Laser)";
    else if(this->type == yoann) 
        typeTour = "Yoann (Rocket)";

    writeString(20, 465,  "Type : ");
    //Affiche la chaine de caractère
    writeString(80, 465,  typeTour);

    return 1;

}

int Tower::reach(listShot *shots, listMonster *monsters) {
    if(shots != NULL) {
        if(monsters != NULL){
            if(this->type != jules) {

                Monster* monster = NULL;

                //Variables pour savoir qui est le plus proche
                Position pointIntersection, pointProche, point1, point2;
                Vector vectorIntersection, vectorProche;
                float normeIntersection, normeProche = -1;

                //Création d'un monstre temporaire pour parcourir la liste de monstres
                Monster* tmp = monsters->getHead();

                //Parcours la liste de monstres
                while(tmp != NULL){

                    Position point; //centre
                    point.set(this->getPosition()->getX(), this->getPosition()->getY());

                    point1.set(tmp->getX() + 20, tmp->getY() + 20);
                    point2.set(tmp->getX() - 20, tmp->getY() - 20);

                    //Vérifie s'il y a une intersection
                    if(intersectionCarreDisque (point1, point2, this->range, point)) {

                        pointIntersection.set(tmp->getX(), tmp->getY());
                        

                        Vector vectorIntersection;
                        vectorIntersection.getVector2D(point, pointIntersection);
                        normeIntersection = vectorIntersection.getNorm();
            
                        //S'il n'y a pas de point d'intersection avant
                        if(normeProche == -1) {
                            Vector vectorProche;
                            vectorProche.getVector2D(point, pointProche);
                            normeProche = vectorProche.getNorm();
                            monster = tmp;
                        }
                        //Si la distance du nouveau point d'intersection est plus proche que celle stocker
                        if(normeIntersection < normeProche) {
                            vectorProche = vectorIntersection;
                            normeProche = normeIntersection;
                            monster = tmp;
                        }

                    }
                    tmp = tmp->getNextM();
                }

                if(monster != NULL)
                    shots->addShot(monster, this);

                return 1;

            }
            else {
            
                //Création d'un monstre temporaire pour parcourir la liste de monstres
                Monster* tmp = monsters->getHead();

                //Parcours la liste de monstres
                while(tmp != NULL){

                    Position point, point1, point2;
                    point.set(this->getPosition()->getX(), this->getPosition()->getY()); //centre
                    point1.set(this->getPosition()->getX() + 20, this->getPosition()->getY() + 20); //centre
                    point2.set(this->getPosition()->getX() - 20, this->getPosition()->getY() - 20); //centre

                    //Vérifie s'il y a une intersection
                    if(intersectionCarreDisque (point1, point2, this->range, point) == 1)
                        shots->addShot(tmp, this); //Ajout d'un shot à la liste

                    tmp = tmp->getNextM();

                }   
                return 1;
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

bool Tower::isSame(Tower* t){
    if(this->p->getX() != t->getPosition()->getX()){
        return 0;
    }
    if(this->p->getY() != t->getPosition()->getY()){
        return 0;
    }
    if(this->type != t->getType()){
        return 0;
    }
    if(this->power != t->getPower()){
        return 0;
    }
    if(this->rate != t->getRate()){
        return 0;
    }
    if(this->cost != t->getCost()){
        return 0;
    }
    if(this->compteur != t->getCompteur()){
        return 0;
    }

    return 1;
}



Yoann::Yoann(float range, float rate, uint cost, float power){
	this->setRange(range);
	this->setRate(rate);
	this->setCost(cost);
	this->setPower(power);
    this->setCompteur(0);
}

towerType Yoann::getType(){
	return yoann;
}



Clara::Clara(float range, float rate, uint cost, float power){
	this->setRange(range);
    this->setRate(rate);
    this->setCost(cost);
    this->setPower(power);
    this->setCompteur(0);
}

towerType Clara::getType(){
	return clara;
}



Jules::Jules(float range, float rate, uint cost, float power){
	this->setRange(range);
    this->setRate(rate);
    this->setCost(cost);
    this->setPower(power);
    this->setCompteur(0);
}

towerType Jules::getType(){
	return jules;
}



Oceane::Oceane(float range, float rate, uint cost, float power){
	this->setRange(range);
    this->setRate(rate);
    this->setCost(cost);
    this->setPower(power);
    this->setCompteur(0);
}

towerType Oceane::getType(){
	return oceane;
}


listTower::listTower(){
    this->length = 0;
    this->head = NULL;
    this->tail = NULL;
}

int listTower::getLength(){
    return this->length;
}

Tower* listTower::getHead(){
    return this->head;
}

Tower* listTower::getTail(){
    return this->tail;
}

void listTower::setLength(int a){
    this->length = a;
}

void listTower::setHead(Tower* t){
    this->head = t;
}

void listTower::setTail(Tower* t){
    this->tail = t;
}


int listTower::addTower(towerType type, Position* p) {

    Tower* tower;
    switch(type){
        case (int)yoann:
            tower = new Yoann();
            break;
        case (int)clara:
            tower = new Clara();
            break;
        case (int)jules:
            tower = new Jules();
            break;
        case (int)oceane:
            tower = new Oceane();                    
            break;
        default: break;
    }

    tower->setPosition(p);
    tower->setNext(NULL);

    if(this->tail == NULL){
        this->head = tower;
        tower->setPrev(NULL);
    }else{
        tower->setPrev(this->tail);
        this->tail->setNext(tower);
    }

    this->setTail(tower);
    this->length++;

    return 1;
}

int listTower::moveTower(Tower* tower, listNode* list_node, float x, float y) {
    if(tower != NULL) {
        Position* pos;
        pos->set(x, y);
        tower->setPosition(pos);
    
        Position p1, p2;

        p1.set(x+15, y+20);
        p2.set(x-15, y-20);

        if(list_node->verificationConstruct(p1, p2) == 1) {

            p1.setX(x+20);
            p1.setY(y+20);
            p2.setX(x-20);
            p2.setY(y-20);

            //Si ce n'est pas le premier de la liste
            if(tower->getPrev() != NULL){

                Position p3, p4;
                //Créer une tour temporaire pour parcourir la liste
                Tower* tmp = this->head;

                //Parcour de la liste
                while(tmp->getNext() != NULL) {

                    p3.setX(tmp->getPosition()->getX()+20);
                    p3.setY(tmp->getPosition()->getY()+20);
                    p4.setX(tmp->getPosition()->getX()-20);
                    p4.setY(tmp->getPosition()->getY()-20);

                    //Vérifie qu'il ne se trouve pas sur une autre tour (pas d'intersection)
                    if(intersectionCarres (p1, p2, p3, p4) == 0)
                        tmp = tmp->getNext();
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

    return 0;

}

void listTower::removeTower(Tower* tower) {
    if(tower != NULL) {

        //Si c'est la dernière tour de la liste
        if (tower->getNext() == NULL) {
            
            //Set la fin de la liste sur la tour précédente
            this->tail->set(tower->getPrev());

            if(this->tail != NULL) {
                //Lien de la dernière tour vers la tour suivante est NULL
                this->tail->setNext(NULL);
            }
            else
                this->head->set(NULL);
                
        }
    
        //Si c'est la première de la liste
        else if (tower->getPrev() == NULL) {
            //Set la tête de la liste sur la tour suivante
            this->head->set(tower->getNext());

            if(this->head != NULL) {
                //Le lien vers de la deuxième tour vers la tour précédente est NULL
                this->head->setPrev(NULL);
            }
            else
                this->tail->set(NULL);
        }

        else {
            //Relie la tour suivante à la tour précédente de la tour que l'on veut supprmer 
            tower->getNext()->setPrev(tower->getPrev());
            //Relie la tour précédente à la tour suivante de la tour que l'on veut supprmer 
            tower->getPrev()->setNext(tower->getNext());

        }
        //Libère espace mémoire : supprime la tour
        free(tower);
        //Décrémente de 1 la taille de la liste
        this->length--;

    }
    else
        fprintf(stderr, "Cette tour n'existe pas");
}


void listTower::removeAllTower() {
//Si la liste n'est pas vide
    if (this->length != 0) {

        //Tant que la liste n'est pas vide
        while (this->head != NULL) {
            this->removeTower(this->getHead());
        }
        
    }
}   

void listTower::freeAllTower() {
    //Si la liste n'est pas vide
    if (this->length != 0) {

        //Tant que la liste n'est pas vide
        while (this->head != NULL) {
            this->removeTower(this->head);
        }
        
    }
    free(this);
}