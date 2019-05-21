#ifndef CLICK_H__
#define CLICK_H__

#include "enum.h"
#include "map.h"
#include <string.h>
#include <iostream>

/************* Prototypes des fonctions *************/

//Action : cliquer sur le menu principal
void clickMenuPrincipal(float x, float y, Menus* nbMenu);
//Action : cliquer sur le menu achat de tour
int clickMenuTour(listTower* towers, Joueur* joueur, float x, float y);
//Action : cliquer pour fermer
int clickExit(listMonster* monsters, listShot* shots, listTower* towers, Map* map, Joueur* joueur, float x, float y);
//Action : cliquer pour afficher les propriétés des tours
Tower* clickTower(listTower* towers, float x, float y, Propriete* propriete);
//Action : cliquer pour afficher les propriétés des monstres
Monster* clickMonster(listMonster* monsters, float x, float y, Propriete* propriete);

#endif
