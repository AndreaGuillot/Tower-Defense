#ifndef LDR_COLOR_3F___
#define LDR_COLOR_3F___

/* Couleur RGB */

typedef struct struct_color {
	float r;
	float g;
	float b;
}Color3f;

Color3f ColorRGB(float r, float g, float b);
unsigned char convert_f32_to_uc8 (float);
float max(float, float);
float min(float, float);
Color3f AddColors(Color3f, Color3f);
Color3f SubColors(Color3f, Color3f);
Color3f MultColors(Color3f, Color3f);
Color3f DivColors(Color3f, Color3f);
Color3f MultColor(Color3f, float);
Color3f DivColor(Color3f, float);

#endif