#include "../include/monstre.h"
#include "../include/draw.h"

Monster::Monster(){
    this->p = NULL;
    this->node_prev = NULL;
    this->node_next = NULL;
    this->monster_prev = NULL;
    this->monster_next = NULL;
}

//Get
Position* Monster::getPosition(){
    return this->p;
}
float Monster::getX(){
    return this->p->getX();
}
float Monster::getY(){
    return this->p->getY();
}    
float Monster::getErreur(){
    return this->erreur;
}

Sens Monster::getSens(){
    return this->sens;
}
Node* Monster::getPrev(){
    return this->node_prev;
}
Node* Monster::getNext(){
    return this->node_next;
}
Monster* Monster::getPrevM(){
    return this->monster_prev;
}
Monster* Monster::getNextM(){
    return this->monster_next;
}

monsterType Monster::getType(){
    return this->type;
}

uint Monster::getPV(){
    return this->pv;
}
uint Monster::getSpeed(){
    return this->speed;
}
//Ce qu'on gagne qd il meurt
uint Monster::getReward(){
    return this->money;
}
float Monster::getResistance_TDR(){
    return this->resistance_TDR;
}
float Monster::getResistance_TDV(){
    return this->resistance_TDV;
}
float Monster::getResistance_TDJ(){
    return this->resistance_TDJ;
}
float Monster::getResistance_TDB(){
    return this->resistance_TDB;
}

//Set
void Monster::set(Monster* m){
    this->setPosition(m->getPosition()->getX(), m->getPosition()->getY());
    this->setSens(m->getSens());
    this->setPV(m->getPV());
    this->setErreur(m->getErreur());
    this->setNodePrev(m->getPrev());
    this->setNodeNext(m->getNext());
    this->setPrevMonster(m->getPrevM());
    this->setNextMonster(m->getNextM());
    this->setType(m->getType());
    this->setPV(m->getPV());
    this->setSpeed(m->getSpeed());
    this->setReward(m->getReward());
    this->setResistance_TDR(m->getResistance_TDR());
    this->setResistance_TDV(m->getResistance_TDV());
    this->setResistance_TDJ(m->getResistance_TDJ());
    this->setResistance_TDB(m->getResistance_TDB());
}

void Monster::setPosition(float x, float y){
    this->p->setX(x);
    this->p->setY(y);
}

void Monster::setX(float x){
    this->p->setX(x);
}

void Monster::setY(float y){
    this->p->setY(y);
}

void Monster::setSens(Sens s){
    this->sens = s;
}

void Monster::setPV(uint pv){
    this->pv = pv;
}

void Monster::setErreur(float e){
    this->erreur = e;
}

void Monster::setNodePrev(Node* node){
    this->node_prev = node;
}
void Monster::setNodeNext(Node* node){
    this->node_next=node;
}

void Monster::setPrevMonster(Monster* m){
    this->monster_prev = m;
}

void Monster::setNextMonster(Monster* m){
    this->monster_next = m;
}

void Monster::setType(monsterType m){
    this->type = m;
}
void Monster::setSpeed(uint a){
    this->speed = a;
}
void Monster::setReward(uint a){
    this->money = a;
}
void Monster::setResistance_TDR(float resistance){
    this->resistance_TDR = resistance;
}
void Monster::setResistance_TDV(float resistance){
    this->resistance_TDV = resistance;
}
void Monster::setResistance_TDJ(float resistance){
    this->resistance_TDJ = resistance;
}
void Monster::setResistance_TDB(float resistance){
    this->resistance_TDB = resistance;
}

