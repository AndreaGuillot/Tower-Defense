#include <stdlib.h>
#include "../include/installation.h"
#include "../include/tower.h"
#include "../include/monstre.h"

class Tower {

    public:
    //Constructeur
    //Get
    Position getPosition(){
        return this->p;
    }

    float getPower(){
    	if(instNear[usine])
    		return 1.25*this->power;
    	else{
    		return this->power;
    	}
    }
    float getRange(){
    	if(instNear[radar])
    		return 1.25*this->range;
    	else{
    		return this->range;
    	}
    }
    float getRate(){
    	if(instNear[stock]){}
    		return 1.25*this->rate;
    	else{
    		return this->rate;
    	}
    }
    uint getCost(){
    	return this->cost;
    }
    Tower getNext(){
        return this->next;
    }
    Tower getPrev(){
        return this->prev;
    }

    //Set
    void set(Tower t){
        this = t;
    }

	void setPower(int p){
		this->power = p;
	}
	void setRange(float rg){
		this->range = rg;
	}
	void setRate(int rt){
		this->rate=rt;
	}
    void setPosition(Position p){
        this->p = p;
    }
    void setNext(Tower tower){
        this->next = tower;
    }
    void setPrev(Tower tower){
        this->prev = tower;
    }

	virtual towerType getType() = 0;

};

class Yoann: public Tower{

    public:

    	Yoann(float range=10.; float rate=2.0; uint cost=120; float power =70.){
    		this->range = range;
    		this->rate = rate;
    		this->cost = cost;
    		this->power = power;
    	}

    	towerType getType(){
    		return yoann;
    	}
}

class Clara: public Tower{

    public:

    	Clara(float range=20.; float rate=1.0; uint cost=80; float power =60.){
    		this->range = range;
    		this->rate = rate;
    		this->cost = cost;
    		this->power = power;
    	}

    	towerType getType(){
    		return clara;
    	}
}

class Jules: public Tower{

    public:

    	Jules(float range=15.; float rate=1.5; uint cost=60; float power =30.){
    		this->range = range;
    		this->rate = rate;
    		this->cost = cost;
    		this->power = power;
    	}

    	towerType getType(){
    		return jules;
    	}

}

class Oceane: public Tower{

    public:

    	Oceane(float range=50.; float rate=0.5; uint cost=50; float power =10.){
    		this->range = range;
    		this->rate = rate;
    		this->cost = cost;
    		this->power = power;
    	}

    	towerType getType(){
    		return oceane;
    	}
}

class listTower{

    listTower(){
        this->length = 0;
        this->head.set(NULL);
        this->tail.set(NULL);
    }

    int addTower(towerType type, Position p) {

        if(this !=NULL){
            switch(type){
                case yoann:
                    Yoann tower;
                    break;
                case clara:
                    Clara tower;
                    break;
                case jules:
                    Jules tower;
                    break;
                case oceane:
                    Oceane tower;                    
                    break;
                default: break;
            }

            tower.setPosition(p);
            tower.setNext(NULL);

            if(this->tail == NULL){
                this->head = tower;
                tower.setPrev(NULL);
            }else{
                tower.setPrev(this->tail);
                this->tail.setNext(tower);
            }

            this->tail = tower;
            this->length++;
        }else{
            fprintf(stderr, "Problème dans la creation de la nouvelle tour\n");
            return 0;
        }
        return 1;
    }

    int moveTower(Tower tower, listNode list_node, float x, float y) {
        if(this != NULL) {
            if(tower != NULL) {
                Position pos = new Position(x, y);
                tower.setPosition(pos);
            
                Point p1, p2;

                p1.setPosition(new Position(x+15, y+20));
                p2.setPosition(new Position(x-15, y-20));

                if(verificationConstruct(list_node, p1, p2) == 1) {

                    p1.setPosition(new Position(x+20, y+20));
                    p2.setPosition(new Position(x-20, y-20));

                    //Si ce n'est pas le premier de la liste
                    if(tower.getPrev() != NULL){

                        Point p3, p4;
                        //Créer une tour temporaire pour parcourir la liste
                        Tower tmp = this.head;

                        //Parcour de la liste
                        while(tmp.getNext() != NULL) {

                            p3.setPosition(new Position(tmp.getPosition().getX()+20, tmp.getPosition().getY()+20));
                            p4.setPosition(new Position(tmp.getPosition().getX()-20, tmp.getPosition().getY()-20));

                            //Vérifie qu'il ne se trouve pas sur une autre tour (pas d'intersection)
                            if(intersectionCarres (p1, p2, p3, p4) == 0)
                                tmp = tmp.getNext();
                            else
                                return 0;
                        }
                        return 1;
                    }
                    //Sinon pas besoin de faire la vérification pour les collisions de quads
                    else
                        return 1;       
                }
            }
            else {
                fprintf(stderr, "Cette tour n'existe pas\n");
                return 0;
            }
        }
        else {
            fprintf(stderr, "Erreur : il y a un problème avec la liste de tours\n");
            return 0;
        }

        return 0;

    }

    void removeTower(Tower tower) {
        if (this != NULL) {
            if(tower != NULL) {

                //Si c'est la dernière tour de la liste
                if (tower.getNext() == NULL) {
                    
                    //Set la fin de la liste sur la tour précédente
                    this->tail.set(tower.getPrev());

                    if(this->tail != NULL) {
                        //Lien de la dernière tour vers la tour suivante est NULL
                        this->tail.setNext(NULL);
                    }
                    else
                        this->head.set(NULL);
                        
                }
            
                //Si c'est la première de la liste
                else if (tower.getPrev() == NULL) {
                    //Set la tête de la liste sur la tour suivante
                    this->head.set(tower.getNext());

                    if(this->head != NULL) {
                        //Le lien vers de la deuxième tour vers la tour précédente est NULL
                        this->head.setPrev(NULL);
                    }
                    else
                        this->tail.set(NULL);
                }

                else {
                    //Relie la tour suivante à la tour précédente de la tour que l'on veut supprmer 
                    tower.getNext().setPrev(tower.getPrev());
                    //Relie la tour précédente à la tour suivante de la tour que l'on veut supprmer 
                    tower.getPrev().setNext(tower.getNext());

                }
                //Libère espace mémoire : supprime la tour
                free(tower);
                //Décrémente de 1 la taille de la liste
                this->length--;

            }
            else
                fprintf(stderr, "Cette tour n'existe pas");
        }
        else 
            fprintf(stderr, "Cette liste de tours n'existe pas");
    }
}