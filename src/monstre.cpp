#include "../include/installation.h"
#include "../include/tower.h"
#include "../include/monstre.h"

class Monster {
	
    public:
    Monster(){
        this = NULL;
    }
    //Get
    Position getPosition(){
        return this->p;
    }
    float getX(){
        return this->x;
    }
    float getY(){
        return this->y;
    }    
    float getErreur(){
        return this->erreur;
    }

    Sens getSens(){
        return this->sens;
    }
    Node getPrev(){
        return this->node_prev;
    }
    Node getNext();{
        return this->node_next;
    }
    Monster getPrevM(){
        return this->monster_prev;
    }
    Monster getNextM(){
        return this->monster_next;
    }

    monsterType getType(){
        return this->type;
    }
    
    float getPV(){
        return this->pv;
    }
    float getSpeed(){
        return this->speed;
    }
    //Ce qu'on gagne qd il meurt
    uint getReward(){
        return this->money;
    }
    float getResistance_TDR(){
        return this->resistance_TDR;
    }
    float getResistance_TDV(){
        return this->resistance_TDV;
    }
    float getResistance_TDJ(){
        return this->resistance_TDJ;
    }
    float getResistance_TDB(){
        return this->resistance_TDB;
    }

    //Set
    void set(Monster m){
        this = m;
    }

    void setPosition(Position p){
        this->p = p;
    }

    void setX(float x){
        this->p.setX(x);
    }

    void setY(float y){
        this->p.setY(y);
    }

    void setSens(Sens s){
        this->sens = s;
    }

    void setPV(uint pv){
        this->pv = pv;
    }

    void setErreur(float e){
        this->erreur = e;
    }

    void setNodePrev(Node node){
        this->node_prev = node;
    }
    void setNodeNext(Node node){
        this->node_next=node;
    }

    void setPrevMonster(Monster m){
        this->monster_prev = m;
    }

    void setNextMonster(Monster m){
        this->monster_next = m;
    }

    //Fonctions

    void calculErreur() {

        //Si on est sur un chemin
        if(this->node_prev != NULL && this->node_next != NULL) {

            //Si on bute sur l'axe des x
            if(this->node_prev.getX() == this->node_next.getX()) {

                this->erreur = 0; //erreur

                if(this->node_prev.getY() <= this->node_next.getY())
                    this->sens = bas;
               else
                    this->sens = haut; 
            }
            //Si on bute sur l'axe des y
            else if(this->node_prev.getY() == this->node_next.getY()) {

                this->erreur = 0;//erreur

                if(this->node_prev.getX() <= this->node_next.getX())
                    this->sens = droite;
                else
                    this->sens = gauche;
            }
            else {

                float dx = (this->node_next.getX()) - (this->node_prev.getX());
                float dy = (this->node_next.getY()) - (this->node_prev.getY());   

                if(dx > 0) {
                    if(dy > 0) {

                        if(dx >= dy)
                            this->erreur = (this->node_next.getX()) - (this->node_prev.getX());
                        else
                            this->erreur = (this->node_next.getY()) - (this->node_prev.getY());
                    }
                    else {

                        if(dx >= -dy)
                            this->erreur = (this->node_next.getX()) - (this->node_prev.getX());
                        else
                            this->erreur = (this->node_next.getY()) - (this->node_prev.getY());

                    }

                    this->sens = droite;

                }
                else {
                    if(dy > 0) {

                        if(-dx >= dy)
                            this->erreur = (this->node_next.getX()) - (this->node_prev.getX());
                        else
                            this->erreur = (this->node_next.getY()) - (this->node_prev.getY());

                    }
                    else {
                        if(dx <= dy)
                            this->erreur = = (this->node_next.getX()) - (this->node_prev.getX());
                        else
                            this->erreur = = (this->node_next.getY()) - (this->node_prev.getY());
                    }
                    this->sens = gauche;
                }       

            }

        }
        else
            fprintf(stderr, "Erreur sur le pointeur du monstre\n");

    }

