#include "classe.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Geteurs et seteurs des classes
char * getNomClasse (Classe_t * p_classe)
{
	return p_classe -> nomClasse;
}

void setNomClasse (Classe_t * p_classe, char * ch)
{

	strcpy (p_classe -> nomClasse , ch);
}

int setNbEleveClasse (Classe_t * p_classe, int i)
{
	if (i >=0 || i <= CLASSEMAX)
	{
		p_classe -> nombreEleveClasse = i;
		return 1;
	}
	else
		return 0;
}

int getNbEleveClasse (Classe_t * p_classe)
{
	return p_classe -> nombreEleveClasse;
}

Eleve_t * getEleve (Classe_t * p_classe , int i)
{
		return &(p_classe -> tab[i]);
}

char *  getNomEleve (Classe_t * p_classe, int i)
{
	Eleve_t * p_eleve = getEleve(p_classe, i);
	return getNom(p_eleve);
}

void setTabNom (Classe_t * p_classe, int i, char  * ch)
{
	Eleve_t * p_eleve = getEleve(p_classe, i);
	setNom(p_eleve, ch);
}

void setTabPrenom (Classe_t * p_classe, int i, char  * ch)
{
	Eleve_t * p_eleve = getEleve(p_classe, i);
	setPrenom(p_eleve, ch);
}

char *  getTabPrenom (Classe_t * p_classe, int i)
{
	Eleve_t * p_eleve = getEleve(p_classe, i);
	return getPrenom(p_eleve);	
}

int  getTabJour (Classe_t * p_classe, int i)
{
	Eleve_t * p_eleve = getEleve(p_classe, i);
	return getJour(p_eleve);
}

int  getTabMois (Classe_t * p_classe, int i)
{
	Eleve_t * p_eleve = getEleve(p_classe, i);
	return getMois(p_eleve);	
}

int  getTabAnnee (Classe_t * p_classe, int i)
{
	Eleve_t * p_eleve = getEleve(p_classe, i);
	return getAnnee(p_eleve);	
}

int setTabJour (Classe_t * p_classe, int i, int jour)
{
	if (jour>0 || jour<=31)
	{
		Eleve_t * p_eleve = getEleve(p_classe, i);
		setJour(p_eleve, jour);
		return 1;	
	}
	else
		return 0;
}

int setTabMois (Classe_t * p_classe, int i, int mois)
{
	if (mois>0 || mois<=12)
	{
		Eleve_t * p_eleve = getEleve(p_classe, i);
		setMois(p_eleve, mois);
		return 1;	
	}
	else
		return 0;
}

int setTabAnnee (Classe_t * p_classe, int i, int annee)
{
	if (annee>2005 || annee<=2013)
	{
		Eleve_t * p_eleve = getEleve(p_classe, i);
		setAnnee(p_eleve, annee);
		return 1;	
	}
	else
		return 0;
}


void afficherClasse(Classe_t * p_classe)
{
    int nb = getNbEleveClasse(p_classe);
    int i;
    
	printf("\n\n------------%s------------ \n\nEffectif : %d\n\n", getNomClasse(p_classe), nb );
	
	for (i = 0 ; i<nb ; i++)
	{
		
			Eleve_t * p_eleve = getEleve(p_classe, i);
		
			afficherEleve(p_eleve);
	}
}

int rechercheEleve (Classe_t * p_classe , char *ch)
{
	int i = 0;
	int nb = getNbEleveClasse(p_classe);
	int test = 1;
	
	while (test != 0 && i < nb)
	{
		test = strcmp(ch,getNomEleve(p_classe, i));
		i++;	
	}
	
	if (test == 0)
	{
		printf("Eleve trouvé!")	;
		afficherEleve(getEleve(p_classe, i-1));
		return 1; 
	}
	else 
	{
		printf("Il n'y a pas d'èleve %s dans la classe de %s\n", ch, getNomClasse(p_classe));
		return 0;
	}	
}


void lectureFichier (Classe_t * p, char * nomFichier)
{
	int i = 0;
	FILE* fichier = fopen(nomFichier, "r");
	while (fscanf(fichier, "%s %s %d %d %d", p->tab[i].nom, p->tab[i].prenom, &(p->tab[i].jourNaissance), &(p->tab[i].moisNaissance), &(p->tab[i].anneeNaissance)) != EOF && i < 25)
	{
		//printf("%d --- %s %s %d %d %d\n", i, p->tab[i].nom, p->tab[i].prenom, p->tab[i].jourNaissance, p->tab[i].moisNaissance, p->tab[i].anneeNaissance);
		i++;
	}
	fclose(fichier);
}


void ajouterEleve(Classe_t * p_classe, Eleve_t * p_eleve)
{
	int nb = getNbEleveClasse(p_classe);
	
	if (nb<CLASSEMAX)
	{	
		p_classe->tab[nb] = * p_eleve;
		
		nb++;
		
		setNbEleveClasse(p_classe, nb);
		
		afficherClasse(p_classe);
	}
	else
	{
		printf("Cette classe est pleine!");
	}
}

void test (void)

{
	//Création eleve1 pour test
	char ch[20] = "durant";
	char ch1[20] = "jean";
	Eleve_t eleve1;
	Eleve_t *p;
	
	p = &eleve1;
	setNom(p, ch);
	setPrenom(p, ch1);
	eleve1.jourNaissance = 13;
	eleve1.moisNaissance = 11;
	eleve1.anneeNaissance = 2016;
	
	//Création eleve2 pour test
	char ch4[20] = "dupond";
	char ch3[20] = "pierre";
	Eleve_t eleve2;
	Eleve_t *p2;
	
	p2 = &eleve2;
	setNom(p2, ch4);
	setPrenom(p2, ch3);
	eleve2.jourNaissance = 12;
	eleve2.moisNaissance = 12;
	eleve2.anneeNaissance = 2014;

	//Pointeur sur classe1
	Classe_t classe1;
	Classe_t *p1;
		p1 = &classe1;

	//saisieClasse(p1);	

	//Test setNom Classe
	char ch2[3] = "CE1";
	setNomClasse(p1, ch2);
	printf("%s\n", getNomClasse(p1));

	//Test setNbEleveClasse
	setNbEleveClasse(p1,1);
	printf("%d\n", getNbEleveClasse(p1));

	
	/*Test setTabPrenom 
	char ch1[20] = "eric";
	setTabPrenom(p1, 0, ch1);

	printf("%s\n", getTabPrenom(p1,0));

	*/

	//Test allocation elève directement
	classe1.tab[0] = eleve1;

	char cha[20] = "dédé";
	char chb[20] = "dudu";
	Eleve_t eleve3;
	Eleve_t *p6;
		p6 = &eleve3;
	setNom(p6, cha);
	setPrenom(p6, chb);
	eleve3.jourNaissance = 13;
	eleve3.moisNaissance = 11;
	eleve3.anneeNaissance = 2016;

	ajouterEleve(p1, p6);
	
	afficherClasse(p1);
}

