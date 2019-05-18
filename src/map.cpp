#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/map.h"

int verifMap(FILE* fileITD, Map *map)
{ 
    char line[100];
    
    /* Première ligne : format itd */
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

    /* Deuxième ligne : commentaire */
    fgets(line, 2, fileITD);
    if(strcmp(line, "#") !=0)
    {
        fprintf(stderr, "Erreur fichier.itd : [commentaire].\n");
        return 0;
    }

    /* Troisème à huitième ligne : paramètres */
    char param[10];
    int R = 0;
    int G = 0;
    int B = 0;
    // Carte
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
        (*map).image = fileName;
    }
    // Chemin
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
        (*map).pathColor = colorRGB(R, G, B);
    }
    // Noeud
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
        (*map).nodeColor = colorRGB(R, G, B);
    }
    // Construct
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
        (*map).constructColor = colorRGB(R, G, B);
    }
    // In
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
        (*map).inColor = colorRGB(R, G, B);
    }
    // Out
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
        (*map).outColor = colorRGB(R, G, B);
    }

    /* Neuvième ligne : nombre de noeuds */
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
        (*map).nbNode = nbNode;
    }

    /* Dixième à dernière ligne : description des noeuds */
    // Re-positionnement du curseur de lecture
    long posFile = ftell(fileITD); 
    fseek(fileITD, posFile, SEEK_SET);
    // Supression du caractère '\n' à la fin du nom de fichier
    while(int i=0 < strlen(fileName))
    {
        if(fileName[i] == '\n')
        {
            fileName[i] = '\0';
        }
        i++;
    }
    // Chargement de l'image
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
    // Création de la liste des noeuds
    fseek(fileITD, posFile, SEEK_SET);
    fscanf(fileITD, "%*d %*d %d %d\n", &X, &Y);
    Node* fileNode = createNode(X, Y);
    Node* tmp = fileNode;
    for(int i = 1; i < nbLine; i++)
    {
        fscanf(fileITD, "%*d %*d %d %d\n", &X, &Y);
        Node* node = createNode(X, Y);
        (*fileNode).next = node;
        fileNode = (*fileNode).next;
    }
    (*fileNode).next = NULL;
    (*map).listNode = tmp;
    // Destruction des données de l'image chargée
    SDL_FreeSurface(image);

    return 1;
}


Map loadMap(char* fileNameITD)
{
    FILE* fileITD = fopen(fileNameITD, "r");
    if(fileITD == NULL)
    {
        fprintf(stderr, "Erreur ouverture du fichier : %s.\n", fileNameITD);
        exit(1);
    } else {
        Map map;
        if(verifMap(fileITD, &map))
        {
            printf("Map créée.\n");
            return map;
        } else {
            fprintf(stderr, "Fichier incorrect : %s.\n", fileNameITD);
            exit(1);
        }
    }
}


class Map{

    /*********************** Dessiner du chemin et des noeuds ***********************/
    /* Dessine du chemin et des noeuds. Prend en paramètre la liste de noeud et la map. *
    *  Retourne 0 en cas d'erreur et 1 sinon.                       */

    bool drawRoad() {

        if(this != NULL) {

            Node tmp = this->listNode.getHead();

            while(tmp.getNext() != NULL) {
            
                glBegin(GL_LINES);
                    glColor3ub(29,168,194);
                    glVertex2d(tmp.getX(), tmp.getY());
                    glVertex2d(tmp.getNext().getX(), tmp.getNext().getY());
                glEnd();

                glPushMatrix();
                    glColor3ub((this.getNodeColor()).getR(),(this.getNodeColor()).getG(),(this.getNodeColor()).getB());
                    glTranslatef(tmp.getX(),tmp.getY(), 0.0);
                    drawDisque(5);
                glPopMatrix();

                glColor3ub(255,255,255);

                tmp = tmp.getNext();                  

            }
        }
        else {
            fprintf(stderr, "Erreur la carte n'existe pas\n");
            return 0;
        }

        return 1;
    }


    char getImage(){
        return this->image;
    }
    Image* getImg(){
        return this->img;
    }
    //Noeuds
    int getNbNode(){
        return this->nbNode;
    }
    listNode getListNode(){
        return this->listNode;
    }
    //Couleurs de la carte
    Color getInColor(){
        return this->inColor;
    }
    Color getOutColor(){
        return this->outColor;
    }
    Color getPathColor(){
        return this->pathColor;
    }
    Color getNodeColor(){
        return this->nodeColor;
    }
    Color getConstructColor(){
        return this->constructColor;
    }
    listNode getListConstruct(){
        return this->listConstruct;
    }

    void setNbMonstres(int a){
        this->nbMonstres = a;
    }

    int apparitionMonster(listMonster monsters, int j, Joueur joueur) {

        if(monsters != NULL) {

                //ajoute un monstre à chaque fois que j est un muliple de 50
                if(j%(*130) == 0){

                    //S'il y a moins ou 10 monstres
                    if(this->nbMonstres < 10) {

                        //Random entre 0, 1 et 2 pour avoir les monstres de type lucie, barbara et julien
                        typeMonster type = rand()%3;
                        monsters.addMonster(type, this->listNode.getHead());
                        
                        this->nbMonstres++;
                    }
                    //S'il n'y a plus de monstre
                    else if(this->nbMonstres == 10 && monsters.getLength() == 0) {
                        joueur.setNbVagues(joueur.getNbVagues()+1); //Monte de niveau
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


}