#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>

#include "../include/map.h"
#include "../include/draw.h"

Map::Map(){
    this->image = "none";
    this->img = NULL;
    this->nbNode = 0;
    this->list_node = NULL;
    this->inColor = Color();
    this->outColor = Color();
    this->pathColor = Color();
    this->nodeColor = Color();
    this->constructColor = Color();
    this->listConstruct = NULL;
    this->list_pixels = NULL;
    this->nbMonstres = 0;
}
//Get
std::string Map::getImage(){
    return this->image;
}
Image* Map::getImg(){
    return this->img;
}
//Noeuds
int Map::getNbNode(){
    return this->nbNode;
}
listNode* Map::getListNode(){
    return this->list_node;
}
//Couleurs de la carte
Color Map::getInColor(){
    return this->inColor;
}
Color Map::getOutColor(){
    return this->outColor;
}
Color Map::getPathColor(){
    return this->pathColor;
}
Color Map::getNodeColor(){
    return this->nodeColor;
}
Color Map::getConstructColor(){
    return this->constructColor;
}
listNode* Map::getListConstruct(){
    return this->listConstruct;
}

int Map::getNbMonstres(){
    return this->nbMonstres;
}

listNode* Map::getList_pixels(){
    return this->list_pixels;
}

//Set
void Map::setImage(std::string a){
    this->image = a;
}
void Map::setImg(Image* img){
    this->img = img;
}
void Map::setNbMonstres(int a){
    this->nbMonstres = a;
}
void Map::setInColor(Color color){
    this->inColor = color;
}
void Map::setOutColor(Color color){
    this->outColor = color;
}
void Map::setPathColor(Color color){
    this->pathColor = color;
}
void Map::setNodeColor(Color color){
    this->nodeColor = color;
}
void Map::setConstructColor(Color color){
    this->constructColor = color;
}

