#include <stdio.h>
#include <stdlib.h>
#include "../include/colors.h"

Color createColor(float r, float g, float b){

	Color color;

	color.red = r;
	color.green = g;
	color.blue = b;

	return color;

}