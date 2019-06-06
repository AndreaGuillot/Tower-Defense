#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "element/Monster.h"
#include "element/Installation.h"
#include "element/Tower.h"
#include "element/Shot.h"

#include "ihm/Node.h"
#include "ihm/Draw.h"
#include "ihm/Interface.h"
#include "file/Texture.h"
#include "file/Map.h"

#define pi 3.14

/*********************** Dessiner le menu des map ***********************/
/* Dessine le menu des map. Prend en paramètre les textures.	*/

int drawMenuMap (GLuint* texture, GLuint* bt_texture, int nbTexture) {

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

		if(nbTexture == 0) {

			//Active le texturage 2D
			glEnable(GL_TEXTURE_2D);
			//appel de la texture
			glBindTexture(GL_TEXTURE_2D, *bt_texture);

				glBegin(GL_QUADS);
				//couleur neutre
				glColor3ub(255,255,255);
				//coordonée de la texture
				glTexCoord2f(0.5, 1);
				//Cordonnée du quadrilatère 
				glVertex2f(492, 121);

				glTexCoord2f(0.5, 0);
				glVertex2f(492, 68);

				glTexCoord2f(0, 0);
				glVertex2f(300, 68);

				glTexCoord2f(0, 1);
				glVertex2f(300, 121);

				glEnd();

			//Déblinder la texture
			glBindTexture(GL_TEXTURE_2D, 0);
			//Désactive le texturage 2D
			glDisable(GL_TEXTURE_2D);

		}
		else {

			//Active le texturage 2D
			glEnable(GL_TEXTURE_2D);
			//appel de la texture
			glBindTexture(GL_TEXTURE_2D, *bt_texture);

				glBegin(GL_QUADS);
				//couleur neutre
				glColor3ub(255,255,255);
				//coordonée de la texture
				glTexCoord2f(1, 1);
				//Cordonnée du quadrilatère 
				glVertex2f(492, 121);

				glTexCoord2f(1, 0);
				glVertex2f(492, 68);

				glTexCoord2f(0.5, 0);
				glVertex2f(300, 68);

				glTexCoord2f(0.5, 1);
				glVertex2f(300, 121);

				glEnd();

			//Déblinder la texture
			glBindTexture(GL_TEXTURE_2D, 0);
			//Désactive le texturage 2D
			glDisable(GL_TEXTURE_2D);

		}

	}
	else {
		fprintf(stderr, "Erreur la texture de la map n'existe pas\n");
		return 0;
	}

	return 1;

}

/*********************** Dessiner le menu principale ***********************/
/* Dessine le menu principale. Prend en paramètre les textures.	*/

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

/*********************** Dessiner l'aide ***********************/
/* Dessine la map. Prend en paramètre une texture.	*/

int drawHelp (GLuint* texture, GLuint* spriteButton, GLuint* spriteButtonMenu, int nbMenu) {

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

		if(nbMenu == 3) {

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
		}
		else {

			/** Bouton menu **/

			//Active le texturage 2D
			glEnable(GL_TEXTURE_2D);
			//appel de la texture
			glBindTexture(GL_TEXTURE_2D, *spriteButtonMenu);

				glBegin(GL_QUADS);
				//couleur neutre
				glColor3ub(255,255,255);
				//coordonée de la texture
				glTexCoord2f(1, 1);
				//Cordonnée du quadrilatère 
				glVertex2f(310, 627);

				glTexCoord2f(1, 0.75);
				glVertex2f(310, 570);

				glTexCoord2f(0, 0.75);
				glVertex2f(68, 570);

				glTexCoord2f(0, 1);
				glVertex2f(68, 627);

				glEnd();

			//Déblinder la texture
			glBindTexture(GL_TEXTURE_2D, 0);
			//Désactive le texturage 2D
			glDisable(GL_TEXTURE_2D);

			/** Bouton jouer **/

			//Active le texturage 2D
			glEnable(GL_TEXTURE_2D);
			//appel de la texture
			glBindTexture(GL_TEXTURE_2D, *spriteButtonMenu);

				glBegin(GL_QUADS);
				//couleur neutre
				glColor3ub(255,255,255);
				//coordonée de la texture
				glTexCoord2f(1, 0.25);
				//Cordonnée du quadrilatère 
				glVertex2f(732, 627);

				glTexCoord2f(1, 0);
				glVertex2f(732, 570);

				glTexCoord2f(0, 0);
				glVertex2f(490, 570);

				glTexCoord2f(0, 0.25);
				glVertex2f(490, 627);

				glEnd();

			//Déblinder la texture
			glBindTexture(GL_TEXTURE_2D, 0);
			//Désactive le texturage 2D
			glDisable(GL_TEXTURE_2D);

		}

	}
	else {
		fprintf(stderr, "Erreur la texture de la map n'existe pas\n");
		return 0;
	}

	return 1;

}

/*********************** Dessiner le menu haut ***********************/
/* Dessine le menu. Prend en paramètre la texture pour le menu et la variable play. Retourne 0 en cas d'erreur 1 sinon.	*/

