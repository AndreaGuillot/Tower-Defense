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
#include "element/Installation.h"
#include "element/Shot.h"
#include "file/Sound.h"
#include "file/Map.h"
#include "file/Texture.h"
#include "file/Image.h"
#include "ihm/Node.h"
#include "ihm/Draw.h"
#include "ihm/Menu.h"
#include "ihm/Interface.h"
#include "file/FileTower.h"
#include "file/FileInstallation.h"

static unsigned int WINDOW_WIDTH = 800;
static unsigned int WINDOW_HEIGHT = 660;
static const unsigned int BIT_PER_PIXEL = 32;
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 80;
static const unsigned int NBVAGUES = 50;
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

	int testMouse = 0; //Voir si on a cliqué sur une tour avant, si c'est 1, on l'a en main
	int testMouseInstallation = 0; //Voir si on a cliqué sur une installation avant, si c'est 1, on l'a en main
	int testTower = 0;
	int testInstallation = 0;
	int nbMenu = 1;
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

	/***** Variables ******/

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
	GLuint monsterText;
	SDL_Surface* imgMonster = NULL;

	//Texture des tours
	GLuint towerText;
	SDL_Surface* imgTower = NULL;

	//Texture des tours
	GLuint installationText;
	SDL_Surface* imgInstallation = NULL;

	//Texture des shots	
	GLuint shotText;
	SDL_Surface* imgShot = NULL;

	//Texture menu
	GLuint menu_tour;
	SDL_Surface* imgButtonMenu = NULL;

	//Texture fond menu
	GLuint fondMenu;
	SDL_Surface* imgFondMenu = NULL;

	//Texture pour les boutons
	GLuint Boutons;
	SDL_Surface* imgBoutons = NULL;

	//Texture fond menu up
	GLuint fondHaut;
	SDL_Surface* imgfondHaut = NULL;

	//Texture fond Game Over
	GLuint fondGameOver;
	SDL_Surface* imgFondGameOver = NULL;
	
	//Texture fond Win
	GLuint fondWin;
	SDL_Surface* imgFondWin = NULL;

	//Initialisation de l'joueur
	Joueur* joueur = newGame();

	//Initialisation de la liste de monstre
	ListMonsters* listMonsters = new_ListMonsters();
	//Initialisation de la liste de tours
	LTower* listTowers = new_LTower();
	//Initialisation de la liste de tours
	LInstallation* listInstallations = new_LInstallation();
	//Initialisation de la liste de shots
	LShot* listShots = new_LShot();

	//Initialisation de la liste de tours (file)
	LFileTower* p_lfileTower =  newFileTower ();
	LFileInstallation* p_lfileInstallation =  newFileInstallation ();

	int i = 0;
	int nb_monster = 0, j = 0;
	int k = 0;
	int propriete = 0;
	int aide = 0;
	int apparition = 130;

	//Pour afficher les propriétés
	Tower* tower = NULL;
	Monster* monster = NULL;
	Installation* installation = NULL;

	int loop = 1;

	    initSounds();
	    loadMusics(); 
   		playMusic(MUSICCANAL,0,1);

	/**** Main loop ***/
  	while(loop) {
   		Uint32 startTime = SDL_GetTicks();
	    	/* dessin */
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);

		if(nbMenu == 4)

			drawGameOverWin(&fondGameOver, &menuPrincipalButton);
		else if(nbMenu == 5)
			drawGameOverWin(&fondWin, &menuPrincipalButton);
		else if(nbMenu == 1) {
			
			//Charge les textures de la première carte
				loadTexture("./images/MenuPrincipal.png", &menuPrincipal, imgMenuPrincipal);

				loadTexture("./images/gros_boutons.png", &menuPrincipalButton, imgMenuPrincipalButton);

				//La carte
				map = newMap ("./data/IDTMap1.idt");
				//Texture de la carte

				loadMapTexture(map, &texture, imgMap);
				loadTexture("./images/map1.ppm", &texture, imgMap);
				//Texture aide
				loadTexture("./images/help.png", &help, imgHelp);

				//Texture des monstres
				loadTexture("./images/monsters.png", &monsterText, imgMonster);
				//Texture des tours
				loadTexture("./images/tours.png", &towerText, imgTower);
				//Texture des installations
				loadTexture("./images/installations.png", &installationText, imgInstallation);

				//Texture des shots	
				loadTexture("./images/shot.png", &shotText, imgShot);
				//Texture menu
				loadTexture("./images/menu_tours.png", &menu_tour, imgButtonMenu);
				//Texture fond menu
				loadTexture("./images/fond_noir.png", &fondMenu, imgFondMenu);
				//Texture pour les boutons
				loadTexture("./images/boutons.png", &Boutons, imgBoutons);
				//Texture fond menu up
				loadTexture("./images/menu_haut.png", &fondHaut, imgfondHaut);

				//Texture fond Game Over
				loadTexture("./images/failed.png", &fondGameOver, imgFondGameOver);
				//Texture fond Win
				loadTexture("./images/win.png", &fondWin, imgFondWin);
				
			drawMenuPrincipal (&menuPrincipal, &menuPrincipalButton);
		}
		else if(nbMenu == 2) 
			drawHelp (&help, &Boutons, &menuPrincipalButton, nbMenu);
		else {
			//Afficher l'aide
			if(aide == 1)
				drawHelp (&help, &Boutons, &menuPrincipalButton, nbMenu);
			//Affiche la carte et les différents élements du jeu
			else {
				//Dessin de la carte
				drawMap(&texture);
				//Dessin du menu du dessus
				drawMenuUp(&Boutons, &fondHaut);
				//Dessin du menu de gauche (les tours)
				drawMenuLeft(&menu_tour, &fondMenu, joueur);
				//Dessin de l'joueur (données du joueur)
				drawInterface (&Boutons, joueur);

				//Si on veut voir les propriétés de la tour                                                                                                
				if(propriete == 1) {
					//Affiche les propriétés de la tours
					drawProprieteTower(&towerText, &menu_tour, tower, joueur);
					monster = NULL;
					installation = NULL;
				}
				//Si on veut voir propriété monstre
				else if(propriete == 2) {

					tower = NULL;
					installation = NULL;
					if(monster != NULL) {
						if(monster->pv > 0) {
							//Affiche les propriété du monstre
							drawProprieteMonster(&monsterText, monster);
						}
						else {
							propriete = 0;
							monster = NULL;
						}
					}
					else
						propriete = 0;

				//Si on veut voir propriété installation
				}else if(propriete == 3) {

					drawProprieteInstallation(&installationText, &menu_tour, installation, joueur);
					monster = NULL;
					tower = NULL;
				}

					apparitionMonster(listMonsters, joueur, map, &apparition, j, &nb_monster);

					//Si lvl 49 (50 vagues) et plus de monstre alors gagner
					if(joueur->lvl == NBVAGUES && listMonsters->length == 0) {

						testMouse = 0;
						testMouseInstallation = 0;
						testTower = 0;
						testInstallation = 0;
						j = 0;
						i = 0;
						nb_monster = 0;
						propriete = 0;
						aide = 0;
						initAll(listMonsters, listShots, listTowers, listInstallations, joueur);

						nbMenu = 5;
					}

					j++;

					//Création d'un pointeur tour temporaire pour parcourir la liste de tours
					Tower *p_temp = listTowers->p_head;

					//Parcours la liste de tours
					while(p_temp != NULL){

						// Si p_temp = au pointeur du dernier de la liste
						if(p_temp == listTowers->p_tail) {
							if(testMouse == 0) {
								if((p_temp->compteur)%(p_temp->rate) == 0) {
									if(inSight (listShots, listMonsters, p_temp) != 0) {
										(p_temp->compteur)=0;
									}
								}
							}
						}
						else {
							if((p_temp->compteur)%(p_temp->rate) == 0) {
								if(inSight (listShots, listMonsters, p_temp) != 0) {
									(p_temp->compteur)=0;
								}
							}
						}

						(p_temp->compteur)++;
						p_temp = p_temp->p_next;
					}

					//Création d'un pointeur tour temporaire pour parcourir la liste de tours
					Installation *p_tmp = listInstallations->p_head;

					//Parcours la liste de tours
					while(p_tmp != NULL){

						// Si p_tmp = au pointeur du dernier de la liste
						if(p_tmp == listInstallations->p_tail) {
							if(testMouseInstallation == 0) {
									if(reach (listInstallations, listTowers, p_tmp) != 0) {
										(p_tmp->compteur)=0;
									}
							}
						}
						else {
							if(reach (listInstallations, listTowers, p_tmp) != 0) {
								(p_tmp->compteur)=0;
							}
						}

						(p_tmp->compteur)++;
						p_tmp = p_tmp->p_next;
					}

				//Dessiner les tours
				drawTower(&towerText, listTowers, listMonsters, tower, testMouse, testTower);
				//Dessiner les installations
				drawInstallation(&installationText, listInstallations, installation, testMouseInstallation, testInstallation);
				//Dessiner les monstres
				drawMonster(&monsterText, listMonsters);


					//Bouger le monstre
					if(moveMonster(listMonsters, map->list_node->p_tail, k) == 2) {

						//Pointeur shot temporaire pour parcourir la liste
						Shot *p_tempS = listShots->p_head;

						while(p_tempS != NULL) {
							if(p_tempS->target == listShots->p_head)
								p_tempS->target == NULL;

							p_tempS = p_tempS->p_next;
						}
						listMonsters = removeMonster(listMonsters, listMonsters->p_head);

							testMouse = 0;
							testMouseInstallation = 0;
							testTower = 0;
							testInstallation = 0;
							j = 0;
							i = 0;
							nb_monster = 0;
							propriete = 0;
							aide = 0;

							initAll(listMonsters, listShots, listTowers, listInstallations, joueur);
	
							nbMenu = 4;
						
					}

					while(i < 3) {
						drawShot(&shotText, listShots); //dessin du shot
				   		moveShot(listShots); //Bouger le shot
						collisionMissile(listShots, listMonsters, joueur, monster, &propriete); //test de collision
						i++;
					}
					i = 0;
					k++;
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
							clickMenuPrincipal(e.button.x, e.button.y, &nbMenu, &nbtexture); 
						}
						else {

							if(testMouse == 0) {
								//test click sur le menu de la tour
								if(clickMenuTour(listTowers, p_lfileTower, joueur, e.button.x, e.button.y) == 1)
									testMouse = 1;
							}
							else {
								if(testTower != 0)
									testMouse = 0;
							}

							if(testMouseInstallation == 0) {
								//test click sur le menu de la installation
								if(clickMenuInstallation(listInstallations, p_lfileInstallation, joueur, e.button.x, e.button.y) == 1)
									testMouseInstallation = 1;
							}
							else {
								if(testInstallation != 0)
									testMouseInstallation = 0;
							}

							if(tower != NULL && propriete == 1) {
								//Test click pour supprimer une tour
								clickTourDelete(listTowers, listShots, tower, joueur, e.button.x, e.button.y, &propriete);
							}

							if(installation != NULL && propriete == 3) {
								//Test click pour supprimer une tour
								clickInstallationDelete(listInstallations, installation, joueur, e.button.x, e.button.y, &propriete, listTowers);
							}

							//Test click exit
							loop = clickExit(listMonsters, listShots, listTowers, listInstallations, p_lfileTower, p_lfileInstallation, map, joueur, e.button.x, e.button.y, aide);
							//Test click sur une tower
							tower = clickTower(listTowers, e.button.x, e.button.y, &propriete);
							//Test click sur une tower
							installation = clickInstallation(listInstallations, e.button.x, e.button.y, &propriete);
							//Test click sur un monstre
							monster = clickMonster(listMonsters, e.button.x, e.button.y, &propriete);
							//Test click aide
							aide = clickAide(e.button.x, e.button.y, aide);
						}
					}
					break;

				case SDL_MOUSEMOTION :
					if(testMouse == 1) {
						//Bouger la tour et test si elle est sur une zone constructible ou non
						if(moveTower(listTowers, listTowers->p_tail, map->list_pixels, e.button.x, e.button.y) == 1)
							testTower = 1;
						else
							testTower = 0;
					}

					if(testMouseInstallation == 1){
						if(moveInstallation(listInstallations, listInstallations->p_tail, map->list_pixels, e.button.x, e.button.y) == 1)
							testInstallation = 1;
						else
							testInstallation = 0;
					}

					break;

				case SDL_KEYDOWN:
			  		switch(e.key.keysym.sym){

		    			case 'q' : 
		    			case SDLK_ESCAPE : 
						loop = 0;
						freeAll(listMonsters, listShots, listTowers, listInstallations, p_lfileTower, p_lfileInstallation, map, joueur);
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
	freeTexture(&menuPrincipal, imgMenuPrincipal);
	freeTexture(&menuPrincipalButton, imgMenuPrincipalButton);
	freeTexture(&texture, imgMap);
	freeTexture(&help, imgHelp);
	freeTexture(&monsterText, imgMonster);
	freeTexture(&towerText, imgTower);
	freeTexture(&installationText, imgInstallation);
	freeTexture(&shotText, imgShot);
	freeTexture(&menu_tour, imgButtonMenu);
	freeTexture(&fondMenu, imgFondMenu);
	freeTexture(&Boutons, imgBoutons);
	freeTexture(&fondHaut, imgfondHaut);
	freeTexture(&fondGameOver, imgFondGameOver);
	freeTexture(&fondWin, imgFondWin);

    Mix_CloseAudio(); //Close Audiol'API 
	SDL_Quit();
	return EXIT_SUCCESS;
}
