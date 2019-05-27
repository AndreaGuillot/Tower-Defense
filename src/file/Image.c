#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "file/Image.h"
#include "file/Map.h"

/************* Ouverture de l'image => Lecture de l'image ************/
/* Récupère les valeurs de l'image et la stock dans une structure Image, 	*
*  vérifie si l'image existe et s'il possède un commentaire. S'il y a un 	*
*  commentaire alors il passe la ligne. Ferme l'image à la fin.			*
*  Prend en paramètre une Image (pour stocker les informations dans la structure*
*  et l'adresse de l'image							*/

int openImg(Image* img, char* nameImg) {

	FILE* image = NULL;
	image = fopen(nameImg, "r");
	int test;	

	if(image == NULL){
		fprintf(stderr, "Erreur : Impossible d'ouvrir l'image\n");
		return 0;
	}
	else{

		//Récupère le type d'image
		if(fscanf(image, "%c%c\n", &(img->magicNumber[0]),  &(img->magicNumber[1])) == 2){

			//Si ce n'est pas un ppm, arrete la fonction 
			if(img->magicNumber[0] != 'P' || img->magicNumber[1] != '6'){
				fprintf(stderr, "L'image n'est pas au bon format\n");
				return 0;
			}
			else {
			
				//Vérifier s'il y a un commentaire
				do {
					//Récupère la hauteur et la largeur && test = 1 s'il trouve une variable sinon retourne 0
					test = fscanf(image, "%d %d\n", &(img->widthImg), &(img->heightImg));
				
					//Si c'est une ligne de commentaire
					if(test == 0) {
						char* letter;
						//Passe la ligne : parcours la ligne jusqu'à qu'il trouve '\n'
						do {
							if(fread(&letter,sizeof(char*),1,image)!=1)
								printf("erreur\n");
						}while(*letter != '\n');
					}			
				}while(test<1);

				//Récupérer la résolution de la couleur
				if(fscanf(image, "%d\n", &(img->maxValue)) == 1){
				
					// On ferme le vide le buffer et on ferme l'image
					fflush(image);
					fclose(image);

				}
				else {
					fprintf(stderr, "Probleme ce n'est pas la valeur maximal du fichier\n");
					return 0;
				}

			}
		}
		else {
			fprintf(stderr, "Probleme ce n'est pas le numéro magique du fichier\n");
			return 0;
		}
	}
	return 1;
}

/************* Supprimer un image  ***********/
/* Supprime une image. Prend en paramètre un pointeur vers l'image  	*/

void freeImage (Image* image) {
	//Si l'interface existe
	if (image != NULL) {
		free(image->path);
		free(image);
	}
}
