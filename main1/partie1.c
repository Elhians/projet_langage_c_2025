#include "partie1.h"

void vider_buffer()
{
    int c = 0;

    while( c != '\n' && c != EOF)
    {
        c = getchar();
    }
    
}

int ajouterEtudiant(Etudiant* VETU, int *NBETU, int numero, char* nom, float note) {

    if (VETU == NULL || NBETU == NULL || nom == NULL)
    {
        fputs("ERREUR!\n", stderr);
    }
    

    if (*NBETU >= MAX_ETUDIANTS) {
        printf("Erreur : Nombre maximal d'etudiants atteint.\n");
        return 0;
    }

    for(int i = 1; i < *NBETU; i++) {
        if (VETU[i].numero == numero) {
            printf("Erreur : Etudiant deja present.\n");
            return 0;
        }
    }
    // Ajouter l'étudiant apres le dernier etudiant present
    VETU[*NBETU].numero = numero;
    strcpy(VETU[*NBETU].nom, nom);
    VETU[*NBETU].note = note;

    (*NBETU)++;

    if ((*NBETU) >= 2)
    {
        printf("Ajout effectue avec succes!\n");
    }

    return 1;
}

int supprimerEtudiant(Etudiant* VETU, int* NBETU, int numero) {
    
    int i, trouve = -1;

    // Trouver l'étudiant  à supprimer dans le tableau
    for (i = 0; i < *NBETU; i++) {
        if (VETU[i].numero == numero) {
            trouve = i;
            break;
        }
    }

    // Si l'étudiant n'est pas trouvé,on quitte
    if (trouve == -1) {
        printf("Étudiant non trouvé.\n");
        return 0;
    }

    // Décaler les éléments vers la gacuhe à partir de l'élément à suppimer pour ecraser sa valeur
    for (i = trouve; i < *NBETU - 1; i++) {
        VETU[i] = VETU[i + 1];
    }

    *NBETU--;

    printf("Suppression réussie.\n");
    return 1;
}

//fonction pour charger les etudiants en memoire
int chargerEtudiant(Etudiant* VETU, int* NBETU, int* SUIVANT){

    FILE *f = fopen("etudiants.dat", "rb");//un fichier binaire (rb et wb)? pcq Contrairement à un fichier texte, un fichier binaire stocke les structures C telles qu'elles sont en mémoire, sans avoir à les convertir en chaînes de caractères.
    
    if(f == NULL){

        printf("Erreur d'ouverture du fichier ou fichier inexistant\n");
        return 0;

    }

    //fread permet de lire des données binaires à partir d'un fichier
    if (1 != fread(NBETU, sizeof(int), 1, f))
    {
        fputs("Erreur lors de la lecture du blocs.\n", stderr);
    }

    // Déplacer le pointeur après le 1er bloc (offset = 1 * sizeof(int))
    fseek(f, 1 * sizeof(int), SEEK_SET);

    if (*NBETU != fread(VETU, sizeof(Etudiant), *NBETU, f))
    {
        fputs("Erreur lors de la lecture des blocs.1\n", stderr);
    }
    
    // Déplacer le pointeur après le 2eme bloc (offset = *NBETU * sizeof(Etudiant))
    fseek(f, 1 * sizeof(int) + (*NBETU * sizeof(Etudiant)), SEEK_SET);

    if(*NBETU != fread(SUIVANT, sizeof(int), *NBETU, f))
    {
        fputs("Erreur lors de la lecture des blocs.2\n", stderr);
    }

    fclose(f);

    return 1;
}

//fonction pour sauvegarder les etudiants dans notre fichier
int sauvegarderEtudiant(Etudiant* VETU, int *NBETU, int *SUIVANT){

    FILE *f = fopen("etudiants.dat", "wb");

    if(f == NULL){

        printf("Erreur d'ouverture du fichier de sauvegarde.\n");
        return 0;
    }

    if (1 != fwrite(NBETU, sizeof(int), 1, f))
    {
        fputs("Cannot write blocks in file1\n", stderr);
    }
    // Déplacer le pointeur après le 1er bloc (offset = 1 * sizeof(int))
    fseek(f, 1 * sizeof(int), SEEK_SET);
    //fwrite permet d'écrire des données binaires dans un fichier
    if (*NBETU != fwrite(VETU, sizeof(Etudiant), *NBETU, f))
    {
        fputs("Cannot write blocks in file\n", stderr);
    }

    // Déplacer le pointeur après le 2eme bloc (offset = *NBETU * sizeof(Etudiant))
    fseek(f, 1 * sizeof(int) + (*NBETU * sizeof(Etudiant)), SEEK_SET);

    if(*NBETU != fwrite(SUIVANT, sizeof(int), *NBETU, f))
    {
        fputs("Erreur lors de la lecture des blocs.\n", stderr);
    }

    fclose(f);
    return 1;
}


void affichageParOrdreDeMerite(Etudiant* VETU, int* SUIVANT, int NBETU, int DEB){

    int rg = 1;
    int i = DEB;
    
    printf("LISTE DES ETUDIANTS PAR ORDRE DE MERITE \n");

    if (DEB == 0)
    {
        printf("Liste vide.\n");
        return;
    }
    

    printf("RANG: %d ; NUMERO: %d ; NOM: %s ; NOTE: %g \n", rg ,VETU[DEB].numero, VETU[DEB].nom, VETU[DEB].note);

    
    while (SUIVANT[i] != 0)
    {
        rg++;
        printf("RANG: %d ; NUMERO: %d ; NOM: %s ; NOTE: %g \n", rg ,VETU[SUIVANT[i]].numero, VETU[SUIVANT[i]].nom, VETU[SUIVANT[i]].note);
        i = SUIVANT[i];
    }
}

int estDansTab(int nb, int* tab, int taille){

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

void affichageAleatoire(Etudiant* VETU, int NBETU){

    int *tab = malloc(sizeof(int) * NBETU);

    if (tab == NULL)
    {
        fputs("ERREUR!\n", stderr);
        exit(EXIT_FAILURE);
    }
    
    remplirTabAvcNbAleatoire(tab, NBETU);

    printf("LISTE NON ORDONNEE DES ETUDIANTS\n");

    for (int i = 1; i < NBETU; i++)
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

    for (int i = 1; i < NBETU; i++)
    {
        printf("Nom: %s ; Numero: %d ; Note: %g \n", VETU[i].nom, VETU[i].numero, VETU[i].note);
    }

}
