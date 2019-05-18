#ifndef ITD_IMAGE_H
#define ITD_IMAGE_H

/************* STRUCTURE DE L'IMAGE *************/
typedef struct struct_image {

	//Chemin vers l'image
	char* path;

	//Numero magic : identifie le type de fichier
	char magicNumber[2];
	
	//Les dimensions de l'images
	unsigned int heightImg;
	unsigned int widthImg;

	//Valeur maximal de la couleur, résolution de la couleur
	int maxValue;

}Image;

/************* Prototypes des fonctions *************/
//Ouvrir et stocker une image
int openImg(Image*, char*);
//Supprimer une image
void freeImage (Image*);
#endif
