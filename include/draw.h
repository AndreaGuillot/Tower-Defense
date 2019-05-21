#ifndef ITD_DRAW_H_
#define ITD_DRAW_H_

#include "color.h"
#include "installation.h"
#include "joueur.h"
#include "map.h"
#include "monstre.h"
#include "shot.h"
#include "struct.h"
#include "tower.h"
#include <string.h>

/************* Prototypes des fonctions *************/

//Dessine : menu principal
int drawMenuPrincipal (GLuint*, GLuint*);
//Dessine : la carte
int drawMap (GLuint*);
//Dessine : menu du haut
int drawMenuUp (GLuint*, GLuint*);
//Dessine : menu de gauche
int drawMenuLeft(GLuint*, GLuint*, Joueur*);
//Dessine : tours
int drawTower (GLuint*, listTower*, listMonster*, Tower*, int, int);
//Dessine : GameOver / Win
int drawGameOverWin(GLuint* texture, GLuint* spriteButton);
//Dessine un disque
void drawDisque(float);
//Dessine un clercle
void drawCercle(float);
//Dessine un rectangle
void drawRectangle (int, int, int, int);
//Dessine le contour d'un rectangle
void drawRectangleLine (int, int, int, int);
//Ecrit du texte
void writeString(int, int, char* s);

#endif
