#ifndef FILE_TOWER_H_
#define FILE_TOWER_H_

#include "color.h"
#include "draw.h"
#include "installation.h"
#include "joueur.h"
#include "map.h"
#include "monstre.h"
#include "shot.h"
#include "struct.h"
#include "tower.h"
#include <string.h>

/************* STRUCTURE DU FICHIER TOUR *************/
/* Liste doublement chainée pour pouvoir naviger dans la liste de tours	*
*  et récupérer facile n'importe quelle tour dans la liste 		*/
class FileTower {

	towerType type_tower;
	int rate;
	int range;
	int cost;
	int power;

	FileTower* prev;
	FileTower* next;

public:
	towerType getType_tower();
	int getRate();
	int getRange();
	int getCost();
	int getPower();
	FileTower* getPrev();
	FileTower* getNext();

	void setType_tower(towerType type);
	void setRate(int n);
	void setRange(int n);
	void setCost(int n);
	void setPower(int n);
	void setPrev(FileTower* t);
	void setNext(FileTower* t);

};

/************* STRUCTURE DE LA LISTE DE TOURS *************/
class listFileTower{
private:
	//Taille de la liste
	int length;

	//Pointeur
	FileTower head; //pointeur vers le premier element
	FileTower tail; //pointeur vers le dernier element

public:

	listFileTower(std::string);

	FileTower getHead();
	FileTower getTail();
	void setHead(FileTower t);
	void setTail(FileTower t);

	int verificationFileTower(char);
	int addFileTower(int, int, char, int, int);
	void removeFileTower(FileTower*);
	void freeAllFileTower ();
};

#endif