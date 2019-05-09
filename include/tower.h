#ifndef TOWER_H__
#define TOWER_H__

#include <installation.h>
#include <stdlib.h>

enum towerType {
    yoann, clara, jules, oceanne
};

class Tower {

    private:
	//Position de la tour
	Position p;
	//Type de la tour
	towerType type;
    //Propriétés de la tour
    uint power;
    float rate;
    uint range;
    uint cost;

    public:
    //Constructeur
    //Accesseurs
    uint getPower(){
    	return this->power;
    }
    uint getRange(){
    	return this->range;
    }
    float getRate(){
    	return this->rate;
    }
    uint getCost(){
    	return this->cost;
    }
	void setPower(int p){
		this->power = p;
	}
	void setRange(float rg){
		this->range = rg;
	}
	void setRate(int rt){
		this->rate=rt;
	}

	virtual string getType() = 0;
};

class Yoann: public Tower{

    public:

    	Yoann(uint range=10; float rate=2.0; uint cost=120; uint power =70){
    		this->range = range;
    		this->rate = rate;
    		this->cost = cost;
    		this->power = power;
    	}

    	string getType(){
    		return "Rocket";
    	}
}

class Clara: public Tower{

    public:

    	Clara(uint range=20; float rate=1.0; uint cost=80; uint power =60){
    		this->range = range;
    		this->rate = rate;
    		this->cost = cost;
    		this->power = power;
    	}

    	string getType(){
    		return "Laser";
    	}
}

class Jules: public Tower{

    public:

    	Jules(uint range=15; float rate=1.5; uint cost=60; uint power =30){
    		this->range = range;
    		this->rate = rate;
    		this->cost = cost;
    		this->power = power;
    	}

    	string getType(){
    		return "Multidimensionnelle";
    	}

}

class Oceanne: public Tower{

    public:

    	Oceanne(uint range=50; float rate=0.5; uint cost=50; uint power =10){
    		this->range = range;
    		this->rate = rate;
    		this->cost = cost;
    		this->power = power;
    	}

    	string getType(){
    		return "Archers";
    	}
}

#endif