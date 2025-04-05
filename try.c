
#include "trie.h"

int main(){
    
    Etudiant etudiants[] = {
        {000, "", 0.0},
        {101, "David", 18.2},
        {102, "Alice", 12.5},
        {103, "Charlie", 9.0},
        {104, "Eve", 14.8},
        {105, "Bob", 15.0}
    };

    int DEB = 1;
    int SUIVANT[] = {0,5,3,0,2,4};

    affichageParOrdreDeMerite(etudiants, SUIVANT, 6, DEB);
    affichageAleatoire(etudiants, 6);
    afficherParOrdreAlphabetique(etudiants, 6);
    return 0;
}

