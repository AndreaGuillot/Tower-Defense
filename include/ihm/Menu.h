#ifndef ITD_MENU_H_
#define ITD_MENU_H_

#include "element/Tower.h"
#include "element/Monster.h"
#include "element/Shot.h"
#include "ihm/Interface.h"
#include "file/FileTower.h"
#include "file/FileInstallation.h"
#include "file/Map.h"

/************* Prototypes des fonctions *************/
//Click menu principal / Jouer
void clickMenuPrincipal(float, float, int*);
int clickPlay(float x, float y, int isPlaying, int* nbMonster, int* j);
//Click pour l'achat d'une tour / d'une installation
int clickMenuTour(LTower*, LFileTower*, Joueur*, float, float);
int clickMenuInstallation(LInstallation* p_linstallation, LFileInstallation* p_lfileInstallation, Joueur* joueur, float x, float y);
//Click supprimer une tour / une installation
int clickTourDelete(LTower*, LShot*, Tower*, Joueur*, float, float, int*);
int clickInstallationDelete(LInstallation*, Installation*, Joueur*, float x, float y, int*, LTower*);
//Click fermer
int clickExit(ListMonsters*, LShot*, LTower*, LInstallation*, LFileTower*, LFileInstallation*, Map*, Joueur*, float, float, int);
//Click aide
int clickAide(float, float, int);
//Click sur tour : afficher les propriétés
Tower* clickTower(LTower*, float, float, int*);
//Click sur monstre : afficher les propriétés
Monster* clickMonster(ListMonsters*, float, float, int*);
//Click sur installation : afficher les propriétés
Installation* clickInstallation(LInstallation* p_linstallation, float x, float y, int* propriete);
//Supprime les monstres, tours et missiles de leur liste et réinitialise l'interface
void initAll (ListMonsters*, LShot*, LTower*, LInstallation*, Joueur*);
//Libère mémoire de tous les élements
void freeAll (ListMonsters*, LShot*, LTower*, LInstallation*, LFileTower*, LFileInstallation*, Map*, Joueur*);

#endif