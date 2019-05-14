#ifndef COLOR_H__
#define COLOR_H__

typedef struct color {

    unsigned int r;
    unsigned int g;
    unsigned int b;
    
}Color;

Color colorRGB(unsigned int r, unsigned int g, unsigned int b);

#endif