#ifndef NODE_H__
#define NODE_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {

	int x;
	int y;
	struct Node* next;

}Node;

Node* createNode(int x, int y);

#endif