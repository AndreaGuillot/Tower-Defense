#ifndef MONSTER_H__
#define MONSTER_H__

class Monster {

    private:
	//Position du monstre
	float x;
	float y;
    //Propriétés du monstre
	int pv;
	int speed;
    int money;
	int resistance_TDR;
    int resistance_TDV;
    int resistance_TDJ;
    int resistance_TDB;
	
    public:
    //Constructeur
    //Accesseurs
    //Mutateurs
    void move();

};

#endif