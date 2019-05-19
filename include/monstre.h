#ifndef MONSTER_H__
#define MONSTER_H__

#include "draw.h"
#include "filetower.h"
#include "installation.h"
#include "color.h"
#include "joueur.h"
#include "map.h"
#include "shot.h"
#include "struct.h"
#include "tower.h"
#include <string.h>
#include <iostream>

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
    Monster* monster_prec;
    Monster* monster_next;
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

    Monster();
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
    void setPV(uint pv);
    void setErreur(float e);
    void setNodePrev(Node node);
    void setNodeNext(Node node);
    void setPrevMonster(Monster m);
    void setNextMonster(Monster m);

    //Fonctions
    void calculErreur();
    int drawProprieteMonster(GLuint* monster);
    bool isSame(Monster m);
};

class Lucie: public Monster{
    public:
        Lucie(uint pv, uint speed, uint money, float resistance_TDR, float resistance_TDV, float resistance_TDJ, float resistance_TDB);
};

class Barbara: public Monster{
    public:
        Barbara(uint pv, uint speed, uint money, float resistance_TDR, float resistance_TDV, float resistance_TDJ, float resistance_TDB);
};


class Julien: public Monster{
    public:
        Julien(uint pv, uint speed, uint money, float resistance_TDR, float resistance_TDV, float resistance_TDJ, float resistance_TDB);
};

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

        bool addMonster(monsterType type, Node* n);
        int moveMonster(Node n);
        void removeMonster(Monster m);
        void removeAllMonsters();
        void freeAllMonsters();
        int drawMonster(GLuint* monster);
};

#endif