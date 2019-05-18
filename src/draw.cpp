#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "../include/draw.h"

#define pi 3.14
#define PRIX_OCEANE 50
#define PRIX_JULES 60
#define PRIX_CLARA 80
#define PRIX_YOANN 120

int drawMenuPrincipal (GLuint* texture, GLuint* spriteButton) {
	if(texture != NULL) {

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *texture);

			glBegin(GL_QUADS);
			//couleur neutre
			glColor3ub(255,255,255);
			//coordonée de la texture
			glTexCoord2f(1, 1);
			//Cordonnée du quadrilatère 
			glVertex2f(800, 660);

			glTexCoord2f(1, 0);
			glVertex2f(800, 0);

			glTexCoord2f(0, 0);
			glVertex2f(0, 0);

			glTexCoord2f(0, 1);
			glVertex2f(0, 660);

			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);

		/** Bouton jouer **/

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *spriteButton);

			glBegin(GL_QUADS);
			//couleur neutre
			glColor3ub(255,255,255);
			//coordonée de la texture
			glTexCoord2f(1, 0.25);
			//Cordonnée du quadrilatère 
			glVertex2f(514, 352);

			glTexCoord2f(1, 0);
			glVertex2f(514, 296);

			glTexCoord2f(0, 0);
			glVertex2f(272, 296);

			glTexCoord2f(0, 0.25);
			glVertex2f(272, 352);

			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);

		/** Bouton aide **/

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *spriteButton);

			glBegin(GL_QUADS);
			//couleur neutre
			glColor3ub(255,255,255);
			//coordonée de la texture
			glTexCoord2f(1, 0.5);
			//Cordonnée du quadrilatère 
			glVertex2f(514, 421);

			glTexCoord2f(1, 0.25);
			glVertex2f(514, 364);

			glTexCoord2f(0, 0.25);
			glVertex2f(272, 364);

			glTexCoord2f(0, 0.5);
			glVertex2f(272, 421);

			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);

		/** Bouton changer de carte **/

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *spriteButton);

			glBegin(GL_QUADS);
			//couleur neutre
			glColor3ub(255,255,255);
			//coordonée de la texture
			glTexCoord2f(1, 0.75);
			//Cordonnée du quadrilatère 
			glVertex2f(514, 490);

			glTexCoord2f(1, 0.5);
			glVertex2f(514, 432);

			glTexCoord2f(0, 0.5);
			glVertex2f(272, 432);

			glTexCoord2f(0, 0.75);
			glVertex2f(272, 490);

			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);

	}
	else {
		fprintf(stderr, "Erreur la texture de la map n'existe pas\n");
		return 0;
	}

	return 1;

}

/*********************** Dessiner la map ***********************/
/* Dessine la map. Prend en paramètre une texture.	*/

int drawMap (GLuint* texture) {

	if(texture != NULL) {

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *texture);

			glBegin(GL_QUADS);
			//couleur neutre
			glColor3ub(255,255,255);
			//coordonée de la texture
			glTexCoord2f(1, 1);
			//Cordonnée du quadrilatère 
			glVertex2f(800, 660);

			glTexCoord2f(1, 0);
			glVertex2f(800, 60);

			glTexCoord2f(0, 0);
			glVertex2f(200, 60);

			glTexCoord2f(0, 1);
			glVertex2f(200, 660);

			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);
	}
	else {
		fprintf(stderr, "Erreur la texture de la map n'existe pas\n");
		return 0;
	}

	return 1;

}

/*********************** Dessiner le menu haut ***********************/
/* Dessine le menu. Prend en paramètre la texture pour le menu et la variable play. Retourne 0 en cas d'erreur 1 sinon.	*/

