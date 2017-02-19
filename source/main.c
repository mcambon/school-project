#include <stdlib.h>
#include <stdio.h>

#include "menu.h"
#include "eleve.h"
#include "classe.h"
#include "ecole.h"

//ASTUCE DE COMPILATION//
//Si make ne marche pas du premier coup faire un make ecole.o en premier puis le make all.

//Vérifie que la fonction initialiserEcole s'est bien déroulée
void testInitialisation (Ecole_t * p_ecole)
{
	afficheEcole(p_ecole);	
}

Ecole_t * initialiserEcole()
{
	Ecole_t * p_ecole;
	int nbClasse = 8;
	char * nomEcole = "L'Ecole du Bonheur";
	
	p_ecole = creerEcole(nomEcole, nbClasse);

	Classe_t * p_classe;
	p_classe = getClasse(p_ecole, 0);
	setNomClasse (p_classe, "PS");
	lectureFichier (p_classe, "PS.txt");	
	setNbEleveClasse (p_classe, 4);
	
	p_classe = getClasse(p_ecole, 1);
	setNomClasse (p_classe, "MS");
	lectureFichier (p_classe, "MS.txt");
	setNbEleveClasse (p_classe, 4);
	
	p_classe = getClasse(p_ecole, 2);
	setNomClasse (p_classe, "GS");
	lectureFichier (p_classe, "GS.txt");
	setNbEleveClasse (p_classe, 4);
	
	p_classe = getClasse(p_ecole, 3);
	setNomClasse (p_classe, "CP");
	lectureFichier (p_classe, "CP.txt");
	setNbEleveClasse (p_classe, 4);
	
	p_classe = getClasse(p_ecole, 4);
	setNomClasse (p_classe, "CE1");
	lectureFichier (p_classe, "CE1.txt");
	setNbEleveClasse (p_classe, 4);
	
	p_classe = getClasse(p_ecole, 5);
	setNomClasse (p_classe, "CE2");
	lectureFichier (p_classe, "CE2.txt");
	setNbEleveClasse (p_classe, 4);
	
	p_classe = getClasse(p_ecole, 6);
	setNomClasse (p_classe, "CM1");
	lectureFichier (p_classe, "CM1.txt");
	setNbEleveClasse (p_classe, 4);
	
	p_classe = getClasse(p_ecole, 7);
	setNomClasse (p_classe, "CM2");
	lectureFichier (p_classe, "CM2.txt");
	setNbEleveClasse (p_classe, 4);
	
	testInitialisation(p_ecole);
	
	return p_ecole;
}


int main (int argc, char* argv[])
{	
	Ecole_t * p_ecole;
	
	p_ecole = initialiserEcole();
	
	afficheMenuGeneral(p_ecole);

	free (p_ecole);
	
	return EXIT_SUCCESS;
}
