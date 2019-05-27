#ifndef ITD_MENU_H_
#define ITD_MENU_H_

#include "element/Tower.h"
#include "element/Monster.h"
#include "element/Shot.h"
#include "ihm/Interface.h"
#include "file/FileTower.h"
#include "file/Map.h"

/************* Appel de fonction *************/
//click menu principal
void clickMenuPrincipal(float, float, int*, int*);
//click pour l'achat d'une tour
int clickMenuTour(LTower*, LFileTower*, Joueur*, float, float);
//click supprimer une tour
int clickTourDelete(LTower*, LShot*, Tower*, Joueur*, float, float, int*);
//click monte de niveau une tour
int clickTourUpgrate(Tower*, Joueur*, float, float, int*);
//click avance rapide / play / pause
int clickTime(float, float, int, int*, int*);
//click fermer
int clickExit(ListMonsters*, LShot*, LTower*, LFileTower*, Map*, Joueur*, float, float, int);
//click aide
int clickAide(float, float, int);
//click sur une tours : afficher les propriétés
Tower* clickTower(LTower*, float, float, int*);
//click sur monstre : afficher les propriétés
Monster* clickMonster(ListMonsters*, float, float, int*);

//click tutorial
int clickTuto(Tower* p_courant, float, float, int, int, int, int*);

//Mouvement de la souris affiche information
int mouseInfo(float, float, int, int);

//Supprime les monstres, tours et missiles de leurs liste et réinitialise la l'interface
void initAll (ListMonsters*, LShot*, LTower*, Joueur*);
//Free tous les élements
void freeAll (ListMonsters*, LShot*, LTower*, LFileTower*, Map*, Joueur*);

#endif
