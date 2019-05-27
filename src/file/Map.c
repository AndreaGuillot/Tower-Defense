#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "file/Map.h"
#include "file/Image.h"
#include "ihm/Node.h"
#include "geometry/Color3f.h"


/************* Initialisation de la carte *************/
/* Alloue de la mémoire pour la carte puis vérifie la carte à l'aide de la fonction verifarificationMap	*
*  Prend en paramère le chemin vers la carte. Retourne le pointeur vers la map.				*/
Map* newMap (char* path) {

	if(path != NULL) {

		//Alloue la memoire
		Map* map = malloc(sizeof(Map));
		if(map != NULL) {

			if(verificationMap(map, path) == 0) {
				fprintf(stderr, "Erreur au moment de la vérification de la map\n");
				return NULL;
			}
			return map;

		}
		else {
			fprintf(stderr, "Erreur au moment de l'allocation mémoire de la map\n");
			return NULL;
		}

	}
	else {
		fprintf(stderr, "Erreur : Ce n'est pas le bon chemin\n");
		return NULL;
	}
	
	return NULL;	
	
}

/************* Vérification de la carte *************/
/* Vérifie si la carte est valide : Présence du bon commentaire (@ITD 1) sur la première ligne 		*
*  Présence de chacun de 8 paramètres et de leurs valeurs, vérifie si ces dernières sont correctes	*
*  nombre de noeud correspondant au nombre de lignes restantes. Vérifie que les noeuds sont bien dans   *
*  un pixel de l'image. Prend en paramètre un pointeur vers une map et le chemin vers le fichier ITD.	*
*  Retourne 0 en cas d'erreur sinon retourne 1								*/

