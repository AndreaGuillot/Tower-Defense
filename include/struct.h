#ifndef STRUCT_H__
#define STRUCT_H__

#include "draw.h"
#include "filetower.h"
#include "installation.h"
#include "color.h"
#include "joueur.h"
#include "map.h"
#include "monstre.h"
#include "shot.h"
#include "tower.h"
#include <string.h>
#include <iostream>

enum Propriete{
	aucune, propTower, propMonster
};

enum Menus{
	menu, play, gameOver, gameWin
};

class Vector;

class Position{
    float x;
    float y;

    Position(float x, float y);

    //Get
    Position get();
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
	float x;
	float y;

	Vector(Position a, Position b);
	Vector get();
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
		Position getPosition();
		float getX();
		float getY();
		Node getNext();

		void setPosition(Position p);
		void setX(float a);
		void setY(float a);
		void setNext(Node node);
};

class listNode {

	int length;

	//Pointeur
	Node head; //pointeur vers le premier element
	Node tail; //pointeur vers le dernier element

public:
	listNode();
	int getLength();
	Node getHead();
	Node getTail();

	void setLength(int a);
	void setHead(Node node);
	void setTail(Node node);
};

bool intersectionCarreDisque (Position point1, Position point2, float rayon, Position origin);

#endif