int drawMenuUp (GLuint* spriteButton, GLuint* fondMenuUp) {

	if(spriteButton != NULL) {

		/** Fonc menu **/
		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *fondMenuUp);

			glBegin(GL_QUADS);
			//couleur neutre
			glColor3ub(255,255,255);
			//coordonée de la texture
			glTexCoord2f(1, 1);
			//Cordonnée du quadrilatère 
			glVertex2f(800, 60);

			glTexCoord2f(1, 0);
			glVertex2f(800, 0);

			glTexCoord2f(0, 0);
			glVertex2f(0, 0);

			glTexCoord2f(0, 1);
			glVertex2f(0, 60);

			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);
		
		
		/** Bouton fermer **/

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *spriteButton);

			glBegin(GL_QUADS);
			//couleur neutre
			glColor3ub(255,255,255);
			//coordonée de la texture
			glTexCoord2f(1, 1);
			//Cordonnée du quadrilatère 
			glVertex2f(790, 45);

			glTexCoord2f(1, 0);
			glVertex2f(790, 15);

			glTexCoord2f(0.875, 0);
			glVertex2f(760, 15);

			glTexCoord2f(0.875, 1);
			glVertex2f(760, 45);

			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);

		/** Bouton play **/

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *spriteButton);

			glBegin(GL_QUADS);
			//couleur neutre
			glColor3ub(255,255,255);
			//coordonée de la texture
			glTexCoord2f(0.5, 1);
			//Cordonnée du quadrilatère 
			glVertex2f(720, 45);

			glTexCoord2f(0.5, 0);
			glVertex2f(720, 15);

			glTexCoord2f(0.375, 0);
			glVertex2f(690, 15);

			glTexCoord2f(0.375, 1);
			glVertex2f(690, 45);

			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);

	}
	else {
		fprintf(stderr, "Erreur il y un problème avec les textures.\n");
		return 0;
	}
	return 1;
}

/*********************** Dessiner le menu left ***********************/
/* Dessine le menu. Prend en paramètre les textures pour le menu et un pointeur vers l'interface.	*
*  Retourne 0 en cas d'erreur 1 sinon.									*/

int drawMenuLeft (GLuint* spriteMenu, GLuint* fondMenu, Joueur joueur) {

	if(spriteMenu != NULL && fondMenu != NULL) {
		
		/** Fond du menu de gauche **/

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D); 
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *fondMenu);

			glBegin(GL_QUADS);
			//coordonée de la texture
			glTexCoord2f(1, 1);
			//Cordonnée du quadrilatère 
			glVertex2f(200, 660);

			glTexCoord2f(1, 0);
			glVertex2f(200, 60);

			glTexCoord2f(0, 0);
			glVertex2f(0, 60);

			glTexCoord2f(0, 1);
			glVertex2f(0, 660);

			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);

		/*** TOUR OCEANE (archer) : 50 pieces ***/

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *spriteMenu);

			if(joueur.getArgent() >= PRIX_OCEANE)
				glColor4f(255,255,255, 1);
			else 
				glColor4f(255,255,255, 0.5);

			glBegin(GL_QUADS);
			//coordonée de la texture
			glTexCoord2f(1, 0.142);
			//Cordonnée du quadrilatère 
			glVertex2f(190, 120);

			glTexCoord2f(1, 0);
			glVertex2f(190, 70);

			glTexCoord2f(0, 0);
			glVertex2f(10, 70);

			glTexCoord2f(0, 0.142);
			glVertex2f(10, 120);

			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);


		/*** TOUR JULES (multidirectionnelle) : 60 pieces***/

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *spriteMenu);

			if(joueur.getArgent() >= PRIX_JULES)
				glColor4f(255,255,255, 1);
			else 
				glColor4f(255,255,255, 0.5);

			glBegin(GL_QUADS);
			//coordonée de la texture
			glTexCoord2f(1, 0.285);
			//Cordonnée du quadrilatère 
			glVertex2f(190, 175);

			glTexCoord2f(1, 0.142);
			glVertex2f(190, 125);

			glTexCoord2f(0, 0.142);
			glVertex2f(10, 125);

			glTexCoord2f(0, 0.285);
			glVertex2f(10, 175);

			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);

		/*** TOUR CLARA (Laser) : 80 pieces ***/

		if(joueur.getArgent() >= PRIX_CLARA)
			glColor4f(255,255,255, 1);
		else 
			glColor4f(255,255,255, 0.5);

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *spriteMenu);

			glBegin(GL_QUADS);
			//coordonée de la texture
			glTexCoord2f(1, 0.428);
			//Cordonnée du quadrilatère 
			glVertex2f(190, 230);

			glTexCoord2f(1, 0.285);
			glVertex2f(190, 180);

			glTexCoord2f(0, 0.285);
			glVertex2f(10, 180);

			glTexCoord2f(0, 0.428);
			glVertex2f(10, 230);

			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);

		/*** TOUR YOANN (rocket) : 120 pieces ***/

		if(joueur.getArgent() >= PRIX_YOANN)
			glColor4f(255,255,255, 1);
		else 
			glColor4f(255,255,255, 0.5);

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *spriteMenu);

			glBegin(GL_QUADS);
			//coordonée de la texture
			glTexCoord2f(1, 0.571);
			//Cordonnée du quadrilatère 
			glVertex2f(190, 285);

			glTexCoord2f(1, 0.428);
			glVertex2f(190, 235);

			glTexCoord2f(0, 0.428);
			glVertex2f(10, 235);

			glTexCoord2f(0, 0.571);
			glVertex2f(10, 285);

			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);
	}
	else {
		fprintf(stderr, "Erreur il y un problème avec les textures.\n");
		return 0;
	}

	return 1;
}

