#include "../include/tower.h"

class Tower {

    public:
    //Constructeur
    Tower(){
        this = NULL;
    }
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
    	if(instNear[stock])
    		return 1.25*this->rate;
    	else
    		return this->rate;
    }
    uint getCost(){
    	return this->cost;
    }
    int getCompteur(){
        return this->compteur;
    }
    Tower* getNext(){
        return this->next;
    }
    Tower* getPrev(){
        return this->prev;
    }

    //Set
    void set(Tower* t){
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
    void setNext(Tower* tower){
        this->next = tower;
    }
    void setPrev(Tower* tower){
        this->prev = tower;
    }
    void setInstNear(installationType a, bool val){
        this->instNear[a] = val;
    }
    int drawProprieteTower(GLuint* tower, GLuint* spriteMenu, GLuint* btPlus, Joueur* joueur) {

        if(this != NULL) {

            int type = this->type;

            float x1 = 0;
            float x2 = 1;
            float y1 = (type * (1.0/4.0));
            float y2 = (type * (1.0/4.0)) + 0.25;

            //Active le texturage 2D
            glEnable(GL_TEXTURE_2D);
            //appel de la texture
            glBindTexture(GL_TEXTURE_2D, *tower);

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
            int money = 0;

            /**** Cadence ****/

            glColor4f(255,255,255, 1);
            //Convertie un int en un string
            sprintf(machaine,"%d",this->rate);

            writeString(20, 390,  "Cadence : ");
            //Affiche la chaine de caractère
            writeString(120, 390,  machaine);

            /**** Portée ****/

            glColor4f(255,255,255, 1);
            //Convertie un int en un string
            sprintf(machaine,"%d",this->range);

            writeString(20, 415,  "Range : ");
            //Affiche la chaine de caractère
            writeString(120, 415,  machaine);

            /**** Puissance ****/

            glColor4f(255,255,255, 1);
            //Convertie un int en un string
            sprintf(machaine,"%d",this->power);

            writeString(20, 440,  "Puissance : ");
            //Affiche la chaine de caractère
            writeString(120, 440,  machaine);

            /**** type de la tour ****/
            glColor4f(255,255,255, 1);
            string typeTour = "";

            //Choisir le bon monstre dans le sprite
            if(this->type == oceane) 
                typeTour = "Océane (Archer)";
            else if(this->type == jules) 
                typeTour = "Jules (Multidirectionnelle)";
            else if(this->type == clara) 
                typeTour = "Clara (Laser)";
            else if(this->type == yoann) 
                typeTour = "Yoann (Rocket)";

            writeString(20, 465,  "Type : ");
            //Affiche la chaine de caractère
            writeString(80, 465,  typeTour);

        }else {
            fprintf(stderr, "probleme d'allocation memoire pour la chaine de caractere\n");
            return 0;
        }

        return 1;

    }

    int reach(listShot *shots, listMonster *monsters) {
        if(shots != NULL) {
            if(monsters != NULL){
                if(this != NULL) {
                    if(this->type != jules) {

                        Monster monster = NULL;

                        //Variables pour savoir qui est le plus proche
                        Position pointIntersection, pointProche, point1, point2;
                        Vector vectorIntersection, vectorProche;
                        float normeIntersection, normeProche = -1;

                        //Création d'un monstre temporaire pour parcourir la liste de monstres
                        Monster tmp = monsters.getHead();

                        //Parcours la liste de monstres
                        while(tmp != NULL){

                            Position point = new Position(this.getPosition().getX(), this.getPosition().getY()); //centre

                            point1.set(tmp.getX() + 20, tmp.getY() + 20);
                            point2.set(tmp.getX() - 20, tmp.getY() - 20);

                            //Vérifie s'il y a une intersection
                            if(intersectionCarreDisque (point1, point2, this->range, point)) {

                                pointIntersection.set(tmp.getX(), tmp.getY());
                                
                                vectorIntersection = Vector(point, pointIntersection);
                                normeIntersection = vectorIntersection.getNorm();
                    
                                //S'il n'y a pas de point d'intersection avant
                                if(normeProche == -1) {
                                    vectorProche = Vector(point, pointProche);
                                    normeProche = vectorProche.getNorm();
                                    monster = tmp;
                                }
                                //Si la distance du nouveau point d'intersection est plus proche que celle stocker
                                if(normeIntersection < normeProche) {
                                    vectorProche = vectorIntersection;
                                    normeProche = normeIntersection;
                                    monster = tmp;
                                }

                            }
                            tmp = tmp->p_next;
                        }

                        if(monster != NULL)
                            shots.addShot(monster, this);

                        return 1;

                    }
                    else {
                    
                        //Création d'un monstre temporaire pour parcourir la liste de monstres
                        Monster tmp = monsters.getHead();

                        //Parcours la liste de monstres
                        while(tmp != NULL){

                            Position point, point1, point2;
                            point.set(this.getPosition().getX(), this.getPosition().getY()); //centre
                            point1.set(this.getPosition().getX() + 20, this.getPosition().getY() + 20); //centre
                            point2.set(this.getPosition().getX() - 20, this.getPosition().getY() - 20); //centre

                            //Vérifie s'il y a une intersection
                            if(intersectionCarreDisque (point1, point2, this->range, point) == 1)
                                shots.addShot(tmp, this); //Ajout d'un shot à la liste

                            tmp = tmp.getNextM();

                        }   
                        return 1;
                    }

                }
                else {
                    fprintf(stderr, "Cette tour n'existe pas\n");
                    return 0;
                }

            }
            else {
                fprintf(stderr, "Cette liste de monstre n'existe pas\n");
                return 0;
            }
        }
        else {
            fprintf(stderr, "Cette liste de missiles n'existe pas\n");
            return 0;
        }

        return 0;

    }

    bool isSame(Tower* t){
        if(this->p.getX() != t.getPosition().getX()){
            return 0;
        }
        if(this->p.getY() != t.getPosition().getY()){
            return 0;
        }
        if(this->type != t.getType()){
            return 0;
        }
        if(this.power != t.getPower()){
            return 0;
        }
        if(this.rate != t.getRate()){
            return 0;
        }
        if(this->cost != t.getCost()){
            return 0;
        }
        if(this->compteur != t.getComteur()){
            return 0;
        }

        return 1;
    }


};

