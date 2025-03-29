#include "supermatrice.h"

SUPERMRT allouerSupermat(int nl, int nc){
    
    /*allocation d'un 
    tableau de lignes ,tableau de pointeurs vers double(), 
    double*tab[], malloc renvoie un pointeur vers ce tableau, 
    sizeof(double)*nc:taille d'une ligne*/
    
    double** tab=malloc((sizeof(double)*nc)*nl);

    if (tab==NULL)
    {
        fputs("ERREUR!\n", stderr);
        exit(EXIT_FAILURE);
    }

    /*definition du descripteur */
    descripteur desc = {
        nl,
        nc,
        tab
    }; 
    
    descripteur desc1 = {nl, nc, tab};

    return &desc;
}