/*********************** Dessiner les tours ***********************/
/* Dessine les tours. Prend en paramètre la texture de la tour, la liste de tours, la liste de monstres, la tour courant	*
*  et les variables xt1, xt2, testMouse et propriete. Retourne 0 en cas d'erreur, 1 sinon. 					*/

int drawTower (GLuint* tower, listTower p_ltower, listMonster p_lmonster, Tower* p_courant, int testMouse, int testTower) {

	if(tower != NULL && p_ltower != NULL && p_lmonster != NULL) {

		//Création d'un pointeur tour temporaire pour parcourir la liste de tours
		Tower *p_temp = p_ltower->p_tail;

			//Parcours la liste de tours
			while(p_temp != NULL){

				if(testMouse == 1) {
					glPushMatrix();
					glTranslatef(p_temp->x,p_temp->y, 0.0);

						//Choisie la couleur
						if(p_temp == p_ltower->p_tail) {
							if(testTower == 1) 
								glColor4f(0,255,0, 0.2);
							else
								glColor4f(255,0,0, 0.2);
						}
						else
							glColor4f(255,255,255, 0.2);
						//Affiche le périmètre d'action
						drawDisque(p_temp->range);
				
					glPopMatrix();
				}

				if(p_courant != NULL && testMouse != 1) {
					if(p_courant == p_temp) {
						glPushMatrix();
							glTranslatef(p_temp->x,p_temp->y, 0.0);
							glColor4f(255,255,255, 0.2);
							drawDisque(p_temp->range);
						glPopMatrix();
					}
				}
				
				glColor3ub(255,255,255);
				glPushMatrix();
				//Active le texturage 2D
				glEnable(GL_TEXTURE_2D);
				//appel de la texture
				glBindTexture(GL_TEXTURE_2D, *tower);

					int xm1, xm2, ym1, ym2;
					xm1 = p_temp->x + 20;
					xm2 = p_temp->x - 20;
					ym1 = p_temp->y + 20;
					ym2 = p_temp->y - 20;

					int towerNumber = 0;
					//Choisir le bon monstre dans le sprite
					if(strcmp("H", p_temp->type_tower) == 0) 
						towerNumber = 0;
					else if(strcmp("M", p_temp->type_tower) == 0) 
						towerNumber = 1;
					else if(strcmp("L", p_temp->type_tower) == 0) 
						towerNumber = 3;
					else if(strcmp("R", p_temp->type_tower) == 0) 
						towerNumber = 2;

					float x1 = 0, x2 = 1, y1 = (towerNumber * (1.0/4.0)) + 0;
					float y2 = (towerNumber * (1.0/4.0)) + 0.25;

					glBegin(GL_QUADS);
					//coordonée de la texture
					glTexCoord2f(x2, y2);
					//Cordonnée du quadrilatère 
					glVertex2f(xm1, ym1);

					glTexCoord2f(x2, y1);
					glVertex2f(xm1, ym2);

					glTexCoord2f(x1, y1);
					glVertex2f(xm2, ym2);

					glTexCoord2f(x1, y2);
					glVertex2f(xm2, ym1);

					glEnd();

				//Déblinder la texture
				glBindTexture(GL_TEXTURE_2D, 0);
				//Désactive le texturage 2D
				glDisable(GL_TEXTURE_2D);
				glPopMatrix();

				p_temp = p_temp->p_prev;
			}
		}
		else {
			fprintf(stderr, "Erreur un des élements n'est pas alloué\n");
			return 0;
		}

		return 1;
}

/******************** Dessiner GameOver / Win ********************/
/* Affiche Game Over ou Win. Prend en paramètre les textures.		*/

