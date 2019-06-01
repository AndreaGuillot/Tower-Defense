#ifndef ITD_FILE_INSTALLATION_H_
#define ITD_FILE_INSTALLATION_H_

/************* STRUCTURE DU FICHIER TOUR *************/
/* Liste doublement chainée pour pouvoir naviger dans la liste de tours	*
*  et récupérer facile n'importe quelle tour dans la liste 		*/
typedef struct struct_fileInstallation {

	//Type de la tour : R (radar) S (stock) et U (Usine)
	char* type_installation;

	//porté de la tour
	int range;

	//cout de la tour
	int cost;

	//Pointer vers l'élément précédent
	struct struct_fileInstallation* p_prev;

	//Pointeur vers l'élément suivant
	struct struct_fileInstallation* p_next;

}FileInstallation;

/************* STRUCTURE DE LA LISTE DE TOURS *************/
typedef struct struct_lfileInstallation {

	//Taille de la liste
	size_t length;

	//Pointeur
	FileInstallation *p_head; //pointeur vers le premier element
	FileInstallation *p_tail; //pointeur vers le dernier element
}LFileInstallation;

/************* Prtotypes de fonctions *************/
//Initialisation de la liste de tours
LFileInstallation* newFileInstallation ();
//Ajout d'une tour à la liste
int addFileInstallation(LFileInstallation*, char*, int, int);
//Supprimer une tour de la liste
LFileInstallation* removeFileInstallation(LFileInstallation*, FileInstallation*);
//Supprimer la liste de tour
void freeAllFileInstallation (LFileInstallation*);
int loadInfoInstallation(LFileInstallation* p_lfileInstallation);

#endif
