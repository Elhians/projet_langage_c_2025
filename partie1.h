#ifndef _PARTIE1_H
#define _PARTIE1_H
#define MAX_ETUDIANTS 100
#include "entete.h"

typedef struct Etudiant Etudiant;
struct Etudiant {
    int numero;
    char *nom;
    double note;
};


void affichageParOrdreDeMerite(Etudiant VETU[], int SUIVANT[], int NBETU, int DEB);
void affichageAleatoire(Etudiant VETU[], int NBETU);
void afficherParOrdreAlphabetique(Etudiant* VETU, int NBETU);
void ajouter_etudiant(int numero, char nom[], float note);
void supprimerEtudiant(int numero); 
int chargerEtudiant();
void sauvegarderEtudiant();

#endif