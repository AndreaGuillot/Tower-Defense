#ifndef MAP_H__
#define MAP_H__

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Map {

    private:
	//Couleur du chemin
    Color3f in;
	Color3f out;
	Color3f path;
	Color3f node;
	Color3f construct;

};

#endif