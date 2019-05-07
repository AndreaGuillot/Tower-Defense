#ifndef INSTALLATION_H__
#define INSTALLATION_H__

enum installationType {
    radar, usine, stock
};

class Installation {

    private:
	//Position de l'installation
	float x;
	float y;
	//Type de l'installation : radar, usine, stock
	installationType type;
    //Propriétés de l'installation
    int height;
	int width;
    int cost;
	int range;

    public:
    //Constructeur
    Installation(uint range, uint cost);
    //Accesseurs
    int getPosition();
    int getSize();
    int getCost();
    int getRange(){
		return this->portee;
	}

};

#endif