//Fonctions
/* Dessine les chemins */
bool Map::drawRoad() {

    Node *tmp = this->list_node->getHead();

    while(tmp->getNext() != NULL) {
    
        glBegin(GL_LINES);
            glColor3ub(29,168,194);
            glVertex2d(tmp->getX(), tmp->getY());
            glVertex2d(tmp->getNext()->getX(), tmp->getNext()->getY());
        glEnd();

        glPushMatrix();
            glColor3ub((this->getNodeColor()).getR(),(this->getNodeColor()).getG(),(this->getNodeColor()).getB());
            glTranslatef(tmp->getX(),tmp->getY(), 0.0);
            drawDisque(5);
        glPopMatrix();

        glColor3ub(255,255,255);

        tmp = tmp->getNext();                  

    }

    return 1;
}
/* Vérification de la map */
int Map::verifMap(FILE* fileITD)
{ 
    char line[100];
    
    /** Première ligne : format itd **/
    int version;
    fgets(line, 5, fileITD);
    if(strcmp(line, "@ITD") != 0)
    {
       fprintf(stderr, "Erreur fichier.itd : [@ITD].\n");
       return 0; 
    }
    fscanf(fileITD, "%d\n", &version);
    if(version < 1)
    {
        fprintf(stderr, "Erreur fichier.itd : @ITD [version].\n");
        return 0; 
    }

    /** Deuxième ligne : commentaire **/
    fgets(line, 2, fileITD);
    if(strcmp(line, "#") !=0)
    {
        fprintf(stderr, "Erreur fichier.itd : [commentaire].\n");
        return 0;
    }

    /** Troisème à huitième ligne : paramètres **/
    char param[10];
    int R = 0;
    int G = 0;
    int B = 0;
    //Carte
    char* fileName = (char*)malloc(sizeof(char)*30);
    if(fileName == NULL)
    {
        fprintf(stderr, "Erreur mémoire : fichier.itd\n");
    }

    fgets(fileName, 30, fileITD);
    char* extension = strchr(fileName, '.');
    if(strcmp(extension, ".ppm\n") != 0)
    {
        fprintf(stderr, "Erreur fichier.itd : [nom fichier]\n");
        return 0;
    }
    else {
        this->image = fileName;
        //load l'image

    }
    //Chemin
    fgets(line, 20, fileITD);
    sscanf(line, "%s" "%d" "%d" "%d", param, &R, &G, &B);
    if(strcmp(param, "chemin") !=0)
    {
        fprintf(stderr, "Erreur fichier.itd : paramètre [chemin].\n");
        return 0;
    }

    if(R < 0 || R > 255 || G < 0 || G> 255 || B < 0 || B> 255)
    {
        fprintf(stderr, "Erreur fichier.itd : couleur [chemin].\n");
        return 0;
    } else {
        this->pathColor = Color(R, G, B);
    }
    //Noeud
    fgets(line, 20, fileITD);
    sscanf(line, "%s" "%d" "%d" "%d", param, &R, &G, &B);
    if(strcmp(param, "noeud") !=0)
    {
        fprintf(stderr, "Erreur fichier.itd : paramètre [noeud].\n");
        return 0;
    } 

    if(R < 0 || R > 255 || G < 0 || G> 255 || B < 0 || B> 255)
    {
        fprintf(stderr, "Erreur fichier.itd : couleur [noeud].\n");
        return 0;
    } else {
        this->nodeColor = Color(R, G, B);
    }
    //Construct
    fgets(line, 25, fileITD);
    sscanf(line, "%s" "%d" "%d" "%d", param, &R, &G, &B);
    if(strcmp(param, "construct") !=0)
    {
        fprintf(stderr, "Erreur fichier.itd : paramètre [construct].\n");
        return 0;
    }

    if(R < 0 || R > 255 || G < 0 || G> 255 || B < 0 || B> 255)
    {
        fprintf(stderr, "Erreur fichier.itd : couleur [construct].\n");
        return 0;
    } else {
        this->constructColor = Color(R, G, B);
    }
    //In
    fgets(line, 20, fileITD);
    sscanf(line, "%s" "%d" "%d" "%d", param, &R, &G, &B);
    if(strcmp(param, "in") !=0)
    {
        fprintf(stderr, "Erreur fichier.itd : paramètre [in].\n");
        return 0;
    }

    if(R < 0 || R > 255 || G < 0 || G> 255 || B < 0 || B> 255)
    {
        fprintf(stderr, "Erreur fichier.itd : couleur [in].\n");
        return 0;
    } else {
        this->inColor = Color(R, G, B);
    }
    //Out
    fgets(line, 20, fileITD);
    sscanf(line, "%s" "%d" "%d" "%d", param, &R, &G, &B);
    if(strcmp(param, "out") !=0)
    {
        fprintf(stderr, "Erreur fichier.itd : paramètre [out].\n");
        return 0;
    }

    if(R < 0 || R > 255 || G < 0 || G> 255 || B < 0 || B> 255)
    {
        fprintf(stderr, "Erreur fichier.itd : couleur [out].\n");
        return 0;
    } else {
        this->outColor = Color(R, G, B);
    }

    /** Neuvième ligne : nombre de noeuds **/
    int nbLine = 0;
    int nbNode = 0;
    int cpt;
    fgets(line, 5, fileITD);
    sscanf(line, "%d", &nbNode);
    while((cpt = fgetc(fileITD)) != EOF)
    {
        if(cpt == '\n')
        {
            nbLine++;
        }
    }
    if((nbLine-9) != nbNode)
    {
        fprintf(stderr, "Erreur fichier.itd : nombre de noeuds incorrect.\n");
        return 0;
    } else {
        this->nbNode = nbNode;
    }

    /** Dixième à dernière ligne : description des noeuds **/
    //Re-positionnement du curseur de lecture
    long posFile = ftell(fileITD); 
    fseek(fileITD, posFile, SEEK_SET);
    //Supression du caractère '\n' à la fin du nom de fichier
    while(int i=0 < strlen(fileName))
    {
        if(fileName[i] == '\n')
        {
            fileName[i] = '\0';
        }
        i++;
    }
    //Chargement de l'image
    int X;
    int Y;
    char file[100] = "images/";
    strcat(file, fileName);
    SDL_Surface* image = IMG_Load(file);
    if(image == NULL)
    {
        fprintf(stderr, "Erreur fichier.itd : impossible d'ouvrir la carte.%s\n", file);
        return 0;
    }
    while(int i = 0 < nbLine)
    {
        fscanf(fileITD, "%*d %*d %d %d\n", &X, &Y);
        if(X > image->w || Y > image->h || X < 0 || Y < 0)
        {
            fprintf(stderr, "Erreur fichier.itd : noeuds [coordonnées]\n");
            return 0;
        }
        i++;
    }
    //Création de la liste des noeuds
    fseek(fileITD, posFile, SEEK_SET);
    fscanf(fileITD, "%*d %*d %d %d\n", &X, &Y);
    Node* fileNode;
    fileNode->createNode(X, Y);
    Node* tmp = fileNode;
    for(int i = 1; i < nbLine; i++)
    {
        fscanf(fileITD, "%*d %*d %d %d\n", &X, &Y);
        Node* node;
        node->createNode(X, Y);
        fileNode->setNext(node);
        fileNode = fileNode->getNext();
    }
    (*fileNode).setNext(NULL);
    this->list_node->setHead(tmp);
    this->list_node->setTail(NULL);
    //Destruction des données de l'image chargée
    SDL_FreeSurface(image);

    return 1;
}
/* Charge la map 
bool Map::loadMap(char* fileNameITD)
{
    FILE* fileITD = fopen(fileNameITD, "r");
    if(fileITD == NULL)
    {
        fprintf(stderr, "Erreur ouverture du fichier : %s.\n", fileNameITD);
        return 0;
    } else {
        if(this->verifMap(fileITD))
        {
            printf("Map créée.\n");
            return 1;
        } else {
            fprintf(stderr, "Fichier incorrect : %s.\n", fileNameITD);
            return 0;
        }
    }
}*/

