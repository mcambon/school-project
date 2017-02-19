#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include "ecole.h"

////////////////// Myriam/////////////////////
 /* 
 * Fonction qui récupère un nombre saisi par utilisateur et teste qu'il est bien entre mini et maxi sinon il redemande une saisie
 * Limitation : la saisie d'un caractère autre qu'un nombre crée une boucle infinie
 * Cette fonction sert à tous les menus*/
int saisieChoix (int mini, int maxi);


////////////////////Affichage des menus/////////////////////

void afficheMenuGeneral (Ecole_t * p_ecole);

void afficheMenuEleve (Ecole_t * p_ecole);

void afficheMenuAffichage (Ecole_t * p_ecole);

void afficheMenuRecherche (Ecole_t * p_ecole);


//////////////////////Traitement des choix utilisateurs///////////////

void traitementChoixGeneral (int choix,Ecole_t * p_ecole);

void traitementChoixEleve (int choix,Ecole_t * p_ecole);

void traitementChoixAffichage (int choix,Ecole_t * p_ecole);

void traitementChoixRecherche (int choix,Ecole_t * p_ecole);

void choixClasse (Ecole_t * p_ecole);

void traitementChoixClasse (int choix, Ecole_t * p_ecole);

#endif