int drawGameOverWin(GLuint* texture, GLuint* spriteButton) {

	if(texture != NULL) {

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *texture);

			glBegin(GL_QUADS);
			//couleur neutre
			glColor3ub(255,255,255);
			//coordonée de la texture
			glTexCoord2f(1, 1);
			//Cordonnée du quadrilatère 
			glVertex2f(800, 660);

			glTexCoord2f(1, 0);
			glVertex2f(800, 0);

			glTexCoord2f(0, 0);
			glVertex2f(0, 0);

			glTexCoord2f(0, 1);
			glVertex2f(0, 660);

			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);

		/** Bouton jouer **/

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *spriteButton);

			glBegin(GL_QUADS);
			//couleur neutre
			glColor3ub(255,255,255);
			//coordonée de la texture
			glTexCoord2f(1, 0.25);
			//Cordonnée du quadrilatère 
			glVertex2f(514, 352);

			glTexCoord2f(1, 0);
			glVertex2f(514, 296);

			glTexCoord2f(0, 0);
			glVertex2f(272, 296);

			glTexCoord2f(0, 0.25);
			glVertex2f(272, 352);

			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);

		/** Bouton aide **/

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *spriteButton);

			glBegin(GL_QUADS);
			//couleur neutre
			glColor3ub(255,255,255);
			//coordonée de la texture
			glTexCoord2f(1, 0.5);
			//Cordonnée du quadrilatère 
			glVertex2f(514, 421);

			glTexCoord2f(1, 0.25);
			glVertex2f(514, 364);

			glTexCoord2f(0, 0.25);
			glVertex2f(272, 364);

			glTexCoord2f(0, 0.5);
			glVertex2f(272, 421);

			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);

		/** Bouton changer de carte **/

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *spriteButton);

			glBegin(GL_QUADS);
			//couleur neutre
			glColor3ub(255,255,255);
			//coordonée de la texture
			glTexCoord2f(1, 0.75);
			//Cordonnée du quadrilatère 
			glVertex2f(514, 490);

			glTexCoord2f(1, 0.5);
			glVertex2f(514, 432);

			glTexCoord2f(0, 0.5);
			glVertex2f(272, 432);

			glTexCoord2f(0, 0.75);
			glVertex2f(272, 490);

			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);

	}
	else {
		fprintf(stderr, "Erreur la texture n'existe pas\n");
		return 0;
	}

	return 1;

}


/************* Dessiner un cercle en fonction de son rayon plein *************/
/* Dessine un cercle plein. Prend en paramètre le rayon du cercle.		*/

void drawDisque(float rayon) {
	
	int i, j = 100;
	float angle, x, y;
	
	glBegin(GL_TRIANGLE_FAN);

	glVertex2f(0, 0);

	for(i = 0; i <= j; i++) {
		angle = (2*pi*i)/j;
		x = rayon*(cos(angle));
		y = rayon*(sin(angle));
		glVertex2f(x,y);
	}

	glEnd();

}

/************* Dessiner un cercle en fonction de son rayon vide *************/
/* Dessine un cercle vide. Prend en paramètre le rayon du cercle.		*/

void drawCercle(float rayon) {
	
	int i, j = 100;
	float angle, x1, y1;
	
	glBegin(GL_LINE_STRIP);

	for(i = 0; i <= j; i++) {
		angle = (2*pi*i)/j;
		x1 = rayon*(cos(angle));
		y1 = rayon*(sin(angle));
		glVertex2f(x1,y1);
	}

	glEnd();

}

/******************** Dessiner un rectangle / carré plein ********************/
/* Dessine un carré ou rectangle plein. Prend en paramètre les coordonées des deux points opposés	*/

void drawRectangle (int x1, int y1, int x2, int y2) {

	glBegin(GL_QUADS);
		glVertex2f(x1,y1);
		glVertex2f(x2,y1);
		glVertex2f(x2,y2);
		glVertex2f(x1,y2);
	glEnd();
}

/******************** Dessiner un rectangle / carré vide ********************/
/* Dessine un carré ou rectangle vide. Prend en paramètre les coordonées des deux points opposés	*/

void drawRectangleLine (int x1, int y1, int x2, int y2) {

	glBegin(GL_LINE_LOOP);
		glVertex2f(x1,y1);
		glVertex2f(x2,y1);
		glVertex2f(x2,y2);
		glVertex2f(x1,y2);
	glEnd();
}


/******************** Ecrire du texte ********************/
/* Ecrire du texte. Prend en paramamètre sa position et la chaine de caractère	*/

void writeString(int x, int y,  string s) {
		// Positionne le premier caractère de la chaîne
		glRasterPos2f(x, y);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, s); // Affiche chaque caractère de la chaîne

		// Réinitialise la position du premier caractère de la chaîne
		glRasterPos2f(0, 0);
}


