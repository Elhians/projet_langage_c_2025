#include "supermatrice.h"

SUPERMRT allouerSupermat(int nl, int nc){
    
    if (nl <= 0 || nc <= 0)
    {
        fputs("ERREUR! VALEUR INCORRECTE POUR LE NOMBRE DE LIGNE OU LE NOMBRE DE COLONNE.\n", stderr);
        exit(EXIT_FAILURE);
    }
    
    int i = 0;

    /*allocation d'un 
    tableau de lignes ,tableau de pointeurs vers double(double*), 
    double*tab[], malloc renvoie un pointeur vers ce tableau, 
    on le recupere dans le champs ligne de notre descripteur ligne 
    sizeof(double*)*nl pour allouer le tableau qui contient
    les pointeurs vers les lignes de la matrice*/

    double* *ligne = malloc(sizeof(double*)*nl);

    if (ligne == NULL)
    {
        fputs("ERREUR LORS DE L'ALLOCATION DU TABLEAU DE LIGNE!\n", stderr);
        exit(EXIT_FAILURE);
    }

    //allocation du descripteur
    descripteur* pdesc = malloc(sizeof(descripteur));
    if (pdesc == NULL)
    {
        fputs("ERREUR LORS DE L'ALLOCATION DU DESCRIPTEUR!\n", stderr);
        //liberer ligne precedement allouer
        free(ligne);
        exit(EXIT_FAILURE);
    }

    //allocation des lignes de la matrice
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

    /*affectation des valeurs au champs du descripteur */
    pdesc -> nl = nl;
    pdesc -> nc = nc;
    pdesc -> ligne = ligne;    

    return pdesc;
}

//juste pour tester, non demande par le prof, c'est la macro ACCES dans supermat.h qui est demande 
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

SUPERMRT superProduit(SUPERMRT a, SUPERMRT b) {
    
    if (a->nc != b->nl) {
        return NULL;
    }

    SUPERMRT resultat = allouerSupermat(a->nl, b->nc);
    if (resultat == NULL) {
        return NULL;
    }

    for (int i = 0; i < a->nl; i++) {
        for (int j = 0; j < b->nc; j++) {
            resultat->ligne[i][j] = 0;
            for (int k = 0; k < a->nc; k++) {
                resultat->ligne[i][j] += a->ligne[i][k] * b->ligne[k][j];
            }
        }
    }

    return resultat;
}

