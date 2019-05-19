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

	int loadMapTexture(Map* map, GLuint* texture, SDL_Surface* image);
	int loadTexture(std::string fileName, GLuint* texture, SDL_Surface* img);
	void freeTexture(GLuint* texture, SDL_Surface* img);

#endif
