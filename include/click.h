#ifndef CLICK_H__
#define CLICK_H__

#include "draw.h"
#include "filetower.h"
#include "installation.h"
#include "color.h"
#include "joueur.h"
#include "map.h"
#include "monstre.h"
#include "shot.h"
#include "tower.h"
#include <string.h>
#include <iostream>

void clickMenuPrincipal(float x, float y, Menus* nbMenu);
int clickMenuTour(listTower towers, listFileTower fileTower, Joueur joueur, float x, float y);
int clickExit(listMonster monsters, listShot shots, listTower towers, listFileTower fileTower, Map* map, Joueur joueur, float x, float y);
Tower* clickTower(listTower towers, float x, float y, Propriete* propriete);
Monster* clickMonster(listMonster monsters, float x, float y, Propriete* propriete);

#endif