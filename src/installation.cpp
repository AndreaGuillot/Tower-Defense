#include "../include/installation.h"

    //Accesseurs
    Position* Installation::getPosition(){
        return this->p;
    }

    uint Installation::getType(){
        return this->type;
    }

    uint Installation::getCost(){
        return this->cost;
    }

    uint Installation::getRange(){
        return this->range;
    }

    void Installation::setPosition(float x, float y){
        this->p->setX(x);
        this->p->setY(y);
    }

    void Installation::setType(installationType type){
        this->type = type;
    }

    void Installation::setCost(uint val){
        this->cost = val;
    }

    void Installation::setRange(uint val){
        this->range = val;
    }

    void Installation::affects(Tower* tower){
        tower->setInstNear((int)this->type, 1);
    }

Andrea::Andrea(uint range = 10, uint cost = 80, installationType type = radar){
        this->setRange(range);
        this->setCost(cost);
        this->setType(type);
    }
    
Margaux::Margaux(uint range = 5, uint cost = 150, installationType type = usine){
        this->setRange(range);
        this->setCost(cost);
        this->setType(type);
    }

BaptisteEtNicolas::BaptisteEtNicolas(uint range = 20, uint cost = 70, installationType type = stock){
        this->setRange(range);
        this->setCost(cost);
        this->setType(type);
    }
