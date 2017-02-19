#ifndef CLASSE_H
#define CLASSE_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

#include "ecole/eleve.h"

#define CLASSEMAX 25

class SchoolClass
{
    private:
        std::string class_name;
        std::vector<Pupil> pupils;

    public:
        SchoolClass(const std::string &name);
        ~SchoolClass();

        const std::string& get_class_name() const;

        Pupil* get_pupil();
        std::size_t get_pupil_number();
        void add_pupil(const Pupil &new_pupil);


};




char *  getNomEleve (Classe_t * p_classe, int i);

char *  getTabNom (Classe_t * p_classe, int i);


char *  getTabPrenom (Classe_t * p_classe, int i);

int  getTabJour (Classe_t * p_classe, int i);

int  getTabMois (Classe_t * p_classe, int i);

int  getTabAnnee (Classe_t * p_classe, int i);

///////////////// Setters //////////////////////////




void setTabNom (Classe_t * p_classe, int i, char  * ch);

void setTabPrenom (Classe_t * p_classe, int i, char  * ch);

int setTabJour (Classe_t * p_classe, int i, int jour);

int setTabMois (Classe_t * p_classe, int i, int mois);

int setTabAnnee (Classe_t * p_classe, int i, int annee);



/////////////////////////////////////////////////////////////

/* Myriam
 * Fonction qui affiche la liste des élèves d'une classe et leurs dates de naissance sous forme formatée
 *à partir d'un pointeur de structure Classe
 *Elle est égalment appelée par la fonction afficheEcole*/
void afficherClasse(Classe_t * p_classe);

/* Myriam
 * Fonction qui recherche un élève dont le nom est donné sous la forme d'une chaine de caractère
 * dans la classe donnée en entrée
 * Si elle le trouve elle affiche la fiche de cet élève sinon elle affiche un message comme quoi elle ne l'a pas trouvé */
int rechercheEleve (Classe_t * p_classe , char *ch);

/*Ludwig
//Lit le fichier dont le nom est donné à l'appel de la fonction et qui contient une liste d'élève pour une classe donnée
* et l'injecte dans la classe dont le pointeur est donnée.*/
void lectureFichier (Classe_t * p, char * nomFichier);

/* Myriam
 * Fonction qui récupère un pointeur de classe et un pointeur d'èleve
 * Si le nombre d'èleve max de la classe n'est pas atteint, elle
 * ajoute l'èleve à la classe et incrémente le compteur d'effectif de la classe.
 * Sinon elle affiche un message comme quoi la classe est pleine.
 * Dans ce cas l'élève n'est ajouté à aucune classe.
 * Amélioration possible :
 * Gérer ce cas en proposant l'ouverture d'une nouvelle classe.*/
void ajouterEleve(Classe_t * p_classe, Eleve_t * p_eleve);

#endif
