#ifndef _TRIE_C
#define _TRIE_C
#include "entete.h"
#define MAX_ETUDIANT 100
typedef struct Etudiant Etudiant;
struct Etudiant {
    int numero;
    char *nom;
    double note;
};
void affichageParOrdreDeMerite(Etudiant* VETU, int* SUIVANT, int NBETU, int DEB);
void affichageAleatoire(Etudiant* VETU, int NBETU);
void afficherParOrdreAlphabetique(Etudiant* VETU, int NBETU);

#endif