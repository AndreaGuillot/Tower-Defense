#ifndef ITD_INSTALLATION_H_
#define ITD_INSTALLATION_H_

#include "element/Monster.h"
#include "geometry/Point2D.h"
#include "ihm/Node.h"
#include "ihm/Interface.h"

/************* STRUCTURE D'INSTALLATION *************/
/* Liste doublement chainée pour pouvoir naviger dans la liste de tours	*
*  et récupérer facile n'importe quelle tour dans la liste 		*/
typedef struct struct_installation {

	//position de la tour
	float x;
	float y;

	//Type de l'installation : U (Usine) R (radar) S (stock)
	char* type_installation;

	//compteur
	int compteur;

	//porté de la tour
	int range;

	//cout de la tour
	int cost;

	//Pointer vers l'élément précédent
	struct struct_installation* p_prev;

	//Pointeur vers l'élément suivant
	struct struct_installation* p_next;

}Installation;

/************* STRUCTURE DE LA LISTE DE TOURS *************/
typedef struct struct_linstallation {

	//Taille de la liste
	size_t length;

	//Pointeur
	Installation *p_head; //pointeur vers le premier element
	Installation *p_tail; //pointeur vers le dernier element
}LInstallation;

/************* Prtotypes de fonctions *************/
//Initialisation de la liste de tours
LInstallation* new_LInstallation(void);
//Ajout d'une tour à la liste
int addInstallation(LInstallation*, char*, int, int, float, float);
//Vérifie si la tour se trouve sur une zone constructible
int verificationConstructInstallation(LNode*, Point2D, Point2D);
//Déplacer une tour
int moveInstallation(LInstallation*, Installation*, LNode*, float, float);
//Supprimer une tour de la liste
LInstallation* removeInstallation(LInstallation*, Installation*);
//Supprime toutes les tours de la liste
void removeAllInstallation (LInstallation*);
//Suprime la liste de tours
void freeAllInstallation (LInstallation*);

#endif
