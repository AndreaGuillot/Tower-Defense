#include "../include/installation.h"
#include "../include/tower.h"
#include "../include/monstre.h"

class Monster {

    private:
    //Position du monstre
    Position p;
    //S'il y a une erreur sur sa position
    float erreur;
    //Ses caractéristiques sur le chemin
    Sens sens;
    Node *node_prev;
    Node *node_next;
    Monster monster_prev;
    Monster monster_next;
    //Propriétés du monstre
    monsterType type;
    uint pv;
    uint speed;
    uint money;
    float resistance_TDR;
    float resistance_TDV;
    float resistance_TDJ;
    float resistance_TDB;
	
    public:
    Monster(){
        this = NULL;
    }
    //Get
    Position getPosition(){
        return this->p;
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

        bool addMonster(monsterType type, Node node) {
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
                    monster.setPosition(node.getPosition());
                    monster.setNodePrev(node);
                    monster.setNodeNext(node.getNext());

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

        /************* Deplacer les monstres *************/
        /* Deplace les monstre : Vérifie s'il se déplace à l'horizontal, vertical ou autrement puis le déplace. Prend en paramètre la liste de  *
        *  monstres et et le dernier noeud de la carte. Retourne 0 en cas d'erreur et 1 sinon et 2 s'il est arrivé à la fin. */
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
                    //Libère espace mémoire : supprime le monstre
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
}

