#ifndef ITD_MONSTER_H_
#define ITD_MONSTER_H_

#include "ihm/Node.h"

/************* STRUCTURE DU MONSTRE *************/
/* Liste doublement chainée pour pouvoir naviguer dans la liste de monstres	*
 * et récupérer facilement n'importe quel monstre dans la liste 			*/
typedef struct struct_monster {

	//Position du monstre
	float x;
	float y;
	float e; //erreur : calcul dans le cas où il n'avance pas tout droit

	//Nombre pour savoir dans quelle sens il avance pour les sprites
	/*  1 = haut 	*
	 *  2 = droite 	*
	 *  3 = bas		*
	 *  4 = gauche	*/
	int sens;

	//Noeud précédent (carte)
	Node* node_prev;

	//Noeud suivant (carte)
	Node* node_next;

	//Type de monstre
	char* type;

	//Point de vie
	int pv;
	int pvMax;

	//Résistance
	float resistanceY;
	float resistanceC;
	float resistanceJ;
	float resistanceO;

	//Le gain (monnaie)
	int gain;

	//Vitesse de déplacement
	int pace;

	//Pointeur vers l'élément précédent
	struct struct_monster* p_prev;

	//Pointeur vers l'élément suivant
	struct struct_monster* p_next;

}Monster;

/************* STRUCTURE DE LA LISTE DE MONSTRES *************/
typedef struct struct_lmonster {

	//Taille de la liste
	size_t length;

	//Pointeur
	Monster *p_head; //pointeur vers le premier element
	Monster *p_tail; //pointeur vers le dernier element

}ListMonsters;


/************* Prototypes des fonctions *************/
//Initialisation de la liste de monstres
ListMonsters* new_ListMonsters(void);
//Ajouter un monstre en fin de liste
int addMonster(ListMonsters* , char* , int , float, float, float, float, int, int, Node*);
//Fait bouger le monstre
int moveMonster(ListMonsters* , Node*, int);
//Calcule l'erreur de déplacement
void calculErreur(Monster*);
//Supprime le monstre
ListMonsters* removeMonster(ListMonsters*, Monster*);
//Supprime tous les monstres de la liste
void removeAllMonsters (ListMonsters*);
//Supprime toute la liste de monstres
void freeAllMonsters (ListMonsters*);

#endif