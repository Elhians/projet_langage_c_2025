#ifndef _SUPERMATRICE_
#define _SUPERMATRICE_
#include <stdio.h>
#include <stdlib.h>

#define ACCES(a,i,j) (a)->ligne[(i)][(j)] 
/*La macro ACCES permet de recuperer (a)->ligne[(i)][(j)] comme lvalue(modifiable) si
    c'etait une fonction, la valeur returner serait une rvalue(non modifiable)*/

/*definition de la structure*/
typedef struct  
{
    int nl;
    int nc;
    double* *ligne; //ligne est un pointeur vers un tableau qui contient des pointeurs vers un double
} descripteur;

/* ligne pointe sur un tableau tab 
    tab est un tableau de nl pointeurs 
    ces pointeurs sont des tableaux qui contiennent des doubles */

typedef descripteur* SUPERMRT;

SUPERMRT allouerSupermat(int nl, int nc);

double acces(SUPERMRT a, int i, int j);

SUPERMRT superProduit(SUPERMRT a, SUPERMRT b); 

void permuterLignes(SUPERMRT a, int i, int j); 

SUPERMRT sousMatrice(SUPERMRT a, int ll, int l2, int cl, int c2);

SUPERMRT matSupermat(double *m, int nld, int ncd, int nle, int nce);

void supermatMat(SUPERMRT sm, double *m, int nld, int ncd); 

int contiguite(SUPERMRT a); 

void rendreSupermat(SUPERMRT sm);

#endif