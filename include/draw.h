#ifndef ITD_DRAW_H_
#define ITD_DRAW_H_

#include "color.h"
#include "filetower.h"
#include "installation.h"
#include "joueur.h"
#include "map.h"
#include "monstre.h"
#include "node.h"
#include "shot.h"
#include "struct.h"
#include "tower.h"
#include <string.h>

//Dessin du menu principal
int drawMenuPrincipal (GLuint*, GLuint*);
//Dessine la carte
int drawMap (GLuint*);
//Dessin le menu du haut
int drawMenuUp (GLuint*, GLuint*);
//Dessin du menu de gauche
int drawMenuLeft(GLuint*, GLuint*, Joueur);
//Dessin des tours
int drawTower (GLuint*, listTower, listMonster, Tower, int, int);
//Dessiner un rectangle avec nombre d'argent besoin pour upgrade une tour
int drawGameOverWin(GLuint* texture, GLuint* spriteButton);
//Dessiner un disque
void drawDisque(float);
//Dessiner un clercle
void drawCercle(float);
//Dessiner un rectangle
void drawRectangle (int, int, int, int);
//Dessiner le contour d'un rectangle
void drawRectangleLine (int, int, int, int);
//Ecrire du texte
void writeString(int, int,  string);

#endif