int verificationMap(Map* map, char* nameITD){ 

	FILE* itd = NULL;
	itd = fopen(nameITD, "r");	

	if(itd == NULL){
		fprintf(stderr, "Erreur : Impossible d'ouvrir le fichier\n");
		return 0;
	}
	else{
		int testCommentaire;
		char* test = (char*)malloc(20*sizeof(char));
		
		//Récupérer le code du fichier itd
		if(fscanf(itd, "%s %d\n", test,  &testCommentaire) == 2) {

			if(strcmp("@ITD", test) == 0 && 1 == testCommentaire){

				//Récupère "carte"
				if(fscanf(itd, "%s", test) == 1) {
			
					//Vérifie qu'il s'agit bien de carte
					if(strcmp("carte", test) == 0) {

						//Alloue de la mémoire pour une image
						Image* new_img = (Image*)malloc(sizeof(Image));
						char* path = (char*)malloc(50*sizeof(char));
				
						//Récupère le chemin vers l'image ppm
						if(fscanf(itd, "%s\n", path) == 1){
							new_img->path = path;
							openImg(new_img, new_img->path);
							map->img = new_img;			

							//Récupère "énergie"
							if(fscanf(itd, "%s", test) == 1) {

								//Vérifie qu'il s'agit bien de l'énergie
								if(strcmp("energie", test) == 0) {
				
									//Récupère l'énergie
									if(fscanf(itd, "%d\n", &(map->energie)) == 1){

										//Récupère "chemin"
										if(fscanf(itd, "%s", test) == 1) {

											//Vérifie qu'il s'agit bien du chemin
											if(strcmp("chemin", test) == 0) {
								
												int r, v, b;
								
												//Récupère la couleur du chemin
												if(fscanf(itd, "%d %d %d\n", &r, &v, &b) == 3){

													(map->road).r = r/255.0;
													(map->road).g = v/255.0;
													(map->road).b = b/255.0;
									
													//Récupère "noeud"
													if(fscanf(itd, "%s", test) == 1) {

														//Vérifie qu'il s'agit bien du chemin
														if(strcmp("noeud", test) == 0) {
								
															//Récupère la couleur du chemin
															if(fscanf(itd, "%d %d %d\n", &r, &v, &b) == 3){

																(map->node).r = r/255.0;
																(map->node).g = v/255.0;
																(map->node).b = b/255.0;
									
																//Récupère "construct"
																if(fscanf(itd, "%s", test) == 1) {

																	//Vérifie qu'il s'agit bien du chemin
																	if(strcmp("construct", test) == 0) {
								
																		//Récupère la couleur du chemin
																		if(fscanf(itd, "%d %d %d\n", &r, &v, &b) == 3){

//Créer la liste de pixel
LNode* list_pixels = new_LNode();
map->list_pixels = list_pixels;
																			(map->construct).r = r/255.0;
																			(map->construct).g = v/255.0;
																			(map->construct).b = b/255.0;
									
																			//Récupère "in"
																			if(fscanf(itd, "%s", test) == 1) {

																				//Vérifie qu'il s'agit bien du chemin
																				if(strcmp("in", test) == 0) {
								
																					//Récupère la couleur du chemin
																					if(fscanf(itd, "%d %d %d\n", &r, &v, &b) == 3){

																						(map->in).r = r/255.0;
																						(map->in.g) = v/255.0;
																						(map->in.b) = b/255.0;
									
																						//Récupère "out"
																						if(fscanf(itd, "%s", test) == 1) {

																							//Vérifie qu'il s'agit bien du chemin
																							if(strcmp("out", test) == 0) {
								
																								//Récupère la couleur du chemin
																								if(fscanf(itd, "%d %d %d\n", &r, &v, &b) == 3){
																									(map->out).r = r/255.0;
																									(map->out).g = v/255.0;
																									(map->out).b = b/255.0;

								//Récupére le nombre de noeuds									
								if(fscanf(itd, "%d\n", &(map->number_node)) == 1){
									int i, x, y;

									//Création d'une nouvelle liste de noeuds
									map->list_node = new_LNode();
									if(map->list_node != NULL){

										//Pour chaque noeud (on fait la boucle, le nombre de fois qu'il y a de nombre de noeuds)
										for(i=0; i < (map->number_node); i++){

											//Récupére les coordonnées
											if(fscanf(itd, "%d %d\n", &x, &y) == 2){

												//Vérifie que le noeud se trouve dans l'image
												if(x <= map->img->widthImg && x >= 0 && y <= map->img->heightImg && y >= 0){
													float x1 = x + 200.0;
													float y1 = y + 60.0;
													//Vérifie que le noeud à bien été ajouté à la liste de noeud
													if(addNode(map->list_node, x1, y1) != 1) {
														fprintf(stderr, "Erreur, ce n'est pas les coordonées d'un noeud");
														return 0;
													}
												}
												else{
													fprintf(stderr, "Erreur, le noeud ne se trouve pas sur la carte");
													return 0;
												}
											}
											else {
												fprintf(stderr, "Erreur, ce n'est pas les coordonées d'un noeud");
												return 0;
											}
										}
										if(fscanf(itd, "%d %d\n", &x, &y) == 2){
											fprintf(stderr, "Erreur, il y a trop de noeuds");
											return 0;
										}
									}
								}
								else {
									fprintf(stderr, "Erreur, ce n'est pas un nombre de noeud");
									return 0;
								}													

																								}
																								else {
																									fprintf(stderr, "Erreur, Ce ne sont pas les valeurs de couleurs\n");
																									return 0;
																								}
																							}
																							else {
																								fprintf(stderr, "Erreur, la huitième ligne ne correspond pas à la sortie\n");
																								return 0;
																							}
																														}
																							else {
																								fprintf(stderr, "Erreur, la huitième ligne ne correspond pas à la sortie\n");
																								return 0;
																							}

																					}
																					else {
																						fprintf(stderr, "Erreur, Ce ne sont pas les valeurs de couleurs\n");
																						return 0;
																					}
																				}
																				else {
																					fprintf(stderr, "Erreur, la septième ligne ne correspond pas à l'entrée\n");
																					return 0;
																				}
																			}
																																						else {
																				fprintf(stderr, "Erreur, la septième ligne ne correspond pas à l'entrée\n");
																				return 0;
																			}

																		}
																		else {
																			fprintf(stderr, "Erreur, Ce ne sont pas les valeurs de couleurs\n");
																			return 0;
																		}
																	}
																	else {
																		fprintf(stderr, "Erreur, la sixième ligne ne correspond pas à la zone constructible\n");
																		return 0;
																	}
																}
																else {
																	fprintf(stderr, "Erreur, la sixième ligne ne correspond pas à la zone constructible\n");
																	return 0;
																}

															}
															else {
																fprintf(stderr, "Erreur, Ce ne sont pas les valeurs de couleurs\n");
																return 0;
															}
														}
														else {
															fprintf(stderr, "Erreur, la cinquième ligne ne correspond pas au noeud\n");
															return 0;
														}
													}
													else {
														fprintf(stderr, "Erreur, la cinquième ligne ne correspond pas au noeud\n");
														return 0;
													}

												}
												else {
													fprintf(stderr, "Erreur, Ce ne sont pas les valeurs de couleurs\n");
													return 0;
												}
											}
											else {
												fprintf(stderr, "Erreur, la quatrième ligne ne correspond pas au chemin\n");
												return 0;
											}
										}
										else {
											fprintf(stderr, "Erreur, la quatrième ligne ne correspond pas au chemin\n");
											return 0;
										}

									}
									else {
										fprintf(stderr, "Erreur, Ce n'est pas une valeur d'énergie\n");
										return 0;
									}
								}
								else {
									fprintf(stderr, "Erreur, la troisième ligne ne correspond pas à l'énergie\n");
									return 0;
								}
							}
							else {
								fprintf(stderr, "Erreur, la troisième ligne ne correspond pas à l'énergie\n");
								return 0;
							}
						}
						else {
							fprintf(stderr, "Erreur, ce n'est pas le chemin vers la carte\n");
							return 0;
						}
					}
					else {
						fprintf(stderr, "Erreur, la deuxième ligne ne correspond pas au chemin vers la carte\n");
						return 0;
					}
				}
				else {
					fprintf(stderr, "Erreur, la deuxième ligne ne correspond pas au chemin vers la carte\n");
					return 0;
				}
			}
			else {
				fprintf(stderr, "Ce n'est pas un fichier ITD\n");
				return 0;
			}
		}
		else {
			fprintf(stderr, "Ce n'est pas un fichier ITD\n");
			return 0;
		}
				
		// On ferme le vide le buffer et on ferme le fichier itd
		fflush(itd);
		fclose(itd);
	}
	return 1;
}

