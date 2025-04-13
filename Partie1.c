#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entete.h"
#include <stdbool.h>
#define MAX_ETUDIANTS 100

Etudiant VETU[MAX_ETUDIANTS]; 
int SUIVANT[MAX_ETUDIANTS];   
int DEB = -1;                 
int NBETU = 0;                
void ajouter_etudiant(int numero, char nom[], float note) {
    if (NBETU >= MAX_ETUDIANTS) {
        printf("Erreur : Nombre maximal d'etudiants atteint.\n");
        return;
    }
    VETU[NBETU].numero = numero;
    strcpy(VETU[NBETU].nom, nom);
    VETU[NBETU].note = note;
    //Dans le cas ou le tableau est vide ou si l'étudiant a une note supérieure à l'étudiant en tête de liste, on le place en tête de liste.
    if(DEB==-1 || note > VETU[DEB].note){
        SUIVANT[NBETU] = DEB;
        DEB = NBETU;
    }else{
        //dans le cas contraire on va cherchez l'indice ou on doit placer l'élément 
        int i = DEB;
        //on verifie qu'on est pas à la fin du tableau et que la note est supérieure à celle de l'étudiant qu'on insére
        while(SUIVANT[i] != -1 && VETU[SUIVANT[i]].note > note){
            //on passe au prochain élément
            i = SUIVANT[i];
        }
        //on intervrtit les deux valeurs
        SUIVANT[NBETU] = SUIVANT[i];
        SUIVANT[i] = NBETU;
    }
    NBETU++;
}
int supprimerEtudiant(Etudiant* VETU, int* SUIVANT, int* NBETU, int* DEB, int numero) {
    if (*NBETU == 0) {
        printf("Erreur : Aucun étudiant à supprimer.\n");
        return 0;
    }

    int i = *DEB, avant = -1, trouve = -1;

    // Recherche de l'étudiant à supprimer et de son prédécesseur
    while (i != -1) { // On suit la chaîne jusqu'à trouver l'étudiant
        if (VETU[i].numero == numero) {
            trouve = i;
            break;
        }
        avant = i;  // Garder en mémoire le prédécesseur
        i = SUIVANT[i];
    }

    // Si l'étudiant n'est pas trouvé
    if (trouve == -1) {
        printf("Étudiant non trouvé.\n");
        return 0;
    }

    // Mise à jour du chaînage
    if (trouve == *DEB) {
        *DEB = SUIVANT[trouve]; // Mettre à jour DEB si c'est le premier
    } else {
        SUIVANT[avant] = SUIVANT[trouve]; // Relier le prédécesseur au suivant
    }

    // Supprimer l'étudiant dans VETU
    for (int j = trouve; j < *NBETU - 1; j++) {
        VETU[j] = VETU[j + 1]; // Décaler les étudiants restants
        SUIVANT[j] = SUIVANT[j + 1]; // Décaler aussi les indices de SUIVANT
    }

    (*NBETU)--; // Réduire le nombre total d'étudiants

    printf("Suppression réussie.\n");
    return 1;
}

int chargerEtudiant(){
    FILE *f = fopen("etudiants.dat", "rb");//un fichier binaire (rb et wb)? pcq Contrairement à un fichier texte, un fichier binaire stocke les structures C telles qu'elles sont en mémoire, sans avoir à les convertir en chaînes de caractères.
    if(f==NULL){
        printf("Erreur d'ouverture du fichier ou fichier inexistant\n");
    }
    //fread permet de lire des données binaires à partir d'un fichier
    fread(&NBETU, sizeof(int), 1, f);
    fread(VETU, sizeof(Etudiant),NBETU, f);
    fread(SUIVANT, sizeof(int),NBETU, f);
    fread(&DEB, sizeof(int), 1, f);

    fclose(f);
}

//fonction pour sauvegarder les etudiants dans notre fichier
void sauvegarderEtudiant(){
    FILE *f = fopen("etudiants.dat", "wb");
    if(f==NULL){
        printf("Erreur d'ouverture du fichier\n");
        return;
    }
    
    fwrite(&NBETU, sizeof(int), 1, f);
    fwrite(VETU,sizeof(Etudiant),NBETU,f);
    fwrite(SUIVANT, sizeof(int), NBETU, f);
    fwrite(&DEB, sizeof(int), 1, f);

   

    fclose(f);
}

void affichageParOrdreDeMerite(){
    int rg = 1;
    int i = DEB;
    
    printf("LISTE DES ETUDIANTS PAR ORDRE DE MERITE \n");
    while (i!= -1)
    {
        printf("RANG: %d ; NUMERO: %d ; NOM: %s ; NOTE: %g \n", rg ,VETU[i].numero, VETU[i].nom, VETU[i].note);
        i = SUIVANT[i];
        rg++;
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
int main() {
    int choix, numero;
    char nom[50];
    float note;
    chargerEtudiant();
    do {
        ajouter_etudiant(0, "mame", 17);
        ajouter_etudiant(5, "fallou", 16);
        ajouter_etudiant(3, "lala", 14);
        ajouter_etudiant(7, "zendaya", 9);
        ajouter_etudiant(2, "mouhamadou", 18);
        ajouter_etudiant(4, "moussa", 12);

        printf("\nMenu:\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Supprimer un etudiant\n");
        printf("3. Afficher les etudiants\n");
        printf("4. Afficher les etudiants par ordre de mérite\n");
        printf("5. Afficher les etudiants par ordre alphabetique\n");
        printf("6. Afficher les etudiants de facon aleatoire\n");
        printf("7. Sauvegarder et quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                printf("Nom : ");
                scanf("%s", nom); 
                bool num_dispo = false;
                printf("Numero : ");
                scanf("%d", &numero);
                while (num_dispo== false)
                {
                    num_dispo=true;
                    for (int i = 0; i < NBETU; i++)
                    {
                        if (VETU[i].numero == numero)
                        {
                            num_dispo = false;
                            printf("Le numero %d est déjà utilisé. Veuillez entrer un autre numero : ", numero);
                            scanf("%d", &numero);

                        }
                    }
                }
                printf("Note : ");
                scanf("%f", &note);
                // Vérification de la note
                while (note<0 || note>20)
                {
                    printf("Veuillez ecrire une note entre 0 et 20 svp.");
                    scanf("%f", &note);
                }
        
                ajouter_etudiant(numero, nom, note);
                break;
            case 2:
                printf("Numero de l'etudiant à supprimer : ");
                scanf("%d", &numero);
                supprimerEtudiant(numero);
                break;
            
            case 3:
                printf("Liste des etudiants :\n");
                for (int i = 0; i < NBETU; i++) {
                    printf("Numero: %d, Nom: %s, Note: %.2f\n", VETU[i].numero, VETU[i].nom, VETU[i].note);
                }
                break;
                return 0;
            case 4:
                affichageParOrdreDeMerite();
                break;
            case 5:
                afficherParOrdreAlphabetique(VETU, NBETU);
                break;
            case 6:
                affichageAleatoire();
                break;
            case 7:
                sauvegarderEtudiant();
                printf("Sauvegarde réussie. Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 7);
    sauvegarderEtudiant();

    return 0;
}
