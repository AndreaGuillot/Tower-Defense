#include <stdio.h>
#include <stdlib.h>
#include "../include/color.h"

/*********************** Gérer couleurs du jeu  ***********************/

Color::Color(uint r, uint g, uint b){
	this->r = r;
	this->g = g;
	this->b = b;
}

//Get
uint Color::getR(){
	return this->r;
}
uint Color::getG(){
	return this->g;
}
uint Color::getB(){
	return this->b;
}

//Set
void Color::setR(uint color){
	this->r = color;
}
void Color::setG(uint color){
	this->g = color;
}
void Color::setB(uint color){
	this->b = color;
}