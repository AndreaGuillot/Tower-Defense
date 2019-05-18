#ifndef MONSTER_H__
#define MONSTER_H__

#include "installation.h"
#include "tower.h"
#include "struct.h"

enum Sens{
    haut, droite, bas, gauche
};

enum monsterType{
    lucie, barbara, julien
};

class Monster {

    private:
	//Position du monstre
	Position p;
    //S'il y a une erreur sur sa position
    float erreur;
    //Ses caractéristiques sur le chemin
    Sens sens;
    Node node_prev;
    Node node_next;
    Monster monster_prec;
    Monster monster_next;
    //Propriétés du monstre
    monsterType type;
	uint pv;
	uint speed;
    uint money;
	float resistance_TDR;
    float resistance_TDV;
    float resistance_TDJ;
    float resistance_TDB;
	
    public:
    //Get
    Position getPosition();
    float getX();
    float getY();
    float getErreur();
    Sens getSens();
    Node getPrev();
    Node getNext();
    Monster getPrevM();
    Monster getNextM();
    
    monsterType getType();
    float getPV();
    float getSpeed();
    //Ce qu'on gagne qd il meurt
    uint getReward();
    float getResistance_TDR();
    float getResistance_TDV();
    float getResistance_TDJ();
    float getResistance_TDB();

    //Set
    void set(Monster m);
    void setPosition(float x, float y);
    void setX(float x);
    void setY(float y);
    void setSens(Sens s);
    void setErreur(float e);
    void setNodePrev(Node node);
    void setNodeNext(Node node);
    void setPrevMonster(Monster m);
    void setNextMonster(Monster m);

    //Fonctions
    void calculErreur();
    void hitBy(Tower tower);
};

class Lucie: public Monster{
    public:
        Lucie(uint pv=200; uint speed; uint money = 20; float resistance_TDR = 0.5; float resistance_TDV = 0; float resistance_TDJ = 0.3; float resistance_TDB = 0.2);
}

class Barbara: public Monster{
    public:
        Barbara(uint pv=100; uint speed; uint money = 15; float resistance_TDR = 0.1; float resistance_TDV = 0.5; float resistance_TDJ = 0.3; float resistance_TDB = 0.1);
}


class Julien: public Monster{
    public:
        Julien(uint pv=50; uint speed; uint money = 8; float resistance_TDR = 0.1; float resistance_TDV = 0.8; float resistance_TDJ = 0.; float resistance_TDB = 0.);
}

class listMonster {

    private:
        int length;
        Monster head;
        Monster tail;

    public:
        listMonster();
        int getLength();
        Monster getHead();
        Monster getTail();

        bool addMonster(monsterType type, Node n);
        int moveMonster(Node n);
        void removeMonster(Monster m);
}

#endif