#include "supermatrice.h"

SUPERMRT allouerSupermat(int nl, int nc){
    
    /*allocation d'un 
    tableau de lignes ,tableau de pointeurs vers double(), 
    double*tab[], malloc renvoie un pointeur vers ce tableau, 
    sizeof(double)*nc:taille d'une ligne*/

    double* t = malloc(sizeof(double)*nc);
    
    double* *ligne = malloc(sizeof(t)*nl);

    if (ligne == NULL)
    {
        fputs("ERREUR!\n", stderr);
        exit(EXIT_FAILURE);
    }

    descripteur* pdesc = malloc(sizeof(descripteur));
    if (pdesc == NULL)
    {
        fputs("ERREUR!\n", stderr);
        exit(EXIT_FAILURE);
    }
    
    /*definition du descripteur */
    pdesc -> nl = nl;
    pdesc -> nc = nc;
    pdesc -> ligne = ligne;    

    return pdesc;
}

double acces(SUPERMRT a, int i, int j){

    descripteur desc = *a;

    if (i < 0 || i >= desc.nl || j < 0 || j >= desc.nc )
    {
        fputs("Cet element n'existe pas.", stderr);
        exit(EXIT_FAILURE);
    }
    
    double* tab[] = *desc.ligne;
    double* ti = tab[i];
    double aij = ti[j];

    return aij;

}

