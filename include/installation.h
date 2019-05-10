#ifndef INSTALLATION_H__
#define INSTALLATION_H__

enum installationType {
    radar, usine, stock
};

class Position{
    float x;
    float y;
};

class Size{
    float width;
    float height;
};

class Installation {

    private:
	//Position de l'installation
	Position p;
	//Type de l'installation : radar, usine, stock
	uint type;
    //Propriétés de l'installation
    Size size;
    uint cost;
	uint range;

    public:
    //Constructeur
    Installation(uint range, uint cost);
    //Accesseurs
    int getPosition(){
        return this->Position;
    }

    int getSize(){
        return this->Size;
    }

    uint getCost(){
        return this->cost;
    }

    uint getRange(){
        return this->range;
    }

    uint getType(){
        return this->type;
    }

    void affects(Tower tower){
        tower.instNear[this->type] = 1;
    }
};

class Andrea: public Installation{

    Andrea(uint range = 10; uint cost = 80; type = radar){
        this->range = range;
        this->cost = cost;
        this->type = type;
    }
    
}

class Margaux: public Installation{

    Margaux(uint range = 5; uint cost = 150; type = usine){
        this->range = range;
        this->cost = cost;
        this->type = type;
    }
}

class BaptisteEtNicolas: public Installation{

    BaptisteEtNicolas(uint range = 20; uint cost = 70; type = stock){
        this->range = range;
        this->cost = cost;
        this->type = type;
    }
}

#endif