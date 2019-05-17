#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <cstdio>
#include "../include/installation.h"
#include "../include/joueur.h"
#include "../include/map.h"
#include "../include/monstre.h"
#include "../include/tower.h"

/* Dimensions de la fenetre */
static unsigned int WINDOW_WIDTH = 800;
static unsigned int WINDOW_HEIGHT = 450;

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

int main(int argc, char** argv) 
{
    int testMouse = 0;
	int play = 0;
	int testTower = 0;
	int nbMenu = 0;
	int nbMap = 0;
	int nbtexture = 0;
	int tuto = 1;
	int tutoend = 0;

	/* Initialisation */
	if(-1 == SDL_Init(SDL_INIT_VIDEO)) {
        	fprintf(stderr, "Impossible d'initialiser la SDL. Fin du programme.\n");
        	return EXIT_FAILURE;
    	}

	setVideoMode();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glutInit(&argc, argv); // initialisation de GLUT

    SDL_WM_SetCaption("Tower Defence", NULL);

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

	Map* map = NULL;

	//La carte
	GLuint texture;
	SDL_Surface* imgMap = NULL;

	//Texture aide
	GLuint help;
	SDL_Surface* imgHelp = NULL;

	//Texture des monstres
	GLuint monster;
	SDL_Surface* imgMonster = NULL;

	//Texture des tours
	GLuint tower;
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
	Interface* interface = newInterface();

	//Initialisation de la liste de monstre
	LMonster* p_lmonster = new_LMonster();
	//Initialisation de la liste de tours
	LTower* p_ltower = new_LTower();
	//Initialisation de la liste de shots
	LShot* p_lshot = new_LShot();

	//Initialisation de la liste de tours (file)
	LFileTower* p_lfileTower =  newFileTower ("./data/IDTtower.idt");

	int i = 0;
	int nb_monster = 0, j = 0;
	int k = 0;
	int propriete = 0;
	int aide = 0;
	int apparition = 130;
	int infoMoney = 0;

	//Pour afficher les propriétés
	Tower* pTower = NULL;
	Monster* pMonster = NULL;

	int loop = 1;

	/**** Main loop ***/
  	while(loop) {
   		Uint32 startTime = SDL_GetTicks();

	    	/* dessin */

		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);

		if(nbMenu == 0)
			drawMenuMap (&menuMap, &menuMapButton, nbtexture);
		else if(nbMenu == 4)
			drawGameOverWin(&fondGameOver, &menuPrincipalButton);
		else if(nbMenu == 5)
			drawGameOverWin(&fondWin, &menuPrincipalButton);
		else if(nbMenu == 1) {
			
			//Charge les textures de la première carte
			if(nbMap == 1) {

				loadTexture("./images/map1/MenuPrincipal.png", &menuPrincipal, imgMenuPrincipal);

				loadTexture("./images/map1/sprite_button_menu.png", &menuPrincipalButton, imgMenuPrincipalButton);

				//La carte
				map = newMap ("./data/IDTMap1.idt");
				//Texture de la carte

				loadMapTexture(map, &texture, imgMap);
				if(nbtexture == 1)
					loadTexture("./images/map1/map1.ppm", &texture, imgMap);
				//Texture aide
				loadTexture("./images/map1/help.png", &help, imgHelp);

				//Texture des monstres
				loadTexture("./images/map1/sprite_monster.png", &monster, imgMonster);
				//Texture des tours
				loadTexture("./images/map1/sprite_tour.png", &tower, imgTower);

				//Texture des shots	
				loadTexture("./images/shot.png", &shot, imgShot);
				//Texture menu
				loadTexture("./images/map1/sprite_menu1.png", &spriteMenu, imgButtonMenu);
				//Texture fond menu
				loadTexture("./images/fondMenu.png", &fondMenu, imgFondMenu);
				//Texture pour les boutons
				loadTexture("./images/map1/sprite_button1.png", &spriteButton, imgSpriteButton);
				//Bouton plus ou upgrate les tours
				loadTexture("./images/map1/bt_plus.png", &btPlus, imgbtPlus);
				//Texture fond menu up
				loadTexture("./images/map1/fondMenuUp.png", &fondMenuUp, imgFondMenuUp);

				//Texture fond Game Over
				loadTexture("./images/map1/GameOver.png", &fondGameOver, imgFondGameOver);
				//Texture fond Win
				loadTexture("./images/map1/YouWin.png", &fondWin, imgFondWin);
				//Texture fond Tuto
				loadTexture("./images/btTuto.png", &fondTuto, imgFondTuto);

			}
			//Charge les textures de la deuxième carte
			else if(nbMap == 2) {
				loadTexture("./images/map2/MenuPrincipal.png", &menuPrincipal, imgMenuPrincipal);

				loadTexture("./images/map2/sprite_button_menu.png", &menuPrincipalButton, imgMenuPrincipalButton);

				//La carte
				map = newMap ("./data/IDTMap2.idt");
				//Texture de la carte

				loadMapTexture(map, &texture, imgMap);
				if(nbtexture == 1)
					loadTexture("./images/map2/map2.ppm", &texture, imgMap);
				//Texture aide
				loadTexture("./images/map2/help.png", &help, imgHelp);

				//Texture des monstres
				loadTexture("./images/map2/sprite_monster.png", &monster, imgMonster);
				//Texture des tours
				loadTexture("./images/map2/sprite_tour.png", &tower, imgTower);

				//Texture des shots	
				loadTexture("./images/shot.png", &shot, imgShot);
				//Texture menu
				loadTexture("./images/map2/sprite_menu1.png", &spriteMenu, imgButtonMenu);
				//Texture fond menu
				loadTexture("./images/fondMenu.png", &fondMenu, imgFondMenu);
				//Texture pour les boutons
				loadTexture("./images/map2/sprite_button1.png", &spriteButton, imgSpriteButton);
				//Bouton plus ou upgrate les tours
				loadTexture("./images/map2/bt_plus.png", &btPlus, imgbtPlus);
				//Texture fond menu up
				loadTexture("./images/map2/fondMenuUp.png", &fondMenuUp, imgFondMenuUp);
				//Texture fond Game Over
				loadTexture("./images/map2/GameOver.png", &fondGameOver, imgFondGameOver);
				//Texture fond Win
				loadTexture("./images/map2/YouWin.png", &fondWin, imgFondWin);
				//Texture fond Tuto
				loadTexture("./images/btTuto.png", &fondTuto, imgFondTuto);
			}

			drawMenuPrincipale (&menuPrincipal, &menuPrincipalButton);
		}
		else if(nbMenu == 2) 
			drawHelp (&help, &spriteButton, &menuPrincipalButton, nbMenu);
		else {
			//Afficher l'aide
			if(aide == 1)
				drawHelp (&help, &spriteButton, &menuPrincipalButton, nbMenu);
			//Affiche la carte et les différents élements du jeu
			else {
				//Dessin de la carte
				drawMap(&texture);
				//Dessin du menu du dessus
				drawMenuUp(&spriteButton, &fondMenuUp, play);
				//Dessin du menu de gauche (les tours)
				drawMenuLeft(&spriteMenu, &fondMenu, interface);
				//Dessin de l'interface (données du joueur)
				drawInterface (&spriteButton, interface);

				if(nbtexture == 0) {
					//Dessin du chemin et noeud
					drawRoad (map);
				}

				//Si proprité = 1
				if(propriete == 1) {
					//Affiche les propriétés de la tours
					drawProprieteTower(&tower, &spriteMenu, &btPlus, pTower, interface);
					pMonster = NULL;
				}
				//Si propriété = 2
				else if(propriete == 2) {

					pTower = NULL;
					if(pMonster != NULL) {
						if(pMonster->pv > 0) {
							//Affiche les propriété du monstre
							drawProprieteMonster(&monster, pMonster);
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

					apparitionMonster(p_lmonster, interface, map, &apparition, j, &nb_monster);

					//Si lvl 19 (20 vagues) et plus de monstre alors gagner
					if(interface->lvl == 20 && p_lmonster->length == 0) {

						play = 0;
						testMouse = 0;
						testTower = 0;
						j = 0;
						i = 0;
						nb_monster = 0;
						propriete = 0;
						aide = 0;
						initAll(p_lmonster, p_lshot, p_ltower, interface);

						nbMenu = 5;
					}

					j++;

					//Création d'un pointeur tour temporaire pour parcourir la liste de tours
					Tower *p_temp = p_ltower->p_head;

					//Parcours la liste de tours
					while(p_temp != NULL){

						// Si p_temp = au pointeur du dernier de la liste
						if(p_temp == p_ltower->p_tail) {
							if(testMouse == 0) {
								if((p_temp->compteur)%(p_temp->rate) == 0) {
									if(inSight (p_lshot, p_lmonster, p_temp) != 0) {
										(p_temp->compteur)=0;
									}
								}
							}
						}
						else {
							if((p_temp->compteur)%(p_temp->rate) == 0) {
								if(inSight (p_lshot, p_lmonster, p_temp) != 0) {
									(p_temp->compteur)=0;
								}
							}
						}

						(p_temp->compteur)++;
						p_temp = p_temp->p_next;
					}
				}

				//Dessiner les tours
				drawTower(&tower, p_ltower, p_lmonster, pTower, testMouse, testTower);
				//Dessiner les monstres
				drawMonster(&monster, p_lmonster, play);

				//Si le jeu n'est pas en pause
				if(play != 1) {

					//Bouger le monstre
					if(moveMonster(p_lmonster, map->list_node->p_tail, k) == 2) {

						//Pointeur shot temporaire pour parcourir la liste
						Shot *p_tempS = p_lshot->p_head;

						while(p_tempS != NULL) {
							if(p_tempS->target == p_lshot->p_head)
								p_tempS->target == NULL;

							p_tempS = p_tempS->p_next;
						}
						p_lmonster = removeMonster(p_lmonster, p_lmonster->p_head);
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

							initAll(p_lmonster, p_lshot, p_ltower, interface);
	
							nbMenu = 4;
						}
					}

					while(i < 3) {
						drawShot(&shot, p_lshot); //dessin du shot
						moveShot(p_lshot); //Bouger le shot
						collisionMissile(p_lshot, p_lmonster, interface, pMonster, &propriete); //test de collision
						i++;
					}
					i = 0;
					k++;

				}
				else {
					drawShot(&shot, p_lshot); //dessin du shot
				}

				if(infoMoney != 0)
					drawMoney(pTower, infoMoney);

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
								if(clickMenuTour(p_ltower, p_lfileTower, interface, e.button.x, e.button.y) == 1)
									testMouse = 1;
							}
							else {
								if(testTower != 0)
									testMouse = 0;
							}

							if(pTower != NULL && propriete == 1) {
								//Test click pour supprimer une tour
								clickTourDelete(p_ltower, p_lshot, pTower, interface, e.button.x, e.button.y, &propriete);
								//Test click pour upgrade une tour
								clickTourUpgrate(pTower, interface, e.button.x, e.button.y, &propriete);
							}

							//test click play / pause / avance rapide
							play = clickTime(e.button.x, e.button.y, play, &nb_monster, &j);
							//Test click exit
							loop = clickExit(p_lmonster, p_lshot, p_ltower, p_lfileTower, map, interface, e.button.x, e.button.y, aide);
							//Test click sur une tower
							pTower = clickTower(p_ltower, e.button.x, e.button.y, &propriete);
							//Test click sur un monstre
							pMonster = clickMonster(p_lmonster, e.button.x, e.button.y, &propriete);
							//Test click aide
							aide = clickAide(e.button.x, e.button.y, aide);
							//Test ckick tuto
							tuto = clickTuto(pTower, e.button.x, e.button.y, tuto, testMouse, testTower, &tutoend);
						}
					}
					break;

				case SDL_MOUSEMOTION :
					if(testMouse == 1) {
						//Bouger la tour et test si elle est sur une zone constructible ou non
						if(moveTower(p_ltower, p_ltower->p_tail, map->list_pixels, e.button.x, e.button.y) == 1)
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
							freeAll(p_lmonster, p_lshot, p_ltower, p_lfileTower, map, interface);
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
	freeTexture(&monster, imgMonster);
	freeTexture(&tower, imgTower);
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
