#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "geometry/Color3f.h"

/*#define max(a,b) (a>=b?a:b)
#define min(a,b) (a<=b?a:b)*/

/* Color RGB : Couleur à partir des valeurs r, g, b */
Color3f ColorRGB(float r, float g, float b) {

	Color3f new_color;

	new_color.r = r;
	new_color.g = g;
	new_color.b = b;

	return new_color;
}

float max(float limite, float color) {
	if(color < limite)
		return limite;
	else
		return color;

	 /*(1/2)*abs(limite+color)+(1/2)*abs(limite-color)*/
}

float min(float limite, float color) {
	if(color > limite)
		return limite;
	else
		return color;

	 /*(1/2)*abs(limite+color)-(1/2)*abs(limite-color) */
}

/* Convertie un float en unsigned char */
unsigned char convert_f32_to_uc8 (float color) {
	/*unsigned char c = 255 * max(0, min(1, color));
	return c;*/
	return 255 * max(0, min(1, color));
}

/*AddColors : La fonction d’addition de couleur */
Color3f AddColors(Color3f C1, Color3f C2){

	Color3f new_color;

	new_color.r = (C1.r) + (C2.r);
	new_color.g = (C1.g) + (C2.g);
	new_color.b = (C1.b) + (C2.b);

	return new_color;
}

/*SubColors : La fonction de soustraction de couleur */
Color3f SubColors(Color3f C1, Color3f C2){

	Color3f new_color;

	new_color.r = (C1.r) - (C2.r);
	new_color.g = (C1.g) - (C2.g);
	new_color.b = (C1.b) - (C2.b);

	return new_color;
}

/* MultColors : La fonction de la multiplication de couleur */
Color3f MultColors(Color3f C1, Color3f C2){

	Color3f new_color;

	new_color.r = (C1.r) * (C2.r);
	new_color.g = (C1.g) * (C2.g);
	new_color.b = (C1.b) * (C2.b);

	return new_color;
}

/* DivColors : La fonction de la division couleur */
Color3f DivColors(Color3f C1, Color3f C2){

	Color3f new_color;

	if((C2.r) == 0 || (C2.g) == 0 || (C2.b) == 0) {
		printf("Erreur : impossible de diviser par 0");
		return C1;
	}

	new_color.r = (C1.r) / (C2.r);
	new_color.g = (C1.g) / (C2.g);
	new_color.b = (C1.b) / (C2.b);

	return new_color;
}

/* Fonction de multiplication d'un couleur par un scalaire */
Color3f MultColor(Color3f c1, float scal) {
    float r = c1.r * scal;
    float g = c1.g * scal;
    float b = c1.b * scal;

    Color3f c = ColorRGB(r, g, b);
    return c;
}

/* Fonction de division d'une couleur par un scalaire */
Color3f DivColor(Color3f c1, float scal) {
	float r, g, b;
	if(scal != 0.0) {
		r = c1.r / scal;
	}
    else {
    	r = 0.0;
    }
    
    if(scal != 0.0) {
    	g = c1.g / scal;
    }
    else {
    	g = 0.0;
    }
    
    if(scal != 0) {
    	b = c1.b / scal;
    }
    else {
    	b = 0.0;
    }
    
    Color3f c = ColorRGB(r, g, b);
    return c;
}
