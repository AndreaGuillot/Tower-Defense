#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <cstdio>
#include "../include/installation.h"
#include "../include/joueur.h"
#include "../include/map.h"
#include "../include/monstre.h"
#include "../include/tower.h"
#include "../include/tower.h"

/* Dimensions de la fenetre */
static unsigned int WINDOW_WIDTH = 800;
static unsigned int WINDOW_HEIGHT = 450;

/* Nombre de bits par pixel de la fenetre */
static const unsigned int BIT_PER_PIXEL = 32;

/* Nombre minimal de millisecondes separant le rendu de deux images */
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;


int main(int argc, char** argv) 
{
   Game game;

   if(game.Init()){
        game.run();
   }

   return EXIT_SUCCESS;
}
