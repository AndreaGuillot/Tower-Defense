#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "file/FileInstallation.h"

/************* Initialisation de la liste d'installations (file) *************/
/* Alloue de la mémoire pour la liste puis vérifie le fichier à l'aide de la fonction verificationFileInstallation	*
 * Prend en paramère le chemin vers le fichier. Retourne le pointeur vers la liste.									*/
LFileInstallation* newFileInstallation () {

		//Alloue la memoire
		LFileInstallation* p_lfileInstallation = malloc(sizeof(LFileInstallation));
		if(p_lfileInstallation != NULL) {

			p_lfileInstallation->length = 0;
			p_lfileInstallation->p_head = NULL;
			p_lfileInstallation->p_tail = NULL;

			if(loadInfoInstallation(p_lfileInstallation) == 0) {
				fprintf(stderr, "Erreur au moment de la vérification du fichier pour les tours\n");
				return NULL;
			}
			return p_lfileInstallation;

		}
		else {
			fprintf(stderr, "Erreur au moment de l'allocation mémoire de la liste\n");
			return NULL;
		}
	
	return NULL;	
	
}

/************* Charge les informations des installations *************/
int loadInfoInstallation(LFileInstallation* p_lfileInstallation) {

	if(p_lfileInstallation != NULL) {

			int i;
			int range, cost;

			for(i = 0; i < 3; i++) {

				switch(i) {

					case 0 : //L'installation Usine : Margaux
						range = 20;
						cost = 150;									
						
						addFileInstallation(p_lfileInstallation, "U", range, cost);
									
						break;

					case 1 : //L'installation Radar : Andrea
						range = 40;
						cost = 80;

						addFileInstallation(p_lfileInstallation, "R", range, cost);
									
						break;


					case 2 : // L'installation Stock : Baptiste
						range = 80;
						cost = 70;	
						
						addFileInstallation(p_lfileInstallation, "S", range, cost);
									
						break;

				}//End switch

			}//End for
					

	}
	else {
		fprintf(stderr,"Erreur avec la liste de fileInstallation\n");
		return 0;
	}
	
	return 1;
}

/************* Ajouter une installation en fin de liste installation (file) *************/
/* Ajoute une installation à la liste. Alloue la place mémoire pour l'installation et attribue les valeurs	*
 * Prend en paramètre la liste d'installation, le type, le périmétre d'action et le cout. 					*
 * Retourne 0 en cas d'erreur et 1 sinon																	*/
int addFileInstallation(LFileInstallation* p_lfileInstallation, char* type_installation, int range, int cost) {

	// On vérifie si notre liste a été allouée
	if (p_lfileInstallation != NULL) {
		//Création d'une nouvelle installation
		FileInstallation* new_fileInstallation = malloc(sizeof(FileInstallation)); 
		
		// On vérifie si le malloc n'a pas échoué
		if (new_fileInstallation !=  NULL) {

			new_fileInstallation->type_installation = type_installation;
			new_fileInstallation->cost = cost;
			new_fileInstallation->range = range;

			//Pointer vers l'installation suivant à NULL car on rajoute à la fin de la liste	
			new_fileInstallation->p_next = NULL; 

			// Cas où notre liste est vide (pointeur vers fin de liste à  NULL)
			if (p_lfileInstallation->p_tail == NULL) {

				// Pointe la tête de la liste sur la nouvelle installation
				p_lfileInstallation->p_head = new_fileInstallation; 

				//Pointe p_prev de la nouvelle installation à NULL
				new_fileInstallation->p_prev = NULL;
			}
			// Cas où des éléments sont déjà présents dans la  liste
			else {
				// Pointe p_prev de la nouvelle installation sur la dernière installation de la liste
				new_fileInstallation->p_prev = p_lfileInstallation->p_tail; 

				// Relie la dernière installation de la liste à la nouvelle installation
				p_lfileInstallation->p_tail->p_next = new_fileInstallation;  
			}

			// Pointe la fin de la liste sur la nouvelle installation
			p_lfileInstallation->p_tail = new_fileInstallation; 

			// On augmente de 1 la taille de la liste
			p_lfileInstallation->length++; 
		}
		else {
			fprintf(stderr, "Problème dans la creation de la nouvelle tour\n");
			return 0;
		}

	}
	else {
		fprintf(stderr, "Cette liste de tours n'existe pas\n");
		return 0;
	}

	return 1; 
}

/************* Supprimer une installation selon sa position *************/
/* Supprime une installation selon sa position, vérifie si c'est le premier, le dernier ou une installation dans la liste puis la supprime 	*
 * Prend en paramètre la liste d'installation et l'installation à supprimer et retourne la liste d'installations. 							*/
LFileInstallation* removeFileInstallation(LFileInstallation* p_lfileInstallation, FileInstallation* p_courant) {

	// On vérifie si notre liste a été allouée
	if (p_lfileInstallation != NULL) {

		if(p_courant != NULL) {

			//Si c'est la dernière installation de la liste
			if (p_courant->p_next == NULL) {
				
				//Pointe la fin de la liste sur la installation précédente
				p_lfileInstallation->p_tail = p_courant->p_prev;

				if(p_lfileInstallation->p_tail != NULL) {
					//Lien de la dernière installation vers l'installation suivante est NULL
					p_lfileInstallation->p_tail->p_next = NULL;
				}
				else
					p_lfileInstallation->p_head = NULL;
					
			}
		
			//Si c'est la première de la liste
			else if (p_courant->p_prev == NULL) {
				//Pointe la tête de la liste vers l'installation suivante
				p_lfileInstallation->p_head = p_courant->p_next;

				if(p_lfileInstallation->p_head != NULL) {
					//Le lien vers de la deuxième installation vers l'installation précédente est NULL
			 		p_lfileInstallation->p_head->p_prev = NULL;
				}
				else
					p_lfileInstallation->p_tail = NULL;
			}

			else {
				//Relie l'installation suivante à l'installation précédente de l'installation que l'on veut supprimer 
				p_courant->p_next->p_prev = p_courant->p_prev;
				//Relie l'installation précédente à l'installation suivante de l'installation que l'on veut supprimer 
				p_courant->p_prev->p_next = p_courant->p_next;

			}
			//Libère espace mémoire : supprime l'installation
			free(p_courant);
			//Décrémente de un la taille de la liste
			p_lfileInstallation->length--;

		}
		else
			fprintf(stderr, "Cette tour n'existe pas");
	}
	else 
		fprintf(stderr, "Cette liste de tours n'existe pas");

	// on retourne notre nouvelle liste
	return p_lfileInstallation; 
}


/************* Supprimer la liste de fileInstallation *************/
/* Supprime la liste d'installations. Prend en paramètre un pointeur vers la liste d'installations 	*/
void freeAllFileInstallation (LFileInstallation* p_lfileInstallation) {
	//Si la liste n'est pas vide
	if (p_lfileInstallation->length != 0) {

		//Tant que la liste n'est pas vide
		while (p_lfileInstallation->p_head != NULL) {
			p_lfileInstallation = removeFileInstallation(p_lfileInstallation, p_lfileInstallation->p_head);
		}
		
	}
	free(p_lfileInstallation);
}