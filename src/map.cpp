#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/map.h"

int verificationMap(char *mapName, Map *map){ 

    //Lecture du fichier
	FILE* fileITD = fopen(mapName, "r");
	if(fileITD == NULL)
    {
		fprintf(stderr, "Erreur fichier : impossible de lire le fichier itd.\n");
		return 0;
	} else {
        
        char line[100];
        
        //Première ligne : format itd
        char *format;
        int number;
        fgets(line, 10, fileITD);
        sscanf(line, "%s" "%d", format, &number);
        if((strcmp(format, "@ITD") != 0) || isdigit(number))
        {
           fprint(stderr, "Erreur fichier : format incorrect.\n");
           return 0; 
        }

        //Deuxième ligne : commentaire
        fgets(line, 2, fileITD);
        if(strcmp(line, "#") !=0)
        {
            fprintf(stderr, 'Erreur fichier : ligne de commentaire incorrecte.\n');
            return 0;
        }

        //Troisème à huitième ligne : paramètres
        char *param;
        int pathR, pathG, pathB;
        int nodeR, nodeG, nodeB;
        int constructR, constructG, constructB;
        int inR, inG, inB;
        int outR, outG, outB;
        ////Carte
        char *filePPM;
        fgets(line, 30, fileITD);
        filePPM = strstr(line, ".ppm");
        if((strcmp(line, "carte") !=0) || (filePPM == NULL))
        {
            fprintf(stderr, "Erreur fichier : paramètre 'carte' incorrect.\n");
            return 0;
        }
        ////Chemin
        fgets(line, 20, fileITD);
        sscanf(line, "%s" "%d" "%d" "%d", param, &pathR, &pathG, &pathB);
        if(strcmp(param, "chemin") !=0)
        {
            fprintf(stderr, "Erreur fichier : paramètre 'chemin' incorrect.\n");
            return 0;
        } else {
            if(pathR < 0 || pathR > 255 || pathG < 0 || pathG > 255 || pathB < 0 || pathB > 255)
            {
                fprintf(stderr, "Erreur fichier : couleur 'chemin' incorrecte.\n");
                return 0;
            } else {
                (*map).colorPath = createColor(pathR, pathG, pathB);
            }
        }
        ////Noeud
        fgets(line, 20, fileITD);
        sscanf(line, "%s" "%d" "%d" "%d", param, &nodeR, &nodeG, &nodeB);
        if(strcmp(param, "noeud") !=0)
        {
            fprintf(stderr, "Erreur fichier : paramètre 'noeud' incorrect.\n");
            return 0;
        } else {
            if(nodeR < 0 || nodeR > 255 || nodeG < 0 || nodeG > 255 || nodeG < 0 || nodeB > 255)
            {
                fprintf(stderr, "Erreur fichier : couleur 'noeud' incorrecte.\n");
                return 0;
            } else {
                (*map).colorNode = createColor(nodeR, nodeG, nodeB);
            }
        }
        ////Construct
        fgets(line, 25, fileITD);
        sscanf(line, "%s" "%d" "%d" "%d", param, &constructR, &constructG, &constructB);
        if(strcmp(param, "construct") !=0)
        {
            fprintf(stderr, "Erreur fichier : paramètre 'construct' incorrect.\n");
            return 0;
        } else {
            if(constructR < 0 || constructR > 255 || constructG < 0 || constructG > 255 || constructG < 0 || constructB > 255)
            {
                fprintf(stderr, "Erreur fichier : couleur 'construct' incorrecte.\n");
                return 0;
            } else {
                (*map).colorConstruct = createColor(constructR, constructG, constructB);
            }
        }
        ////In
        fgets(line, 20, fileITD);
        sscanf(line, "%s" "%d" "%d" "%d", param, &inR, &inG, &inB);
        if(strcmp(param, "in") !=0)
        {
            fprintf(stderr, "Erreur fichier : paramètre 'in' incorrect.\n");
            return 0;
        } else {
            if(inR < 0 || inR > 255 || inG < 0 || inG > 255 || inG < 0 || inB > 255)
            {
                fprintf(stderr, "Erreur fichier : couleur 'in' incorrecte.\n");
                return 0;
            } else {
                (*map).colorIn = createColor(inR, inG, inB);
            }
        }
        ////Out
        fgets(line, 20, fileITD);
        sscanf(line, "%s" "%d" "%d" "%d", param, &outR, &outG, &outB);
        if(strcmp(param, "out") !=0)
        {
            fprintf(stderr, "Erreur fichier : paramètre 'out' incorrect.\n");
            return 0;
        } else {
            if(outR < 0 || outR > 255 || outG < 0 || outG > 255 || outG < 0 || outB > 255)
            {
                fprintf(stderr, "Erreur fichier : couleur 'out' incorrecte.\n");
                return 0;
            } else {
                (*map).colorOut = createColor(outR, outG, outB);
            }
        }

        //Neuvième ligne : nombre de noeuds
        int nbNode;
        int nbLine;
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
            fprintf(stderr, "Erreur fichier : nombre de noeuds incorrect.\n");
            return 0;
        } else {
            (*map).nbNode = nbNode;
        }
        //Dixième à dernière ligne : description des noeuds 
        int nodeIndice;
		int nodeType;
		int nodeX;
		int nodeY;
        int nodeLink;
        fgets(line, 20, fileITD);

    }
    
    fclose(fileITD);

}