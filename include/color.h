#ifndef COLOR_H__
#define COLOR_H__

#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

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

Color stringToColor(std::string);
std::vector<std::string> split(std::string str);

#endif