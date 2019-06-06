#ifndef ITD_FILE_INSTALLATION_H_
#define ITD_FILE_INSTALLATION_H_

/************* STRUCTURE DU FICHIER INSTALLATION *************/
/* Liste doublement chainée pour pouvoir naviguer dans la liste d'installations	*
 * et récupérer facilement n'importe quelle installation dans la liste 			*/
typedef struct struct_fileInstallation {

	//Type de l'installation : R (radar) S (stock) et U (Usine)
	char* type_installation;

	//Portée de l'installation
	int range;

	//Coût de l'installation
	int cost;

	//Pointeur vers l'élément précédent
	struct struct_fileInstallation* p_prev;

	//Pointeur vers l'élément suivant
	struct struct_fileInstallation* p_next;

}FileInstallation;

/************* STRUCTURE DE LA LISTE D'INSTALLATIONS *************/
typedef struct struct_lfileInstallation {

	//Taille de la liste
	size_t length;

	//Pointeur
	FileInstallation *p_head; //pointeur vers le premier element
	FileInstallation *p_tail; //pointeur vers le dernier element

}LFileInstallation;


/************* Prtotypes de fonctions *************/
//Initialisation de la liste des installations
LFileInstallation* newFileInstallation ();
//Ajout d'une installation à la liste
int addFileInstallation(LFileInstallation*, char*, int, int);
//Supprimer une installation de la liste
LFileInstallation* removeFileInstallation(LFileInstallation*, FileInstallation*);
//Supprimer la liste des installations
void freeAllFileInstallation (LFileInstallation*);
//Charge les informations des installations
int loadInfoInstallation(LFileInstallation* p_lfileInstallation);

#endif