#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL_image.h>
#include <cstdlib>
#include <cstdio>
#include "../include/map.h"
//#include "../include/installation.h"
//#include "../include/joueur.h"
//#include "../include/monstre.h"
//#include "../include/tower.h"
//#include "../include/tower.h"

/* Dimensions de la fenetre */
static unsigned int WINDOW_WIDTH = 800;
static unsigned int WINDOW_HEIGHT = 450;

/* Nombre de bits par pixel de la fenetre */
static const unsigned int BIT_PER_PIXEL = 32;

/* Nombre minimal de millisecondes separant le rendu de deux images */
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;

GLuint mapBackground;

void reshape()
{
  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0., 900., 0., 600.);
}

int main(int argc, char** argv) 
{
	/*Game game;

	if(game.Init()){
	    game.run();
	}*/



	/* Chargement carte itd */
	char fileITD[256] = "data/";
	strcat(fileITD, argv[1]);
	Map map = loadMap(fileITD);

	/* Chargement carte ppm */
	char fileName[256] = "images/"; strcat(fileName, map.image);
	SDL_Surface* background = IMG_Load(fileName);
	if(background == NULL) {
	fprintf(stderr, "Impossible de charger l'image %s\n", fileName);
	return EXIT_FAILURE;
	}
	//mapBackground = loadTexture(fileName);

	/* Supression texture */
	glDeleteTextures(1, &mapBackground);


   return EXIT_SUCCESS;
}