class Yoann: public Tower{

    public:

    	Yoann(float range=10.; float rate=2.0; uint cost=120; float power =70.){
    		this->range = range;
    		this->rate = rate;
    		this->cost = cost;
    		this->power = power;
            this->compteur = 0;
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
            this->compteur = 0;
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
            this->compteur = 0;
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
            this->compteur = 0;
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

    int getLength(){
        return this->length;
    }

    Tower* getHead(){
        return this->;head
    }

    Tower* getTail(){
        return this->tail;
    }

    void setLength(int a){
        this->length = a;
    }

    void setHead(Tower* t){
        this->head = t;
    }

    void setTail(Tower* t){
        this->tail = t;
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

    int moveTower(Tower* tower, listNode list_node, float x, float y) {
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
                    if(tower->getPrev() != NULL){

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

    void removeTower(Tower* tower) {
        if (this != NULL) {
            if(tower != NULL) {

                //Si c'est la dernière tour de la liste
                if (tower->getNext() == NULL) {
                    
                    //Set la fin de la liste sur la tour précédente
                    this->tail.set(tower->getPrev());

                    if(this->tail != NULL) {
                        //Lien de la dernière tour vers la tour suivante est NULL
                        this->tail.setNext(NULL);
                    }
                    else
                        this->head.set(NULL);
                        
                }
            
                //Si c'est la première de la liste
                else if (tower->getPrev() == NULL) {
                    //Set la tête de la liste sur la tour suivante
                    this->head.set(tower->getNext());

                    if(this->head != NULL) {
                        //Le lien vers de la deuxième tour vers la tour précédente est NULL
                        this->head.setPrev(NULL);
                    }
                    else
                        this->tail.set(NULL);
                }

                else {
                    //Relie la tour suivante à la tour précédente de la tour que l'on veut supprmer 
                    tower->getNext().setPrev(tower->getPrev());
                    //Relie la tour précédente à la tour suivante de la tour que l'on veut supprmer 
                    tower->getPrev().setNext(tower->getNext());

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

    void removeTower(Tower tower) {
        if (this != NULL) {
            if(tower != NULL) {
                if (tower->getNext() == NULL) {
                    this.setTail(tower->getPrev());

                    if(this.getTail() != NULL) {
                        //Lien de la dernière tour vers la tour suivante est NULL
                        this.getTail().setNext(NULL);
                    }
                    else
                        this.setHead(NULL);
                        
                }
            
                //Si c'est la première de la liste
                else if (tower->getPrev() == NULL) {
                    //Pointe la tête de la liste vers la tour suivante
                    this.setHead(tower->getNext());

                    if(this.getHead() != NULL) {
                        //Le lien vers de la deuxième tour vers la tour précédente est NULL
                        this.getHead().setPrev(NULL);
                    }
                    else
                        this.setTail(NULL);
                }

                else {
                    //Relie la tour suivante à la tour précédente de la tour que l'on veut supprmer 
                    tower->getNet().setPrev(tower->getPrev());
                    //Relie la tour précédente à la tour suivante de la tour que l'on veut supprmer 
                    tower->getPrev().setNext(tower->getNet());

                }
                //Libère espace mémoire : supprime la tour
                free(tower);
                //Décrémente de un la taille de la liste
                this->length--;

            }
            else
                fprintf(stderr, "Cette tour n'existe pas");
        }
        else 
            fprintf(stderr, "Cette liste de tours n'existe pas");
    }

    void removeAllTower() {
    //Si la liste n'est pas vide
        if (this->length != 0) {

            //Tant que la liste n'est pas vide
            while (this.getHead() != NULL) {
                this = removeTower(this, this.getHead());
            }
            
        }
    }   

    void freeAllTower() {
        //Si la liste n'est pas vide
        if (this->length != 0) {

            //Tant que la liste n'est pas vide
            while (this->head != NULL) {
                this = removeTower(this, this->head);
            }
            
        }
        free(this);
    }
}