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

    VETU[NBETU].numero = numero;
    strcpy(VETU[NBETU].nom, nom);
    VETU[NBETU].note = note;

    NBETU++;
}
void supprimerEtudiant(int numero) {
    int i, trouve = -1;

    // Trouver l'étudiant dans le tableau
    for (i = 0; i < NBETU; i++) {
        if (VETU[i].numero == numero) {
            trouve = i;
            break;
        }
    }

    // Si l'étudiant n'est pas trouvé
    if (trouve == -1) {
        printf("Étudiant non trouvé.\n");
        return;
    }

    // Décaler les éléments pour combler le trou
    for (i = trouve; i < NBETU - 1; i++) {
        VETU[i] = VETU[i + 1];
    }

    // Réduire le nombre d'étudiants
    NBETU--;
    printf("Suppression réussie.\n");
}
int chargerEtudiant(){
    FILE *f = fopen("etudiants.dat", "rb");//un fichier binaire (rb et wb)? pcq Contrairement à un fichier texte, un fichier binaire stocke les structures C telles qu'elles sont en mémoire, sans avoir à les convertir en chaînes de caractères.
    if(f==NULL){
        printf("Erreur d'ouverture du fichier ou fichier inexistant\n");
    }
    //fread permet de lire des données binaires à partir d'un fichier
    fread(&NBETU, sizeof(int), 1, f);
    // Sauvegarder les étudiants
    fread(VETU, sizeof(Etudiant), MAX_ETUDIANTS, f);
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
    fclose(f);
}

int main() {
    int choix, numero;
    char nom[50];
    float note;
    chargerEtudiant();

    do {
        printf("\nMenu:\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Supprimer un etudiant\n");
        printf("3. Afficher les etudiants\n");
        printf("4. Sauvegarder et quitter\n");

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
                printf("Liste des etudiants :\n");
                for (int i = 0; i < NBETU; i++) {
                    printf("Numero: %d, Nom: %s, Note: %.2f\n", VETU[i].numero, VETU[i].nom, VETU[i].note);
                }
                break;
                return 0;
            case 4:
                sauvegarderEtudiant();
                printf("Sauvegarde réussie. Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 4);

    return 0;
}
