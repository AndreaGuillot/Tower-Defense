#ifndef ITD_FILE_TOWER_H_
#define ITD_FILE_TOWER_H_

/************* STRUCTURE DU FICHIER TOUR *************/
/* Liste doublement chainée pour pouvoir naviger dans la liste de tours	*
 * et récupérer facile n'importe quelle tour dans la liste 				*/
typedef struct struct_fileTower {

	//Type de la tour : R (rocket) L (laser), M (mitraillette) et H (hybride)
	char* type_tower;

	//Cadence 
	int rate;

	//Portée de la tour
	int range;

	//Coût de la tour
	int cost;

	//Puissance de tir de la tour
	int power;

	//Pointeur vers l'élément précédent
	struct struct_fileTower* p_prev;

	//Pointeur vers l'élément suivant
	struct struct_fileTower* p_next;

}FileTower;

/************* STRUCTURE DE LA LISTE DE TOURS *************/
typedef struct struct_lfileTower {

	//Taille de la liste
	size_t length;

	//Pointeur
	FileTower *p_head; //pointeur vers le premier element
	FileTower *p_tail; //pointeur vers le dernier element

}LFileTower;


/************* Prtotypes de fonctions *************/
//Initialisation de la liste de tours
LFileTower* newFileTower ();
//Ajout d'une tour à la liste
int addFileTower(LFileTower*, int, int, char*, int, int);
//Supprimer une tour de la liste
LFileTower* removeFileTower(LFileTower*, FileTower*);
//Supprimer la liste de tour
void freeAllFileTower (LFileTower*);
//Charge les informations des tours
int loadInfoTour(LFileTower* p_lfileTower);

#endif