#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "sdl_tools.h"
#include "geometry/Color3f.h"
#include "element/Monster.h"
#include "element/Tower.h"
#include "element/Shot.h"
#include "file/Map.h"
#include "file/Texture.h"
#include "file/Image.h"
#include "ihm/Node.h"
#include "ihm/Draw.h"
#include "ihm/Menu.h"
#include "ihm/Interface.h"
#include "file/FileTower.h"

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
	int nbMenu = 0;
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

    Map map = NULL;

	/***** Variables ******/
	//Texture menuMap
	GLuint menuMap;
	SDL_Surface* imgMenuMap = NULL;
	loadTexture("./images/menu-map.png", &menuMap, imgMenuMap);

	//Texture menuMap button
	GLuint menuMapButton;
	SDL_Surface* imgMenuMapButton = NULL;
	loadTexture("./images/sprite_bt-texture.png", &menuMapButton, imgMenuMapButton);


	//Texture menuPrincipal
	GLuint menuPrincipal;
	SDL_Surface* imgMenuPrincipal = NULL;

	//Texture menuPrincipal button
	GLuint menuPrincipalButton;
	SDL_Surface* imgMenuPrincipalButton = NULL;

	//La carte
	GLuint texture;
	SDL_Surface* imgMap = NULL;

	//Texture aide
	GLuint help;
	SDL_Surface* imgHelp = NULL;

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

	//Texture passer les tuto
	GLuint fondTuto;
	SDL_Surface* imgFondTuto = NULL;


	//Initialisation de l'interface
	Joueur joueur = new Joueur();

	//Initialisation de la liste de monstre
	listMonster monsters = new listMonster();
	//Initialisation de la liste de tours
	listTower towers = new listTower();
	//Initialisation de la liste de shots
	listShot shots = new listShot();

	//Initialisation de la liste de tours (file) --------------------------------------------------AUCUNE IDEE DE CE A QUOI CA SERT
	listFileTower fileTower =  new listFileTower ("../data/IDTtower.idt");

	int i = 0;
	int j = 0;
	int k = 0;
	Propriete propriete = aucune;
	int apparition = 130;
	int infoMoney = 0;

	//Pour afficher les propriétés
	Tower tower = NULL;
	Monster pMonster = NULL;

	bool loop = 1;

	/**** Main loop ***/
  	while(loop) {
   		Uint32 startTime = SDL_GetTicks();

	    	/* dessin */

		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
/************************************************************************************************************************/
		if(nbMenu == gameOver)
			drawGameOverWin(&fondGameOver, &menuPrincipalButton);
		else if(nbMenu == gameWin)
			drawGameOverWin(&fondWin, &menuPrincipalButton);
		else if(nbMenu == menu) {

				loadTexture("../images/temp/MenuPrincipal.png", &menuPrincipal, imgMenuPrincipal);

				loadTexture("../images/temp/sprite_button_menu.png", &menuPrincipalButton, imgMenuPrincipalButton);

				//La carte
				Map map = loadMap("./data/IDTMap1.idt");
				//Texture de la carte

				loadMapTexture(map, &texture, imgMap);
				if(nbtexture == 1)
					loadTexture("../images/temp/map1.ppm", &texture, imgMap);
				
				//Texture des monstres
				loadTexture("../images/temp/sprite_monster.png", &monsterTxtTxt, imgMonster);
				//Texture des tours
				loadTexture("../images/temp/sprite_tour.png", &towerTxtTxt, imgTower);

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
		}else {
			
			drawMap(&texture);
			//Dessin du menu du dessus
			drawMenuUp(&spriteButton, &fondMenuUp);
			//Dessin du menu de gauche (les tours)
			drawMenuLeft(&spriteMenu, &fondMenu, joueur);
			//Dessin de l'interface (données du joueur)
			drawInterface (&spriteButton, joueur);

			if(nbtexture == 0) {
				//Dessin du chemin et noeud
				map.drawRoad ();
			}

			//Si proprité = 1
			if(propriete == propTower) {
				//Affiche les propriétés de la tours
				tower.drawProprieteTower(&towerTxt, &spriteMenu, &btPlus, interface);
				pMonster = NULL;
			}
			//Si propriété = 2
				else if(propriete == propMonster) {

					tower = NULL;
					if(pMonster != NULL) {
						if(pMonster->pv > 0) {
							//Affiche les propriété du monstre
							drawProprieteMonster(&monsterTxt, pMonster);
						}
						else {
							propriete = 0;
							pMonster = NULL;
						}
					}
					else
						propriete = 0;
				}

				//Si c'est le tuto alors le jeu est en pause
				if(tuto != 0) 
					play = 1;
				else if(tuto == 0 && tutoend == 1) {
					play = 0;
					tutoend=0;
				}

				//Si ce n'est pas en pause
				if(play != 1) {

					apparitionMonster(monsters, interface, map, &apparition, j, &nb_monster);

					//Si lvl 19 (20 vagues) et plus de monstre alors gagner
					if(interface->lvl == 20 && monsters->length == 0) {

						play = 0;
						testMouse = 0;
						testTower = 0;
						j = 0;
						i = 0;
						nb_monster = 0;
						propriete = 0;
						aide = 0;
						initAll(monsters, shots, towers, interface);

						nbMenu = 5;
					}

					j++;

					//Création d'un pointeur tour temporaire pour parcourir la liste de tours
					Tower *p_temp = towers->p_head;

					//Parcours la liste de tours
					while(p_temp != NULL){

						// Si p_temp = au pointeur du dernier de la liste
						if(p_temp == towers->p_tail) {
							if(testMouse == 0) {
								if((p_temp->compteur)%(p_temp->rate) == 0) {
									if(inSight (shots, monsters, p_temp) != 0) {
										(p_temp->compteur)=0;
									}
								}
							}
						}
						else {
							if((p_temp->compteur)%(p_temp->rate) == 0) {
								if(inSight (shots, monsters, p_temp) != 0) {
									(p_temp->compteur)=0;
								}
							}
						}

						(p_temp->compteur)++;
						p_temp = p_temp->p_next;
					}
				}

				//Dessiner les tours
				drawTower(&towerTxt, towers, monsters, tower, testMouse, testTower);
				//Dessiner les monstres
				drawMonster(&monsterTxt, monsters, play);

				//Si le jeu n'est pas en pause
				if(play != 1) {

					//Bouger le monstre
					if(moveMonster(monsters, map->list_node->p_tail, k) == 2) {

						//Pointeur shot temporaire pour parcourir la liste
						Shot *p_tempS = shots->p_head;

						while(p_tempS != NULL) {
							if(p_tempS->target == shots->p_head)
								p_tempS->target == NULL;

							p_tempS = p_tempS->p_next;
						}
						monsters = removeMonster(monsters, monsters->p_head);
						udapteLife(interface);
						if(interface->life <= 0) {
							play = 0;
							testMouse = 0;
							testTower = 0;
							j = 0;
							i = 0;
							nb_monster = 0;
							propriete = 0;
							aide = 0;

							initAll(monsters, shots, towers, interface);
	
							nbMenu = 4;
						}
					}

					while(i < 3) {
						drawShot(&shot, shots); //dessin du shot
						moveShot(shots); //Bouger le shot
						collisionMissile(shots, monsters, interface, pMonster, &propriete); //test de collision
						i++;
					}
					i = 0;
					k++;

				}
				else {
					drawShot(&shot, shots); //dessin du shot
				}

				if(infoMoney != 0)
					drawMoney(tower, infoMoney);

				if(tuto != 0) 
					drawTutorial(&fondTuto, tuto);
			}
		}
		

		glFlush();
		SDL_GL_SwapBuffers();
		/* ****** */    

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
						if(nbMenu != 3) {
							//test click menu principal
							clickMenuPrincipale(e.button.x, e.button.y, &nbMenu, &nbMap, &nbtexture); 
						}
						else {

							if(testMouse == 0) {
								//test click sur le menu de la tour
								if(clickMenuTour(towers, fileTower, interface, e.button.x, e.button.y) == 1)
									testMouse = 1;
							}
							else {
								if(testTower != 0)
									testMouse = 0;
							}

							if(tower != NULL && propriete == 1) {
								//Test click pour supprimer une tour
								clickTourDelete(towers, shots, tower, interface, e.button.x, e.button.y, &propriete);
								//Test click pour upgrade une tour
								clickTourUpgrate(tower, interface, e.button.x, e.button.y, &propriete);
							}

							//test click play / pause / avance rapide
							play = clickTime(e.button.x, e.button.y, play, &nb_monster, &j);
							//Test click exit
							loop = clickExit(monsters, shots, towers, fileTower, map, interface, e.button.x, e.button.y, aide);
							//Test click sur une tower
							tower = clickTower(towers, e.button.x, e.button.y, &propriete);
							//Test click sur un monstre
							pMonster = clickMonster(monsters, e.button.x, e.button.y, &propriete);
							//Test click aide
							aide = clickAide(e.button.x, e.button.y, aide);
							//Test ckick tuto
							tuto = clickTuto(tower, e.button.x, e.button.y, tuto, testMouse, testTower, &tutoend);
						}
					}
					break;

				case SDL_MOUSEMOTION :
					if(testMouse == 1) {
						//Bouger la tour et test si elle est sur une zone constructible ou non
						if(moveTower(towers, towers->p_tail, map->list_pixels, e.button.x, e.button.y) == 1)
							testTower = 1;
						else
							testTower = 0;
					}

					infoMoney = mouseInfo(e.button.x, e.button.y, testMouse, propriete);					

					break;

				case SDL_KEYDOWN:
			  		switch(e.key.keysym.sym){
		    			case SDLK_ESCAPE : 
							loop = 0;
							freeAll(monsters, shots, towers, fileTower, map, interface);
							break;

			    		default : break;
			 		}
			  		break;
			  
				default:
			  		break;
			}
	
		}

		Uint32 elapsedTime = SDL_GetTicks() - startTime;
		if(play == 0) {
			if(elapsedTime < FRAMERATE_MILLISECONDS) {
				SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
			}
		}
		else if(play == 2) {
			if(elapsedTime < FRAMERATE_MILLISECONDS_RAPIDE) {
		      	SDL_Delay(FRAMERATE_MILLISECONDS_RAPIDE - elapsedTime);
		   	}
		}
	  }


	glBindTexture(GL_TEXTURE_2D, 0);

	//Free toutes les textures
	freeTexture(&menuMap, imgMenuMap);
	freeTexture(&menuMapButton, imgMenuMapButton);
	freeTexture(&menuPrincipal, imgMenuPrincipal);
	freeTexture(&menuPrincipalButton, imgMenuPrincipalButton);
	freeTexture(&texture, imgMap);
	freeTexture(&help, imgHelp);
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
	freeTexture(&fondTuto, imgFondTuto);

	SDL_Quit();
	return EXIT_SUCCESS;
}