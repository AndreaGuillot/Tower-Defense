#ifndef STRUCT_H__
#define STRUCT_H__

#include <string.h>
#include <iostream>
#include "map.h"
#include "enum.h"

/************* Classes Vector et Map *************/
//Gère les éléments vectoriels
class Vector;
//Gère la map
class Map;

/************* Classe Position : gère position des éléments *************/
class Position {
	
	private: 
		float x;
		float y;

	public:
		//Constructeur
		Position();
		//Get
		Position* get();
		float getX();
		float getY();
		//Set
		void set(float x, float y);
		void setX(float x);
		void setY(float y);
		//Fonctions
		/* Crée vecteur */
		void addVector(Vector v);
};

class Vector {

	private: 
		float x;
		float y;

	public:
		//Constructeur
		Vector(Position a, Position b);

		//Get
		Vector* get();
		float getX();
		float getY();
		float getNorm();

		//Set
		void setX(float x);
		void setY(float y);

		//Fonctions
		void normalize();
};

/************* Classe Size : gère taille images *************/
class Size{
    float width;
    float height;
};


/************* Classe Node : gère les noeuds *************/
class Node {

	private: 
		//Propriétés
		Position pos;
		Node* next;

	public:
		//Constructeur
		Node();
		//Get
		Position getPosition();
		float getX();
		float getY();
		Node* getNext();
		//Set
		void createNode(float x, float y);
		void setPosition(Position p);
		void setX(float a);
		void setY(float a);
		void setNext(Node* node);
};

/************* Classe Node : gère les noeuds *************/
class listNode {

	int length;
	Node* head; //pointeur vers le premier element
	Node* tail; //pointeur vers le dernier element

	public:
		//Constructeur
		listNode();
		//Get
		int getLength();
		Node* getHead();
		Node* getTail();
		//Set
		void setLength(int a);
		void setHead(Node* node);
		void setTail(Node* node);
		//Fonctions
		/* Ajoute noeud */
		bool addNode(float x, float y);
};

//Calculent intersections
bool intersectionCarreDisque (Position point1, Position point2, float rayon, Position origin);
bool intersectionCarres (Position point1, Position point2, Position pointC1, Position pointC2);

/************* Classe Node : gère les noeuds *************/
class Image {

	private:
		//Chemin vers l'image
		char* path;
		//Numero magic : identifie le type de fichier
		char magicNumber[2];
		//Les dimensions de l'images
		unsigned int heightImg;
		unsigned int widthImg;
		//Valeur maximal de la couleur, résolution de la couleur
		int maxValue;

	public:
		//Constructeur
		Image(char* nameImg);
		//Get
		char* getPath();
		char* getMagicNumber();
		uint getHeight();
		uint getWidth();
		int getMaxValue();
		//Fonctions : gèrent couleurs de l'image
		int ChangeColor(unsigned char* tabPixels, Map* map);
		int changeColorRoad(unsigned char* tabPixels, Map* map);
		int changeColorConstruct(unsigned char* tabPixels, Map* map);
		int changeColorNode(unsigned char* tabPixels, Map* map);
		int changeColorIn(unsigned char* tabPixels, Map* map);
		int changeColorOut(unsigned char* tabPixels, Map* map);
};

#endif