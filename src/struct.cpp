#include"struct.h"
#include <stdlib.h>
#include <math.h>

class Position{

	Position(float x, float y){
		this->x = x;
		this->y = y;
	}

	float get(){
		return this;
	}

	float getX(){
    	return x;
    }

    float getY(){
    	return y;
    }

    void set(float x, float y){
    	this->x = x;
    	this->y = y;
    }

    void setX(float x){
    	this->x = x;
    }

    void setY(float y){
    	this->y = y;
    }
}

class Vector{

	Vector(Point2D A, Point2D B){
		this.x = (B.getX()) - (A.getX());
		this.y = (B.getY()) - (A.getY());
	}

	Vector get(){
		return this;
	}

	float getNorm() {
		float norme;

		norme = pow(this->x, 2.0) pow(this->y, 2.0);
		norme = sqrt(norme);

		return norme;
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

bool intersectionCarreDisque (Position point1, Position point2, float rayon, Position origin) {

	int i;
	Position point;

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

#endif