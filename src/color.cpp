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

std::vector<std::string> split(std::string str){
	std::vector<std::string> myArray;
	std::stringstream ss(str);
	std::string couleur;

	while(std::getline(ss, couleur, ' ')){
		myArray.push_back(couleur);
	}

	return myArray;
}

Color stringToColor(std::string str){
	std::vector<std::string> couleurs = split(str);
	uint r = std::stoi(couleurs[0]);
	uint g = std::stoi(couleurs[1]);
	uint b = std::stoi(couleurs[2]);

	Color couleur = Color(r, g, b);
	return couleur;
}