    int drawProprieteMonster (GLuint* monster) {

        if(this != NULL) {

            int monsterNumber = this->type;

            float x1 = (monsterNumber * (1.0/4.0)) + (2.0/12.0);
            float x2 = (monsterNumber * (1.0/4.0)) + 0.25;
            float y1 = 0;
            float y2 = 0.25;

            //Active le texturage 2D
            glEnable(GL_TEXTURE_2D);
            //appel de la texture
            glBindTexture(GL_TEXTURE_2D, *monster);

                glBegin(GL_QUADS);
                //couleur neutre
                glColor3ub(255,255,255);
                //coordonée de la texture
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

            string machaine;

            /**** points de vie ****/
            //Convertie un int en un string
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
            //Convertie un int en un string
            sprintf(machaine,"%d",this->resistance_TDB);

            writeString(20, 440,  "Resistance à Océane: ");
            //Affiche la chaine de caractère
            writeString(120, 440,  machaine);


            /**** nombre de monstre ****/
            string type;
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

    bool isSame(Monster m){
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
};

class Lucie: public Monster{
    public:
        Lucie(uint pv=200; uint speed = 0.09; uint money = 20; float resistance_TDR = 0.5; float resistance_TDV = 0; float resistance_TDJ = 0.3; float resistance_TDB = 0.2){
            this->pv = pv;
            this->speed = speed;
            this->money = money;
            this->resistance_TDR = resistance_TDR;
            this->resistance_TDV = resistance_TDV;
            this->resistance_TDJ = resistance_TDJ;
            this->resistance_TDB = resistance_TDB;
        }
}

class Barbara: public Monster{
    public:
        Barbara(uint pv=100; uint speed = 0.11; uint money = 15; float resistance_TDR = 0.1; float resistance_TDV = 0.5; float resistance_TDJ = 0.3; float resistance_TDB = 0.1){
            this->pv = pv;
            this->speed = speed;
            this->money = money;
            this->resistance_TDR = resistance_TDR;
            this->resistance_TDV = resistance_TDV;
            this->resistance_TDJ = resistance_TDJ;
            this->resistance_TDB = resistance_TDB;
        }
}


class Julien: public Monster{
    public:
        Julien(uint pv=50; uint speed = 0.14; uint money = 8; float resistance_TDR = 0.1; float resistance_TDV = 0.8; float resistance_TDJ = 0; float resistance_TDB = 0){
            this->pv = pv;
            this->speed = speed;
            this->money = money;
            this->resistance_TDR = resistance_TDR;
            this->resistance_TDV = resistance_TDV;
            this->resistance_TDJ = resistance_TDJ;
            this->resistance_TDB = resistance_TDB;
        }

}

class listMonster {

    public:

        listMonster(){
            this->length = 0;
            head.set(NULL);
            tail.set(NULL);
        }

        int getLength(){
            return this->length;
        }
        Monster getHead(){
            return this->head;
        }
        Monster getTail(){
            return this->tail;
        }

        bool addMonster(monsterType type, Node* node) {
            if(this!=NULL){
                //On crée le monstre

                switch(type){
                    case Lucie: 
                        Lucie monster;
                        break;

                    case Barbara: 
                        Barbara monster;
                        break;
                    case Julien: 
                        Julien monster;
                        break;
                    default: break;
                }

                if(monster != NULL){
                    monster.setPosition(node->getPosition());
                    monster.setNodePrev(node);
                    monster.setNodeNext(node->getNext());

                    //Vérifie le déplacement pour savoir dans quelle sens il se déplace et pour donner l'erreur
                    monster.calculErreur();

                    //Comme il est a la fin de la liste, il pointe sur NULL
                    monster.setNextMonster(NULL);

                    //Si la liste était vide de base, alors elle est composée de seulement ce monstre
                    if(this->tail == NULL){
                        this->head.set(monster);
                        monster.setPrevMonster(NULL);
                    }else{
                    //On pointe le précédent monstre sur la queue de la liste et on ajoute a la queue le monstre
                        monster.setPrevMonster(this->tail);
                        this->tail.setNextMonster(monster);
                    }

                    this->tail.set(monster);

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

        int moveMonster (Node node){

            if(this != NULL){
                Monster tmp = this->head;

                while(tmp != NULL){
                    if(k%tmp.getSpeed() == 0){
                        //S'il avance selon l'axe des y
                        if(tmp.getPrev().getX() == tmp.getNext().getX()){
                            if(tmp.getSens() == bas)
                                tmp.setY(tmp.getPosition().getY()+1);
                            else
                                tmp.setY(tmp.getPosition().getY()-1);

                        //S'il avance selon l'axe des x
                        }else if(tmp.getPrev().getY() == tmp.getNext().getY()){
                            if(tmp.getSens() == droite)
                                tmp.setX(tmp.getPosition().getX()+1);
                            else
                                tmp.setX(tmp.getPosition().getX()-1);
                        }else{
                            //Il avance selon les deux axes

                            float x, y;
                            x = (tmp.getNext().getPosition() - tmp.getPrev().getPosition())*2;
                            y = (tmp.getNext().getPositionY() - tmp.getPrev().getPosition())*2;

                            if(x>0){
                                if(y>0){
                                    if(x>=y){
                                        tmp.setX(tmp.getPositionX()+1);
                                        tmp.setErreur(tmp.getErreur() - y);

                                        if(tmp.getErreur() <=0){
                                            tmp.setY(tmp.getY()+1);
                                            tmp.setErreur(tmp.getErreur()+x);
                                        }
                                    }else{
                                        tmp.setY(tmp.getY()+1);
                                        tmp.setErreur(tmp.getErreur() - x);

                                        if(tmp.getErreur() <= 0){
                                            tmp.setX(tmp.getX()+1);
                                            tmp.setErreur(tmp.getErreur() + y);
                                        }
                                    }
                                }else{

                                    if(x>=y){
                                        tmp.setX(tmp.getX+1);
                                        tmp.setErreur(tmp.getErreur() + y);

                                        if(tmp.getErreur() <=0){
                                            tmp.setY(tmp.getY()-1);
                                            tmp.setErreur(tmp.getErreur() +x);
                                        }
                                    }else{
                                        tmp.setY(tmp.getY()-1);
                                        tmp.setErreur(tmp.getErreur() +x);

                                        if(tmp.getErreur() > 0){
                                            tmp.setX(tmp.getX()+1);
                                            tmp.setErreur(tmp.getErreur()+y);
                                        }
                                    }
                                }
                            }else{
                                if(y>0){
                                    if( -x >= y){
                                        tmp.setX(tmp.getX()-1);
                                        tmp.setErreur(tmp.getErreur()+y);

                                        if(tmp.getErreur() >= 0){
                                            tmp.setY(tmp.getY()+1);
                                            tmp.setErreur(tmp.getErreur()+x);
                                        }
                                    }else{
                                        tmp.setY(tmp.getY()+1);
                                        tmp.setErreur(tmp.getErreur()+x);

                                        if(tmp.getErreur() <=0){
                                            tmp.setX(tmp.getX()-1);
                                            tmp.setErreur(tmp.getErreur()+y);
                                        }
                                    }
                                }else{
                                    if(x <= y){
                                        tmp.setX(tmp.getX()-1);
                                        tmp.setErreur(tmp.getErreur() - y);

                                        if(tmp.getErreur() >= 0){
                                            tmp.setY(tmp.getY()-1);
                                            tmp.setErreur(tmp.getErreur() +x);
                                        }
                                    }else{
                                        tmp.setY(tmp.getY()-1);
                                        tmp.setErreur(tmp.getErreur() - y);

                                        if(tmp.getErreur() >= 0){
                                            tmp.setX(tmp.getX()-1);
                                            tmp.setErreur(tmp.getErreur() +y);
                                        }
                                    }
                                }
                            }
                        }

                        if(tmp.getPosition() == tmp.getNext().getPosition()){
                            if(tmp.getPosition() == node.getPosition())
                                return 2;
                            else{
                                tmp.setNodePrev(tmp.getNext());
                                tmp.setNodeNext(tmp.getNext().getNext());

                                tmp.calculErreur();
                            }
                        }
                    }

                    tmp = tmp.getNext();
                }

            }else {
                fprintf(stderr, "Cette liste de monstres n'existe pas");
                return 0;
            }

            return 1;
        }

        void removeMonster(Monster monster) {

            if (this != NULL) {
                if(monster != NULL) {
                    //Si c'est le dernier monstre de la liste
                    if (monster.getNextM() == NULL) {
                    
                        //Pointe la fin de la liste sur le monstre précédent
                        this->tail.set(monster.getPrevM());
                    
                        if(this->tail != NULL) {
                            //Lien du dernier monstre vers le monstre suivant est NULL
                            this->tail.setNextMonster(NULL);
                        }
                        else
                            this->head.set(NULL);
                        
                    }
                    //Si c'est le premier monstre de la liste
                    else if (monster.getPrevM() == NULL) {
                        //Pointe la tête de la liste vers le monstre suivant
                        this->head.set(monster.getNextM());

                        if(this->head != NULL) {
                            //Le lien vers du deuxième monstre vers le monstre précédent est NULL
                            this->head.setPrevMonster(NULL);
                        }
                        else
                            this->tail.set(NULL);
                    }

                    else {
                        //Relie le monstre suivant au monstre précédent du monstre que l'on veut supprimer 
                        monster.getNextM().setPrevMonster(monster.getPrevM());
                        //Relie le monstre précédent au monstre suivant du monstre que l'on veut supprimer 
                        monster.getPrevM().setNextMonster(monster.getNextM());
                    }
                    //Libère esspeed mémoire : supprime le monstre
                    free(monster);
                    //Décrémente de un la taille de la liste
                    this->length--;

                }
                else {
                    fprintf(stderr, "Ce monstre n'existe pas\n");
                    return NULL;
                }
            }
            else {
                fprintf(stderr, "Cette liste de monstres n'existe pas\n");
                return NULL;
            }
        }

        void removeAllMonsters() {
            //Si la liste n'est pas vide
            if (this->length != 0) {

                //Tant que la liste n'est pas vide
                while (this->head != NULL) {
                    this = removeMonster(this, this->head);
                }
                
            }
        }

        void freeAllMonsters() {
            //Si la liste n'est pas vide
            if (this->length != 0) {

                //Tant que la liste n'est pas vide
                while (this->head != NULL) {
                    this = removeMonster(this, this->head);
                }
                
            }
            free(this);
        }

        int drawMonster(GLuint* monster) {
            if(monster != NULL && this != NULL) {
            
                //Création d'un pointeur monstre temporaire pour parcourir la liste de monstres
                Monster tmp = this->tail;

                //Parcours la liste de monstres
                while(tmp != NULL){

                    int monsterNumber = tmp.getType();
                    
                    float xm1, xm2, ym1, ym2;
                    xm1 = tmp.getX() + 20;
                    xm2 = tmp.getX() - 20;
                    ym1 = tmp.getY() + 20;
                    ym2 = tmp.getY() - 20;

                    float x1 = (monsterNumber * (3.0/12.0));
                    float x2 = (monsterNumber * (3.0/12.0));
                    float y1 = 0, y2 = 0;

                    switch(tmp.getSens()) {
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
                    //appel de la texture
                    glBindTexture(GL_TEXTURE_2D, *monster);
                
                        glPushMatrix();
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
                        glPopMatrix();

                    //Déblinder la texture
                    glBindTexture(GL_TEXTURE_2D, 0);
                    //Désactive le texturage 2D
                    glDisable(GL_TEXTURE_2D);

                    tmp = tmp.getPrev();
                }
            }
            else {
                printf("Erreur : la texture du monstre ou la liste de monstre n'existe pas\n");
                return 0;
            }

            return 1;
        }
}

