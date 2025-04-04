#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int nl;
    int nc;
    double* *ligne;
}descripteur;

typedef descripteur* SUPERMRT;

void permuterLignes(SUPERMRT a, int i, int j);
SUPERMRT sousMatrice(SUPERMRT a, int l1, int l2, int c1, int c2);
SUPERMRT matSupermat(double *m, int nld, int ncd, int nle, int nce);


void permuterLignes(SUPERMRT a, int i, int j){
    //verifier si les indices sont valides
    if(i<=0 || j<=0 || a==NULL || a->nl<i || a->nl<j){
        printf("Erreur : Les donnees saisies sont erronees\n");
        return;
    }
    i=i-1;//Ainsi la ligne 1 du user va coincider avec la ligne 0 du tableau ligne ainsi de suite
    j=j-1;
    int nbrColonnes=a->nc;//je recupere le nombre nombre de Colonnes dans nbrColonnes pour que ca soit plus facile à manipuler
    
    double *temp=(a->ligne)[i];//p[i]=>*(p+i)
    (a->ligne)[i]=(a->ligne)[j];
    (a->ligne)[j]=temp;

    printf("Les lignes %d et %d ont ete permutees avec succes\n", i+1, j+1);

    /*
    //je récupere le tableau de lignes dans pi et pj pour que ça soit plus facile à manipuler
    double* pi=(a->ligne)[i];
    double* pj=(a->ligne)[j];
    for (int i = 0; i < nbrColonnes; i++)
    {
        double* temp=pi;
        pi=pj;
        pj=temp;
    }
    */
    return;
}