#include "ecole.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void recherche (Ecole_t * p_ecole)
{
	printf("\n\n\n\n\n\n\n1_PS\n2_MS\n3_GS\n4_CP\n5_CE1\n6_CE2\n7_CM1\n8_CM2\n");
	printf("Dans quelle classe voulez vous chercher?\n");
	
	Classe_t * p_classe;
	Classe_t classe1;
	p_classe = &classe1;
	
	int choix;
	
	do
	{
		printf("Votre choix : ");
		scanf("%d", &choix);
	}
	while (choix < 1 || choix > 8);
	
	switch (choix)
	{
	case 1 : p_classe = getClasse(p_ecole, 0);break;
	case 2 : p_classe = getClasse(p_ecole, 1);break;
	case 3 : p_classe = getClasse(p_ecole, 2);break;
	case 4 : p_classe = getClasse(p_ecole, 3);break;
	case 5 : p_classe = getClasse(p_ecole, 4);break;
	case 6 : p_classe = getClasse(p_ecole, 5);break;
	case 7 : p_classe = getClasse(p_ecole, 6);break;
	case 8 : p_classe = getClasse(p_ecole, 7);break;
	default : printf("Entrée invalide\n");
	}
	char nom [50];
	printf("Tapez le nom à rechercher\n");
	scanf("%s", nom); //faire un toLower pour récupérer un nom en minuscule
	rechercheEleve(p_classe, nom);
		
}

void rechercheDansEcole (Ecole_t * p_ecole)
{
	Classe_t * p_classe;
	Classe_t classe1;
	p_classe = &classe1;
	
	int nbClasse = getNbClasseEcole(p_ecole);
	
	char nom [50];
	printf("Tapez le nom à rechercher\n");
	scanf("%s", nom); //Il aurait fallut faire un toLower pour être sur de récupérer un nom en minuscule
	
	
	int i;
	int test = 1;
	for (i = 0 ; i < nbClasse ; i++)
	{
		p_classe = getClasse(p_ecole, i);
	
		do
		{
			test = rechercheEleve(p_classe, nom);
			i++;
		}
		while (test != 0 && i < nbClasse);
		if (test == 1)
		{
			afficherEleve(getEleve(p_classe, i)); 
		}
		else 
		{
		//printf("Il n'y a pas d'èleve %s dans la classe de %s\n", nom, getNomClasse(p_classe));
		}
	}			
}


Eleve_t * nouvelEleve (Ecole_t * p_ecole)
{
	Eleve_t * p_eleve;
	Eleve_t eleve1;
	p_eleve = &eleve1;
	
	p_eleve = saisieEleve(p_eleve);
	
	int niveau = calculNiveau(p_eleve);
	
	ajouterEleve(getClasse(p_ecole, niveau), p_eleve);
	
	afficheMenuEleve(p_ecole);

return p_eleve;
}

Classe_t * getClasse (Ecole_t * p, int i)
{
	
return &(p -> classes[i]);
	
}

void setNomEcole (Ecole_t * p, char * ch)
{

	strcpy (p -> nomEcole , ch);
}

int setNbClasseEcole (Ecole_t * p, int i)
{
	p -> nombreClasse = i;
	return 1;
}

char * getNomEcole (Ecole_t * p)
{
	return p -> nomEcole;
}

int getNbClasseEcole (Ecole_t * p)
{
	return p -> nombreClasse;
}


void afficheEcole (Ecole_t * p_ecole)
{
	Classe_t * p_classe;
	int i;
	
	printf("----%s----\n", getNomEcole(p_ecole));
	printf("Nombre de classes : %d\n", getNbClasseEcole(p_ecole));
	
	for (i = 0; i< (getNbClasseEcole(p_ecole)); i++)
	{
		p_classe = getClasse (p_ecole, i);
		afficherClasse(p_classe);
	}
}

Ecole_t * creerEcole (char * nomEcole, int nbClasse)
{
	Ecole_t * p_ecole;
	p_ecole = (Ecole_t*) malloc (sizeof(Ecole_t));
	
	setNomEcole(p_ecole, nomEcole);
	setNbClasseEcole(p_ecole, nbClasse);

	return p_ecole;	
}


