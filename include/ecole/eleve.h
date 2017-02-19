#ifndef ELEVE_H
#define ELEVE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define ANNEESCOLAIRE 2016

typedef struct Eleve
{
	char nom [50];
	char prenom[50];
	int jourNaissance;
	int moisNaissance;
	int anneeNaissance;
}Eleve_t;

//Ludwig//

//Fonctions mise en page
void minuscule(char * ch);
void majuscule(char * ch);
char * moisFonction (int moisNaissance, char * nomMois);

//Fonctions set
void setNom (Eleve_t * p, char  * ch);
void setPrenom (Eleve_t * p, char  * ch);
int setJour (Eleve_t * p, int i);
int setMois (Eleve_t * p, int i);
int setAnnee (Eleve_t * p, int i);

//Fonctions get
char * getNom (Eleve_t * p);
char * getPrenom (Eleve_t * p);
int getJour (Eleve_t * p);
int getMois (Eleve_t * p);
int getAnnee (Eleve_t * p);

//Saisie
Eleve_t *  saisieEleve (Eleve_t * p);
int nouvelleSaisie ();

//Accés fichier : stock via les get / read via le fichier
void stockerEleveFichier(Eleve_t * p);

//Affiche UN élève depuis la structure
void afficherEleve(Eleve_t * p);

int calculNiveau(Eleve_t * p_eleve);

int calculAge (int anneeNaissance);

#endif
