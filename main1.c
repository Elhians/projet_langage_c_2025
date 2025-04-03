#include"partie1.h"

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
        printf("5. Afficher les etudiants par ordre de mérite\n");
        printf("6. Afficher les etudiants par ordre alphabetique\n");
        printf("7. Afficher les etudiants de facon aleatoire\n");

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
            case 5:
                affichageParOrdreDeMerite();
                break;
            case 6:
                afficherParOrdreAlphabetique(VETU, NBETU);
                break;
            case 7:
                affichageAleatoire();
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 4);

    return 0;
}
