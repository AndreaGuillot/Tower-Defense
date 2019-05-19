#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "../include/draw.h"
#include "../include/filetower.h"
#include "../include/installation.h"
#include "../include/color.h"
#include "../include/map.h"
#include "../include/monstre.h"
#include "../include/shot.h"
#include "../include/struct.h"
#include "../include/tower.h"
#include "../include/joueur.h"
#include "../include/texture.h"
#include "../include/click.h"
#include <string.h>
#include <iostream>

static unsigned int WINDOW_WIDTH = 800;
static unsigned int WINDOW_HEIGHT = 660;
static const unsigned int BIT_PER_PIXEL = 32;
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 10;
static const Uint32 FRAMERATE_MILLISECONDS_RAPIDE = 1000 / 50;
float pi = 3.14;

void reshape() {
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0., 800., 660., 0.);
}

void setVideoMode() {
	if(NULL == SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL, 
        	SDL_OPENGL  | SDL_RESIZABLE | SDL_DOUBLEBUF)) {
		fprintf(stderr, "Impossible d'ouvrir la fenetre. Fin du programme.\n");
		exit(EXIT_FAILURE);
	}
  
	reshape();
  
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapBuffers();
}

int main(int argc, char** argv) {

	int testMouse = 0;
	int testTower = 0;
	Menus nbMenu = menu;
	int nbtexture = 0;

	/* Initialisation */
	if(-1 == SDL_Init(SDL_INIT_VIDEO)) {
        	fprintf(stderr, "Impossible d'initialiser la SDL. Fin du programme.\n");
        	return EXIT_FAILURE;
    	}

	setVideoMode();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glutInit(&argc, argv); // initialisation de GLUT

    	SDL_WM_SetCaption("Tower Defense IMAC1", NULL);

    Map map;

	/***** Variables ******/

	//Texture menuPrincipal
	GLuint menuPrincipal;
	SDL_Surface* imgMenuPrincipal = NULL;

	//Texture menuPrincipal button
	GLuint menuPrincipalButton;
	SDL_Surface* imgMenuPrincipalButton = NULL;

	//La carte
	GLuint texture;
	SDL_Surface* imgMap = NULL;

	//Texture des monstres
	GLuint monsterTxt;
	SDL_Surface* imgMonster = NULL;

	//Texture des tours
	GLuint towerTxt;
	SDL_Surface* imgTower = NULL;

	//Texture des shots	
	GLuint shot;
	SDL_Surface* imgShot = NULL;

	//Texture menu
	GLuint spriteMenu;
	SDL_Surface* imgButtonMenu = NULL;

	//Texture fond menu
	GLuint fondMenu;
	SDL_Surface* imgFondMenu = NULL;

	//Texture pour les boutons
	GLuint spriteButton;
	SDL_Surface* imgSpriteButton = NULL;
	
	//Bouton plus ou upgrate les tours
	GLuint btPlus;
	SDL_Surface* imgbtPlus = NULL;

	//Texture fond menu up
	GLuint fondMenuUp;
	SDL_Surface* imgFondMenuUp = NULL;

	//Texture fond Game Over
	GLuint fondGameOver;
	SDL_Surface* imgFondGameOver = NULL;
	
	//Texture fond Win
	GLuint fondWin;
	SDL_Surface* imgFondWin = NULL;

	//Initialisation de l'interface
	Joueur* joueur = new Joueur();

	//Initialisation de la liste de monstre
	listMonster* monsters = new listMonster();
	//Initialisation de la liste de tours
	listTower* towers = new listTower();
	//Initialisation de la liste de shots
	listShot* shots = new listShot();

	//Initialisation de la liste de tours (file) --------------------------------------------------AUCUNE IDEE DE CE A QUOI CA SERT
	listFileTower* fileTower =  new listFileTower("../data/IDTtower.idt");

	int i = 0;
	int j = 0;
	int k = 0;
	int nb_monster = 0;
	Propriete propriete = aucune;

	//Pour afficher les propriétés
	Tower* tower;
	Monster* pMonster;

	bool loop = 1;

	/**** Main loop ***/
  	while(loop) {
   		Uint32 startTime = SDL_GetTicks();

	    	/* dessin */

		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);

		if(nbMenu == gameOver)
			drawGameOverWin(&fondGameOver, &menuPrincipalButton);
		else if(nbMenu == gameWin)
			drawGameOverWin(&fondWin, &menuPrincipalButton);
		else if(nbMenu == menu) {

				loadTexture("../images/temp/MenuPrincipal.png", &menuPrincipal, imgMenuPrincipal);

				loadTexture("../images/temp/sprite_button_menu.png", &menuPrincipalButton, imgMenuPrincipalButton);

				//La carte
				map.loadMap("./data/IDTMap1.idt");
				//Texture de la carte

				loadMapTexture(&map, &texture, imgMap);
				if(nbtexture == 1)
					loadTexture("../images/temp/map1.ppm", &texture, imgMap);
				
				//Texture des monstres
				loadTexture("../images/temp/sprite_monster.png", &monsterTxt, imgMonster);
				//Texture des tours
				loadTexture("../images/temp/sprite_tour.png", &towerTxt, imgTower);

				//Texture des shots	
				loadTexture("../images/shot.png", &shot, imgShot);
				//Texture menu
				loadTexture("../images/temp/sprite_menu1.png", &spriteMenu, imgButtonMenu);
				//Texture fond menu
				loadTexture("../images/fondMenu.png", &fondMenu, imgFondMenu);
				//Texture pour les boutons
				loadTexture("../images/temp/sprite_button1.png", &spriteButton, imgSpriteButton);
				//Bouton plus ou upgrate les tours
				loadTexture("../images/temp/bt_plus.png", &btPlus, imgbtPlus);
				//Texture fond menu up
				loadTexture("../images/temp/fondMenuUp.png", &fondMenuUp, imgFondMenuUp);

				//Texture fond Game Over
				loadTexture("../images/temp/GameOver.png", &fondGameOver, imgFondGameOver);
				//Texture fond Win
				loadTexture("../images/temp/YouWin.png", &fondWin, imgFondWin);

				drawMenuPrincipal (&menuPrincipal, &menuPrincipalButton);
		}else {//On joue
			
			drawMap(&texture);
			//Dessin du menu du dessus
			drawMenuUp(&spriteButton, &fondMenuUp);
			//Dessin du menu de gauche (les tours)
			drawMenuLeft(&spriteMenu, &fondMenu, *joueur);
			//Dessin de l'interface (données du joueur)
			joueur->drawInterface (&spriteButton);

			if(nbtexture == 0) {
				//Dessin du chemin et noeud
				map.drawRoad ();
			}

			//Si on veut voir les propriété d'une tour
			if(propriete == propTower) {
				//Affiche les propriétés de la tours
				tower->drawProprieteTower(&towerTxt, &spriteMenu, &btPlus, joueur);
				pMonster = NULL;
			}
			//Si on veut voir les proriétés d'un monstre
			else if(propriete == propMonster) {

					tower = NULL;
					if(pMonster != NULL) {
						if(pMonster->getPV() > 0) {
							//Affiche les propriété du monstre
							pMonster->drawProprieteMonster(&monsterTxt);
						}
						else {
							propriete = aucune;
							pMonster = NULL;
						}
					}
					else
						propriete = aucune;
			}

			map.apparitionMonster(monsters, j, *joueur);

			//Si nbVague = 20 vagues et plus de monstre alors gagné
			if(joueur->getNbVagues() == 20 && monsters->getLength() == 0) {

				testMouse = 0;
				testTower = 0;
				j = 0;
				i = 0;
				map.setNbMonstres(0);
				propriete = aucune;
				initAll(*monsters, *shots, *towers, *joueur);

				nbMenu = gameWin;
			}

			j++;

			//Création d'un pointeur tour temporaire pour parcourir la liste de tours
			Tower* tower = towers->getHead();

			//Parcours la liste de tours
			while(tower != NULL){

				// Si tower = au pointeur du dernier de la liste
				if(tower == towers->getTail()) {
					if(testMouse == 0) {
						if((tower->getCompteur())%(int)(tower->getRate()) == 0) {
							if(tower->reach(shots, monsters) != 0) {
								tower->setCompteur(0);
							}
						}
					}
				}
				else {
					if((tower->getCompteur())%(int)(tower->getRate()) == 0) {
						if(tower->reach(shots, monsters) != 0) {
							tower->setCompteur(0);
						}
					}
				}

				tower->setCompteur(tower->getCompteur()+1);
				tower = tower->getNext();
			}

			//Dessiner les tours
			drawTower(&towerTxt, *towers, *monsters, tower, testMouse, testTower);
			//Dessiner les monstres
			monsters->drawMonster(&monsterTxt);

			if(monsters->moveMonster(*(map.getListNode().getTail())) == 2) {

				//Pointeur shot temporaire pour parcourir la liste
				Shot *tmpShot = shots->getHead();

				while(tmpShot != NULL) {
					if(tmpShot->getTarget().isSame(shots->getHead()->getTarget())){
						Monster empty;
						tmpShot->setTarget(empty);
					}

					*tmpShot = tmpShot->getNext();
				}

				monsters->removeMonster(monsters->getHead());

				//Il a perdu

				testMouse = 0;
				testTower = 0;
				j = 0;
				i = 0;
				nb_monster = 0;
				propriete = aucune;

				initAll(*monsters, *shots, *towers, *joueur);

				nbMenu = gameOver;
			}
			

			while(i < 3) {
				shots->draw(&shot); //dessin du shot
				shots->moveShot(); //Bouger le shot
				collisionMissile(*shots, *monsters, *joueur, *pMonster, &propriete); //test de collision
				i++;
			}
			i = 0;
			k++;

		}

		glFlush();
		SDL_GL_SwapBuffers();    

		SDL_Event e;
		while(SDL_PollEvent(&e)) {
			if(e.type == SDL_QUIT) {
				loop = 0;
				break;
			}
		      
			switch(e.type) {

				case SDL_VIDEORESIZE:
					WINDOW_WIDTH = e.resize.w;
					WINDOW_HEIGHT = e.resize.h;
					setVideoMode();
					break;

				case SDL_MOUSEBUTTONDOWN :
					if(e.button.button == SDL_BUTTON_LEFT) {
						if(nbMenu != play) {
							//test click menu principal
							clickMenuPrincipal(e.button.x, e.button.y, &nbMenu); 
						}
						else {

							if(testMouse == 0) {
								//test click sur le menu de la tour
								if(clickMenuTour(*towers, *fileTower, *joueur, e.button.x, e.button.y) == 1)
									testMouse = 1;
							}
							else {
								if(testTower != 0)
									testMouse = 0;
							}

							//Test click exit
							loop = clickExit(*monsters, *shots, *towers, *fileTower, &map, *joueur, e.button.x, e.button.y);
							//Test click sur une tower
							tower = clickTower(*towers, e.button.x, e.button.y, &propriete);
							//Test click sur un monstre
							pMonster = clickMonster(*monsters, e.button.x, e.button.y, &propriete);
						}
					}
					break;

				case SDL_MOUSEMOTION :
					if(testMouse == 1) {
						//Bouger la tour et test si elle est sur une zone constructible ou non
						if(towers->moveTower(towers->getTail(), map.getList_pixels(), e.button.x, e.button.y) == 1)
							testTower = 1;
						else
							testTower = 0;
					}

					break;

				case SDL_KEYDOWN:
			  		switch(e.key.keysym.sym){
		    			case SDLK_ESCAPE : 
							loop = 0;
							freeAll(*monsters, *shots, *towers, *fileTower, map, *joueur);
							break;

			    		default : break;
			 		}
			  		break;
			  
				default:
			  		break;
			}
	
		}

		Uint32 elapsedTime = SDL_GetTicks() - startTime;
		if(elapsedTime < FRAMERATE_MILLISECONDS) {
			SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
		}
	  }


	glBindTexture(GL_TEXTURE_2D, 0);

	//Free toutes les textures
	freeTexture(&texture, imgMap);
	freeTexture(&monsterTxt, imgMonster);
	freeTexture(&towerTxt, imgTower);
	freeTexture(&shot, imgShot);
	freeTexture(&spriteMenu, imgButtonMenu);
	freeTexture(&fondMenu, imgFondMenu);
	freeTexture(&spriteButton, imgSpriteButton);
	freeTexture(&btPlus, imgbtPlus);
	freeTexture(&fondMenuUp, imgFondMenuUp);
	freeTexture(&fondGameOver, imgFondGameOver);
	freeTexture(&fondWin, imgFondWin);

	SDL_Quit();
	return EXIT_SUCCESS;
}
