#include "../include/joueur.h"
#include <stdlib.h>
#include <string.h>

Joueur::Joueur(){
    this->argent = 100;
    this->nbVagues = 0;
}

//Get
uint Joueur::getArgent(){
    return this->argent;
}
int Joueur::getNbVagues(){
    return this->nbVagues;
}

//Set
void Joueur::setArgent(uint argent){
    this->argent = argent;
}
void Joueur::setNbVagues(int n){
    this->nbVagues = n;
}

//Fonctions
void Joueur::updateMonsterKill(Monster* m){
    if(m != NULL){
        this->argent += m->getReward();
    }else{
        fprintf(stderr, "Erreur avec le monstre\n");
    }
}

bool Joueur::updateMoneyBuildTower(float cost){
    int new_argent = this->argent-cost;
    if(new_argent<0){
        return 0;
    }else{
        this->argent = new_argent;
        return 1;
    }
}

bool Joueur::updateMoneyBuildInstallation(Installation* i){
    int new_argent = this->argent - i->getCost();
    if(new_argent<0){
        return 0;
    }else{
        this->argent = new_argent;
        return 1;
    }
}

bool Joueur::drawInterface (GLuint* spriteButton) {
    if(this != NULL) {

        char* machaine;

        glColor3ub(255,255,255);
        
        /**** Money ****/
        //Convertie un int en un string
        sprintf(machaine,"%d",this->getArgent());
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

void Joueur::initInterface () {
    if (this != NULL) {
        this->argent = 100;
        this->nbVagues = 0;
    }
}

void initAll (listMonster* monsters, listShot* shots, listTower* towers, Joueur* joueur) {

    //Retire les missiles de la liste
    shots->removeAllShot();
    //Retire les monstres de la liste
    monsters->removeAllMonsters();
    //Retire les tours de la liste
    towers->removeAllTower();
    //Réinitialise l'interface
    joueur->initInterface();
}

void freeAll (listMonster* monsters, listShot* shots, listTower* towers, Map* map, Joueur* joueur) {

    //Liblère la liste de missiles
    shots->freeAllShot();
    //Libère la liste de monstres
    monsters->freeAllMonsters();
    //Libère la liste de tours
    towers->freeAllTower();
    //Libère la map
    /**













    A FAIRE

























    */
    //map->freeMap();  
    //Libère l'interface
    //joueur->freeInterface();
}