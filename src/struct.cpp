#include"../include/struct.h"
#include <stdlib.h>
#include <math.h>

Position::Position(){
	this->x = x=0;
	this->y = y=0;
}

Position Position::get(){
	return this;
}

float Position::getX(){
	return x;
}

float Position::getY(){
	return y;
}

void Position::set(float x, float y){
	this->x = x;
	this->y = y;
}

void Position::setX(float x){
	this->x = x;
}

void Position::setY(float y){
	this->y = y;
}

void Position::addVector(Vector V) {		
	this->x += (V.getX());
	this->y += (V.getY());
}



Vector::Vector(Position A, Position B){
	this.x = (B.getX()) - (A.getX());
	this.y = (B.getY()) - (A.getY());
}

Vector Vector::get(){
	return this;
}

float Vector::getX(){
	return this->x;
}

float Vector::getY(){
	return this->y;
}

float Vector::getNorm() {
	float norme;

	norme = pow(this->x, 2.0) pow(this->y, 2.0);
	norme = sqrt(norme);
	return norme;
}

void Vector::setX(float x){
	this->x = x;
}
void Vector::setY(float y){
	this->y = y;
}

void Vector::normalize(){
	float norme = this.getNorm();	
	this->x = (this->x) / norme;
	this->y = (this->y) / norme;
}



Node::Node(){
	this->pos = Position();
	this->next = NULL;
}
Position Node::getPosition(){
	return this->pos;
}

float Node::getX(){
	return this->pos.getX();
}

float Node::getY(){
	return this->pos.getY();
}

Node* Node::getNext(){
	return this->next;
}

void Node::createNode(float x, float y){
	this->x = x;
	this->y = y;
}

void Node::setPosition(Position p){
	this->pos = p;
}
void Node::setX(float a){
	this->x = a;
}
void Node::setY(float a){
	this->y = a;
}
void Node::setNext(Node node){
	this->next = node;
}





listNode::listNode(){
	this=NULL;
}

int listNode::getLength(){
	return this->length;
}

Node* listNode::getHead(){
	return this->head;
}

Node* listNode::getTail(){
	return this->tail;
}

void listNode::setLength(int a){
	this->length = a;
}

void listNode::setHead(Node* node){
	this->head = node;
}

void listNode::setTail(Node* node){
	this->tail = node;
}

bool intersectionCarreDisque (Position point1, Position point2, float rayon, Position origin) {

	int i;
	Position point = Position(0, 0);

	for(i = 0; i < 4; i++) {

		//Vérifie avec les quatres points du quad
		switch(i) {
			case 0 :
				point.set(point1.getX(), point1.getY());
				break;
			case 1 :
				point.set(point1.getX(), point2.getY());
				break;
			case 2 :
				point.set(point2.getX(), point2.getY());
				break;
			case 3 :
				point.set(point2.getX(), point1.getY());
				break;
			default :
				break;

		}

		if(pow((point.getX() - origin.getX()), 2.0) + pow((point.getY() - origin.getY()), 2.0) - pow(rayon, 2.0) <= 0)
			return 1;

	}

	return 0;
}

bool intersectionCarres (Position point1, Position point2, Position pointC1, Position pointC2) {

	int i;
	Position point = Position(0, 0);

	int xmin = ((point1.getX()) < (point2.getX())) ? (point1.getX()) : (point2.getX());
	int xmax = ((point1.getX()) > (point2.getX())) ? (point1.getX()) : (point2.getX());

	int ymin = ((point1.getY()) < (point2.getY())) ? (point1.getY()) : (point2.getY());
	int ymax = ((point1.getY()) > (point2.getY())) ? (point1.getY()) : (point2.getY());

	for(i = 0; i < 4; i++) {

		//Vérifie avec les quatres points du quad
		switch(i) {
			case 0 :
				point.getX() = pointC1.getX(); point.getY() = pointC1.getY();
				break;
			case 1 :
				point.getX() = pointC1.getX(); point.getY() = pointC2.getY();
				break;
			case 2 :
				point.getX() = pointC2.getX(); point.getY() = pointC2.getY();
				break;
			case 3 :
				point.getX()= pointC2.getX(); point.getY() = pointC1.getY();
				break;
			default :
				break;

		}

		if(point.getX() <= xmax && point.getX() >= xmin && point.getY() <= ymax && point.getY() >= ymin)
			return 1;

	}

	return 0;
}



Image::Image(char* nameImg) {

		FILE* image = NULL;
		image = fopen(nameImg, "r");
		int test;	

		if(image == NULL){
			fprintf(stderr, "Erreur : Impossible d'ouvrir l'image\n");
			return 0;
		}
		else{

			//Récupère le type d'image
			if(fscanf(image, "%c%c\n", &(this->magicNumber[0]),  &(this->magicNumber[1])) == 2){

				//Si ce n'est pas un ppm, arrete la fonction 
				if(this->magicNumber[0] != 'P' || this->magicNumber[1] != '6'){
					fprintf(stderr, "L'image n'est pas au bon format\n");
					return 0;
				}
				else {
				
					//Vérifier s'il y a un commentaire
					do {
						//Récupère la hauteur et la largeur && test = 1 s'il trouve une variable sinon retourne 0
						test = fscanf(image, "%d %d\n", &(this->widthImg), &(this->heightImg));
					
						//Si c'est une ligne de commentaire
						if(test == 0) {
							char* letter;
							//Passe la ligne : parcours la ligne jusqu'à qu'il trouve '\n'
							do {
								if(fread(&letter,sizeof(char*),1,image)!=1)
									printf("erreur\n");
							}while(*letter != '\n');
						}			
					}while(test<1);

					//Récupérer la résolution de la couleur
					if(fscanf(image, "%d\n", &(this->maxValue)) == 1){
					
						// On ferme le vide le buffer et on ferme l'image
						fflush(image);
						fclose(image);

					}
					else {
						fprintf(stderr, "Probleme ce n'est pas la valeur maximal du fichier\n");
						return 0;
					}

				}
			}
			else {
				fprintf(stderr, "Probleme ce n'est pas le numéro magique du fichier\n");
				return 0;
			}
		}
		return 1;
	}