bool Map::loadMap (std::string path) {

    std::ifstream file(path);
    if (file.is_open()) {

        std::string line, imagePath, pathColor, nodeColor, constructColor, startColor, endColor;
        while (std::getline(file, line)) {
            if (line.find("#") != std::string::npos) { continue; } // Skip comments
            else if (line.find("carte") != std::string::npos) { imagePath = line.substr(6, line.size()); }
            else if (line.find("energie") != std::string::npos) { continue; } //On fait pas l'energie
            else if (line.find("chemin") != std::string::npos) { pathColor = line.substr(8, line.size()); }
            else if (line.find("noeud") != std::string::npos) { nodeColor = line.substr(6, line.size()); }
            else if (line.find("construct") != std::string::npos) { constructColor = line.substr(10, line.size()); }
            else if (line.find("in") != std::string::npos) { startColor = line.substr(3, line.size()); }
            else if (line.find("out") != std::string::npos) { endColor = line.substr(3, line.size()); }
        }
        file.close();
        this->image = imagePath;
        this->pathColor = stringToColor(pathColor);
        this->nodeColor = stringToColor(nodeColor);
        this->constructColor = stringToColor(constructColor);
        this->inColor = stringToColor(startColor);
        this->outColor = stringToColor(endColor);
        return 1;
    }
    else {
        fprintf(stderr, "[ITD] Unable to open file\n");
        return 0;
    }
}

/* Affiche monstre */
bool Map::apparitionMonster(listMonster* monsters, int j, Joueur* joueur) {

    if(monsters != NULL) {

            //Ajoute un monstre à chaque fois que j est un muliple de 50
            if(j%130 == 0){

                //S'il y a moins ou 10 monstres
                if(this->nbMonstres < 10) {

                    //Random entre 0, 1 et 2 pour avoir les monstres de type lucie, barbara et julien
                    monsterType type = monsterType(rand()%3);
                    monsters->addMonster(type, this->list_node->getHead());
                    
                    this->nbMonstres++;
                }
                //S'il n'y a plus de monstre
                else if(this->nbMonstres == 10 && monsters->getLength() == 0) {
                    joueur->setNbVagues(joueur->getNbVagues()+1); //Monte de niveau
                    this->nbMonstres++;
                }else
                    this->nbMonstres = 0;
            }
    }
    else {
        fprintf(stderr, "Erreur avec la liste de monstre\n");
        return 0;
    }

    return 1;
}

void Map::freeMap () {
    //Si la map existe
    if (this != NULL) {
        this->img->freeImage ();
        this->list_pixels->freeAllNode ();
        this->list_node->freeAllNode ();
        this->listConstruct->freeAllNode ();
        free(this);
    }
}

