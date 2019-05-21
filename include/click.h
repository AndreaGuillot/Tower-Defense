#ifndef CLICK_H__
#define CLICK_H__

#include "enum.h"
#include "map.h"
#include <string.h>
#include <iostream>

void clickMenuPrincipal(float x, float y, Menus* nbMenu);
int clickMenuTour(listTower* towers, Joueur* joueur, float x, float y);
int clickExit(listMonster* monsters, listShot* shots, listTower* towers, Map* map, Joueur* joueur, float x, float y);
Tower* clickTower(listTower* towers, float x, float y, Propriete* propriete);
Monster* clickMonster(listMonster* monsters, float x, float y, Propriete* propriete);

#endif
