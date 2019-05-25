#include"../include/struct.h"
#include <stdlib.h>
#include <math.h>

/*************************************************
					POSITION 
***!************************************************/
Position::Position(){
	this->x = 0;
	this->y = 0;
}
//Get
Position* Position::get(){
	return this;
}

float Position::getX(){
	return x;
}

float Position::getY(){
	return y;
}
//Set
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
//Fonction
void Position::addVector(Vector V) {		
	this->x += (V.getX());
	this->y += (V.getY());
}


/*************************************************
					VECTOR 
***!************************************************/


Vector::Vector(){
	this->x = NULL;
	this->y = NULL;
}
//Get
Vector* Vector::get(){
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

	norme = pow(this->x, 2.0) + pow(this->y, 2.0);
	norme = sqrt(norme);
	return norme;
}
//Set
void Vector::setX(float x){
	this->x = x;
}
void Vector::setY(float y){
	this->y = y;
}
//Fonction
void Vector::normalize(){
	float norme = this->getNorm();	
	this->x = (this->x) / norme;
	this->y = (this->y) / norme;
}

void Vector::getVector2D(Position A, Position B) {
	
	this->setX(B.getX() - A.getX());
	this->setY(B.getY() - A.getY());
}


/*************************************************
					NODE 
***!************************************************/


Node::Node(){
	this->pos = NULL;
	this->next = NULL;
}
//Get
Position* Node::getPosition(){
	return this->pos;
}

float Node::getX(){
	return this->pos->getX();
}

float Node::getY(){
	return this->pos->getY();
}

Node* Node::getNext(){
	return this->next;
}
void Node::createNode(float x, float y){
	this->pos->setX(x);
	this->pos->setY(y);
}
//Set 
void Node::setPosition(Position* p){
	this->pos = p;
}
void Node::setX(float a){
	this->pos->setX(a);
}
void Node::setY(float a){
	this->pos->setY(a);
}
void Node::setNext(Node* node){
	this->next = node;
}


/*************************************************
					LISTNODE 
***!************************************************/


listNode::listNode(){
	this->length = 0;
	this->head=NULL;
	this->tail=NULL;
}
//Get
int listNode::getLength(){
	return this->length;
}

Node* listNode::getHead(){
	return this->head;
}

Node* listNode::getTail(){
	return this->tail;
}
//Set
void listNode::setLength(int a){
	this->length = a;
}

void listNode::setHead(Node* node){
	this->head = node;
}

void listNode::setTail(Node* node){
	this->tail = node;
}
//Fonction

int listNode::verificationConstruct(Position point1, Position point2) {

	int i, test = 0;
	Position point;

	for(i = 0; i < 4; i++) {

		//Vérifie avec les quatres points du quad
		switch(i) {
			case 0 : 
				point.setX(point1.getX()); point.setY(point1.getY());
				break;
			case 1 : 
				point.setX(point1.getX()); point.setY(point2.getY());
				break;
			case 2 :
				point.setX(point2.getX()); point.setY(point2.getY());
				break;
			case 3 :
				point.setX(point2.getX()); point.setY(point1.getY());
				break;
		}

		//Créer un pointeur temporaire node pour parcourir la liste de noeud
		Node* tmp = this->head;

		while(tmp != NULL){

			if(point.getX() == tmp->getX() && point.getY() == tmp->getY())
				test++;

			tmp = tmp->getNext();
		}

	}

	//Si les 4 extremité sont dans la zone constructible
	if(test < 4)
		return 0;
	return 1;

}
bool listNode::addNode(float x, float y) {

	//On vérifie si notre liste a été allouée
	if (this != NULL) {
		//Création d'un nouveau noeud
		Node* tmp;

		tmp->setY(x); 
		tmp->setX(y); 
		//Rajoute à la fin : dernier élement de la liste 
		tmp->setNext(NULL); 

		//Cas où notre liste est vide (pointeur vers fin de liste à  NULL)
		if (this->getHead() == NULL) 
			this->setHead(NULL); // Pointe la tête de la liste sur le nouveau noeud

		//Cas où des éléments sont déjà présents dans la  liste
		else 
			this->getHead()->setNext(tmp);  // Relie le dernier calque de la liste au nouveau noeud

		//Pointe la fin de la liste sur le nouveau noeud
		this->setTail(tmp); 

		//On augmente de 1 la taille de la liste
		this->setLength(this->getLength()+1); 
	}
	else {
		printf("Cette liste de noeuds n'existe pas\n");
		return 0;
	}

	return 1; 
}

