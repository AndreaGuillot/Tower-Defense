#ifndef STRUCT_H__
#define STRUCT_H__

#include <string.h>
#include <iostream>
#include "map.h"

enum Propriete{
	aucune, propTower, propMonster
};

enum Menus{
	menu, play, gameOver, gameWin
};

class Vector;
class Map;

class Position{
private: 
    float x;
    float y;
public:
    Position();

    //Get
    Position* get();
    float getX();
    float getY();
    //Set
    void set(float x, float y);
    void setX(float x);
    void setY(float y);

    //functions

    void addVector(Vector v);
};

class Vector{
private: 
	float x;
	float y;
public:
	Vector(Position a, Position b);
	Vector* get();
	float getX();
	float getY();
	float getNorm();

	void setX(float x);
	void setY(float y);

	void normalize();
};

class Size{
    float width;
    float height;
};

class Node {

	private: 

	Position pos;
	Node* next;

	public:
		Node();
		Position getPosition();
		float getX();
		float getY();
		Node* getNext();

		void createNode(float x, float y);
		void setPosition(Position p);
		void setX(float a);
		void setY(float a);
		void setNext(Node* node);
};

class listNode {

	int length;

	//Pointeur
	Node* head; //pointeur vers le premier element
	Node* tail; //pointeur vers le dernier element

public:
	listNode();
	int getLength();
	Node* getHead();
	Node* getTail();

	void setLength(int a);
	void setHead(Node* node);
	void setTail(Node* node);
};

bool intersectionCarreDisque (Position point1, Position point2, float rayon, Position origin);
bool intersectionCarres (Position point1, Position point2, Position pointC1, Position pointC2);

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

		Image(char* nameImg);
		char* getPath();
		char* getMagicNumber();
		uint getHeight();
		uint getWidth();
		int getMaxValue();

		int ChangeColor(unsigned char* tabPixels, Map* map);
		int changeColorRoad(unsigned char* tabPixels, Map* map);
		int changeColorConstruct(unsigned char* tabPixels, Map* map);
		int changeColorNode(unsigned char* tabPixels, Map* map);
		int changeColorIn(unsigned char* tabPixels, Map* map);
		int changeColorOut(unsigned char* tabPixels, Map* map);
};

#endif