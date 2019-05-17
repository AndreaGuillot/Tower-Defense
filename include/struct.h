#ifndef STRUCT_H__
#define STRUCT_H__

class Position{
    float x;
    float y;

    Position(float x, float y);

    float getX();
    float getY();
    void positionSetX(float x);
    void positionSetY(float y);
};

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

};

class listNode {

	int length;

	//Pointeur
	Node head; //pointeur vers le premier element
	Node tail; //pointeur vers le dernier element
};

#endif