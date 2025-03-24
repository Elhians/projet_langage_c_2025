#include "entete.h"

typedef struct Etudiant Etudiant;
struct Etudiant {
    char *nom;
    double note;
};


void affichageParOrdreDeMerite(Etudiant VETU[], int SUIVANT[], int NBETU){

    printf("/t/t/t LISTE DES ETUDIANTS PAR ORDRE DE MERITE /t/t/t");
    printf("RANG: /t/t/t NOM: /t/t/t NOTE: /t");

    for (int i = NBETU; i >= 0; i--)
    {
        printf("%d /t/t/t/t %s /t/t/t/t %d ", (NBETU - i + 1) ,VETU[SUIVANT[i]].nom, VETU[SUIVANT[i]].note);
    }
    
}

int estDansTab(int nb, int tab[], int taille){

    int trouve = 1;
    int milieu = taille / 2;

    for (int i = 0; i < milieu; i++)
    {
        if (tab[i] == nb)
        {
            return trouve;
        }
        
    }
    for (int i = milieu; i < taille; i++)
    {
        if (tab[i] == nb)
        {
            return trouve;
        }
        
    }
    return 0;
    
}

int nbAleatoire(int min, int max){

    sleep(1); //pause d'une seconde pour etre sur que la valeur change
    srand(time(NULL)); //initialisation du generateur de nombre aleatoire en fonction du nombre de seconde ecoulee depuis 1970 00h00mn00s

    int nbAleatoire = (rand()% (max - min + 1)) + min; //Valeur aleatoire comprise entre 0 et max - min + 1 a laquelle on ajoute min

    return nbAleatoire;

}

void remplirTabAvcNbAleatoire(int *tab, int taille){

    int nb = nbAleatoire(0, taille);
    int i = 0; 
    
    while(i < taille)
    {
        if (!estDansTab(nb, tab, taille))
        {
            tab[i] = nb;
            i++;
        }
        else{ 
            nb = nbAleatoire(0, taille);
        }
    }
    
    
}
void affichageAleatoire(Etudiant VETU[], int NBETU){

    int *tab = malloc(sizeof(int) * NBETU);

    if (*tab == NULL)
    {
        fputs("ERREUR!\n", stderr);
        exit(EXIT_FAILURE);
    }
    
    remplirTabAvcNbAleatoire(tab, NBETU);

    printf("/t/t/t LISTE NON ORDONNEE DES ETUDIANTS /t/t/t");
    printf("/t/t/t NOM: /t/t/t NOTE: /t");

    for (int i = NBETU; i >= 0; i--)
    {
        printf("/t/t/t/t %s /t/t/t/t %d ", VETU[tab[i]].nom, VETU[tab[i]].note);
    }
    
}

