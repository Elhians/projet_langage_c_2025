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
void ajouter_etudiant(int numero, char nom[], float note) {
    if (NBETU >= MAX_ETUDIANTS) {
        printf("Erreur : Nombre maximal d'etudiants atteint.\n");
        return;
    }
    int i;
    for(i==0; i<NBETU; i++) {
        if (VETU[i].numero == numero) {
            printf("Erreur : Etudiant deja present.\n");
            return;
        }
    }
    // Ajouter l'étudiant à la fin du tableau
    VETU[NBETU].numero = numero;
    strcpy(VETU[NBETU].nom, nom);
    VETU[NBETU].note = note;

    NBETU++;
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
        // Si c'est le premier élément, on met à jour DEB
        *DEB = SUIVANT[trouve];
    } else {
        // Sinon, on relie le prédécesseur au suivant
        SUIVANT[avant] = SUIVANT[trouve];
    }

    // Vérifier si l'étudiant supprimé était le dernier dans la chaîne
    int dernier = *DEB;
    while (SUIVANT[dernier] != 0) { // Trouver le nouveau dernier
        dernier = SUIVANT[dernier];
    }
    SUIVANT[dernier] = 0; // Mettre à jour le dernier étudiant

    (*NBETU)--;

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
