#ifndef ITD_DRAW_H_
#define ITD_DRAW_H_

#include "element/Monster.h"
#include "element/Tower.h"
#include "element/Shot.h"

#include "ihm/Node.h"
#include "ihm/Draw.h"
#include "ihm/Interface.h"
#include "file/Texture.h"
#include "file/Map.h"

/************* Prototypes des fonctions *************/
//Dessin menu Map
int drawMenuMap (GLuint*, GLuint*, int);
//Dessin du menu principal
int drawMenuPrincipal (GLuint*, GLuint*);
//Dessine la carte
int drawMap (GLuint*);
//Dessin de l'aide
int drawHelp (GLuint*, GLuint*, GLuint*, int);
//Dessin du chemin et des noeuds
int drawRoad (Map*);
//Dessin le menu du haut
int drawMenuUp (GLuint*, GLuint*);
//Dessin du menu de gauche
int drawMenuLeft(GLuint*, GLuint*, Joueur*);
//Dessiner l'interface (score, argent, vie, nb de monstre tués
int drawInterface (GLuint*, Joueur*);
//Affiche propriete d'une tour
int drawProprieteTower (GLuint*, GLuint*, GLuint* , Tower*, Joueur*);
//Affiche les propriétés du monstre
int drawProprieteMonster (GLuint*, Monster*);
//Affiche GameOver / Win
int drawGameOverWin (GLuint*, GLuint*);

//Dessin des tours
int drawTower (GLuint*, LTower*, ListMonsters*, Tower*, int, int);
//Dessin des missiles
int drawShot (GLuint*, LShot*);
//Dessine les monstres
int drawMonster(GLuint*, ListMonsters*);
//Dessine la barre de pv des monstres
int drawPVMonster(ListMonsters*);

//Dessin du tutorial
int drawTutorial(GLuint*, int);

//Dessiner un rectangle avec nombre d'argent besoin pour upgrade une tour
int drawMoney(Tower*, int);

//Apparition des monstres
int apparitionMonster(ListMonsters*, Joueur*, Map*, int*, int, int*);

//Dessiner un disque
void drawDisque(float);
//Dessiner un clercle
void drawCercle(float);
//Dessiner un rectangle
void drawRectangle (int, int, int, int);
//Dessiner le contour d'un rectangle
void drawRectangleLine (int, int, int, int);
//Ecrire du texte
void writeString(int, int,  char*);

#endif
