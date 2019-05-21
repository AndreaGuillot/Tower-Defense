#ifndef COLOR_H__
#define COLOR_H__

#include "draw.h"
#include "joueur.h"
#include "map.h"
#include "monstre.h"
#include "shot.h"
#include "struct.h"
#include "tower.h"
#include <string.h>

/************* Classe Color : gère les couleurs *************/

class Color {

    private:
        //Rouge, vert, bleu
        unsigned int r;
        unsigned int g;
        unsigned int b;
    
    public:
        //Constructeur  
        Color(uint r, uint g, uint b);
        //Get
        uint getR();
        uint getG();
        uint getB();
        //Set
        void setR(uint color);
        void setG(uint color);
        void setB(uint color);
};

#endif