/************* Change la couleur du chemin, des zones constructibles, des noeuds, de l'entrée et de la sortie *************/
/* Change la couleur du chemin, des zones constructibles, des noeuds, de l'entrée et de la sortie de la map : 	*
*  Appelle les différentes fonctions qui permettent le changement de couleurs : 				*
*  -  changeColorRoad : change la couleur du chemin							 	*
*  -  changeColorConstruct : change la couleur des zones constructibles						*
*  -  changeColorNode : change la couleur des noeuds							 	*
*  -  changeColorIn : change la couleur de l'entrée							 	*
*  -  changeColorOut : change la couleur de la sortie							 	*
*  Prend en paramètre l'image pour connaitre la taille de cette dernière, le tableau de pixel et la map pour	*
*  savoir en quelle couleur il faut changer pour les différents élements. Retourne 0 en cas d'erreur sinon 	*
*  retourne 1													*/
int ChangeColor(Image* img, unsigned char* tabPixels, Map* map) {

	changeColorRoad(img, tabPixels, map);
	changeColorConstruct(img, tabPixels, map);
	changeColorNode(img, tabPixels, map);
	changeColorIn(img, tabPixels, map);
	changeColorOut(img, tabPixels, map);
	return 1;

}

/************* Change la couleur du chemin *************/
/* Change la couleur du chemin : parcours le tableau de pixel et vérifie la couleur. SI c'est du rose 	*
*  alors change la couleur en la couleur définie dans le fichier IDT. Prend en paramètre l'image pour	*
*  connaitre la taille de cette dernière, le tableau de pixel et la map pour savoir en quelle couleur	*
*  il faut changer pour le chemin. Retourne 0 en cas d'erreur sinon retourne 1				*/
							