int drawMenuUp (GLuint* spriteButton, GLuint* fondMenuUp, int isPlaying) {

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


		/** Bouton aide **/

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *spriteButton);

			glBegin(GL_QUADS);
			//couleur neutre
			glColor3ub(255,255,255);
			//coordonée de la texture
			glTexCoord2f(0.875, 1);
			//Cordonnée du quadrilatère 
			glVertex2f(755, 45);

			glTexCoord2f(0.875, 0);
			glVertex2f(755, 15);

			glTexCoord2f(0.75, 0);
			glVertex2f(725, 15);

			glTexCoord2f(0.75, 1);
			glVertex2f(725, 45);

			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);

		if(isPlaying) {

			/** Bouton pause **/

			//Active le texturage 2D
			glEnable(GL_TEXTURE_2D);
			//appel de la texture
			glBindTexture(GL_TEXTURE_2D, *spriteButton);

				
				glBegin(GL_QUADS);
				//couleur neutre
				glColor3ub(255,255,255);
				//coordonée de la texture
				glTexCoord2f(0.625, 1);
				//Cordonnée du quadrilatère 
				glVertex2f(720, 45);

				glTexCoord2f(0.625, 0);
				glVertex2f(720, 15);

				glTexCoord2f(0.75, 0);
				glVertex2f(690, 15);

				glTexCoord2f(0.75, 1);
				glVertex2f(690, 45);

				glEnd();

			//Déblinder la texture
			glBindTexture(GL_TEXTURE_2D, 0);
			//Désactive le texturage 2D
			glDisable(GL_TEXTURE_2D);

		}
		else {

			/** Bouton play **/

			//Active le texturage 2D
			glEnable(GL_TEXTURE_2D);
			//appel de la texture
			glBindTexture(GL_TEXTURE_2D, *spriteButton);

				glBegin(GL_QUADS);
				//couleur neutre
				glColor3ub(255,255,255);
				//coordonée de la texture
				glTexCoord2f(0.625, 1);
				//Cordonnée du quadrilatère 
				glVertex2f(720, 45);

				glTexCoord2f(0.625, 0);
				glVertex2f(720, 15);

				glTexCoord2f(0.5, 0);
				glVertex2f(690, 15);

				glTexCoord2f(0.5, 1);
				glVertex2f(690, 45);

				glEnd();

			//Déblinder la texture
			glBindTexture(GL_TEXTURE_2D, 0);
			//Désactive le texturage 2D
			glDisable(GL_TEXTURE_2D);

		}


	}
	else {
		fprintf(stderr, "Erreur il y un problème avec les textures.\n");
		return 0;
	}

	return 1;
}

/*********************** Dessiner le menu left ***********************/
/* Dessine le menu. Prend en paramètre les textures pour le menu et un pointeur vers l'joueur.	*
*  Retourne 0 en cas d'erreur 1 sinon.									*/

int drawMenuLeft (GLuint* spriteMenu, GLuint* fondMenu, Joueur* joueur) {

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

		/*** PREMIERE TOUR
			OCEANE
			PRIX 50 ***/

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *spriteMenu);

			if(joueur->money >= 50)
				glColor4f(255,255,255, 1);
			else 
				glColor4f(255,255,255, 0.5);

			glBegin(GL_QUADS);
			//coordonée de la texture
			glTexCoord2f(0.5, 0.14);
			//Cordonnée du quadrilatère 
			glVertex2f(100, 120);

			glTexCoord2f(0.5, 0);
			glVertex2f(100, 70);

			glTexCoord2f(0, 0);
			glVertex2f(10, 70);

			glTexCoord2f(0, 0.14);
			glVertex2f(10, 120);

			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);

		/*** DEUXIEME TOUR
			JULES
			PRIX 60 ***/

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *spriteMenu);

			if(joueur->money >= 60)
				glColor4f(255,255,255, 1);
			else 
				glColor4f(255,255,255, 0.5);

			glBegin(GL_QUADS);
			//coordonée de la texture
			glTexCoord2f(1, 0.14);
			//Cordonnée du quadrilatère 
			glVertex2f(190, 120);

			glTexCoord2f(1, 0);
			glVertex2f(190, 70);

			glTexCoord2f(0.5, 0);
			glVertex2f(100, 70);

			glTexCoord2f(0.5, 0.14);
			glVertex2f(100, 120);

			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);


		/*** TROISIEME TOUR
			CLARA
			PRIX 80 ***/

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *spriteMenu);

			if(joueur->money >= 80)
				glColor4f(255,255,255, 1);
			else 
				glColor4f(255,255,255, 0.5);


			glBegin(GL_QUADS);
			//coordonée de la texture
			glTexCoord2f(0.5, 0.3);
			//Cordonnée du quadrilatère 
			glVertex2f(100, 175);

			glTexCoord2f(0.5, 0.15);
			glVertex2f(100, 125);

			glTexCoord2f(0, 0.15);
			glVertex2f(10, 125);

			glTexCoord2f(0, 0.3);
			glVertex2f(10, 175);

			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);

		/*** QUATRIEME TOUR
			YOANN
			PRIX 120 ***/

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *spriteMenu);

			if(joueur->money >= 120)
				glColor4f(255,255,255, 1);
			else 
				glColor4f(255,255,255, 0.5);


			glBegin(GL_QUADS);
			//coordonée de la texture
			glTexCoord2f(1, 0.3);
			//Cordonnée du quadrilatère 
			glVertex2f(190, 175);

			glTexCoord2f(1, 0.15);
			glVertex2f(190, 125);

			glTexCoord2f(0.5, 0.15);
			glVertex2f(100, 125);

			glTexCoord2f(0.5, 0.3);
			glVertex2f(100, 175);

			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);

		/** PREMIERE INSTALLATION
			ANDREA
			PRIX 80***/

			if(joueur->money >= 80)
				glColor4f(255,255,255, 1);
			else 
				glColor4f(255,255,255, 0.5);

			//Active le texturage 2D
			glEnable(GL_TEXTURE_2D);
			//appel de la texture
			glBindTexture(GL_TEXTURE_2D, *spriteMenu);

				glBegin(GL_QUADS);
				//coordonée de la texture
				glTexCoord2f(0.5, 0.5);
				//Cordonnée du quadrilatère 
				glVertex2f(100, 230);

				glTexCoord2f(0.5, 0.35);
				glVertex2f(100, 180);

				glTexCoord2f(0, 0.35);
				glVertex2f(10, 180);

				glTexCoord2f(0, 0.5);
				glVertex2f(10, 230);

				glEnd();

			//Déblinder la texture
			glBindTexture(GL_TEXTURE_2D, 0);
			//Désactive le texturage 2D
			glDisable(GL_TEXTURE_2D);

		/** PREMIERE INSTALLATION
			MARGAUX
			PRIX 150***/

			if(joueur->money >= 150)
				glColor4f(255,255,255, 1);
			else 
				glColor4f(255,255,255, 0.5);

			//Active le texturage 2D
			glEnable(GL_TEXTURE_2D);
			//appel de la texture
			glBindTexture(GL_TEXTURE_2D, *spriteMenu);

				glBegin(GL_QUADS);
				//coordonée de la texture
				glTexCoord2f(1, 0.5);
				//Cordonnée du quadrilatère 
				glVertex2f(190, 230);

				glTexCoord2f(1, 0.35);
				glVertex2f(190, 180);

				glTexCoord2f(0.5, 0.35);
				glVertex2f(100, 180);

				glTexCoord2f(0.5, 0.5);
				glVertex2f(100, 230);

				glEnd();

			//Déblinder la texture
			glBindTexture(GL_TEXTURE_2D, 0);
			//Désactive le texturage 2D
			glDisable(GL_TEXTURE_2D);

		/*** TROISIEME INSTALLATION
			BAPTISTE
			PRIX 70***/

			if(joueur->money >= 70)
				glColor4f(255,255,255, 1);
			else 
				glColor4f(255,255,255, 0.5);

			//Active le texturage 2D
			glEnable(GL_TEXTURE_2D);
			//appel de la texture
			glBindTexture(GL_TEXTURE_2D, *spriteMenu);

				glBegin(GL_QUADS);
				//coordonée de la texture
				glTexCoord2f(0.5, 0.67);
				//Cordonnée du quadrilatère 
				glVertex2f(145, 285);

				glTexCoord2f(0.5, 0.52);
				glVertex2f(145, 235);

				glTexCoord2f(0, 0.52);
				glVertex2f(55, 235);

				glTexCoord2f(0, 0.67);
				glVertex2f(55, 285);

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

