#include "../include/joueur.h"
#include <stdlib.h>
#include <string.h>

class Joueur {

    public:
    //Constructeur
        Joueur(){
            this->argent = 100;
            this->nbVagues = 0;
        }

        //Get
        uint getArgent(){
            return this->argent;
        }
        int getNbVagues(){
            return this->nbVagues;
        }

        //Set
        void setArgent(uint argent){
            this->argent = argent;
        }
        void setNbVagues(int n){
            this->nbVagues = n;
        }

        //Fonctions
        void updateMoneyKill(Monster m){
            this->argent += m.getReward();
        }

        bool updateMoneyBuildTower(Tower* t){
            int new_argent -= t->getCost();
            if(new_argent<0){
                return 0;
            }else{
                this->argent = new_argent;
                return 1;
            }
        }

        bool updateMoneyBuildInstallation(Installation i){
            int new_argent -= i.getCost();
            if(new_argent<0){
                return 0;
            }else{
                this->argent = new_argent;
                return 1;
            }
        }

        bool drawInterface (GLuint* spriteButton) {
            if(this != NULL) {

                string machaine;

                glColor3ub(255,255,255);
                
                /**** Money ****/
                //Convertie un int en un string
                sprintf(machaine,"%d",this.getArgent());
                //Affiche la chaine de caractère
                writeString(180, 40,  machaine);

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
                    glVertex2f(140, 45);

                    glTexCoord2f(0.125, 0);
                    glVertex2f(140, 15);

                    glTexCoord2f(0, 0);
                    glVertex2f(170, 15);

                    glTexCoord2f(0, 1);
                    glVertex2f(170, 45);

                    glEnd();

                //Déblinder la texture
                glBindTexture(GL_TEXTURE_2D, 0);
                //Désactive le texturage 2D
                glDisable(GL_TEXTURE_2D);
            }
            else {
                fprintf(stderr, "Il y a un problème avec l'interface\n");
                return 0;
            }   

            return 1;

        }
};