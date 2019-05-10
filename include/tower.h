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
	bool type;
    //Propriétés de la tour
    //On a des float pour quand on ajoute les 25%
    float power;
    float rate;
    float range;
    uint cost;
    //Installations à proximité
    bool instNear[3] = {0, 0, 0};
    public:
    //Constructeur
    //Accesseurs
    float getPower(){
    	if(instNear[usine])
    		return 1.25*this->power;
    	else{
    		return this->power;
    	}
    }
    float getRange(){
    	if(instNear[radar])
    		return 1.25*this->range;
    	else{
    		return this->range;
    	}
    }
    float getRate(){
    	if(instNear[stock]){}
    		return 1.25*this->rate;
    	else{
    		return this->rate;
    	}
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

	void addInstallation(Installation installation){
		//Si c'est du type radar par exemple, on aura à l'index radar (=0 grace à l'enum) TRUE
		this->instNear[installation.type] = 1;
	}

	void delInstallation(Installation installation){
		this->instNear[installation.type] = 0;
	}

};

class Yoann: public Tower{

    public:

    	Yoann(float range=10.; float rate=2.0; uint cost=120; float power =70.){
    		this->range = range;
    		this->rate = rate;
    		this->cost = cost;
    		this->power = power;
    	}

    	bool getType(){
    		return yoann;
    	}
}

class Clara: public Tower{

    public:

    	Clara(float range=20.; float rate=1.0; uint cost=80; float power =60.){
    		this->range = range;
    		this->rate = rate;
    		this->cost = cost;
    		this->power = power;
    	}

    	bool getType(){
    		return clara;
    	}
}

class Jules: public Tower{

    public:

    	Jules(float range=15.; float rate=1.5; uint cost=60; float power =30.){
    		this->range = range;
    		this->rate = rate;
    		this->cost = cost;
    		this->power = power;
    	}

    	bool getType(){
    		return jules;
    	}

}

class Oceanne: public Tower{

    public:

    	Oceanne(float range=50.; float rate=0.5; uint cost=50; float power =10.){
    		this->range = range;
    		this->rate = rate;
    		this->cost = cost;
    		this->power = power;
    	}

    	bool getType(){
    		return oceanne;
    	}
}

#endif