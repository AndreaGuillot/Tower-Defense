#ifndef TEXTURE_H__
#define TEXTURE_H__

#include "map.h"
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>

<<<<<<< HEAD
//Charge les textures de la map
int loadMapTexture(Map* map, GLuint* texture, SDL_Surface* image);
//Charge textures
int loadTexture(std::string fileName, GLuint* texture, SDL_Surface* img);
//Libère espace mémoire
void freeTexture(GLuint* texture, SDL_Surface* img);
=======
	int loadMapTexture(Map* map, GLuint* texture, SDL_Surface* image);
	int loadTexture(char* fileName, GLuint* texture, SDL_Surface* img);
	void freeTexture(GLuint* texture, SDL_Surface* img);
>>>>>>> master

#endif
