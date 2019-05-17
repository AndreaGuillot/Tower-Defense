#include <stdio.h>
#include <stdlib.h>
#include "../include/color.h"

Color colorRGB(unsigned int r, unsigned int g, unsigned int b){

	Color newColor;
	newColor.r = r;
	newColor.g = g;
	newColor.b = b;

	return newColor;

}