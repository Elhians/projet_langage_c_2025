#include "supermatrice.h"

SUPERMRT allouerSupermat(int nl, int nc){
    
    /*allocation d'un 
    tableau de lignes ,tableau de pointeurs vers double(), 
    double*tab[], malloc renvoie un pointeur vers ce tableau, 
    sizeof(double)*nc:taille d'une ligne*/

    if (nl <= 0 || nc <= 0)
    {
        fputs("ERREUR! VALEUR INCORRECTE POUR LE NOMBRE DE LIGNE OU LE NOMBRE DE COLONNE.\n", stderr);
        exit(EXIT_FAILURE);
    }
    
    int i = 0;
    double* *ligne = malloc(sizeof(double*)*nl);

    if (ligne == NULL)
    {
        fputs("ERREUR LORS DE L'ALLOCATION DU TABLEAU DE LIGNE!\n", stderr);
        exit(EXIT_FAILURE);
    }

    descripteur* pdesc = malloc(sizeof(descripteur));
    if (pdesc == NULL)
    {
        fputs("ERREUR LORS DE L'ALLOCATION DU DESCRIPTEUR!\n", stderr);
        //liberer ligne precedement allouer
        free(ligne);
        exit(EXIT_FAILURE);
    }
    
    while (i < nl)
    {
        ligne[i] = malloc(sizeof(double)*nc);

        if (ligne[i] == NULL)
        {
            fputs("ERREUR LORS DE L'ALLOCATION DES LIGNES!\n", stderr);

            //liberer ligne et pdesc preceement alloue
            free(ligne);
            free(pdesc);
            //liberer toutes les lignes precedement alloue
            for (int j = 0; j < i; i++)
            {
                free(ligne[j]);
            }

            exit(EXIT_FAILURE);
        }
        i++;
    }

    /*definition du descripteur */
    pdesc -> nl = nl;
    pdesc -> nc = nc;
    pdesc -> ligne = ligne;    

    return pdesc;
}

double acces(SUPERMRT a, int i, int j){

    if (a == NULL)
    {
        fputs("Le supermrt n'existe pas.", stderr);
        exit(EXIT_FAILURE);
    }
    
    if (i < 0 || i >= a->nl || j < 0 || j >= a->nc )
    {
        fputs("Cet element n'existe pas.", stderr);
        exit(EXIT_FAILURE);
    }

    //double* tab[] = a->ligne;
    //double* ti = a->ligne[i];
    //double aij = a->ligne[i][j];

    return a->ligne[i][j];

}

