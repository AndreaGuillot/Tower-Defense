#include "../include/node.h"

Node* createNode(int x, int y) {

	Node* newNode = (Node*)malloc(sizeof(Node));
	if(newNode == NULL) {
		fprintf(stderr, "Erreur mémoire : noeuds");
        exit(1);
	}
	(*newNode).x = x;
	(*newNode).y = y;
	(*newNode).next = NULL;

	return newNode;

}