int changeColorRoad(Image* img, unsigned char* tabPixels, Map* map) {

	int i, j;

	// On parcourt les lignes du tableau
	for(i=0; i<(img->heightImg); i++) {

		// puis on parcourt les colonnes du tableau
		for(j=0; j<(img->widthImg); j++) {
			
			//On vérifie la couleur
			if(tabPixels[i*(img->widthImg)*3+j*3] == 255 && tabPixels[i*(img->widthImg)*3+j*3+1] == 0 && tabPixels[i*(img->widthImg)*3+j*3+2] == 0){

				//Change de couleur
				tabPixels[i*(img->widthImg)*3+j*3] = ((map->road).r)*255;
				tabPixels[i*(img->widthImg)*3+j*3+1] = ((map->road).g)*255;
				tabPixels[i*(img->widthImg)*3+j*3+2] = ((map->road).b)*255;
			}
		}
	}

	return 1;

}

/************* Change la couleur des zones constructibles *************/
/* Change la couleur du chemin : parcours le tableau de pixel et vérifie la couleur. SI c'est du bleu 	*
*  alors change la couleur en la couleur définie dans le fichier IDT. Prend en paramètre l'image pour	*
*  connaitre la taille de cette dernière, le tableau de pixel et la map pour savoir en quelle couleur	*
*  Il faut changer pour les zones constructibles. Il prend également les coordonnées de chaque pixel 	*
*  bleu et les ajoute dans la liste des pixels des zones constructibles de la map. Retourne 0 en cas 	*
*  d'erreur sinon retourne 1										*/
							
int changeColorConstruct(Image* img, unsigned char* tabPixels, Map* map) {

	int i, j;
	
	if(map->list_pixels != NULL) {

		// On parcourt les lignes du tableau
		for(i=0; i<(img->heightImg); i++) {

			// puis on parcourt les colonnes du tableau
			for(j=0; j<(img->widthImg); j++) {
			
				//On vérifie la couleur
				if(tabPixels[i*(img->widthImg)*3+j*3] == 0 && tabPixels[i*(img->widthImg)*3+j*3+1] == 0 && tabPixels[i*(img->widthImg)*3+j*3+2] == 255){

					//Change de couleur
					tabPixels[i*(img->widthImg)*3+j*3] = ((map->construct).r)*255;
					tabPixels[i*(img->widthImg)*3+j*3+1] = ((map->construct).g)*255;
					tabPixels[i*(img->widthImg)*3+j*3+2] = ((map->construct).b)*255;

					//Ajoute le noeud à la liste de pixels avec les coordonnées
					addNode(map->list_pixels, j + 200, i + 60);
				}
			}
		}
	}
	else {
		fprintf(stderr, "Erreur : problème au moment de l'allocation pour la liste de pixels de la zone constructible\n");
		return 0;
	}

	return 1;

}


/************* Change la couleur des noeuds *************/
/* Change la couleur du chemin : parcours le tableau de pixel et vérifie la couleur. SI c'est du bleu 	*
*  alors change la couleur en la couleur définie dans le fichier IDT. Prend en paramètre l'image pour	*
*  connaitre la taille de cette dernière, le tableau de pixel et la map pour savoir en quelle couleur	*
*  Il faut changer pour des noeuds. Retourne 0 en cas d'erreur sinon retourne 1				*/
							
