#ifndef _PARTIE1_C
#define _PARTIE1_C
#include "entete.h"
#define MAX_ETUDIANTS 100
typedef struct Etudiant Etudiant;
struct Etudiant {
    int numero;
    char nom[50];
    float note;
};

int ajouterEtudiant(Etudiant* VETU, int* NBETU, int numero, char* nom, float note);
int supprimerEtudiant(Etudiant* VETU, int* NBETU, int numero);
int chargerEtudiant(Etudiant* VETU, int* NBETU, int* SUIVANT);
int sauvegarderEtudiant(Etudiant* VETU, int* NBETU, int* SUIVANT);
void affichageParOrdreDeMerite(Etudiant* VETU, int* SUIVANT, int NBETU, int DEB);
void affichageAleatoire(Etudiant* VETU, int NBETU);
void afficherParOrdreAlphabetique(Etudiant* VETU, int NBETU);

#endif