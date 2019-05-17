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