/*********************** Dessiner l'joueur (score, argent, vie, nb de monstre tués ***********************/
/* Dessine l'joueur. Prend en paramètre un pointeur vers la texture et un pointeur vers l'joueur.	*
*  Retourne 0 en cas d'erreur, 1 sinon. 								*/

int drawInterface (GLuint* spriteButton, Joueur* joueur) {

	if(joueur != NULL) {

		//Alloue de la mémoire pour une chaine de caractère
		char* machaine = malloc(20*sizeof(char));

		//Si la chaine de caracteres à bien été alloué
		if(machaine != NULL) {

			glColor3ub(0,0,0);
			/**** Niveau ****/
			//Convertie un int en un string
			sprintf(machaine,"%d",joueur->lvl);

			writeString(40, 40,  "Vagues de monstres passees : ");
			//Affiche la chaine de caractère
			writeString(300, 40,  machaine);
			writeString(320, 40,  "/ 50");

			/**** Money ****/
			//Convertie un int en un string
			sprintf(machaine,"%d",joueur->money);
			//Affiche la chaine de caractère
			writeString(410, 40,  machaine);

			//Active le texturage 2D
			glEnable(GL_TEXTURE_2D);
			//appel de la texture
			glBindTexture(GL_TEXTURE_2D, *spriteButton);

				glBegin(GL_QUADS);
				//couleur neutre
				glColor3ub(255,255,255);
				//coordonée de la texture
				glTexCoord2f(0.125, 1);
				//Cordonnée du quadrilatère 
				glVertex2f(375, 45);

				glTexCoord2f(0.125, 0);
				glVertex2f(375, 15);

				glTexCoord2f(0, 0);
				glVertex2f(405, 15);

				glTexCoord2f(0, 1);
				glVertex2f(405, 45);

				glEnd();

			//Déblinder la texture
			glBindTexture(GL_TEXTURE_2D, 0);
			//Désactive le texturage 2D
			glDisable(GL_TEXTURE_2D);

		}
		else {
			fprintf(stderr, "probleme d'allocation memoire pour la chaine de caractere\n");
			return 0;
		}
	}
	else {
		fprintf(stderr, "Il y a un problème avec l'joueur\n");
		return 0;
	}	

	return 1;

}

/*********************** Dessiner les propriétés des tours ***********************/
/* Dessine les propriétés des tours. Prend en paramètre un pointeur vers la tour courante 		*
*  Retourne 0 en cas d'erreur, 1 sinon. 								*/

