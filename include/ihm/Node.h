#ifndef NODE_H
#define NODE_H
#include <stdio.h>
#include <stdlib.h>

/************* STRUCTURE DU NOEUD *************/
/* Liste chainée pour pouvoir naviger dans la liste de noeuds	*/

typedef struct struct_node {

	//Coordonée x du noeud
	float x;
	//Coordonnée y du noeud
	float y;

	//Noeud suivant
	struct struct_node *p_next;

}Node;

/************* STRUCTURE DE LA LISTE DE NOEUDS *************/
typedef struct struct_lnode {

	//Taille de la liste
	size_t length;

	//Pointeur
	Node *p_head; //pointeur vers le premier element
	Node *p_tail; //pointeur vers le dernier element
}LNode;

/************* Appel de fonction *************/
//Initialisation de la liste de noeuds
LNode* new_LNode(void);
//Ajouter un noeud à la liste de noeuds
int addNode(LNode*, float, float);
//Supprimer un noeud
LNode* removeNode(LNode*, Node*);
//Supprimer la liste de noeuds
void freeAllNode (LNode*);

#endif