int Map::verificationMap(char* nameITD){ 

    FILE* itd = NULL;
    itd = fopen(nameITD, "r");  

    if(itd == NULL){
        fprintf(stderr, "Erreur : Impossible d'ouvrir le fichier\n");
        return 0;
    }
    else{
        int testCommentaire;
        char* test = (char*)malloc(20*sizeof(char));
        
        //Récupérer le code du fichier itd
        if(fscanf(itd, "%s %d\n", test,  &testCommentaire) == 2) {

            if(strcmp("@ITD", test) == 0 && 1 == testCommentaire){

                //Récupère "carte"
                if(fscanf(itd, "%s", test) == 1) {
            
                    //Vérifie qu'il s'agit bien de carte
                    if(strcmp("carte", test) == 0) {

                        //Alloue de la mémoire pour une image
                        Image* new_img;
                        char* path;
                
                        //Récupère le chemin vers l'image ppm
                        if(fscanf(itd, "%s\n", path) == 1){
                            new_img->setPath(path);
                            new_img->openImg(new_img->getPath());
                            this->setImg(new_img);         

                            //Récupère "énergie"
                            if(fscanf(itd, "%s", test) == 1) {


                                        //Récupère "chemin"
                                        if(fscanf(itd, "%s", test) == 1) {

                                            //Vérifie qu'il s'agit bien du chemin
                                            if(strcmp("chemin", test) == 0) {
                                
                                                int r, v, b;
                                
                                                //Récupère la couleur du chemin
                                                if(fscanf(itd, "%d %d %d\n", &r, &v, &b) == 3){

                                                    (this->pathColor).setR(r/255.0);
                                                    (this->pathColor).setG(v/255.0);
                                                    (this->pathColor).setB(b/255.0);
                                    
                                                    //Récupère "noeud"
                                                    if(fscanf(itd, "%s", test) == 1) {

                                                        //Vérifie qu'il s'agit bien du chemin
                                                        if(strcmp("noeud", test) == 0) {
                                
                                                            //Récupère la couleur du chemin
                                                            if(fscanf(itd, "%d %d %d\n", &r, &v, &b) == 3){

                                                                (this->nodeColor).setR(r/255.0);
                                                                (this->nodeColor).setG(v/255.0);
                                                                (this->nodeColor).setB(b/255.0);
                                    
                                                                //Récupère "construct"
                                                                if(fscanf(itd, "%s", test) == 1) {

                                                                    //Vérifie qu'il s'agit bien du chemin
                                                                    if(strcmp("construct", test) == 0) {
                                
                                                                        //Récupère la couleur du chemin
                                                                        if(fscanf(itd, "%d %d %d\n", &r, &v, &b) == 3){

//Créer la liste de pixel
listNode* list_pixels;
this->list_pixels = list_pixels;
                                                                            (this->constructColor).setR(r/255.0);
                                                                            (this->constructColor).setG(v/255.0);
                                                                            (this->constructColor).setB(b/255.0);
                                    
                                                                            //Récupère "in"
                                                                            if(fscanf(itd, "%s", test) == 1) {

                                                                                //Vérifie qu'il s'agit bien du chemin
                                                                                if(strcmp("in", test) == 0) {
                                
                                                                                    //Récupère la couleur du chemin
                                                                                    if(fscanf(itd, "%d %d %d\n", &r, &v, &b) == 3){

                                                                                        (this->inColor).setR(r/255.0);
                                                                                        (this->inColor).setG(v/255.0);
                                                                                        (this->inColor).setB(b/255.0);
                                    
                                                                                        //Récupère "out"
                                                                                        if(fscanf(itd, "%s", test) == 1) {

                                                                                            //Vérifie qu'il s'agit bien du chemin
                                                                                            if(strcmp("out", test) == 0) {
                                
                                                                                                //Récupère la couleur du chemin
                                                                                                if(fscanf(itd, "%d %d %d\n", &r, &v, &b) == 3){
                                                                                                    (this->outColor).setR(r/255.0);
                                                                                                    (this->outColor).setG(v/255.0);
                                                                                                    (this->outColor).setB(b/255.0);

                                //Récupére le nombre de noeuds                                  
                                if(fscanf(itd, "%d\n", &(this->nbNode)) == 1){
                                    int i, x, y;

                                    //Création d'une nouvelle liste de noeuds
                                    this->list_node;
                                    if(this->list_node != NULL){

                                        //Pour chaque noeud (on fait la boucle, le nombre de fois qu'il y a de nombre de noeuds)
                                        for(i=0; i < (this->nbNode); i++){

                                            //Récupére les coordonnées
                                            if(fscanf(itd, "%d %d\n", &x, &y) == 2){

                                                //Vérifie que le noeud se trouve dans l'image
                                                if(x <= this->img->getWidth() && x >= 0 && y <= this->img->getHeight() && y >= 0){
                                                    float x1 = x + 200.0;
                                                    float y1 = y + 60.0;
                                                    //Vérifie que le noeud à bien été ajouté à la liste de noeud
                                                    if(this->list_node->addNode(x1, y1) != 1) {
                                                        fprintf(stderr, "Erreur, ce n'est pas les coordonées d'un noeud");
                                                        return 0;
                                                    }
                                                }
                                                else{
                                                    fprintf(stderr, "Erreur, le noeud ne se trouve pas sur la carte");
                                                    return 0;
                                                }
                                            }
                                            else {
                                                fprintf(stderr, "Erreur, ce n'est pas les coordonées d'un noeud");
                                                return 0;
                                            }
                                        }
                                        if(fscanf(itd, "%d %d\n", &x, &y) == 2){
                                            fprintf(stderr, "Erreur, il y a trop de noeuds");
                                            return 0;
                                        }
                                    }
                                }
                                else {
                                    fprintf(stderr, "Erreur, ce n'est pas un nombre de noeud");
                                    return 0;
                                }                                                   

                                                                                                }
                                                                                                else {
                                                                                                    fprintf(stderr, "Erreur, Ce ne sont pas les valeurs de couleurs\n");
                                                                                                    return 0;
                                                                                                }
                                                                                            }
                                                                                            else {
                                                                                                fprintf(stderr, "Erreur, la huitième ligne ne correspond pas à la sortie\n");
                                                                                                return 0;
                                                                                            }
                                                                                                                        }
                                                                                            else {
                                                                                                fprintf(stderr, "Erreur, la huitième ligne ne correspond pas à la sortie\n");
                                                                                                return 0;
                                                                                            }

                                                                                    }
                                                                                    else {
                                                                                        fprintf(stderr, "Erreur, Ce ne sont pas les valeurs de couleurs\n");
                                                                                        return 0;
                                                                                    }
                                                                                }
                                                                                else {
                                                                                    fprintf(stderr, "Erreur, la septième ligne ne correspond pas à l'entrée\n");
                                                                                    return 0;
                                                                                }
                                                                            }
                                                                                                                                                        else {
                                                                                fprintf(stderr, "Erreur, la septième ligne ne correspond pas à l'entrée\n");
                                                                                return 0;
                                                                            }

                                                                        }
                                                                        else {
                                                                            fprintf(stderr, "Erreur, Ce ne sont pas les valeurs de couleurs\n");
                                                                            return 0;
                                                                        }
                                                                    }
                                                                    else {
                                                                        fprintf(stderr, "Erreur, la sixième ligne ne correspond pas à la zone constructible\n");
                                                                        return 0;
                                                                    }
                                                                }
                                                                else {
                                                                    fprintf(stderr, "Erreur, la sixième ligne ne correspond pas à la zone constructible\n");
                                                                    return 0;
                                                                }

                                                            }
                                                            else {
                                                                fprintf(stderr, "Erreur, Ce ne sont pas les valeurs de couleurs\n");
                                                                return 0;
                                                            }
                                                        }
                                                        else {
                                                            fprintf(stderr, "Erreur, la cinquième ligne ne correspond pas au noeud\n");
                                                            return 0;
                                                        }
                                                    }
                                                    else {
                                                        fprintf(stderr, "Erreur, la cinquième ligne ne correspond pas au noeud\n");
                                                        return 0;
                                                    }

                                                }
                                                else {
                                                    fprintf(stderr, "Erreur, Ce ne sont pas les valeurs de couleurs\n");
                                                    return 0;
                                                }
                                            }
                                            else {
                                                fprintf(stderr, "Erreur, la quatrième ligne ne correspond pas au chemin\n");
                                                return 0;
                                            }
                                        }
                                        else {
                                            fprintf(stderr, "Erreur, la quatrième ligne ne correspond pas au chemin\n");
                                            return 0;
                                        }
                                }
                            else {
                                fprintf(stderr, "Erreur, la troisième ligne ne correspond pas à l'énergie\n");
                                return 0;
                            }
                        }
                        else {
                            fprintf(stderr, "Erreur, ce n'est pas le chemin vers la carte\n");
                            return 0;
                        }
                    }
                    else {
                        fprintf(stderr, "Erreur, la deuxième ligne ne correspond pas au chemin vers la carte\n");
                        return 0;
                    }
                }
                else {
                    fprintf(stderr, "Erreur, la deuxième ligne ne correspond pas au chemin vers la carte\n");
                    return 0;
                }
            }
            else {
                fprintf(stderr, "Ce n'est pas un fichier ITD\n");
                return 0;
            }
        }
        else {
            fprintf(stderr, "Ce n'est pas un fichier ITD\n");
            return 0;
        }
                
        // On ferme le vide le buffer et on ferme le fichier itd
        fflush(itd);
        fclose(itd);
    }
    return 1;
}