//Fonctions
/* Cherche les erreurs */
void Monster::calculErreur() {

    //Si on est sur un chemin
    if(this->node_prev != NULL && this->node_next != NULL) {

        //Si on bute sur l'axe des x
        if(this->node_prev->getX() == this->node_next->getX()) {

            this->erreur = 0; //erreur

            if(this->node_prev->getY() <= this->node_next->getY())
                this->sens = bas;
            else
                this->sens = haut; 
        }
        //Si on bute sur l'axe des y
        else if(this->node_prev->getY() == this->node_next->getY()) {

            this->erreur = 0;//erreur

            if(this->node_prev->getX() <= this->node_next->getX())
                this->sens = droite;
            else
                this->sens = gauche;
        }
        else {

            float dx = (this->node_next->getX()) - (this->node_prev->getX());
            float dy = (this->node_next->getY()) - (this->node_prev->getY());   

            if(dx > 0) {
                if(dy > 0) {

                    if(dx >= dy)
                        this->erreur = (this->node_next->getX()) - (this->node_prev->getX());
                    else
                        this->erreur = (this->node_next->getY()) - (this->node_prev->getY());
                }
                else {

                    if(dx >= -dy)
                        this->erreur = (this->node_next->getX()) - (this->node_prev->getX());
                    else
                        this->erreur = (this->node_next->getY()) - (this->node_prev->getY());

                }

                this->sens = droite;

            }
            else {
                if(dy > 0) {

                    if(-dx >= dy)
                        this->erreur = (this->node_next->getX()) - (this->node_prev->getX());
                    else
                        this->erreur = (this->node_next->getY()) - (this->node_prev->getY());

                }
                else {
                    if(dx <= dy)
                        this->erreur = (this->node_next->getX()) - (this->node_prev->getX());
                    else
                        this->erreur = (this->node_next->getY()) - (this->node_prev->getY());
                }
                this->sens = gauche;
            }       

        }

    }
    else
        fprintf(stderr, "Erreur sur le pointeur du monstre\n");

}
/* Affcihe propriétés monstre */
int Monster::drawProprieteMonster (GLuint* monster) {

    if(this != NULL) {

        int monsterNumber = this->type;

        float x1 = (monsterNumber * (1.0/4.0)) + (2.0/12.0);
        float x2 = (monsterNumber * (1.0/4.0)) + 0.25;
        float y1 = 0;
        float y2 = 0.25;

        //Active le texturage 2D
        glEnable(GL_TEXTURE_2D);
        //Appel de la texture
        glBindTexture(GL_TEXTURE_2D, *monster);

            glBegin(GL_QUADS);
            //Couleur neutre
            glColor3ub(255,255,255);
            //Coordonée de la texture
            glTexCoord2f(x2, y1);
            //Cordonnée du quadrilatère 
            glVertex2f(20, 300);

            glTexCoord2f(x2, y2);
            glVertex2f(20, 340);

            glTexCoord2f(x1, y2);
            glVertex2f(60, 340);

            glTexCoord2f(x1, y1);
            glVertex2f(60, 300);


            glEnd();

        //Déblinder la texture
        glBindTexture(GL_TEXTURE_2D, 0);
        //Désactive le texturage 2D
        glDisable(GL_TEXTURE_2D);

        char* machaine;

        /**** points de vie ****/
        //Convertit un int en un string
        sprintf(machaine,"%d",this->pv);

        writeString(20, 365,  "Points de vie : ");
        //Affiche la chaine de caractère
        writeString(120, 365,  machaine);

        /**** Vitesse ****/
        //Convertie un int en un string
        sprintf(machaine,"%d",this->speed);

        writeString(20, 390,  "Vitesse : ");
        //Affiche la chaine de caractère
        writeString(120, 390,  machaine);

        /**** Resistance ****/
        //Convertit un int en un string
        sprintf(machaine,"%f",this->resistance_TDB);

        writeString(20, 440,  "Resistance à Océane: ");
        //Affiche la chaine de caractère
        writeString(120, 440,  machaine);


        /**** nombre de monstre ****/
        char* type;
        switch(this->type){
            case barbara:
                type = "Barbara";
                break;
            case julien:
                type = "Julien";
                break;
            case lucie:
                type = "Lucie";
                break;
            default:break;
        }

        writeString(20, 465,  "Type : ");
        //Affiche la chaine de caractère
        writeString(120, 465,  type);
    }

    return 1;

}
/* Vérifie doublons */
bool Monster::isSame(Monster* m){
    if(this->getX() != m->getX()){
        return 0;
    }
    if(this->getY() != m->getY()){
        return 0;
    }
    if(this->getErreur() != m->getErreur()){
        return 0;
    }
    if(this->getSens() != m->getSens()){
        return 0;
    }
    if(this->getPrev() != m->getPrev()){
        return 0;
    }
    if(this->getNext() != m->getNext()){
        return 0;
    }
    if(this->getType() != m->getType()){
        return 0;
    }
    if(this->getPV() != m->getPV()){
        return 0;
    }
    if(this->getSpeed() != m->getSpeed()){
        return 0;
    }
    if(this->getReward() != m->getReward()){
        return 0;
    }
    if(this->getResistance_TDR() != m->getResistance_TDR()){
        return 0;
    }
    if(this->getResistance_TDV() != m->getResistance_TDV()){
        return 0;
    }
    if(this->getResistance_TDJ() != m->getResistance_TDJ()){
        return 0;
    }
    if(this->getResistance_TDB() != m->getResistance_TDB()){
        return 0;
    }
    return 1;
}

