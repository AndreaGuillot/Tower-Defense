#ifndef ITD_MENU_H_
#define ITD_MENU_H_

#include "element/Tower.h"
#include "element/Monster.h"
#include "element/Shot.h"
#include "ihm/Interface.h"
#include "file/FileTower.h"
#include "file/FileInstallation.h"
#include "file/Map.h"

/************* Appel de fonction *************/
//click menu principal
void clickMenuPrincipal(float, float, int*);
//click pour l'achat d'une tour
int clickMenuTour(LTower*, LFileTower*, Joueur*, float, float);
int clickMenuInstallation(LInstallation* p_linstallation, LFileInstallation* p_lfileInstallation, Joueur* joueur, float x, float y);
//click supprimer une tour
int clickTourDelete(LTower*, LShot*, Tower*, Joueur*, float, float, int*);
int clickInstallationDelete(LInstallation*, Installation*, Joueur*, float x, float y, int*, LTower*);
//click fermer
int clickExit(ListMonsters*, LShot*, LTower*, LInstallation*, LFileTower*, LFileInstallation*, Map*, Joueur*, float, float, int);
//click aide
int clickAide(float, float, int);
//click sur une tours : afficher les propriétés
Tower* clickTower(LTower*, float, float, int*);
//click sur monstre : afficher les propriétés
Monster* clickMonster(ListMonsters*, float, float, int*);
Installation* clickInstallation(LInstallation* p_linstallation, float x, float y, int* propriete);

//Supprime les monstres, tours et missiles de leurs liste et réinitialise la l'interface
void initAll (ListMonsters*, LShot*, LTower*, LInstallation*, Joueur*);
//Free tous les élements
void freeAll (ListMonsters*, LShot*, LTower*, LInstallation*, LFileTower*, LFileInstallation*, Map*, Joueur*);

#endif
