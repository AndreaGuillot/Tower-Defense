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
    //Accesseurs
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

    //Constructeurs

    void setPosition(Position p){
        this->p = p;
    }

    void setX(float x){
        this->p.positionSetX(x);
    }

    void setY(float y){
        this->p.positionSetY(y);
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
            if(this->node_prev->x == this->node_next->x) {

                this->erreur = 0; //erreur

                if(this->node_prev->y <= this->node_next->y)
                    this->sens = bas;
                else
                    this->sens = haut;
            }
            //Si on bute sur l'axe des y
            else if(this->node_prev->y == this->node_next->y) {

                this->erreur = 0;//erreur

                if(this->node_prev->x <= this->node_next->x)
                    this->sens = droite;
                else
                    this->sens = gauche;
            }
            else {

                float dx = (this->node_next->x) - (this->node_prev->x);
                float dy = (this->node_next->y) - (this->node_prev->y);   

                if(dx > 0) {
                    if(dy > 0) {

                        if(dx >= dy)
                            this->erreur = (this->node_next->x) - (this->node_prev->x);
                        else
                            this->erreur = (this->node_next->y) - (this->node_prev->y);
                    }
                    else {

                        if(dx >= -dy)
                            this->erreur = (this->node_next->x) - (this->node_prev->x);
                        else
                            this->erreur = (this->node_next->y) - (this->node_prev->y);

                    }

                    this->sens = droite;

                }
                else {
                    if(dy > 0) {

                        if(-dx >= dy)
                            this->erreur = (this->node_next->x) - (this->node_prev->x);
                        else
                            this->erreur = (this->node_next->y) - (this->node_prev->y);

                    }
                    else {

                        if(dx <= dy)
                            this->erreur = (this->node_next->x) - (this->node_prev->x);
                        else
                            this->erreur = (this->node_next->y) - (this->node_prev->y);

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

    private:
        int length;

        Monster head;
        Monster tail;

    public:
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
                    monster->monster_next = NULL;

                    //Si la liste était vide de base, alors elle est composée de seulement ce monstre
                    if(this->tail == NULL){
                        this->head = monster;
                        monster.setPrevMonster(NULL);
                    }else{
                    //On pointe le précédent monstre sur la queue de la liste et on ajoute a la queue le monstre
                        monster.setPrevMonster(this->tail);
                        this->tail.setNextMonster(monster);
                    }

                    this->tail = monster;

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
}