//Types de monstre
Lucie::Lucie(uint pv, uint speed, uint money, float resistance_TDR, float resistance_TDV, float resistance_TDJ, float resistance_TDB){
            this->setPV(pv);
            this->setSpeed(speed);
            this->setReward(money);
            this->setResistance_TDR(resistance_TDR);
            this->setResistance_TDV(resistance_TDV);
            this->setResistance_TDJ(resistance_TDJ);
            this->setResistance_TDB(resistance_TDB);
        }

Barbara::Barbara(uint pv, uint speed, uint money, float resistance_TDR, float resistance_TDV, float resistance_TDJ, float resistance_TDB){
            this->setPV(pv);
            this->setSpeed(speed);
            this->setReward(money);
            this->setResistance_TDR(resistance_TDR);
            this->setResistance_TDV(resistance_TDV);
            this->setResistance_TDJ(resistance_TDJ);
            this->setResistance_TDB(resistance_TDB);
        }

Julien::Julien(uint pv, uint speed, uint money, float resistance_TDR, float resistance_TDV, float resistance_TDJ, float resistance_TDB){
            this->setPV(pv);
            this->setSpeed(speed);
            this->setReward(money);
            this->setResistance_TDR(resistance_TDR);
            this->setResistance_TDV(resistance_TDV);
            this->setResistance_TDJ(resistance_TDJ);
            this->setResistance_TDB(resistance_TDB);
        }
//Liste des monstres
listMonster::listMonster(){
    this->length = 0;
    this->head = NULL;
    this->tail = NULL;
}

//Get
int listMonster::getLength(){
    return this->length;
}
Monster* listMonster::getHead(){
    return this->head;
}
Monster* listMonster::getTail(){
    return this->tail;
}