int drawProprieteTower (GLuint* tower, GLuint* spriteMenu, Tower* p_courant, Joueur* joueur) {

	if(p_courant != NULL) {

		int towerNumber = 0;
		//Choisir le bon monstre dans le sprite
		if(strcmp("O", p_courant->type_tower) == 0) 
			towerNumber = 0;
		else if(strcmp("J", p_courant->type_tower) == 0) 
			towerNumber = 1;
		else if(strcmp("C", p_courant->type_tower) == 0) 
			towerNumber = 2;
		else if(strcmp("Y", p_courant->type_tower) == 0) 
			towerNumber = 3;

		float x1 = 0, x2 = 1, y1 = (towerNumber * (1.0/4.0)) + 0;
		float y2 = (towerNumber * (1.0/4.0)) + 0.25;

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *tower);

			glBegin(GL_QUADS);
			//couleur neutre
			glColor3ub(255,255,255);
			//coordonée de la texture
			glTexCoord2f(x1, y1);
			//Cordonnée du quadrilatère 
			glVertex2f(80, 300);

			glTexCoord2f(x1, y2);
			glVertex2f(80, 340);

			glTexCoord2f(x2, y2);
			glVertex2f(120, 340);

			glTexCoord2f(x2, y1);
			glVertex2f(120, 300);


			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);


		//Alloue de la mémoire pour une chaine de caractère
		char* machaine = malloc(20*sizeof(char));

		//Si la chaine de caracteres à bien été alloué
		if(machaine != NULL) {

			/**** Titre de la tour ****/
			glColor4f(255,255,255, 1);
			char* titreTour = "";

			//Choisir le bon monstre dans le sprite
			if(strcmp("O", p_courant->type_tower) == 0) 
				titreTour = "OCEANE";
			else if(strcmp("J", p_courant->type_tower) == 0) 
				titreTour = "JULES";
			else if(strcmp("C", p_courant->type_tower) == 0) 
				titreTour = "CLARA";
			else if(strcmp("Y", p_courant->type_tower) == 0) 
				titreTour = "YOANN";

			//Affiche la chaine de caractère
			writeString(60, 360,  titreTour);

			/**** Cadence ****/
			glColor4f(255,255,255, 1);
			//Convertie un int en un string
			sprintf(machaine,"%d",p_courant->rate);

			writeString(20, 390,  "Cadence : ");
			//Affiche la chaine de caractère
			writeString(120, 390,  machaine);

			
			/**** Périmètre d'action ****/
			glColor4f(255,255,255, 1);
			//Convertie un int en un string
			sprintf(machaine,"%d",p_courant->range);

			writeString(20, 415,  "Range : ");
			//Affiche la chaine de caractère
			writeString(120, 415,  machaine);

			/**** puissance ****/

			glColor4f(255,255,255, 1);
			//Convertie un int en un string
			sprintf(machaine,"%d",p_courant->power);

			writeString(20, 440,  "Puissance : ");
			//Affiche la chaine de caractère
			writeString(120, 440,  machaine);


			/**** type de la tour ****/
			glColor4f(255,255,255, 1);
			char* typeTour = "";

			//Choisir le bon monstre dans le sprite
			if(strcmp("O", p_courant->type_tower) == 0) 
				typeTour = "Archer";
			else if(strcmp("J", p_courant->type_tower) == 0) 
				typeTour = "Folle";
			else if(strcmp("C", p_courant->type_tower) == 0) 
				typeTour = "Laser";
			else if(strcmp("Y", p_courant->type_tower) == 0) 
				typeTour = "Rocket";

			writeString(20, 465,  "Type : ");
			//Affiche la chaine de caractère
			writeString(80, 465,  typeTour);

	
			/*** Bouton supprimer ****/
			glColor4f(255,255,255, 1);			

			//Active le texturage 2D
			glEnable(GL_TEXTURE_2D);
			//appel de la texture
			glBindTexture(GL_TEXTURE_2D, *spriteMenu);

				glBegin(GL_QUADS);
				//coordonée de la texture
				glTexCoord2f(1, 0.857);
				//Cordonnée du quadrilatère 
				glVertex2f(190, 540);

				glTexCoord2f(1, 0.714);
				glVertex2f(190, 490);

				glTexCoord2f(0, 0.714);
				glVertex2f(10, 490);

				glTexCoord2f(0, 0.857);
				glVertex2f(10, 540);

				glEnd();

			//Déblinder la texture
			glBindTexture(GL_TEXTURE_2D, 0);
			//Désactive le texturage 2D
			glDisable(GL_TEXTURE_2D);

		}
		else {
			fprintf(stderr, "probleme d'allocation memoire pour la chaine de caractere\n");
			return 0;
		}	
	}

	return 1;

}

/*********************** Dessiner les propriétés des installations ***********************/
/* Dessine les propriétés des installations. Prend en paramètre un pointeur vers la installation courante 		*
*  Retourne 0 en cas d'erreur, 1 sinon. 								*/

int drawProprieteInstallation (GLuint* installation, GLuint* spriteMenu, Installation* p_courant, Joueur* joueur) {

	if(p_courant != NULL) {

		int installationNumber = 0;
		//Choisir le bon monstre dans le sprite
		if(strcmp("U", p_courant->type_installation) == 0) 
			installationNumber = 0;
		else if(strcmp("R", p_courant->type_installation) == 0) 
			installationNumber = 1;
		else if(strcmp("S", p_courant->type_installation) == 0) 
			installationNumber = 2;

		float x1 = 0, x2 = 1, y1 = (installationNumber * (1./3.)) + 0;
		float y2 = (installationNumber * (1./3.)) + 0.33;

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *installation);

			glBegin(GL_QUADS);
			//couleur neutre
			glColor3ub(255,255,255);
			//coordonée de la texture
			glTexCoord2f(x1, y1);
			//Cordonnée du quadrilatère 
			glVertex2f(80, 300);

			glTexCoord2f(x1, y2);
			glVertex2f(80, 340);

			glTexCoord2f(x2, y2);
			glVertex2f(120, 340);

			glTexCoord2f(x2, y1);
			glVertex2f(120, 300);


			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);


		//Alloue de la mémoire pour une chaine de caractère
		char* machaine = malloc(20*sizeof(char));

		//Si la chaine de caracteres à bien été alloué
		if(machaine != NULL) {
			
			/**** Titre de la tour ****/
			glColor4f(255,255,255, 1);
			char* titreTour = "";
			char* typeInstallation = "";
			char* description = "";

			//Choisir le bon monstre dans le sprite
			if(strcmp("U", p_courant->type_installation) == 0) {
				titreTour = "MARGAUX";
				typeInstallation = "Usine";
				description = "Ajoute 25% de force";
			}
			else if(strcmp("R", p_courant->type_installation) == 0) {
				titreTour = "ANDREA";
				typeInstallation = "Radar";
				description = "Ajoute 25% de portee";
			}
			else if(strcmp("S", p_courant->type_installation) == 0) {
				titreTour = "BAPTISTE";
				typeInstallation = "Stock";
				description = "Ajoute 25% de cadence";
			}

			//Affiche la chaine de caractère
			writeString(60, 360,  titreTour);

			/**** Périmètre d'action ****/
			glColor4f(255,255,255, 1);
			//Convertie un int en un string
			sprintf(machaine,"%d",p_courant->range);

			writeString(20, 390,  "Range : ");
			//Affiche la chaine de caractère
			writeString(90, 390,  machaine);

			/**** type de l'installation ****/
			glColor4f(255,255,255, 1);

			writeString(20, 415,  "Type : ");
			//Affiche la chaine de caractère
			writeString(80, 415,  typeInstallation);

			/**** description de l'installation ****/
			glColor4f(255,255,255, 1);

			//Affiche la chaine de caractère
			writeString(5, 440,  description);

	
			/*** Bouton supprimer ****/
			glColor4f(255,255,255, 1);			

			//Active le texturage 2D
			glEnable(GL_TEXTURE_2D);
			//appel de la texture
			glBindTexture(GL_TEXTURE_2D, *spriteMenu);

				glBegin(GL_QUADS);
				//coordonée de la texture
				glTexCoord2f(1, 0.857);
				//Cordonnée du quadrilatère 
				glVertex2f(190, 540);

				glTexCoord2f(1, 0.714);
				glVertex2f(190, 490);

				glTexCoord2f(0, 0.714);
				glVertex2f(10, 490);

				glTexCoord2f(0, 0.857);
				glVertex2f(10, 540);

				glEnd();

			//Déblinder la texture
			glBindTexture(GL_TEXTURE_2D, 0);
			//Désactive le texturage 2D
			glDisable(GL_TEXTURE_2D);

		}
		else {
			fprintf(stderr, "probleme d'allocation memoire pour la chaine de caractere\n");
			return 0;
		}	
	}

	return 1;

}