void listNode::removeNode(Node* node) {

	if(node != NULL) {

		//Pointe la tête de la liste vers le noeud suivante
		this->setHead(node->getNext());

		if(this->head == NULL) 
			this->setTail(NULL);
		
		free(node);
		this->length--;
	}
	else
		fprintf(stderr, "Ce noeud n'existe pas");
}

void listNode::freeAllNode () {
	//Si la liste n'est pas vide
	if (this->length != 0) {

		//Tant que la liste n'est pas vide
		while (this->head != NULL) {
			this->removeNode(this->head);
		}
		
	}
	free(this);
}


/*************************************************
					AUTRES FONCTIONS 
***!************************************************/

bool intersectionCarreDisque (Position point1, Position point2, float rayon, Position origin) {

	int i;
	Position point = Position();

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
	Position point = Position();

	int xmin = ((point1.getX()) < (point2.getX())) ? (point1.getX()) : (point2.getX());
	int xmax = ((point1.getX()) > (point2.getX())) ? (point1.getX()) : (point2.getX());

	int ymin = ((point1.getY()) < (point2.getY())) ? (point1.getY()) : (point2.getY());
	int ymax = ((point1.getY()) > (point2.getY())) ? (point1.getY()) : (point2.getY());

	for(i = 0; i < 4; i++) {

		//Vérifie avec les quatres points du quad
		switch(i) {
			case 0 :
				point.setX(pointC1.getX()); point.setY(pointC1.getY());
				break;
			case 1 :
				point.setX(pointC1.getX()); point.setY(pointC2.getY());
				break;
			case 2 :
				point.setX(pointC2.getX()); point.setY(pointC2.getY());
				break;
			case 3 :
				point.setX(pointC2.getX()); point.setY(pointC1.getY());
				break;
			default :
				break;

		}

		if(point.getX() <= xmax && point.getX() >= xmin && point.getY() <= ymax && point.getY() >= ymin)
			return 1;

	}

	return 0;
}


/**************************************************
						IMAGE 
***!************************************************/
Image::Image(char* nameImg) {

		FILE* image = NULL;
		image = fopen(nameImg, "r");
		int test;	

		if(image == NULL){
			fprintf(stderr, "Erreur : Impossible d'ouvrir l'image\n");
		}
		else{

			//Récupère le type d'image
			if(fscanf(image, "%c%c\n", &(this->magicNumber[0]),  &(this->magicNumber[1])) == 2){

				//Si ce n'est pas un ppm, arrete la fonction 
				if(this->magicNumber[0] != 'P' || this->magicNumber[1] != '6'){
					fprintf(stderr, "L'image n'est pas au bon format\n");
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
					
						//On ferme l'image
						fflush(image);
						fclose(image);

					}
					else {
						fprintf(stderr, "Probleme ce n'est pas la valeur maximal du fichier\n");
					}
				}
			}
			else {
				fprintf(stderr, "Probleme ce n'est pas le numéro magique du fichier\n");
			}
		}
	}
//Get
char* Image::getPath(){
	return this->path;
}
char* Image::getMagicNumber(){
	return this->magicNumber;
}
uint Image::getHeight(){
	return this->heightImg;
}
uint Image::getWidth(){
	return this->widthImg;
}
int Image::getMaxValue(){
	return this->maxValue;
}

void Image::setPath(char* line){
	strcpy(this->path, line);
}
void Image::setMagicNumber(char* line){
	strcpy(this->magicNumber, line);
}
void Image::setHeight(uint nb){
	this->heightImg = nb;
}
void Image::setWidth(uint nb){
	this->widthImg = nb;
}
void Image::setMaxValue(int nb){
	this->maxValue = nb;
}


//Fonctions : gèrent couleurs
int Image::ChangeColor(unsigned char* tabPixels, Map* map) {
	this->changeColorRoad(tabPixels, map);
	this->changeColorConstruct(tabPixels, map);
	this->changeColorNode(tabPixels, map);
	this->changeColorIn(tabPixels, map);
	this->changeColorOut(tabPixels, map);
	return 1;

}

int Image::changeColorRoad(unsigned char* tabPixels, Map* map) {

	for(uint i=0; i<(this->heightImg); i++) {
		for(uint j=0; j<(this->widthImg); j++) {
			
			//On vérifie si la route est bien ()
			if(tabPixels[i*(this->widthImg)*3+j*3] == 255 && tabPixels[i*(this->widthImg)*3+j*3+1] == 0 && tabPixels[i*(this->widthImg)*3+j*3+2] == 0){

				//Change de couleur
				tabPixels[i*(this->widthImg)*3+j*3] = ((map->getPathColor()).getR())*255;
				tabPixels[i*(this->widthImg)*3+j*3+1] = ((map->getPathColor()).getG())*255;
				tabPixels[i*(this->widthImg)*3+j*3+2] = ((map->getPathColor()).getB())*255;
			}
		}
	}

	return 1;

}

