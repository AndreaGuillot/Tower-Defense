#include "../include/joueur.h"
#include "../include/draw.h"
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
/* Monstre tué */
void Joueur::updateMonsterKill(Monster* m){
    if(m != NULL){
        this->argent += m->getReward();
    }else{
        fprintf(stderr, "Erreur avec le monstre\n");
    }
}
/* Argent achat tour */
bool Joueur::updateMoneyBuildTower(float cost){
    int new_argent = this->argent-cost;
    if(new_argent<0){
        return 0;
    }else{
        this->argent = new_argent;
        return 1;
    }
}
/* Argent achat installation */
bool Joueur::updateMoneyBuildInstallation(Installation* i){
    int new_argent = this->argent - i->getCost();
    if(new_argent<0){
        return 0;
    }else{
        this->argent = new_argent;
        return 1;
    }
}
/* Dessine interface joueur */
bool Joueur::drawInterface (GLuint* spriteButton) {
    
    char* machaine;

    glColor3ub(255,255,255);
    
    /**** Money ****/
    //Convertie un int en un string
    sprintf(machaine,"%d",this->getArgent());
    //Affiche la chaine de caractère
    writeString(180, 40,  machaine);

    //Active le texturage 2D
    glEnable(GL_TEXTURE_2D);
    //Appel de la texture
    glBindTexture(GL_TEXTURE_2D, *spriteButton);

        glBegin(GL_QUADS);
        //Couleur neutre
        glColor3ub(255,255,255);
        //Coordonée de la texture
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

    return 1;

}

//Initialisations

void Joueur::initInterface () {
    this->argent = 100;
    this->nbVagues = 0;
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

void Joueur::freeInterface () {
    if (this != NULL) {
        free(this);
    }
}

void freeAll (listMonster* monsters, listShot* shots, listTower* towers, Map* map, Joueur* joueur) {

    //Liblère la liste de missiles
    shots->freeAllShot();
    //Libère la liste de monstres
    monsters->freeAllMonsters();
    //Libère la liste de tours
    towers->freeAllTower();
    //Libère la map
    map->freeMap();  
    //Libère l'interface
    joueur->freeInterface();
}