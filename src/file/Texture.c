#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>

#include "file/Map.h"
#include "file/Image.h"
#include "file/Texture.h"

/************* Chargement de la texture de la map *************/
/* Charge l'image, attribut l'image à la texture, change les couleurs de la map (fonction ChangeColor)	*
*  Prend en paramètre un pointeur vers la carte, un pointeur vers la texture, et un pointeur vers la 	*
*  surface SDLRetourne 1 si la carte et charger.							*/

int loadMapTexture(Map* map, GLuint* texture, SDL_Surface* image) {

	image = IMG_Load(map->img->path);
	if(image == NULL) {
		fprintf(stderr, "impossible de charger l'image %s\n", map->img->path);
		return EXIT_FAILURE;
	}

	//Fait une copie de la texture pour la stocker => allocation mémoire
	glGenTextures(1, texture);
	//dire qu'on fait des modification sur cette texture
	glBindTexture(GL_TEXTURE_2D, *texture);

	//choisi le bon format selon l'image
	GLenum format;
	switch(image->format->BytesPerPixel) {
		case 1:
			format = GL_RED;
			break;
		case 3:
			/* Ne gere pas les machines big-endian (a confirmer...) */
			format = GL_RGB;
			break;
		case 4:
			/* Ne gere pas les machines big-endian (a confirmer...) */
			format = GL_RGBA;
			break;
		default:
			/* On ne traite pas les autres cas */
			fprintf(stderr, "Format des pixels de l’image %s non pris en charge\n", map->img->path);
			return EXIT_FAILURE;
	}

	//Change les couleurs de la map
	ChangeColor(map->img, image->pixels, map);
	//Passe l'image pour produire la texture
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->w, image->h, 0, format, GL_UNSIGNED_BYTE, image->pixels);

	//dit qu'on utilise un filtre linéaire : fait une moyenne des couleurs
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	return 1;
}

/************* Chargement de textures *************/
/* Charge l'image, attribut l'image à la texture. Prend en paramètre un pointeur vers la carte, 	*
*  un pointeur vers la texture, et un pointeur vers la surface SDLRetourne 1 si la carte et charger.	*/

int loadTexture(char* fileName, GLuint* texture, SDL_Surface* img) {
	
	img = IMG_Load(fileName);
	if(img == NULL) {
		fprintf(stderr, "impossible de charger l'image %s\n", fileName);
		return 0;
	}

	//Fait une copie de la texture pour la stocker
	glGenTextures(1, texture);
	//dire qu'on fait des modification sur cette texture
	glBindTexture(GL_TEXTURE_2D, *texture);

	//choisi le bon format selon l'image
	GLenum format;
	switch(img->format->BytesPerPixel) {
		case 1:
			format = GL_RED;
			break;
		case 3:
			format = GL_RGB;
			break;
		case 4:
			format = GL_RGBA;
			break;
		default:
			fprintf(stderr, "Format des pixels de l’image %s non pris en charge\n", fileName);
			return EXIT_FAILURE;
	}

	//
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img->w, img->h, 0, format, GL_UNSIGNED_BYTE, img->pixels);

	//dit qu'on utilise un filtre linéaire : fait une moyenne des couleurs
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	return 1;
}

/************* Supprimer une texture *************/
/* Supprime une texture. Prend en paramètre un pointeur vers la texture et un pointeur vers une  	*
*  surface SDL.												*/

void freeTexture(GLuint* texture, SDL_Surface* img) {
	SDL_FreeSurface(img);
	glDeleteTextures(1, texture);
}
