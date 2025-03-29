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
void supprimerEtudiant(int numero) {
    int i, trouve = -1;

    // Trouver l'étudiant  à supprimer dans le tableau
    for (i = 0; i < NBETU; i++) {
        if (VETU[i].numero == numero) {
            trouve = i;
            break;
        }
    }

    // Si l'étudiant n'est pas trouvé,on quitte
    if (trouve == -1) {
        printf("Étudiant non trouvé.\n");
        return;
    }

    // Décaler les éléments vers la gacuhe à partir de l'élément à suppimer pour ecraser sa valeur
    for (i = trouve; i < NBETU - 1; i++) {
        VETU[i] = VETU[i + 1];
    }
    NBETU--;
    printf("Suppression réussie.\n");
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
