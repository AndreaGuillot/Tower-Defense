#include <stdio.h>
#include <stdlib.h>
#include "../include/color.h"

/*Color colorRGB(unsigned int r, unsigned int g, unsigned int b){

	Color newColor;
	newColor.r = r;
	newColor.g = g;
	newColor.b = b;

	return newColor;

}*/

class Color{

	Color(uint r, uint g, uint, b){
		this->r = r;
		this->g = g;
		this->b = b;
	}

	uint getR(){
		return this->r;
	}
    uint getG(){
    	return this->g;
    }
    uint getB(){
    	return this->b;
    }
}