int Image::changeColorConstruct(unsigned char* tabPixels, Map* map) {

	if(map->getListConstruct() != NULL) {

		for(uint i=0; i<(this->heightImg); i++) {
			for(uint j=0; j<(this->widthImg); j++) {
			
				if(tabPixels[i*(this->widthImg)*3+j*3] == 0 && tabPixels[i*(this->widthImg)*3+j*3+1] == 0 && tabPixels[i*(this->widthImg)*3+j*3+2] == 255){

					//Change de couleur
					tabPixels[i*(this->widthImg)*3+j*3] = ((map->getConstructColor()).getR())*255;
					tabPixels[i*(this->widthImg)*3+j*3+1] = ((map->getConstructColor()).getG())*255;
					tabPixels[i*(this->widthImg)*3+j*3+2] = ((map->getConstructColor()).getB())*255;

					//Ajoute le noeud à la liste de pixels avec les coordonnées
					map->getListConstruct()->addNode(j + 200, i + 60);
				}
			}
		}
	}
	else {
		fprintf(stderr, "Erreur : problème au moment de l'allocation pour la liste de pixels de la zone constructible\n");
		return 0;
	}

	return 1;

}

int Image::changeColorNode(unsigned char* tabPixels, Map* map) {

	for(uint i=0; i<(this->heightImg); i++) {

		// puis on parcourt les colonnes du tableau
		for(uint j=0; j<(this->widthImg); j++) {
			
			//On vérifie la couleur
			if(tabPixels[i*(this->widthImg)*3+j*3] == 6 && tabPixels[i*(this->widthImg)*3+j*3+1] == 0 && tabPixels[i*(this->widthImg)*3+j*3+2] == 255){

				//Change de couleur
				tabPixels[i*(this->widthImg)*3+j*3] = ((map->getConstructColor()).getR())*255;
				tabPixels[i*(this->widthImg)*3+j*3+1] = ((map->getConstructColor()).getG())*255;
				tabPixels[i*(this->widthImg)*3+j*3+2] = ((map->getConstructColor()).getB())*255;
			}
		}
	}

	return 1;

}

int Image::changeColorIn(unsigned char* tabPixels, Map* map) {

	for(uint i=0; i<(this->heightImg); i++) {

		// puis on parcourt les colonnes du tableau
		for(uint j=0; j<(this->widthImg); j++) {
			
			//On vérifie la couleur
			if(tabPixels[i*(this->widthImg)*3+j*3] == 255 && tabPixels[i*(this->widthImg)*3+j*3+1] == 0 && tabPixels[i*(this->widthImg)*3+j*3+2] == 67){

				//Change de couleur
				tabPixels[i*(this->widthImg)*3+j*3] = ((map->getInColor()).getR())*255;
				tabPixels[i*(this->widthImg)*3+j*3+1] = ((map->getInColor()).getG())*255;
				tabPixels[i*(this->widthImg)*3+j*3+2] = ((map->getInColor()).getB())*255;
			}
		}
	}

	return 1;

}

int Image::changeColorOut(unsigned char* tabPixels, Map* map) {

	for(uint i=0; i<(this->heightImg); i++) {

		// puis on parcourt les colonnes du tableau
		for(uint j=0; j<(this->widthImg); j++) {
			
			//On vérifie la couleur
			if(tabPixels[i*(this->widthImg)*3+j*3] == 255 && tabPixels[i*(this->widthImg)*3+j*3+1] == 252 && tabPixels[i*(this->widthImg)*3+j*3+2] == 0){

				//Change de couleur
				tabPixels[i*(this->widthImg)*3+j*3] = ((map->getOutColor()).getR())*255;
				tabPixels[i*(this->widthImg)*3+j*3+1] = ((map->getOutColor()).getG())*255;
				tabPixels[i*(this->widthImg)*3+j*3+2] = ((map->getOutColor()).getB())*255;
			}
		}
	}

	return 1;

}

int Image::openImg(char* nameImg) {

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

void Image::freeImage () {
	//Si l'interface existe
	if (this != NULL) {
		free(this->path);
		free(this);
	}
}