/*********************** Dessiner les propriétés des monstres ***********************/
/* Dessine les propriétés des tours. Prend en paramètre un pointeur vers le monstre courant 		*
*  Retourne 0 en cas d'erreur, 1 sinon. 								*/

int drawProprieteMonster (GLuint* monster, Monster* p_courant) {

	if(p_courant != NULL) {

		int monsterNumber = 0;
			//Choisir le bon monstre dans le sprite
			if(strcmp("J", p_courant->type) == 0) 
				monsterNumber = 0;
			else if(strcmp("B", p_courant->type) == 0) 
				monsterNumber = 2;
			else if(strcmp("L", p_courant->type) == 0) 
				monsterNumber = 1;

		float x1 = 0, x2 = 1, y1 = (monsterNumber * (1./3.)) + 0;
		float y2 = (monsterNumber * (1./3.)) + 0.33;

		//Active le texturage 2D
		glEnable(GL_TEXTURE_2D);
		//appel de la texture
		glBindTexture(GL_TEXTURE_2D, *monster);

			glBegin(GL_QUADS);
			//couleur neutre
			glColor3ub(255,255,255);
			//coordonée de la texture
			glTexCoord2f(x1, y1);
			//Cordonnée du quadrilatère 
			glVertex2f(80, 300);

			glTexCoord2f(x1, y2);
			glVertex2f(80, 340);

			glTexCoord2f(x2, y2);
			glVertex2f(120, 340);

			glTexCoord2f(x2, y1);
			glVertex2f(120, 300);


			glEnd();

		//Déblinder la texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//Désactive le texturage 2D
		glDisable(GL_TEXTURE_2D);

		//Alloue de la mémoire pour une chaine de caractère
		char* machaine = malloc(20*sizeof(char));

		//Si la chaine de caracteres à bien été alloué
		if(machaine != NULL) {

			char* titreMonster="";

			/*Choisir le bon monstre dans le sprite*/
			if(strcmp("J", p_courant->type) == 0) {
				titreMonster = "JULIEN";
			}
			else if(strcmp("B", p_courant->type) == 0) {
				titreMonster = "BARBARA";
			}
			else if(strcmp("L", p_courant->type) == 0) {
				titreMonster = "LUCIE";
			}

			//Affiche la chaine de caractère
			writeString(60, 360,  titreMonster);

			/**** points de vie ****/
			//Convertie un int en un string
			sprintf(machaine,"%d",p_courant->pv);

			writeString(20, 385,  "PV : ");
			//Affiche la chaine de caractère
			writeString(120, 385,  machaine);

			/**** vitesse ****/
			//Convertie un int en un string
			sprintf(machaine,"%d",(10-p_courant->pace)*10);

			writeString(20, 410,  "Vitesse : ");
			//Affiche la chaine de caractère
			writeString(120, 410,  machaine);
			writeString(150, 410,  "km/h");

			/**** Resistance ****/

			//Affiche resistance Oceane
			sprintf(machaine,"%1.f",100*p_courant->resistanceO);
			//Convertie un int en un string
			writeString(20, 435,  "Resistance Oceane : ");
			//Affiche la chaine de caractère
			writeString(90, 455,  machaine);
			writeString(110, 455,  "%");

			
			//Convertie un int en un string
			sprintf(machaine,"%1.f",100*p_courant->resistanceJ);

			writeString(20, 480,  "Resistance Jules: ");
			//Affiche la chaine de caractère
			writeString(90, 500,  machaine);
			writeString(110, 500,  "%");

			//Convertie un int en un string
			sprintf(machaine,"%1.f",100*p_courant->resistanceC);

			writeString(20, 525,  "Resistance Clara: ");
			//Affiche la chaine de caractère
			writeString(90, 545,  machaine);
			writeString(110, 545,  "%");

			//Convertie un int en un string
			sprintf(machaine,"%1.f",100*p_courant->resistanceY);

			writeString(20, 570,  "Resistance Yoann: ");
			//Affiche la chaine de caractère
			writeString(90, 590,  machaine);
			writeString(110, 590,  "%");

			/*GAIN*/

			//Convertie un int en un string
			sprintf(machaine,"%d",p_courant->gain);

			writeString(20, 615,  "Score: ");
			//Affiche la chaine de caractère
			writeString(90, 615,  machaine);

		}
		else {
			fprintf(stderr, "probleme d'allocation memoire pour la chaine de caractere\n");
			return 0;
		}
	}

	return 1;

}


/*********************** Dessiner les tours ***********************/
/* Dessine les tours. Prend en paramètre la texture de la tour, la liste de tours, la liste de monstres, la tour courant	*
*  et les variables xt1, xt2, testMouse et propriete. Retourne 0 en cas d'erreur, 1 sinon. 					*/

