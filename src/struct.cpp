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

    void setX(float x){
    	this->x = x;
    }

    void setY(float y){
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

		float getX(){
			return this->pos.getX();
		}

		float getY(){
			return this->pos.getY();
		}

		Node getNext(){
			return this->next;
		}

		void setNext(Node node){
			this->next = node;
		}

};

class listNode {

	int length;

	//Pointeur
	Node head; //pointeur vers le premier element
	Node tail; //pointeur vers le dernier element

public: 
	int getLength(){
		return this->length;
	}

	Node getHead(){
		return this->head;
	}

	Node getTail(){
		return this->tail;
	}

	void setHead(Node node){
		this->head = node;
	}

	void setTail(Node node){
		this->tail = node;
	}
};

#endif