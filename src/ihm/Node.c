#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Appel de la structures
#include "ihm/Node.h"


/************* Création d'une nouvelle liste de noeuds *************/
/* Initialisation de la liste de noeuds et allocation de mémoire pour la liste de noeuds	*
*  Retourne la liste de noeuds									*/

LNode* new_LNode(void) {
	
	//Alloue de la mémoire 
	LNode* p_lnode = malloc(sizeof(LNode));
	if (p_lnode != NULL) {
		p_lnode->length = 0;
		p_lnode->p_head = NULL;
		p_lnode->p_tail = NULL;
	}
	return p_lnode;
}

/************* Ajouter un noeud à la liste de noeuds *************/
/* Ajoute un noeud à la liste. Alloue la place mémoire pour le noeuds et attribue les valeurs	*
*  Vérifie si la liste est vide ou non pour attribuer les pointeurs. Prend en paramètre la 	*
*  liste de noeud, les coordonées du noeud. Retourne 0 en cas d'erreur sinon retourne 1		*/

int addNode(LNode* p_lnode, float x, float y) {

	// On vérifie si notre liste a été allouée
	if (p_lnode != NULL) {
		//Création d'un nouveau noeud
		Node* new_node = malloc(sizeof(Node)); 

		// On vérifie si le malloc n'a pas échoué
		if (new_node != NULL) {
		
			new_node->x = x; 
			new_node->y = y; 
			// Rajoute à la fin : dernier élement de la liste 
			new_node->p_next = NULL; 

			// Cas où notre liste est vide (pointeur vers fin de liste à  NULL)
			if (p_lnode->p_tail == NULL) 
				p_lnode->p_head = new_node; // Pointe la tête de la liste sur le nouveau noeud

			// Cas où des éléments sont déjà présents dans la  liste
			else 
				p_lnode->p_tail->p_next = new_node;  // Relie le dernier calque de la liste au nouveau noeud

			// Pointe la fin de la liste sur le nouveau noeud
			p_lnode->p_tail = new_node; 

			// On augmente de 1 la taille de la liste
			p_lnode->length++; 
		}
		else {
			printf("Probleme au moment de l'allocation du nouveau noeud\n");
			return 0;
		}
	}
	else {
		printf("Cette liste de noeuds n'existe pas\n");
		return 0;
	}

	return 1; 
}

/************* Supprimer un noeud selon sa position *************/
/* Supprime un noeud selon sa position, supprime à partir du premier noeud 				*
*  Prend en paramètre la liste de noeuds et le noeud à supprimer et retourne la liste de noeuds.	*/

LNode* removeNode(LNode* p_lnode, Node* p_courant) {

	// On vérifie si notre liste a été allouée
	if (p_lnode != NULL) {

		if(p_courant != NULL) {

			//Pointe la tête de la liste vers le noeud suivante
			p_lnode->p_head = p_courant->p_next;

			if(p_lnode->p_head == NULL) 
				p_lnode->p_tail = NULL;
			
			//Libère espace mémoire : supprime la tour
			free(p_courant);
			//Décrémente de un la taille de la liste
			p_lnode->length--;

		}
		else
			fprintf(stderr, "Ce noeud n'existe pas");
	}
	else 
		fprintf(stderr, "Cette liste de noeuds n'existe pas");

	// on retourne notre nouvelle liste
	return p_lnode; 
}


/************* Supprimer la liste de noeuds *************/
/* Supprime la liste de noeuds. Prend en paramètre un pointeur vers la liste de noeuds 	*/

void freeAllNode (LNode* p_lnode) {
	//Si la liste n'est pas vide
	if (p_lnode->length != 0) {

		//Tant que la liste n'est pas vide
		while (p_lnode->p_head != NULL) {
			p_lnode = removeNode(p_lnode, p_lnode->p_head);
		}
		
	}
	free(p_lnode);
}
