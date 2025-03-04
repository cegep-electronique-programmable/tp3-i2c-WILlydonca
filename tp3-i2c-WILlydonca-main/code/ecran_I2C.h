

/*
* ecran.h
* Contient toutes les fonctions pour interagir avec l'ecran modele
* NHD-0420D3Z-FL-GBW
*
* Auteur : Wilken'S Pinthi�re
*/

#ifndef ECRAN_I2C_H     
#define ECRAN_I2C_H

/***********Includes************/


/************Defines************/


/*********Declarations**********/

void ecranAllume(void); // allume l'�cran

void ercranEteint(void); // �teint l'�cran


void curseurposition(int position); // positionne le curseur


void vide_ecran(void); // vide l'�cran

void ecriture(int charactere); // permet d'�crire un caract�re � la fois seulement

void movedroite(void); // fait bouger le curseur vers la droite

void movegauche(void); // fait bouger le curseur vers la droite

void shiftdroite(void); // fait bouger les caracth�re vers la droite

void shiftgauche(void); // fait bouger les caracth�re vers la gauche

void test(void); // test capture

#endif
