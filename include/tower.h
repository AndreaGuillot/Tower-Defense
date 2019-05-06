#ifndef TOWER_H__
#define TOWER_H__

enum towerType {
    red, green, yellow, blue
};

class Tower {

    private:
	//Position de la tour
	float x;
	float y;
	//Type de la tour
	towerType type;
    //Propriétés de la tour
	int power;
    int rate;
    int range;
    int cost;

    public:
    //Constructeur
    towerDefense(uint power, uint range, uint rate) {
		this->power = power;
		this->range = range;
		this->rate = rate;
	};
    //Accesseurs
    uint getPower() {
		return this->power;
	}
	uint getRange() {
		return this->range;
	}
	uint getRate() {
		return this->rate;
	}
	uint getCost() {
		return this->cost;
	}
    
};

#endif