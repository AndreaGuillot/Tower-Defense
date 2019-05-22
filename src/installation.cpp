#include "../include/installation.h"


Installation::Installation(){
    this->p = NULL;
    this->cost = 0;
    this->range = 0;
}
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
    tower->setInstNear(this->type, 1);
}

//Types d'installation
Andrea::Andrea(uint range, uint cost, installationType type){
        this->setRange(range);
        this->setCost(cost);
        this->setType(type);
    }
    
Margaux::Margaux(uint range, uint cost, installationType type){
        this->setRange(range);
        this->setCost(cost);
        this->setType(type);
    }

BaptisteEtNicolas::BaptisteEtNicolas(uint range, uint cost, installationType type){
        this->setRange(range);
        this->setCost(cost);
        this->setType(type);
    }
