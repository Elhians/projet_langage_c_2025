#include "entete.h"

typedef struct Etudiant Etudiant;
struct Etudiant {
    int numero;
    char *nom;
    double note;
};


void affichageParOrdreDeMerite(Etudiant VETU[], int SUIVANT[], int NBETU, int DEB){

    int rg = 1;
    int i = DEB;
    printf("/t/t/t LISTE DES ETUDIANTS PAR ORDRE DE MERITE /t/t/t\n");
    printf("RANG: /t/t/t NOM: /t/t/t NOTE: /t\n");

    printf("%d /t/t/t/t %s /t/t/t/t %d \n", rg ,VETU[DEB].nom, VETU[DEB].note);

    
    while (SUIVANT[i] != SUIVANT[0])
    {
        rg++;
        printf("%d /t/t/t/t %s /t/t/t/t %d \n", rg ,VETU[SUIVANT[i]].nom, VETU[SUIVANT[i]].note);
        i = SUIVANT[i];
    }
        rg++;
        printf("%d /t/t/t/t %s /t/t/t/t %d \n", rg ,VETU[SUIVANT[i]].nom, VETU[SUIVANT[i]].note);
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

    printf("/t/t/t LISTE NON ORDONNEE DES ETUDIANTS /t/t/t\n");
    printf("/t/t/t NOM: /t/t/t NOTE: /t\n");

    for (int i = 0; i < NBETU; i++)
    {
        printf("/t/t/t/t %s /t/t/t/t %d \n", VETU[tab[i]].nom, VETU[tab[i]].note);
    }
    free(tab);
}

int firstInDictionnaryOrder(char* mot1, char* mot2){

    int i = 0, s1 = 0, s2 = 0;

    while(mot1[i] != '\0' || mot2[i] != '\0'){

        s1 += tolower(mot1[i]);
        s2 += tolower(mot2[i]);

        if (s1 > s2)
        {
            return 0;
        }
        if (s2 > s1)
        {
            return  1;
        }
        
        i++;
    }
    return 1;
    
}

void trierParOrdreAlphabetique(Etudiant* VETU, int NBETU){
    
    Etudiant temp;

    for (int i = 1; i < NBETU; i++)
    {
        for (int j = i + 1; j < NBETU - 1; j++)
        {
            if (firstInDictionnaryOrder(VETU[j].nom, VETU[i].nom))
            {
                temp = VETU[i];
                VETU[i] = VETU[j];
                VETU[j] = temp;
            }
        }
    }
    
}
void afficherParOrdreAlphabetique(Etudiant* VETU, int NBETU){
    printf("/t/t/t LISTE NON ORDONNEE DES ETUDIANTS /t/t/t\n");
    printf("/t/t/t NOM: /t/t/t NOTE: /t\n");

    trierParOrdreAlphabetique(VETU, NBETU);

    for (int i = 0; i < NBETU; i++)
    {
        printf("/t/t/t/t %s /t/t/t/t %d \n", VETU[i].nom, VETU[i].note);
    }

}
