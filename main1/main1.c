#include "partie1.h"

void menuPrincipale(){

        printf("\nMenu:\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Supprimer un etudiant\n");
        printf("3. Afficher les etudiants\n");
        printf("4. Afficher les etudiants par ordre de mérite\n");
        printf("5. Afficher les etudiants par ordre alphabetique\n");
        printf("6. Afficher les etudiants de facon aleatoire\n");
        printf("7. Sauvegarder et quitter\n");

        printf("Choix : ");
}


int main(){

    int numero = 0;
    int choix = 0;
    int NBETU = 1;
    float note = 0;
    char nom[50] = "";

    Etudiant* VETU = calloc(sizeof(Etudiant), MAX_ETUDIANTS);
    int DEB = 0;
    int* SUIVANT = calloc(sizeof(int), MAX_ETUDIANTS);

    if (VETU == NULL || SUIVANT == NULL)
    {
        fputs("ERREUR!\n", stderr);
        exit(EXIT_FAILURE);
    }

    chargerEtudiant(VETU, &NBETU, SUIVANT, &DEB);

    do{
        menuPrincipale();
        scanf("%d", &choix);
        vider_buffer();

        switch (choix) {
            
            case 1:
                
                printf("Numero : ");
                scanf("%d", &numero);
                vider_buffer();

                printf("Nom : ");
                fgets(nom, 50, stdin);

                printf("Note : ");
                scanf("%g", &note);
                vider_buffer();

                ajouterEtudiant(VETU, SUIVANT, &NBETU, &DEB, numero, nom, note);

                break;
            
            case 2:

                printf("Numero de l'etudiant à supprimer : ");

                scanf("%d", &numero);
                vider_buffer();

                supprimerEtudiant(VETU, &NBETU, numero);
                break;
            
            case 3:

                printf("Liste des etudiants :\n");

                for (int i = 1; i < NBETU; i++) {
                    printf("Numero: %d, Nom: %s, Note: %g\n", VETU[i].numero, VETU[i].nom, VETU[i].note);
                }

                printf("Nombre d'etudiants: %d\n", NBETU - 1);
                
            break;

            case 4:

                affichageParOrdreDeMerite(VETU, SUIVANT, NBETU, DEB);
                printf("Nombre d'etudiants: %d\n", NBETU - 1);
                break;

            case 5:

                trierParOrdreAlphabetique(VETU, NBETU);
                printf("Nombre d'etudiants: %d\n", NBETU - 1);
                break;

            case 6:

                affichageAleatoire(VETU, NBETU);
                printf("Nombre d'etudiants: %d\n", NBETU - 1);
                break;
            case 7:

                sauvegarderEtudiant(VETU, &NBETU, SUIVANT, &DEB);
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide.\n");
                break;
        }

    } while(choix != 7);

    free(VETU);
    free(SUIVANT);
    return 0;
}