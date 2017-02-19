#include "eleve.h"

//Fonction to lower pour noms et prénoms
//Pour éviter les erreurs lors des recherches
void minuscule(char * ch)
{
	int i = 0;
	
	while(ch[i]) 
	{
		ch[i] = tolower(ch[i]);
		i++;
	}
}


//Fonction to upper pour noms et la première lettre des prénoms
//Pour la mise en page sur l'invité de commande
void majuscule(char * ch)
{
	int i =0;
	
	while (ch[i])
	{
		ch[i] = toupper(ch[i]);
		i++;
	}
}


//Fonction set et get pour le nom de l'élève
void setNom (Eleve_t * p, char  * ch)
{
	minuscule (ch);
	strcpy (p -> nom , ch);
}

char * getNom (Eleve_t * p)
{
	return p -> nom;
}


//Fonction set et get pour le prénom de l'élève
void setPrenom (Eleve_t * p, char  * ch)
{
	minuscule (ch);
	strcpy (p -> prenom , ch);
}

char * getPrenom (Eleve_t * p)
{
	return p -> prenom;
}


//Fonctions set et get pour le jour de naissance
int setJour (Eleve_t * p, int i)
{
	//Remplacer le if/else par fonction test myriam
	if ( i <= 31 && i > 0)
	{
		p -> jourNaissance = i;
		return(1);
	}
	else
	{
		return(0);
	}
}

int getJour (Eleve_t * p)
{
	return p -> jourNaissance;
}


//Fonctions set et get pour le mois de naissance
int setMois (Eleve_t * p, int i)
{
	//Remplacer le if/else par fonction test myriam
	if ( i <= 12 && i > 0)
	{
		p -> moisNaissance = i;
		return(1);
	}
	else
	{
		return(0);
	}
}

int getMois (Eleve_t * p)
{
	return p -> moisNaissance;
}


//Fonctions set et get pour l'année de naissance
int setAnnee (Eleve_t * p, int i)
{
	//Remplacer le if/else par fonction test myriam
	if ( i <= 2013 && i > 2005)
	{
		p -> anneeNaissance = i;
		return(1);
	}
	else
	{
		return(0);
	}
}

int getAnnee (Eleve_t * p)
{
	return p -> anneeNaissance;
}


//Fonction de saisie renvoyant vers les fonctions set 
Eleve_t * saisieEleve (Eleve_t * p)
{
	char ch [50];
	int i;
	
	printf("Saisissez le nom de l'élève : \n");
	
	scanf("%s", ch);
	
	setNom(p, ch);

	
	printf("Saisissez le prénom de l'élève: \n");
	scanf("%s", ch);
	setPrenom(p, ch);
	
	printf("Saisissez le jour de naissance de l'élève : \n");
	scanf("%d", &i);
	setJour(p, i);
	
	printf("Saisissez le mois de naissance de l'élève : \n");
	scanf("%d", &i);
	setMois(p, i);
	
	printf("Saisissez l'année de naissance de l'élève : \n");
	scanf("%d", &i);
	setAnnee(p, i);
	
	return p;
}


//Fonction pour transformer l'int du mois en une chaîne de caractère contenant le nom du mois
char * moisFonction (int moisNaissance, char * nomMois)
{
		switch (moisNaissance)
	{
		case 1 : nomMois = "Janvier"; break;
		case 2 : nomMois = "Février"; break;
		case 3 : nomMois = "Mars"; break;
		case 4 : nomMois = "Avril"; break;
		case 5 : nomMois = "Mai"; break;
		case 6 : nomMois = "Juin"; break;
		case 7 : nomMois = "Juillet"; break;
		case 8 : nomMois = "Août"; break;
		case 9 : nomMois = "Septembre"; break;
		case 10 : nomMois = "Octobre"; break;
		case 11 : nomMois = "Novembre"; break;
		case 12 : nomMois = "Décembre"; break;		
	}
return(nomMois);
}


//Fonction renvoyant vers les fonctions get et imprimant dans le .txt
void stockerEleveFichier(Eleve_t * p)
{	
	FILE * f = fopen ("projet.txt", "a");
	fprintf(f, "%s ", getNom(p));
	fprintf(f, "%s ", getPrenom(p));
	fprintf(f, "%d %d %d\n", getJour(p), getMois(p), getAnnee(p));	
	fclose(f);
}


//Affiche UN élève, à relier avec fonction recherche
void afficherEleve(Eleve_t * p)
{
	char nomMois [15];
	printf("\n");
	majuscule(p->nom);
	printf("%s ", p->nom);
	printf("%s ", p->prenom);
	strcpy (nomMois, moisFonction(getMois(p), nomMois));
	printf("%d %s %d\n", p->jourNaissance, nomMois, p->anneeNaissance);
}

int calculNiveau(Eleve_t * p_eleve)
{
	int annee = getAnnee(p_eleve);
	int age = calculAge (annee);
	enum niveau {PS, MS, GS, CP, CE1, CE2, CM1, CM2};
	int niveau;
	switch (age)
	{
		case 3 : niveau = PS ;break;
		case 4 : niveau = MS ;break;
		case 5 : niveau = GS ;break;
		case 6 : niveau = CP ;break;
		case 7 : niveau = CE1 ;break;
		case 8 : niveau = CE2 ;break;
		case 9 : niveau = CM1 ;break;
		case 10 : niveau = CM2 ;break;
		default : printf("Problème");
	}
	return niveau;
}

int calculAge (int anneeNaissance)
{
	int age = (ANNEESCOLAIRE - anneeNaissance);
	return (age);
}



/*
int main (void)
{
	Ecole_t ecole;
	int i = 0;
	int choixUtilisateur = 1;
	
	//------ A ranger dans une fonction ------
	choixUtilisateur = nouvelleSaisie();
	if (choixUtilisateur == 1)
	{
		do
		{
			saisieEleve(&(ecole.classe[0].tab[i]));
			i++;
			choixUtilisateur = nouvelleSaisie();
			
		}while (choixUtilisateur == 1);
	}
	else if (choixUtilisateur == 2)
	{
		printf("---- Fonction retour au menu principal myriam. ----\n");
	}
	
	stockerEleveFichier(&(ecole.classe[0].tab[0]));
	
	//lectureFichier avant afficherEleve écrase les données de la structure
	lectureFichier(&(ecole.classe[0]));
	
	afficherEleve(&(ecole.classe[0].tab[0]));

return EXIT_SUCCESS;
}*/
