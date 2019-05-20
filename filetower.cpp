#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/filetower.h"

towerType FileTower::getType_tower(){
		return this->type_tower;
	}
	int FileTower::getRate(){
		return this->rate;
	}
	int FileTower::getRange(){
		return this->range;
	}
	int FileTower::getCost(){
		return this->cost;
	}
	int FileTower::getPower(){
		return this->power;
	}
	FileTower* FileTower::getPrev(){
		return this->prev;
	}
	FileTower* FileTower::getNext(){
		return this->next;
	}

	void FileTower::setType_tower(towerType type){
		this->type_tower = type;
	}
	void FileTower::setRate(int n){
		this->rate = n;
	}
	void FileTower::setRange(int n){
		this->range = n;
	}
	void FileTower::setCost(int n){
		this->cost = n;
	}
	void FileTower::setPower(int n){
		this->power = n;
	}
	void FileTower::setPrev(FileTower* t){
		this->prev = t;
	}
	void FileTower::setNext(FileTower* t){
		this->next = t;
	}

FileTower* listFileTower::getHead(){
		return this->head;
	}
	FileTower* listFileTower::getTail(){
		return this->tail;
	}
	void listFileTower::setHead(FileTower* t){
		this->head= t;
	}
	void listFileTower::setTail(FileTower* t){
		this->tail= t;
	}

	/************* Initialisation de la liste de tour (file) *************/
	/* Alloue de la mémoire pour la liste puis vérifie le fichier à l'aide de la fonction verificationFileTower	*
	*  Prend en paramère le chemin vers le fichier. Retourne le pointeur vers la liste.				*/
	listFileTower::listFileTower (char* path) {
		if(this != NULL){
			if(path != NULL) {
				
				this->length = 0;
				this->head = NULL;
				this->tail = NULL;

				if(this->verificationFileTower(path) == 0) {
					fprintf(stderr, "Erreur au moment de la vérification du fichier pour les tours\n");
				}
			}
			else {
				fprintf(stderr, "Erreur au moment de l'allocation mémoire de la liste\n");
			}

		}
		else {
			fprintf(stderr, "Erreur : Ce n'est pas le bon chemin\n");
		}
	}

	/************* Vérification du fichier *************/
	/* Vérifie si le fichier est valide : Présence du bon code (@ITD 2) sur la première ligne 		*
	*  Présence de chacun de paramètres et de leurs valeurs, vérifie si ces dernières sont correctes	*
	*  Prend en paramètre un pointeur vers une la liste et le chemin vers le fichier ITD.			*
	*  Retourne 0 en cas d'erreur sinon retourne 1								*/

	int listFileTower::verificationFileTower(char* path) {

		if(this != NULL) {
			
			if(path != NULL) {

				FILE* itd = NULL;
				itd = fopen(path, "r");	

				if(itd == NULL){
					fprintf(stderr, "Erreur : Impossible d'ouvrir le fichier\n");
					return 0;
				}
				else{

					int testCommentaire, i;
					int power, rate, range, cost;
					char* test = (char*)malloc(20*sizeof(char));

					//Récupérer le code du fichier itd
					if(fscanf(itd, "%s %d\n", test,  &testCommentaire) == 2) {

						if(strcmp("@ITD", test) == 0 && 2 == testCommentaire){

							for(i = 0; i < 4; i++) {

								switch(i) {

									case 0 :
										//Récupère "powerR"
										if(fscanf(itd, "%s", test) == 1) {
				
											//Vérifie qu'il s'agit bien de powerR
											if(strcmp("powerR", test) == 0) {

												//Récupère la valeur de powerR
												if(fscanf(itd, "%d\n", &power) == 1){

													//Récupère "rateR"
													if(fscanf(itd, "%s", test) == 1) {
				
														//Vérifie qu'il s'agit bien de rateR
														if(strcmp("rateR", test) == 0) {

															//Récupère la valeur de rateR
															if(fscanf(itd, "%d\n", &rate) == 1){

																//Récupère "rangeR"
																if(fscanf(itd, "%s", test) == 1) {
				
																	//Vérifie qu'il s'agit bien de rateR
																	if(strcmp("rangeR", test) == 0) {

																		//Récupère la valeur de rateR
																		if(fscanf(itd, "%d\n", &range) == 1){

																			//Récupère "costR"
																			if(fscanf(itd, "%s", test) == 1) {
				
																				//Vérifie qu'il s'agit bien de costR
																				if(strcmp("costR", test) == 0) {

																					//Récupère la valeur de costR
																					if(fscanf(itd, "%d\n", &cost) == 1){

																					this->addFileTower(power, rate, "R", range, cost);
													

																					}
																					else {
																						fprintf(stderr,"Erreur : ce n'est pas costR\n");
																						return 0;
																					}
																				}
																				else {
																					fprintf(stderr,"Erreur : ce n'est pas costR\n");
																					return 0;
																				}
																			}
																			else {
																				fprintf(stderr,"Erreur : ce n'est pas costR\n");
																				return 0;
																			}
													

																		}
																		else {
																			fprintf(stderr,"Erreur : ce n'est pas rangeR\n");
																			return 0;
																		}
																	}
																	else {
																		fprintf(stderr,"Erreur : ce n'est pas rangeR\n");
																		return 0;
																	}
																}
																else {
																	fprintf(stderr,"Erreur : ce n'est pas rangeR\n");
																	return 0;
																}
													

															}
															else {
																fprintf(stderr,"Erreur : ce n'est pas rateR\n");
																return 0;
															}
														}
														else {
															fprintf(stderr,"Erreur : ce n'est pas rateR\n");
															return 0;
														}
													}
													else {
														fprintf(stderr,"Erreur : ce n'est pas rateR\n");
														return 0;
													}
												}
												else {
													fprintf(stderr,"Erreur : ce n'est pas powerR\n");
													return 0;
												}
											}
											else {
												fprintf(stderr,"Erreur : ce n'est pas powerR\n");
												return 0;
											}
										}
										else {
											fprintf(stderr,"Erreur : ce n'est pas powerR\n");
											return 0;
										}
										break;

									case 1 :
										//Récupère "powerL"
										if(fscanf(itd, "%s", test) == 1) {
				
											//Vérifie qu'il s'agit bien de powerL
											if(strcmp("powerL", test) == 0) {

												//Récupère la valeur de powerL
												if(fscanf(itd, "%d\n", &power) == 1){

													//Récupère "rateL"
													if(fscanf(itd, "%s", test) == 1) {
				
														//Vérifie qu'il s'agit bien de rateL
														if(strcmp("rateL", test) == 0) {

															//Récupère la valeur de rateL
															if(fscanf(itd, "%d\n", &rate) == 1){

																//Récupère "rangeL"
																if(fscanf(itd, "%s", test) == 1) {
				
																	//Vérifie qu'il s'agit bien de rateL
																	if(strcmp("rangeL", test) == 0) {

																		//Récupère la valeur de rateL
																		if(fscanf(itd, "%d\n", &range) == 1){

																			//Récupère "costL"
																			if(fscanf(itd, "%s", test) == 1) {
				
																				//Vérifie qu'il s'agit bien de costL
																				if(strcmp("costL", test) == 0) {

																					//Récupère la valeur de costL
																					if(fscanf(itd, "%d\n", &cost) == 1){

																					this->addFileTower(power, rate, "L", range, cost);
													

																					}
																					else {
																						fprintf(stderr,"Erreur : ce n'est pas costL\n");
																						return 0;
																					}
																				}
																				else {
																					fprintf(stderr,"Erreur : ce n'est pas costL\n");
																					return 0;
																				}
																			}
																			else {
																				fprintf(stderr,"Erreur : ce n'est pas costL\n");
																				return 0;
																			}
													

																		}
																		else {
																			fprintf(stderr,"Erreur : ce n'est pas rangeL\n");
																			return 0;
																		}
																	}
																	else {
																		fprintf(stderr,"Erreur : ce n'est pas rangeL\n");
																		return 0;
																	}
																}
																else {
																	fprintf(stderr,"Erreur : ce n'est pas rangeL\n");
																	return 0;
																}
													

															}
															else {
																fprintf(stderr,"Erreur : ce n'est pas rateL\n");
																return 0;
															}
														}
														else {
															fprintf(stderr,"Erreur : ce n'est pas rateL\n");
															return 0;
														}
													}
													else {
														fprintf(stderr,"Erreur : ce n'est pas rateL\n");
														return 0;
													}
												}
												else {
													fprintf(stderr,"Erreur : ce n'est pas powerL\n");
													return 0;
												}
											}
											else {
												fprintf(stderr,"Erreur : ce n'est pas powerL\n");
												return 0;
											}
										}
										else {
											fprintf(stderr,"Erreur : ce n'est pas powerL\n");
											return 0;
										}
										break;


										case 2 :
										//Récupère "powerM"
										if(fscanf(itd, "%s", test) == 1) {
				
											//Vérifie qu'il s'agit bien de powerM
											if(strcmp("powerM", test) == 0) {

												//Récupère la valeur de powerM
												if(fscanf(itd, "%d\n", &power) == 1){

													//Récupère "rateM"
													if(fscanf(itd, "%s", test) == 1) {
				
														//Vérifie qu'il s'agit bien de rateM
														if(strcmp("rateM", test) == 0) {

															//Récupère la valeur de rateM
															if(fscanf(itd, "%d\n", &rate) == 1){

																//Récupère "rangeM"
																if(fscanf(itd, "%s", test) == 1) {
				
																	//Vérifie qu'il s'agit bien de rateM
																	if(strcmp("rangeM", test) == 0) {

																		//Récupère la valeur de rateM
																		if(fscanf(itd, "%d\n", &range) == 1){

																			//Récupère "costM"
																			if(fscanf(itd, "%s", test) == 1) {
				
																				//Vérifie qu'il s'agit bien de costM
																				if(strcmp("costM", test) == 0) {

																					//Récupère la valeur de costM
																					if(fscanf(itd, "%d\n", &cost) == 1){

																					this->addFileTower(power, rate, "M", range, cost);
													

																					}
																					else {
																						fprintf(stderr,"Erreur : ce n'est pas costM\n");
																						return 0;
																					}
																				}
																				else {
																					fprintf(stderr,"Erreur : ce n'est pas costM\n");
																					return 0;
																				}
																			}
																			else {
																				fprintf(stderr,"Erreur : ce n'est pas costM\n");
																				return 0;
																			}
													

																		}
																		else {
																			fprintf(stderr,"Erreur : ce n'est pas rangeM\n");
																			return 0;
																		}
																	}
																	else {
																		fprintf(stderr,"Erreur : ce n'est pas rangeM\n");
																		return 0;
																	}
																}
																else {
																	fprintf(stderr,"Erreur : ce n'est pas rangeM\n");
																	return 0;
																}
													

															}
															else {
																fprintf(stderr,"Erreur : ce n'est pas rateM\n");
																return 0;
															}
														}
														else {
															fprintf(stderr,"Erreur : ce n'est pas rateM\n");
															return 0;
														}
													}
													else {
														fprintf(stderr,"Erreur : ce n'est pas rateM\n");
														return 0;
													}
												}
												else {
													fprintf(stderr,"Erreur : ce n'est pas powerM\n");
													return 0;
												}
											}
											else {
												fprintf(stderr,"Erreur : ce n'est pas powerM\n");
												return 0;
											}
										}
										else {
											fprintf(stderr,"Erreur : ce n'est pas powerM\n");
											return 0;
										}
										break;


										case 3 :
										//Récupère "powerH"
										if(fscanf(itd, "%s", test) == 1) {
				
											//Vérifie qu'il s'agit bien de powerH
											if(strcmp("powerH", test) == 0) {

												//Récupère la valeur de powerH
												if(fscanf(itd, "%d\n", &power) == 1){

													//Récupère "rateH"
													if(fscanf(itd, "%s", test) == 1) {
				
														//Vérifie qu'il s'agit bien de rateH
														if(strcmp("rateH", test) == 0) {

															//Récupère la valeur de rateH
															if(fscanf(itd, "%d\n", &rate) == 1){

																//Récupère "rangeH"
																if(fscanf(itd, "%s", test) == 1) {
				
																	//Vérifie qu'il s'agit bien de rateH
																	if(strcmp("rangeH", test) == 0) {

																		//Récupère la valeur de rateH
																		if(fscanf(itd, "%d\n", &range) == 1){

																			//Récupère "costH"
																			if(fscanf(itd, "%s", test) == 1) {
				
																				//Vérifie qu'il s'agit bien de costH
																				if(strcmp("costH", test) == 0) {

																					//Récupère la valeur de costH
																					if(fscanf(itd, "%d\n", &cost) == 1){

																					this->addFileTower(power, rate, "H", range, cost);
													

																					}
																					else {
																						fprintf(stderr,"Erreur : ce n'est pas costH\n");
																						return 0;
																					}
																				}
																				else {
																					fprintf(stderr,"Erreur : ce n'est pas costH\n");
																					return 0;
																				}
																			}
																			else {
																				fprintf(stderr,"Erreur : ce n'est pas costH\n");
																				return 0;
																			}
													

																		}
																		else {
																			fprintf(stderr,"Erreur : ce n'est pas rangeH\n");
																			return 0;
																		}
																	}
																	else {
																		fprintf(stderr,"Erreur : ce n'est pas rangeH\n");
																		return 0;
																	}
																}
																else {
																	fprintf(stderr,"Erreur : ce n'est pas rangeH\n");
																	return 0;
																}
													

															}
															else {
																fprintf(stderr,"Erreur : ce n'est pas rateH\n");
																return 0;
															}
														}
														else {
															fprintf(stderr,"Erreur : ce n'est pas rateH\n");
															return 0;
														}
													}
													else {
														fprintf(stderr,"Erreur : ce n'est pas rateH\n");
														return 0;
													}
												}
												else {
													fprintf(stderr,"Erreur : ce n'est pas powerH\n");
													return 0;
												}
											}
											else {
												fprintf(stderr,"Erreur : ce n'est pas powerH\n");
												return 0;
											}
										}
										else {
											fprintf(stderr,"Erreur : ce n'est pas powerH\n");
											return 0;
										}
										break;
			

								}//End switch

							}//End for
						}
						else {
							fprintf(stderr,"Erreur : il n'y a pas le bon code\n");
							return 0;
						}
					}
					else {
						fprintf(stderr,"Erreur : il n'y a pas le bon code\n");
						return 0;
					}
				}
			}
			else {
				fprintf(stderr,"Erreur : sur le chemin\n");
				return 0;
			}
		}
		else {
			fprintf(stderr,"Erreur avec la liste de fileTower\n");
			return 0;
		}
		
		return 1;
	}

	/************* Ajouter une tour en fin de liste tour (file) *************/
	/* Ajoute une tour à la liste. Alloue la place mémoire pour la tour et attribue les valeurs	*
	*  Prend en paramètre la liste de tours, la puissance d'attaque, la vitesse d'attaque, le type 	*
	*  le périmétre d'action et le cout. Retourne 0 en cas d'erreur et 1 sinon			*/

	int listFileTower::addFileTower(int power, int rate, char* type_tower, int range, int cost) {

		// On vérifie si notre liste a été allouée
		if (this != NULL) {
			//Création d'une nouvelle tour
			FileTower* new_fileTower; 
			
			new_fileTower->setRate(rate);
			new_fileTower->setRange(range);
			new_fileTower->setType_tower(type_tower);
			new_fileTower->setCost(cost);
			new_fileTower->setPower(power);
		
			new_fileTower->setNext(NULL); 

			if (this->tail == NULL) {
				// Pointe la tête de la liste sur la nouvelle tour
				this->setHead(new_fileTower); 

				//Pointe p_prev de la nouvelle tour à NULL
				new_fileTower->setPrev(NULL);
			}
			// Cas où des éléments sont déjà présents dans la  liste
			else {
				// Pointe p_prev de la nouvelle tour sur la dernière tour de la liste
				new_fileTower->setPrev(this->tail); 

				// Relie la dernière tour de la liste à la nouvelle tour
				this->tail->setNext(new_fileTower);  
			}

			// Pointe la fin de la liste sur la nouvelle tour
			this->tail = new_fileTower; 

			// On augmente de 1 la taille de la liste
			this->length++; 
			}
			else {
				fprintf(stderr, "Problème dans la creation de la nouvelle tour\n");
				return 0;
			}

		}
		else {
			fprintf(stderr, "Cette liste de tours n'existe pas\n");
			return 0;
		}

		return 1; 
	}

	/************* Supprimer une tour selon sa position *************/
	/* Supprime une tour selon sa position, vérifie si c'est le premier, le dernier ou une tour dans la liste puis la supprime 	*
	*  Prend en paramètre la liste de tours et la tour à supprimer et retourne la liste de tours.					*/

	void listFileTower::removeFileTower(FileTower* fileTower) {

		// On vérifie si notre liste a été allouée
		if (this != NULL) {

			if(fileTower != NULL) {

				//Si c'est la dernière tour de la liste
				if (fileTower.getNext() == NULL) {
					
					//Pointe la fin de la liste sur la tour précédente
					this->setTail(fileTower->getPrev());

					if(this->tail != NULL) {
						//Lien de la dernière tour vers la tour suivante est NULL
						this->tail->setNext(NULL);
					}
					else
						this->setHead(NULL);
						
				}
			
				//Si c'est la première de la liste
				else if (fileTower.getPrev() == NULL) {
					//Pointe la tête de la liste vers la tour suivante
					this->setHead(fileTower.getNext());

					if(this->head != NULL) {
						//Le lien vers de la deuxième tour vers la tour précédente est NULL
				 		this->head->setPrev(NULL);
					}
					else
						this->tail = NULL;
				}

				else {
					//Relie la tour suivante à la tour précédente de la tour que l'on veut supprmer 
					fileTower.getNext()->setPrev(fileTower.getPrev());
					//Relie la tour précédente à la tour suivante de la tour que l'on veut supprmer 
					fileTower.getPrev()->setNext(fileTower.getNext());

				}
				//Libère espace mémoire : supprime la tour
				free(fileTower);
				//Décrémente de un la taille de la liste
				this->length--;

			}
			else
				fprintf(stderr, "Cette tour n'existe pas");
		}
		else 
			fprintf(stderr, "Cette liste de tours n'existe pas");

		// on retourne notre nouvelle liste
		return this; 
	}


	/************* Supprimer la liste de fileTower *************/
	/* Supprime la liste de missiles. Prend en paramètre un pointeur vers la liste de missiles 	*/

	void listFileTower::freeAllFileTower () {
		//Si la liste n'est pas vide
		if (this->length != 0) {

			//Tant que la liste n'est pas vide
			while (this->head != NULL) {
				this = removeFileTower(this, this->head);
			}
			
		}
		free(this);
	}