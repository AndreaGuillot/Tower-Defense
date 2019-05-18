#ifndef FILE_TOWER_H_
#define FILE_TOWER_H_

/************* STRUCTURE DU FICHIER TOUR *************/
/* Liste doublement chainée pour pouvoir naviger dans la liste de tours	*
*  et récupérer facile n'importe quelle tour dans la liste 		*/
class FileTower {

	towerType type_tower;
	int rate;
	int range;
	int cost;
	int power;

	//Pointer vers l'élément précédent
	FileTower prev;

	//Pointeur vers l'élément suivant
	FileTower next;

}

/************* STRUCTURE DE LA LISTE DE TOURS *************/
class listFileTower{
private:
	//Taille de la liste
	int length;

	//Pointeur
	FileTower head; //pointeur vers le premier element
	FileTower tail; //pointeur vers le dernier element

public:

	listFileTower(char);
	int verificationFileTower(char);
	int addFileTower(int, int, char, int, int);
	void removeFileTower(FileTower*);
	void freeAllFileTower ();
}

#endif
