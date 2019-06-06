#ifndef ITD_INSTALLATION_H_
#define ITD_INSTALLATION_H_

#include "element/Monster.h"
#include "element/Tower.h"
#include "geometry/Point2D.h"
#include "ihm/Node.h"
#include "ihm/Interface.h"

/************* STRUCTURE DE L'INSTALLATION *************/
/* Liste doublement chainée pour pouvoir naviguer dans la liste d'installations	*
 * et récupérer facilement n'importe quelle installation dans la liste 			*/
typedef struct struct_installation {

	//Position de l'installation
	float x;
	float y;

	//Type de l'installation : U (usine) R (radar) S (stock)
	char* type_installation;

	//Portée de l'installation
	int range;

	//Coût de l'installation
	int cost;

	//Pointeur vers l'élément précédent
	struct struct_installation* p_prev;

	//Pointeur vers l'élément suivant
	struct struct_installation* p_next;

}Installation;

/************* STRUCTURE DE LA LISTE DES INSTALLATIONS *************/
typedef struct struct_linstallation {

	//Taille de la liste
	size_t length;

	//Pointeurs
	Installation *p_head; //pointeur vers le premier element
	Installation *p_tail; //pointeur vers le dernier element

}LInstallation;


/************* Prototypes de fonctions *************/
//Initialisation de la liste de tours
LInstallation* new_LInstallation(void);
//Ajout d'une tour à la liste
int addInstallation(LInstallation*, char*, int, int, float, float);
//Vérifie si la tour se trouve sur une zone constructible
int verificationConstructInstallation(LNode*, Point2D, Point2D);
//Déplacer une installation
int moveInstallation(LInstallation*, LTower*, Installation*, LNode*, float, float);
//Déplacer une tour
int moveTower(LTower*, LInstallation*, Tower*, LNode*, float, float);
//Supprimer une installation de la liste
LInstallation* removeInstallation(LInstallation*, Installation*, LTower*);
//Supprimer toutes les tours de la liste
void removeAllInstallation (LInstallation*);
//Supprimer la liste de tours
void freeAllInstallation (LInstallation*);
//Gèrent les effets des installations sur les tours
int reach (LInstallation* , LTower* , Installation*);
int affects(Tower*, Installation*);
int wontreach (LInstallation* , LTower* , Installation*);
int notaffect(Tower*, Installation*);

#endif