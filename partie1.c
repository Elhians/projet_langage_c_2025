#include"partie1.h"


void affichageParOrdreDeMerite(Etudiant VETU[], int SUIVANT[], int NBETU, int DEB){

    int rg = 1;
    int i = DEB;
    
    printf("LISTE DES ETUDIANTS PAR ORDRE DE MERITE \n");

    printf("RANG: %d ; NUMERO: %d ; NOM: %s ; NOTE: %g \n", rg ,VETU[DEB].numero, VETU[DEB].nom, VETU[DEB].note);

    
    while (SUIVANT[i] != 0)
    {
        rg++;
        printf("RANG: %d ; NUMERO: %d ; NOM: %s ; NOTE: %g \n", rg ,VETU[SUIVANT[i]].numero, VETU[SUIVANT[i]].nom, VETU[SUIVANT[i]].note);
        i = SUIVANT[i];
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

    srand(time(NULL)); //initialisation du generateur de nombre aleatoire en fonction du nombre de seconde ecoulee depuis 1970 00h00mn00s

    //int nbAleatoire = (rand()% (max - min + 1)) + min; //Valeur aleatoire comprise entre 0 et max - min + 1 a laquelle on ajoute min

    return (rand() % (max - min)) + min;

}

void remplirTabAvcNbAleatoire(int *tab, int taille){

    int nb = nbAleatoire(0, taille);
    int i = 1; 
    
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

void affichageAleatoire(){

    int *tab = (int*) malloc(sizeof(int) * NBETU);

    if (tab == NULL)
    {
        fputs("ERREUR!\n", stderr);
        exit(EXIT_FAILURE);
    }
    
    remplirTabAvcNbAleatoire(tab, NBETU);

    printf("LISTE NON ORDONNEE DES ETUDIANTS\n");

    for (int i = 0; i < NBETU; i++)
    {
        printf("Numero: %d ; Nom: %s ; Note: %g \n", VETU[tab[i]].numero, VETU[tab[i]].nom, VETU[tab[i]].note);
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

    for (int i = 1; i < NBETU - 1; i++) 
    {
        for (int j = i + 1; j < NBETU; j++)
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
    printf("LISTE PAR ORDRE ALPHABETIQUE DES ETUDIANTS\n");

    trierParOrdreAlphabetique(VETU, NBETU);

    for (int i = 0; i < NBETU; i++)
    {
        printf("Nom: %s ; Numero: %d ; Note: %g \n", VETU[i].nom, VETU[i].numero, VETU[i].note);
    }

}
