#ifndef _ENTETE_H
#define _ENTETE_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<strings.h>
#include<time.h>
#include<ctype.h>
#include<unistd.h>

typedef struct Etudiant Etudiant;
struct Etudiant {
    int numero;
    char *nom;
    double note;
};

int firstInDictionnaryOrder(char* mot1, char* mot2);
void remplirTabAvcNbAleatoire(int *tab, int taille);
void affichageParOrdreDeMerite(Etudiant VETU[], int SUIVANT[], int NBETU, int DEB);
void affichageAleatoire(Etudiant VETU[], int NBETU);
void afficherParOrdreAlphabetique(Etudiant* VETU, int NBETU);

#endif