#ifndef MONSTER_H__
#define MONSTER_H__

#include "draw.h"
#include "installation.h"
#include "color.h"
#include "joueur.h"
#include "map.h"
#include "shot.h"
#include "struct.h"
#include "tower.h"
#include <string.h>
#include <iostream>
#include "enum.h"

/************* Classes Node et listNode *************/
//Gère les noeuds
class Node;
//Gère liste noeuds
class listNode;

/************* Classe Monster : gère les monstres *************/
class Monster {

    private:
        //Position du monstre
        Position p;
        //S'il y a une erreur sur sa position
        float erreur;
        //Ses caractéristiques sur le chemin
        Sens sens;
        Node* node_prev;
        Node* node_next;
        Monster* monster_prev;
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
        //Constructeur
        Monster();
        //Get
        Position getPosition();
        float getX();
        float getY();
        float getErreur();
        Sens getSens();
        Node* getPrev();
        Node* getNext();
        Monster* getPrevM();
        Monster* getNextM();
        monsterType getType();
        uint getPV();
        uint getSpeed();
        //Ce qu'on gagne qd il meurt
        uint getReward();
        float getResistance_TDR();
        float getResistance_TDV();
        float getResistance_TDJ();
        float getResistance_TDB();
        //Set
        void set(Monster* m);
        void setPosition(float x, float y);
        void setX(float x);
        void setY(float y);
        void setSens(Sens s);
        void setPV(uint pv);
        void setErreur(float e);
        void setNodePrev(Node* node);
        void setNodeNext(Node* node);
        void setPrevMonster(Monster* m);
        void setNextMonster(Monster* m);
        void setType(monsterType type);
        void setSpeed(uint a);
        void setReward(uint a);
        void setResistance_TDR(float resistance);
        void setResistance_TDV(float resistance);
        void setResistance_TDJ(float resistance);
        void setResistance_TDB(float resistance);
        //Fonctions
        /* Erreur position */
        void calculErreur();
        /* Dessine monstre */
        int drawProprieteMonster(GLuint* monster);
        /* Evite les doublons */
        bool isSame(Monster* m);
};

//3 types de monstre
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

//Gère : liste monstres
class listMonster {

    private:
        //Propriétés
        int length;
        Monster* head; //pointeur vers le premier element
        Monster* tail; //pointeur vers le denier element

    public:
        //Constructeur
        listMonster();
        //Get
        int getLength();
        Monster* getHead();
        Monster* getTail();
        //Fonctions
        /* Ajoute monstre */
        bool addMonster(monsterType type, Node* n);
        /* Deplacement monstre */
        int moveMonster(Node* n, int k);
        /* Supprime monstre */
        void removeMonster(Monster* m);
        /* Supprime tous les monstres */
        void removeAllMonsters();
        /* Libere espace mémoire */
        void freeAllMonsters();
        /* Dessine monstre */
        int drawMonster(GLuint* monster);
};

#endif