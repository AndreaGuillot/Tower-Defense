#ifndef ITD_TEXTURE_H_
#define ITD_TEXTURE_H_

#include "file/Map.h"

/************* Prototypes des fonctions *************/
//Chargement de la texture de la carte
int loadMapTexture(Map*, GLuint*, SDL_Surface*);
//Chargement des textures
int loadTexture(char*, GLuint*, SDL_Surface*);
//Supprimer une texture
void freeTexture(GLuint*, SDL_Surface*);

#endif