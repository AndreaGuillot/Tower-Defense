#include"struct.h"
#include <stdlib.h>

class Position{

	Position(float x, float y){
		this->x = x;
		this->y = y;
	}

	float getX(){
    	return x;
    }

    float getY(){
    	return y;
    }

    void positionSetX(float x){
    	this->x = x;
    }

    void positionSetY(float y){
    	this->y = y;
    }
}

class Node {

	private: 

	Position pos;
	Node next;

	public:
		Position getPosition(){
			return this->pos;
		}

		float getPositionX(){
			return this->pos.getX();
		}

		float getPositionY(){
			return this->pos.getY();
		}

		Node getNext(){
			return this->next;
		}

};

class listNode {

	int length;

	//Pointeur
	Node head; //pointeur vers le premier element
	Node tail; //pointeur vers le dernier element
};

#endif