//Fonctions
/* Affiche monstre */
bool listMonster::listMonster::addMonster(monsterType type, Node* node) {
    if(this!=NULL){
        //On crée le monstre
        Monster* monster;
        switch(type){
            case lucie: 
                monster = new Lucie();
                break;

            case barbara: 
                monster = new Barbara();
                break;
            case julien: 
                monster = new Julien();
                break;
            default: break;
        }

        if(monster != NULL){
            monster->setPosition(node->getPosition()->getX(), node->getPosition()->getY());
            monster->setNodePrev(node);
            monster->setNodeNext(node->getNext());

            //Vérifie le déplacement pour savoir dans quelle sens il se déplace et pour donner l'erreur
            monster->calculErreur();

            //Comme il est a la fin de la liste, il pointe sur NULL
            monster->setNextMonster(NULL);

            //Si la liste était vide de base, alors elle est composée de seulement ce monstre
            if(this->tail == NULL){
                this->head->set(monster);
                monster->setPrevMonster(NULL);
            }else{
            //On pointe le précédent monstre sur la queue de la liste et on ajoute a la queue le monstre
                monster->setPrevMonster(this->tail);
                this->tail->setNextMonster(monster);
            }

            this->tail->set(monster);

            this->length++;
        }else{
            fprintf(stderr, "Problème dans la creation du nouveau monstre\n");
            return 0;
        }
    }else{
        fprintf(stderr, "Cette liste de monstres n'existe pas\n");
        return 0;
    }
    return 1;
}
/* Déplacements */
int listMonster::moveMonster (Node* node, int k){

    if(this != NULL){
        Monster* tmp = this->head;

        while(tmp != NULL){
            if(k%tmp->getSpeed() == 0){
                //S'il avance selon l'axe des y
                if(tmp->getPrev()->getX() == tmp->getNext()->getX()){
                    if(tmp->getSens() == bas)
                        tmp->setY(tmp->getPosition()->getY()+1);
                    else
                        tmp->setY(tmp->getPosition()->getY()-1);

                //S'il avance selon l'axe des x
                }else if(tmp->getPrev()->getY() == tmp->getNext()->getY()){
                    if(tmp->getSens() == droite)
                        tmp->setX(tmp->getPosition()->getX()+1);
                    else
                        tmp->setX(tmp->getPosition()->getX()-1);
                }else{
                    //Il avance selon les deux axes
                    float x, y;
                    x = (tmp->getNext()->getX() - tmp->getPrev()->getX())*2;
                    y = (tmp->getNext()->getY() - tmp->getPrev()->getY())*2;

                    if(x>0){
                        if(y>0){
                            if(x>=y){
                                tmp->setX(tmp->getX()+1);
                                tmp->setErreur(tmp->getErreur() - y);

                                if(tmp->getErreur() <=0){
                                    tmp->setY(tmp->getY()+1);
                                    tmp->setErreur(tmp->getErreur()+x);
                                }
                            }else{
                                tmp->setY(tmp->getY()+1);
                                tmp->setErreur(tmp->getErreur() - x);

                                if(tmp->getErreur() <= 0){
                                    tmp->setX(tmp->getX()+1);
                                    tmp->setErreur(tmp->getErreur() + y);
                                }
                            }
                        }else{

                            if(x>=y){
                                tmp->setX(tmp->getX()+1);
                                tmp->setErreur(tmp->getErreur() + y);

                                if(tmp->getErreur() <=0){
                                    tmp->setY(tmp->getY()-1);
                                    tmp->setErreur(tmp->getErreur() +x);
                                }
                            }else{
                                tmp->setY(tmp->getY()-1);
                                tmp->setErreur(tmp->getErreur() +x);

                                if(tmp->getErreur() > 0){
                                    tmp->setX(tmp->getX()+1);
                                    tmp->setErreur(tmp->getErreur()+y);
                                }
                            }
                        }
                    }else{
                        if(y>0){
                            if( -x >= y){
                                tmp->setX(tmp->getX()-1);
                                tmp->setErreur(tmp->getErreur()+y);

                                if(tmp->getErreur() >= 0){
                                    tmp->setY(tmp->getY()+1);
                                    tmp->setErreur(tmp->getErreur()+x);
                                }
                            }else{
                                tmp->setY(tmp->getY()+1);
                                tmp->setErreur(tmp->getErreur()+x);

                                if(tmp->getErreur() <=0){
                                    tmp->setX(tmp->getX()-1);
                                    tmp->setErreur(tmp->getErreur()+y);
                                }
                            }
                        }else{
                            if(x <= y){
                                tmp->setX(tmp->getX()-1);
                                tmp->setErreur(tmp->getErreur() - y);

                                if(tmp->getErreur() >= 0){
                                    tmp->setY(tmp->getY()-1);
                                    tmp->setErreur(tmp->getErreur() +x);
                                }
                            }else{
                                tmp->setY(tmp->getY()-1);
                                tmp->setErreur(tmp->getErreur() - y);

                                if(tmp->getErreur() >= 0){
                                    tmp->setX(tmp->getX()-1);
                                    tmp->setErreur(tmp->getErreur() +y);
                                }
                            }
                        }
                    }
                }

                if((tmp->getX() == tmp->getNext()->getX()) && (tmp->getY() == tmp->getNext()->getY())){
                    if((tmp->getX() == node->getX()) && (tmp->getY() == node->getY()))
                        return 2;
                    else{
                        tmp->setNodePrev(tmp->getNext());
                        tmp->setNodeNext(tmp->getNext()->getNext());

                        tmp->calculErreur();
                    }
                }
            }

            tmp = tmp->getNextM();
        }

    }else {
        fprintf(stderr, "Cette liste de monstres n'existe pas");
        return 0;
    }

    return 1;
}
/* Supprime monstre */
void listMonster::removeMonster(Monster* monster) {

    if (this != NULL) {
        if(monster != NULL) {
            //Si c'est le dernier monstre de la liste
            if (monster->getNextM() == NULL) {
            
                //Pointe la fin de la liste sur le monstre précédent
                this->tail->set(monster->getPrevM());
            
                if(this->tail != NULL) {
                    //Lien du dernier monstre vers le monstre suivant est NULL
                    this->tail->setNextMonster(NULL);
                }
                else
                    this->head->set(NULL);
                
            }
            //Si c'est le premier monstre de la liste
            else if (monster->getPrevM() == NULL) {
                //Pointe la tête de la liste vers le monstre suivant
                this->head->set(monster->getNextM());

                if(this->head != NULL) {
                    //Le lien vers du deuxième monstre vers le monstre précédent est NULL
                    this->head->setPrevMonster(NULL);
                }
                else
                    this->tail->set(NULL);
            }

            else {
                //Relie le monstre suivant au monstre précédent du monstre que l'on veut supprimer 
                monster->getNextM()->setPrevMonster(monster->getPrevM());
                //Relie le monstre précédent au monstre suivant du monstre que l'on veut supprimer 
                monster->getPrevM()->setNextMonster(monster->getNextM());
            }
            //Libère esspeed mémoire : supprime le monstre
            free(monster);
            //Décrémente de un la taille de la liste
            this->length--;

        }
        else {
            fprintf(stderr, "Ce monstre n'existe pas\n");
        }
    }
    else {
        fprintf(stderr, "Cette liste de monstres n'existe pas\n");
    }
}
/* Supprime tous les monstres */
void listMonster::removeAllMonsters() {
    //Si la liste n'est pas vide
    if (this->length != 0) {

        //Tant que la liste n'est pas vide
        while (this->head != NULL) {
            this->removeMonster(this->head);
        }
        
    }
}
/* Libère espace mémoire */
void listMonster::freeAllMonsters() {
    //Si la liste n'est pas vide
    if (this->length != 0) {

        //Tant que la liste n'est pas vide
        while (this->head != NULL) {
            this->removeMonster(this->head);
        }
        
    }
    free(this);
}
/* Dessine monstre */
int listMonster::drawMonster(GLuint* monster) {
    if(monster != NULL && this != NULL) {
    
        //Création d'un pointeur monstre temporaire pour parcourir la liste de monstres
        Monster* tmp = this->tail;

        //Parcours la liste de monstres
        while(tmp != NULL){

            int monsterNumber = tmp->getType();
            
            float xm1, xm2, ym1, ym2;
            xm1 = tmp->getX() + 20;
            xm2 = tmp->getX() - 20;
            ym1 = tmp->getY() + 20;
            ym2 = tmp->getY() - 20;

            float x1 = (monsterNumber * (3.0/12.0));
            float x2 = (monsterNumber * (3.0/12.0));
            float y1 = 0, y2 = 0;

            switch(tmp->getSens()) {
                case haut :
                    y1 = 0.5;
                    y2 = 0.75;
                    break;
                case droite :
                    y1 = 0.75;
                    y2 = 1;
                    break;
                case bas :
                    y1 = 0;
                    y2 = 0.25;
                    break;
                case gauche :
                    y1 = 0.25;
                    y2 = 0.5;
                    break;
            }
        
            //Active le texturage 2D
            glEnable(GL_TEXTURE_2D);
            //Appel de la texture
            glBindTexture(GL_TEXTURE_2D, *monster);
        
                glPushMatrix();
                    glBegin(GL_QUADS);
                        //Coordonée de la texture
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
                glPopMatrix();

            //Déblinder la texture
            glBindTexture(GL_TEXTURE_2D, 0);
            //Désactive le texturage 2D
            glDisable(GL_TEXTURE_2D);

            tmp = tmp->getPrevM();
        }
    }
    else {
        printf("Erreur : la texture du monstre ou la liste de monstre n'existe pas\n");
        return 0;
    }

    return 1;
}