int drawTower (GLuint* tower, LTower* p_ltower, ListMonsters* p_lmonster, Tower* p_courant, int testMouse, int testTower) {

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
					if(strcmp("O", p_temp->type_tower) == 0) 
						towerNumber = 0;
					else if(strcmp("J", p_temp->type_tower) == 0) 
						towerNumber = 1;
					else if(strcmp("C", p_temp->type_tower) == 0) 
						towerNumber = 2;
					else if(strcmp("Y", p_temp->type_tower) == 0) 
						towerNumber = 3;

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

/*********************** Dessiner les installations ***********************/
/* Dessine les installations. Prend en paramètre la texture de l'installation, la liste d'installations, la liste de monstres, l'installation courant	*
*  et les variables xt1, xt2, testMouse et propriete. Retourne 0 en cas d'erreur, 1 sinon. 					*/

int drawInstallation (GLuint* installation, LInstallation* p_linstallation, Installation* p_courant, int testMouse, int testInstallation) {

	if(installation != NULL && p_linstallation != NULL ) {

		//Création d'un pointeur installation temporaire pour parcourir la liste de tours
		Installation *p_temp = p_linstallation->p_tail;

			//Parcours la liste de tours
			while(p_temp != NULL){

				if(testMouse == 1) {
					glPushMatrix();
					glTranslatef(p_temp->x,p_temp->y, 0.0);

						//Choisie la couleur
						if(p_temp == p_linstallation->p_tail) {
							if(testInstallation == 1) 
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
				glBindTexture(GL_TEXTURE_2D, *installation);

					int xm1, xm2, ym1, ym2;
					xm1 = p_temp->x + 20;
					xm2 = p_temp->x - 20;
					ym1 = p_temp->y + 20;
					ym2 = p_temp->y - 20;

					int installationNumber = 0;
					//Choisir le bon monstre dans le sprite
					if(strcmp("U", p_temp->type_installation) == 0) 
						installationNumber = 0;
					else if(strcmp("R", p_temp->type_installation) == 0) 
						installationNumber = 1;
					else if(strcmp("S", p_temp->type_installation) == 0) 
						installationNumber = 2;

					float x1 = 0, x2 = 1, y1 = (installationNumber * (1.0/3.0)) + 0;
					float y2 = (installationNumber * (1.0/3.0)) + 0.33;

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

/*********************** Dessiner les missiles ***********************/
/* Dessine les missiles. Prend en paramètre la texture du missile, et la liste de missiles. Retourne 0 en cas	*
*  d'erreur, 1 sinon.												*/

int drawShot (GLuint* shot, LShot* p_lshot) {

	if(shot != NULL && p_lshot != NULL) {

		Shot* tmp_shot = p_lshot->p_head;

		while(tmp_shot != NULL) {
		
			//Active le texturage 2D
			glEnable(GL_TEXTURE_2D);
			//appel de la texture
			glBindTexture(GL_TEXTURE_2D, *shot);

				int xm1, xm2, ym1, ym2;
				xm1 = tmp_shot->x + 5;
				xm2 = tmp_shot->x - 5;
				ym1 = tmp_shot->y + 5;
				ym2 = tmp_shot->y - 5;

				glPushMatrix();
					glBegin(GL_QUADS);
					//coordonée de la texture
					glTexCoord2f(1, 0);
					//Cordonnée du quadrilatère 
					glVertex2f(xm1, ym1);

					glTexCoord2f(1, 1);
					glVertex2f(xm1, ym2);

					glTexCoord2f(0, 1);
					glVertex2f(xm2, ym2);

					glTexCoord2f(0, 0);
					glVertex2f(xm2, ym1);

					glEnd();
				glPopMatrix();

			//Déblinder la texture
			glBindTexture(GL_TEXTURE_2D, 0);
			//Désactive le texturage 2D
			glDisable(GL_TEXTURE_2D);

			tmp_shot = tmp_shot->p_next;
		}
	}
	else {
		fprintf(stderr, "Erreur : al texture du shot ou la liste de shot n'existe pas\n");
		return 0;
	}

	return 1;

}

/*********************** Dessiner les monstres ***********************/
/* Dessine les monstres. Prend en paramètre la texture des monstres, la liste de monstre, le dernier noeud. 	*
*  Retourne 0 en cas d'erreur et 1 sinon.									*/

int drawMonster(GLuint* monster, ListMonsters* p_lmonster) {

	if(monster != NULL && p_lmonster != NULL) {

		Monster* tmp_monster = p_lmonster->p_head;

		while(tmp_monster != NULL) {

			float y1=0, y2=0;
			//Choisir le bon monstre dans le sprite
			if(strcmp("J", tmp_monster->type) == 0){ 
				y1 = 0;
				y2 = 1./3.0;
			}
			else if(strcmp("B", tmp_monster->type) == 0){ 
				y1 = 2./3.;
				y2 = 1;
			}				
			else if(strcmp("L", tmp_monster->type) == 0){ 
				y1 = 1./3.;
				y2 = 2./3.;
			}
		
			//Active le texturage 2D
			glEnable(GL_TEXTURE_2D);
			//appel de la texture
			glBindTexture(GL_TEXTURE_2D, *monster);

				int xm1, xm2, ym1, ym2;
				xm1 = tmp_monster->x + 20;
				xm2 = tmp_monster->x - 20;
				ym1 = tmp_monster->y + 20;
				ym2 = tmp_monster->y - 20;

				glPushMatrix();
					glBegin(GL_QUADS);
					//coordonée de la texture
					glTexCoord2f(1, y2);
					//Cordonnée du quadrilatère 
					glVertex2f(xm1, ym1);

					glTexCoord2f(1, y1);
					glVertex2f(xm1, ym2);

					glTexCoord2f(0, y1);
					glVertex2f(xm2, ym2);

					glTexCoord2f(0, y2);
					glVertex2f(xm2, ym1);

					glEnd();
				glPopMatrix();

			//Déblinder la texture
			glBindTexture(GL_TEXTURE_2D, 0);
			//Désactive le texturage 2D
			glDisable(GL_TEXTURE_2D);

			tmp_monster = tmp_monster->p_next;
		}
		drawPVMonster(p_lmonster);
	}
	else {
		fprintf(stderr, "Erreur : al texture du shot ou la liste de shot n'existe pas\n");
		return 0;
	}

	return 1;
}

/************* Dessiner la barre de vie du monstre *************/
/* Dessine la barre de vie du monstre. Descend en fonction du nombre de vie restant et change de 	*
*  couleur. Prend en paramètre la liste de monstres. Retourne 0 en cas d'erreur et 1 sinon.		*/

int drawPVMonster(ListMonsters* p_lmonster) {

	//On vérifie si notre liste a été allouée
	if(p_lmonster != NULL) {
	
		float pourcentagePV, x;

		//Création d'un pointeur monstre temporaire pour parcourir la liste de monstres
		Monster *p_tmp = p_lmonster->p_head;

		//Parcours la liste de monstres
		while(p_tmp != NULL){

			//Calcule le pourcentage de pv restant
			pourcentagePV = (float)p_tmp->pv / (float)p_tmp->pvMax;
			x = pourcentagePV * 40;

			glPushMatrix();
				float xm1, xm2, ym1, ym2;
				
				//Calcule des coordonées du rectangle
				xm1 = p_tmp->x - 20 + x;
				xm2 = p_tmp->x - 20;
				ym1 = p_tmp->y - 22;
				ym2 = p_tmp->y - 26;

				//Choix de la couleur du rectangle en fonction du poucentage de pv restant
				if(pourcentagePV <= 0.1)
					glColor3ub(255,0,0);
				else if(pourcentagePV <= 0.3)
					glColor3ub(255,96,0);
				else if(pourcentagePV <= 0.5)
					glColor3ub(255,150,0);
				else if(pourcentagePV <= 0.7)
					glColor3ub(255,240,0);
				else
					glColor3ub(27,101,10);

				//Dessine le rectangle
				glBegin(GL_QUADS);
					glVertex2f(xm1, ym1);
					glVertex2f(xm1, ym2);
					glVertex2f(xm2, ym2);
					glVertex2f(xm2, ym1);
				glEnd();
				
				//Remet la couleur neutre (blanc)
				glColor3ub(255,255,255);

			glPopMatrix();

			p_tmp = p_tmp->p_next;
		}
	}
	else {
		printf("Cette liste de monstres n'existe pas");
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

/************ Faire apparaitre un monstre sur la map **************/
/* Fait apparaitre un monstre sur la map. Prend en paramètre un pointeur vers la liste de monstre, un pointeur vers 	*
*  l'joueur, un pointeur vers la map, un int, un int (apparition) et int nombre de monstre. Retourne 0 en cas 	*
*  d'erreur et 1 sinon.													*/

int apparitionMonster(ListMonsters* p_lmonster, Joueur* joueur, Map* map, int* apparition, int j, int* nb_monster) {

	if(p_lmonster != NULL) {

		if(joueur != NULL) {

			int random;

			/*Caractéristiques Julien*/
			char* typeJ = "J";
			int pvMaxJ = 50;
			float resistanceYJ = 0.1;
			float resistanceCJ = 0.8;
			float resistanceJJ = 0;
			float resistanceOJ = 0;
			int paceJ = 5;
			int gainJ = 4;

			/*Caractéristiques Barbara*/
			char* typeB = "B";
			int pvMaxB = 100;
			float resistanceYB = 0.1;
			float resistanceCB = 0.5;
			float resistanceJB = 0.3;
			float resistanceOB = 0.1;
			int paceB = 3;
			int gainB = 6;

			/*Caractéristiques Lucie*/
			char* typeL = "L";
			int pvMaxL = 200;
			float resistanceYL = 0.5;
			float resistanceCL = 0;
			float resistanceJL = 0.3;
			float resistanceOL = 0.2;
			int paceL = 1;
			int gainL = 10;

			//ajoute un monstre à chaque fois que j est un muliple de 50
			if(j%(*apparition) == 0){

				//S'il y a moins ou 10 monstres
				if((*nb_monster) < 10) {

					//Si c'est
					if(joueur->lvl == 0)
						//Ajoute un Julien
						addMonster(p_lmonster, typeJ, pvMaxJ, resistanceYJ, resistanceCJ, resistanceJJ, resistanceOJ, paceJ, gainJ, map->list_node->p_head);
					//Si le joueur est à un niveau entre 1 et 3
					else if(joueur->lvl > 0 && joueur->lvl <= 3) {

						//Random entre 1 et 2
						random = rand()%(3-1) +1;

						if(random == 1)
							//Ajoute un Julien
							addMonster(p_lmonster, typeJ, pvMaxJ, resistanceYJ, resistanceCJ, resistanceJJ, resistanceOJ, paceJ, gainJ, map->list_node->p_head);
						else
							//Ajoute une Barbara
							addMonster(p_lmonster, typeB, pvMaxB, resistanceYB, resistanceCB, resistanceJB, resistanceOB, paceB, gainB, map->list_node->p_head);
					
					}
					//Si le joueur est à un niveau entre 4 et 5
					else if(joueur->lvl > 3 && joueur->lvl <= 5) {
						(*apparition) = 100;

						//Random entre 1 et 3
						random = rand()%(4-1) +1;

						if(random == 1)
							//Ajoute un Julien
							addMonster(p_lmonster, typeJ, pvMaxJ+20, resistanceYJ, resistanceCJ, resistanceJJ, resistanceOJ, paceJ, gainJ, map->list_node->p_head);
						else if(random == 2)
							//Ajoute une Barbara
							addMonster(p_lmonster, typeB, pvMaxB, resistanceYB, resistanceCB, resistanceJB, resistanceOB, paceB, gainB, map->list_node->p_head);
						else
							//Ajoute une Lucie
							addMonster(p_lmonster, typeL, pvMaxL, resistanceYL, resistanceCL, resistanceJL, resistanceOL, paceL, gainL, map->list_node->p_head);

					}
					//Si le joueur est à un niveau suppérieur à 6 à 8
					else if(joueur->lvl > 5 && joueur->lvl <= 8) {
						(*apparition) = 50;

						//Random entre 1 et 4
						random = rand()%(5-1) +1;

						if(random == 1)
							//Ajoute un Julien
							addMonster(p_lmonster, typeJ, pvMaxJ+20, resistanceYJ, resistanceCJ, resistanceJJ, resistanceOJ, paceJ, gainJ, map->list_node->p_head);
						else if(random == 2)
							//Ajoute une Barbara
							addMonster(p_lmonster, typeB, pvMaxB+20, resistanceYB, resistanceCB, resistanceJB, resistanceOB, paceB, gainB, map->list_node->p_head);
						else
							//Ajoute une Lucie
							addMonster(p_lmonster, typeL, pvMaxL, resistanceYL, resistanceCL, resistanceJL, resistanceOL, paceL, gainL,  map->list_node->p_head);

					}
					//Si le joueur est à un niveau suppérieur à 9 à 12
					else if(joueur->lvl > 8 && joueur->lvl <= 12) {
						(*apparition) = 50;

						//Random entre 1 et 5
						random = rand()%(6-1) +1;

						if(random == 1)
							//Ajoute un Julien
							addMonster(p_lmonster, typeJ, pvMaxJ+20, resistanceYJ, resistanceCJ, resistanceJJ, resistanceOJ, paceJ, gainJ, map->list_node->p_head);
						else if(random == 2  || random == 4)
							//Ajoute une Barbara
							addMonster(p_lmonster, typeB, pvMaxB+20, resistanceYB, resistanceCB, resistanceJB, resistanceOB, paceB, gainB,  map->list_node->p_head);
						else
							//Ajoute une Lucie
							addMonster(p_lmonster, typeL, pvMaxL, resistanceYL, resistanceCL, resistanceJL, resistanceOL, paceL, gainL,  map->list_node->p_head);

					}
					//Si le joueur est à un niveau suppérieur à 9 à 12
					else if(joueur->lvl > 8 && joueur->lvl <= 12) {
						(*apparition) = 50;

						//Random entre 1 et 6
						random = rand()%(7-1) +1;

						if(random == 1)
							//Ajoute un Julien
							addMonster(p_lmonster, typeJ, pvMaxJ+20, resistanceYJ, resistanceCJ, resistanceJJ, resistanceOJ, paceJ, gainJ, map->list_node->p_head);
						else if(random == 2 || random == 4)
							//Ajoute une Barbara
							addMonster(p_lmonster, typeB, pvMaxB+20, resistanceYB, resistanceCB, resistanceJB, resistanceOB, paceB, gainB,  map->list_node->p_head);
						else
							//Ajoute une Lucie
							addMonster(p_lmonster, typeL, pvMaxL+10, resistanceYL, resistanceCL, resistanceJL, resistanceOL, paceL, gainL,  map->list_node->p_head);

					}
					//Si le joueur est à un niveau suppérieur à 13 à 15
					else if(joueur->lvl > 12 && joueur->lvl <= 15) {
						(*apparition) = 50;

						//Random entre 1 et 7
						random = rand()%(8-1) +1;

						if(random == 1)
							//Ajoute un Julien
							addMonster(p_lmonster, typeJ, pvMaxJ+20, resistanceYJ, resistanceCJ, resistanceJJ, resistanceOJ, paceJ, gainJ, map->list_node->p_head);
						else if(random == 2 || random == 4)
							//Ajoute une Barbara
							addMonster(p_lmonster, typeB, pvMaxB+20, resistanceYB, resistanceCB, resistanceJB, resistanceOB, paceB, gainB,  map->list_node->p_head);
						else
							//Ajoute une Lucie
							addMonster(p_lmonster, typeL, pvMaxL+10, resistanceYL, resistanceCL, resistanceJL, resistanceOL, paceL, gainL,  map->list_node->p_head);

					}
					//Si le joueur est à un niveau suppérieur à 13 à 15
					else if(joueur->lvl > 12 && joueur->lvl <= 15) {
						(*apparition) = 30;

						//Random entre 1 et 8
						random = rand()%(9-1) +1;

						if(random == 1)
							//Ajoute un Julien
							addMonster(p_lmonster, typeJ, pvMaxJ+20, resistanceYJ, resistanceCJ, resistanceJJ, resistanceOJ, paceJ, gainJ, map->list_node->p_head);
						else if(random == 2 || random == 4)
							//Ajoute une Barbara
							addMonster(p_lmonster, typeB, pvMaxB+20, resistanceYB, resistanceCB, resistanceJB, resistanceOB, paceB, gainB,  map->list_node->p_head);
						else
							//Ajoute une Lucie
							addMonster(p_lmonster, typeL, pvMaxL+10, resistanceYL, resistanceCL, resistanceJL, resistanceOL, paceL, gainL,  map->list_node->p_head);

					}
					

					(*nb_monster)++;
				}
				//S'il n'y a plus de monstre
				else if(*nb_monster == 10 && p_lmonster->length == 0) {
					updateLvl(joueur); //Monte de niveau
					(*nb_monster)++;
				}
				else if(*nb_monster > 10 && *nb_monster <= 15) 
					(*nb_monster)++;
				else if(*nb_monster == 16) 
					*nb_monster = 0;
			}

		}
		else {
			fprintf(stderr, "Erreur avec l'joueur\n");
			return 0;
		}
	}
	else {
		fprintf(stderr, "Erreur avec la liste de monstre\n");
		return 0;
	}

	return 1;
}


/************* Dessiner un cercle en fonction de son rayon plein *************/
/* Dessine un cercle plein. Prend en paramètre le rayon du cercle.		*/

void drawDisque(float rayon) {
	
	int i, j = 100;
	float angle, x1, y1;
	
	glBegin(GL_TRIANGLE_FAN);

	glVertex2f(0, 0);

	for(i = 0; i <= j; i++) {
		angle = (2*pi*i)/j;
		x1 = rayon*(cos(angle));
		y1 = rayon*(sin(angle));
		glVertex2f(x1,y1);
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

void writeString(int x, int y,  char* s) {

		char* c;
		
		// Positionne le premier caractère de la chaîne
		glRasterPos2f(x, y);
		for (c = s; *c != '\0'; c++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Affiche chaque caractère de la chaîne

		// Réinitialise la position du premier caractère de la chaîne
		glRasterPos2f(0, 0);
}


