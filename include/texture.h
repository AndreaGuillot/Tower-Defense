#ifndef TEXTURE_H__
#define TEXTURE_H__

#include "map.h"
#include "struct.h"
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>

//Charge les textures de la map
int loadMapTexture(Map* map, GLuint* texture, SDL_Surface* image);
//Charge textures
int loadTexture(std::string fileName, GLuint* texture, SDL_Surface* img);
//Libère espace mémoire
void freeTexture(GLuint* texture, SDL_Surface* img);

#endif
