#ifndef STRUCT_H__
#define STRUCT_H__

enum Propriete{
	aucune, propTower, propMonster
};

enum Menus{
	menu, play, gameOver, gameWin
};

class Position{
    float x;
    float y;

    Position(float x, float y);

    Position get();
    float getX();
    float getY();
    void set(float x, float y);
    void setX(float x);
    void setY(float y);
};

class Vector{
	float x;
	float y;

	Vector(Position a, Position b);
	Vector get();
	float getNorm();
}

class Size{
    float width;
    float height;
};

class Node {

	private: 

	Position pos;
	Node next;

	public:
		Position getPosition();
		float getX();
		float getY();

};

class listNode {

	int length;

	//Pointeur
	Node head; //pointeur vers le premier element
	Node tail; //pointeur vers le dernier element
};

#endif