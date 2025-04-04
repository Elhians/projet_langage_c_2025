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

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}


void permuterLignes(SUPERMRT a, int i, int j){
    //verifier si les indices sont valides
    if(i<=0 || j<=0 || a==NULL || a->nl<i || a->nl<j){
        printf("Erreur : Les donnees saisies sont erronees\n");
        return;
    }
    i=i-1;//Ainsi la ligne 1 du user va coincider avec la ligne 0 du tableau ligne ainsi de suite
    j=j-1;
    
    double *temp=(a->ligne)[i];//p[i]=>*(p+i)
    (a->ligne)[i]=(a->ligne)[j];
    (a->ligne)[j]=temp;

    printf("Les lignes %d et %d ont ete permutees avec succes\n", i+1, j+1);
    return;
}

SUPERMRT sousMatrice(SUPERMRT a, int l1, int l2, int c1, int c2){
    /*if (a==NULL){
        printf("Veuillez renseigner une supermatrice existente");
        return;
    }
    if (l1<1 || l1>a->nl ||l2<1 || l2>a->nl || c1<1 || c1>a->nc || c2<1 || c2>a->nc || l1>l2 || c1>c2)
    {
        printf("Les donnees renseignees sont erronees");
        return;
    }*/
    
    SUPERMRT newA=(SUPERMRT)malloc(sizeof(descripteur));
    newA->nl=l2-l1+1;
    newA->nc=c2-c1+1;
    newA->ligne=(double**)malloc(newA->nl*sizeof(double*));
    l1=l1-1;
    c1--;
    for (int i = 0; i < newA->nl; i++)
    {
        (newA->ligne)[i]=((a->ligne)[l1])+c1;
        l1=l1+1;
    }
    return newA;
}

SUPERMRT matSupermat(double *m, int nld, int ncd, int nle, int nce){
    SUPERMRT superMat = (SUPERMRT)malloc(sizeof(descripteur));
    superMat->ligne=(double**)malloc(nle*sizeof(double*));
    superMat->nl=nle;
    superMat->nc=nce;
    double *temp=m;
    for (int i = 0; i < nle; i++)
    {
        (superMat->ligne)[i]= temp;
        temp+=ncd;
    } 
    return superMat;
}