int changeColorNode(Image* img, unsigned char* tabPixels, Map* map) {

	int i, j;

	// On parcourt les lignes du tableau
	for(i=0; i<(img->heightImg); i++) {

		// puis on parcourt les colonnes du tableau
		for(j=0; j<(img->widthImg); j++) {
			
			//On vérifie la couleur
			if(tabPixels[i*(img->widthImg)*3+j*3] == 6 && tabPixels[i*(img->widthImg)*3+j*3+1] == 0 && tabPixels[i*(img->widthImg)*3+j*3+2] == 255){

				//Change de couleur
				tabPixels[i*(img->widthImg)*3+j*3] = ((map->construct).r)*255;
				tabPixels[i*(img->widthImg)*3+j*3+1] = ((map->construct).g)*255;
				tabPixels[i*(img->widthImg)*3+j*3+2] = ((map->construct).b)*255;
			}
		}
	}

	return 1;

}

/************* Change la couleur de l'entrée *************/
/* Change la couleur du chemin : parcours le tableau de pixel et vérifie la couleur. Si c'est du jaune 	*
*  alors change la couleur en la couleur définie dans le fichier IDT. Prend en paramètre l'image pour	*
*  connaitre la taille de cette dernière, le tableau de pixel et la map pour savoir en quelle couleur	*
*  Il faut changer pour l'entrée. Retourne 0 en cas d'erreur sinon retourne 1				*/
							
int changeColorIn(Image* img, unsigned char* tabPixels, Map* map) {

	int i, j;

	// On parcourt les lignes du tableau
	for(i=0; i<(img->heightImg); i++) {

		// puis on parcourt les colonnes du tableau
		for(j=0; j<(img->widthImg); j++) {
			
			//On vérifie la couleur
			if(tabPixels[i*(img->widthImg)*3+j*3] == 255 && tabPixels[i*(img->widthImg)*3+j*3+1] == 0 && tabPixels[i*(img->widthImg)*3+j*3+2] == 67){

				//Change de couleur
				tabPixels[i*(img->widthImg)*3+j*3] = ((map->in).r)*255;
				tabPixels[i*(img->widthImg)*3+j*3+1] = ((map->in).g)*255;
				tabPixels[i*(img->widthImg)*3+j*3+2] = ((map->in).b)*255;
			}
		}
	}

	return 1;

}

/************* Change la couleur de la sortie *************/
/* Change la couleur du chemin : parcours le tableau de pixel et vérifie la couleur. Si c'est du rouge 	*
*  alors change la couleur en la couleur définie dans le fichier IDT. Prend en paramètre l'image pour	*
*  connaitre la taille de cette dernière, le tableau de pixel et la map pour savoir en quelle couleur	*
*  Il faut changer pour la sortie. Retourne 0 en cas d'erreur sinon retourne 1				*/
							
int changeColorOut(Image* img, unsigned char* tabPixels, Map* map) {

	int i, j;

	// On parcourt les lignes du tableau
	for(i=0; i<(img->heightImg); i++) {

		// puis on parcourt les colonnes du tableau
		for(j=0; j<(img->widthImg); j++) {
			
			//On vérifie la couleur
			if(tabPixels[i*(img->widthImg)*3+j*3] == 255 && tabPixels[i*(img->widthImg)*3+j*3+1] == 252 && tabPixels[i*(img->widthImg)*3+j*3+2] == 0){

				//Change de couleur
				tabPixels[i*(img->widthImg)*3+j*3] = ((map->out).r)*255;
				tabPixels[i*(img->widthImg)*3+j*3+1] = ((map->out).g)*255;
				tabPixels[i*(img->widthImg)*3+j*3+2] = ((map->out).b)*255;
			}
		}
	}

	return 1;

}

/************* Supprimer l'interface  ***********/
/* Supprime l'interface. Prend en paramètre un pointeur vers la map  	*/

void freeMap (Map* map) {
	//Si la map existe
	if (map != NULL) {
		freeImage (map->img);
		freeAllNode (map->list_pixels);
		freeAllNode (map->list_node);
		free(map);
	}
}
