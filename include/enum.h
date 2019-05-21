#ifndef ENUM_H__
#define ENUM_H__

/************* Toutes les énumérations *************/

//4 directions
enum Sens{
    haut, droite, bas, gauche
};
//3 types de monstre :
/*  lucie   :   vie++ ; vitesse-  ; valeur++   */
/*  barbara :   vie+  ; vitesse+  ; valeur+    */
/*  julien  :   vie-  ; vitesse++ ; valeur-    */
enum monsterType{
    lucie, barbara, julien
};
//4 types de tour
/*  oceane  :   puissance++ ; cadence-   ; portee+    */
/*  jules   :   puissance+  ; cadence++  ; portee-    */
/*  clara   :   puissance-  ; cadence+   ; portee--   */
/*  yoann   :   puissance-- ; cadence++  ; portee++   */
enum towerType {
    oceane, jules, clara, yoann
};
//3 choix : aucune propriété, propriétés de la tour, propriétés du monstre
enum Propriete{
	aucune, propTower, propMonster
};
//4 choix : page menu principal, page jeu, page GameOver, page Win
enum Menus{
	menu, play, gameOver, gameWin
};
//3 types d'installation :
/*  radar :   portee ↗      */
/*  usine :   puissance ↗   */
/*  stock :   cadence ↗     */
enum installationType {
    radar, usine, stock
};

#endif