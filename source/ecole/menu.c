#include "menu.h"

#include <stdio.h>
#include "ecole.h"


void traitementChoixEleve (int choix, Ecole_t * p_ecole)
{
	switch (choix)
	{
	case 1 : nouvelEleve(p_ecole);break;//Permet la saisie d'une nouvelle fiche élève et l'affecte à une classe en fonction de son age
	case 2 : printf("modification fiche\n");break;//Modifier fiche existante 
	// (on n'a pas eu le temps de finir cette fonction) 
	case 3 : printf("affichage fiche\n");break;//Afficher fiche afficheEleve() après avoir recherché l'élève dont le nom/prenom a été saisi par l'utlisateur
	// (on n'a pas eu le temps de finir cette fonction)
	case 4 : afficheMenuGeneral(p_ecole);break;
	default : printf("Entrée invalide\n");
	}	
}

void afficheMenuEleve (Ecole_t * p_ecole)
{ 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n-------MENU ELEVES-------\n\n");
	printf("1 - Créer nouvelle fiche élève\n");
	printf("2 - Modifier une fiche élève existante\n");
	printf("3 - Afficher une fiche élève existante\n");
	printf("4 - Retour au menu général\n\n");

	traitementChoixEleve (saisieChoix(1, 4), p_ecole);
}

void traitementChoixClasse (int choix, Ecole_t * p_ecole)
{
	switch (choix)
	{
	case 1 : afficherClasse(getClasse(p_ecole, 0));break;
	case 2 : afficherClasse(getClasse(p_ecole, 1));break;
	case 3 : afficherClasse(getClasse(p_ecole, 2));break;
	case 4 : afficherClasse(getClasse(p_ecole, 3));break;
	case 5 : afficherClasse(getClasse(p_ecole, 4));break;
	case 6 : afficherClasse(getClasse(p_ecole, 5));break;
	case 7 : afficherClasse(getClasse(p_ecole, 6));break;
	case 8 : afficherClasse(getClasse(p_ecole, 7));break;
	default : printf("Entrée invalide\n");
	}
}

void choixClasse (Ecole_t * p_ecole)
{
	printf("\n\n\n\n\n\n\n1_PS\n2_MS\n3_GS\n4_CP\n5_CE1\n6_CE2\n7_CM1\n8_CM2\n");
	printf("Quelle classe voulez vous afficher?\n");
	traitementChoixClasse (saisieChoix(1, 8), p_ecole);
}

void traitementChoixAffichage (int choix, Ecole_t * p_ecole)
{
	switch (choix)
	{
	case 1 : choixClasse(p_ecole);break;//Affiche liste des Elève d'une classe 
	case 2 : afficheEcole(p_ecole);break; //Affiche liste des Elève de l'école
	case 3 : afficheMenuGeneral(p_ecole);break;
	default : printf("Entrée invalide\n");
	}	
}

void afficheMenuAffichage (Ecole_t * p_ecole)
{ 	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n---------------MENU----------------");
	printf("\n------Affichage des effectifs------\n\n");
	printf("1 - Afficher la liste des élèves d'une classe\n");
	printf("2 - Afficher la liste des élève de l'école\n");
	printf("3 - Retour au menu général\n\n");
	
	traitementChoixAffichage (saisieChoix(1, 3), p_ecole);
}

void traitementChoixRecherche (int choix, Ecole_t * p_ecole)
{
	switch (choix)
	{
		case 1 : recherche(p_ecole);break;//Recherche Elève dans classe
		case 2 : rechercheDansEcole(p_ecole);break; //Recherche Elève dans école
		case 3 : afficheMenuGeneral(p_ecole);break;
		default : printf("Entrée invalide");
	}	
}

void afficheMenuRecherche (Ecole_t * p_ecole)
{ 	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n-------MENU RECHERCHE-------\n\n");
	printf("1 - Rechercher un élève dans une classe\n");
	printf("2 - Rechercher un élève dans l'école\n");
	printf("3 - Retour au menu général\n\n");

	traitementChoixRecherche (saisieChoix(1, 3), p_ecole);
}

void traitementChoixGeneral (int choix, Ecole_t * p_ecole )
{
	switch (choix)
	{
		case 1 : afficheMenuEleve(p_ecole);break;
		case 2 : afficheMenuAffichage( p_ecole);break;
		case 3 : afficheMenuRecherche(p_ecole);break;
		case 4 : ;break;
		default : printf("Entrée invalide");
	}	
}

int saisieChoix (int mini, int maxi)
{
	int choix;
	do
	{
		printf("Votre choix : ");
		scanf("%d", &choix);
	}
	while (choix < mini || choix > maxi);
	
	return choix;
}

void afficheMenuGeneral (Ecole_t * p_ecole)
{ 	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("-------MENU GENERAL-------\n\n");
	printf("1 - Gestion des fiches élève\n");
	printf("2 - Affichage des effectifs\n");
	printf("3 - Rechercher un élève\n");
	printf("4 - Quitter\n\n");

	traitementChoixGeneral (saisieChoix(1, 4), p_ecole);
}





