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
    int trouve = -1;
    int precedent = -1;
    int actuel = *DEB;
    
    // Recherche de l'étudiant à supprimer
    while (actuel != -1) {
        if (VETU[actuel].numero == numero) {
            trouve = actuel;
            break;
        }
        precedent = actuel;
        actuel = SUIVANT[actuel];
    }
    
    if (trouve == -1) {
        printf("Etudiant avec numero %d non trouvé.\n", numero);
        return 0;
    }
    
    // Suppression de l'étudiant de la liste chaînée
    if (precedent == -1) {
        *DEB = SUIVANT[trouve];
    } else {
        SUIVANT[precedent] = SUIVANT[trouve];
    }
    
    // Compacter le tableau VETU
    for (int i = trouve; i < *NBETU - 1; i++) {
        VETU[i] = VETU[i + 1];
    }
    
    // Mise à jour des indices dans SUIVANT
    for (int i = 0; i < *NBETU; i++) {
        if (SUIVANT[i] > trouve) {
            SUIVANT[i]--;
        } else if (SUIVANT[i] == trouve) {
            if (trouve == *NBETU - 1) {
                SUIVANT[i] = -1;
            } else {
                SUIVANT[i] = trouve;
            }
        }
    }
    
    // Ajustement du début si nécessaire
    if (*DEB > trouve) {
        (*DEB)--;
    }
    
    (*NBETU)--;
    
    printf("Suppression réussie de l'étudiant avec numero %d.\n", numero);
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
