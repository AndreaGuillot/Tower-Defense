#ifndef MONSTER_H__
#define MONSTER_H__

#include "struct.h"
#include "enum.h"
#include <string.h>
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

/************* Classes Node et listNode *************/
//Gère les noeuds
class Node;
//Gère liste noeuds
class listNode;

/************* Classe Monster : gère les monstres *************/
class Monster {

    private:
        //Position du monstre
        Position* p;
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
        Position* getPosition();
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
        Lucie(uint pv = 200, uint speed = 9, uint money = 20, float resistance_TDR = 0.5, float resistance_TDV = 0, float resistance_TDJ = 0.3, float resistance_TDB = 0.2);
};
class Barbara: public Monster{
    public:
        Barbara(uint pv = 100, uint speed = 11, uint money = 15, float resistance_TDR = 0.1, float resistance_TDV = 0.5, float resistance_TDJ = 0.3, float resistance_TDB = 0.1);
};
class Julien: public Monster{
    public:
        Julien(uint pv = 50, uint speed = 14, uint money = 8, float resistance_TDR = 0.1, float resistance_TDV = 0.8, float resistance_TDJ = 0, float resistance_TDB = 0);
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