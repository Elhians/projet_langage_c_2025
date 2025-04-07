#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ETUDIANTS 100

typedef struct {
    int numero;
    char nom[50];
    float note;
} Etudiant;

Etudiant VETU[MAX_ETUDIANTS]; 
int SUIVANT[MAX_ETUDIANTS];   
int DEB = -1;                 
int NBETU = 0;                
int ajouterEtudiant(Etudiant* VETU, int* SUIVANT, int *NBETU, int* DEB, int numero, char* nom, float note) {

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

    //Dans le cas ou le tableau est vide ou si l'étudiant a une note supérieure à l'étudiant en tête de liste, on le place en tête de liste.
    if(*DEB == 0 || note > VETU[*DEB].note){
        SUIVANT[*NBETU] = *DEB;
        *DEB = *NBETU;
    }else{
        //dans le cas contraire on va cherchez l'indice ou on doit placer l'élément 
        int i = *DEB;
        //on verifie qu'on est pas à la fin du tableau et que la note est supérieure à celle de l'étudiant qu'on insére
        while(SUIVANT[i] != -1 && VETU[SUIVANT[i]].note > note){
            //on passe au prochain élément
            i = SUIVANT[i];
        }
        //on intervrtit les deux valeurs
        SUIVANT[*NBETU] = SUIVANT[i];
        SUIVANT[i] = *NBETU;
    }

    (*NBETU)++;

    if ((*NBETU) >= 2)
    {
        printf("Ajout effectue avec succes!\n");
    }

    return 1;
}
int supprimerEtudiant(Etudiant* VETU, int* SUIVANT, int* NBETU, int* DEB, int numero) {
    if (*NBETU == 0) {
        printf("Erreur : Aucun étudiant à supprimer.\n");
        return 0;
    }

    int i = *DEB, avant = -1, trouve = -1;

    // Recherche de l'étudiant à supprimer et de son prédécesseur
    while (i != 0) { // On suit la chaîne jusqu'à trouver l'étudiant
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



int main() {
    int choix, numero;
    char nom[50];
    float note;

    do {
        printf("\nMenu:\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Supprimer un etudiant\n");
        printf("3. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Numero : ");
                scanf("%d", &numero);
                printf("Nom : ");
                scanf("%s", nom);
                printf("Note : ");
                scanf("%f", &note);
                ajouter_etudiant(numero, nom, note);
                break;
            
            case 2:
                printf("Numero de l'etudiant à supprimer : ");
                scanf("%d", &numero);
                supprimerEtudiant(numero);
                break;

            case 3:
                return 0;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 3);

    return 0;
}
