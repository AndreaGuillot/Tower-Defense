#include"struct.h"
#include <stdlib.h>
#include <math.h>

class Position{

	Position(float x, float y){
		this->x = x;
		this->y = y;
	}

	Position get(){
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

    void addVector(Vector V) {		
		this->x += (V.getX());
		this->y += (V.getY());
	}
}

class Vector{

	Vector(Position A, Position B){
		this.x = (B.getX()) - (A.getX());
		this.y = (B.getY()) - (A.getY());
	}

	Vector get(){
		return this;
	}

	float getX(){
		return this->x;
	}

	float getY(){
		return this->y;
	}

	float getNorm() {
		float norme;

		norme = pow(this->x, 2.0) pow(this->y, 2.0);
		norme = sqrt(norme);
		return norme;
	}

	void setX(float x){
		this->x = x;
	}
	void setY(float y){
		this->y = y;
	}

	void normalize(){
		float norme = this.getNorm();	
		this->x = (this->x) / norme;
		this->y = (this->y) / norme;
	}

}

class Node {

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

		void setPosition(Position p){
			this->pos = p;
		}
		void setX(float a){
			this->x = a;
		}
		void setY(float a){
			this->y = a;
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

	void setLength(int a){
		this->length = a;
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

bool intersectionCarres (Position point1, Position point2, Position pointC1, Position pointC2) {

	int i;
	Position point;

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

#endif