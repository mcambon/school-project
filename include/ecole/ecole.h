#ifndef ECOLE_H
#define ECOLE_H

#include <stdio.h>
#include <stdlib.h>

#include "classe.h"


typedef struct Ecole
{
		char nomEcole[30];
		int nombreClasse;
		Classe_t classes[8];
}Ecole_t;

//Myriam//

//////////////////Getters //////////////////

Classe_t * getClasse (Ecole_t * p, int i);

char * getNomEcole (Ecole_t * p);

int getNbClasseEcole (Ecole_t * p);


//////////////////Setters ///////////////////

void setNomEcole (Ecole_t * p, char * ch);


int setNbClasseEcole (Ecole_t * p, int i);


//////////////////////////////////////////////////

/*Fonction appelée au lancement du programme
* Initialise la structure de l'Ecole et renvoit un pointeur vers cette structure
* la remplie avec un nom prédéfinit et crée les 8 classes de base
* les remplira avec la fonction lectureFichier de Ludwig */
Ecole_t * creerEcole (char * nomEcole, int nbClasse);

/*Permet la saisie d'une nouvelle fiche élève et l'affecte à une classe en fonction de son age
 * Prend un pointeur d'école en entrée et renvoie un pointeur vers l'élève*/
Eleve_t * nouvelEleve (Ecole_t * p_ecole);

/*Fonction qui affiche la liste de tous les élèves de l'école passée en paramètre d'entrée
 * Elle affiche la liste des élèves de chaque classe de l'école*/
void afficheEcole (Ecole_t * p_ecole);

/*Fonction qui demande à l'utilisateur un nom et qui cherche dans toutes les classes de l'école si l'élève apparaît.
 * Ne fonctionne pas. Nous n'avons pas eu le temps de la finir*/
void rechercheDansEcole (Ecole_t * p_ecole);

/*Fonction qui demande à l'utilisateur un nom et une classe et qui cherche dans la classes donnée si l'élève apparaît.
 * Ne fonctionne pas complètement. Elle ne trouve pas le premier élève d'une classe*/
void recherche (Ecole_t * p_ecole);

#endif

