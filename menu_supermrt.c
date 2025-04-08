#include <stdio.h>
#include <stdlib.h>
#include "supermatrice.h" 

// 1. Fonction allouerSupermat
SUPERMRT allouerSupermat(int nl, int nc) {
    if (nl <= 0 || nc <= 0) {
        fputs("ERREUR! VALEUR INCORRECTE POUR LE NOMBRE DE LIGNE OU LE NOMBRE DE COLONNE.\n", stderr);
        exit(EXIT_FAILURE);
    }
    
    int i = 0;
    double **ligne = malloc(sizeof(double*) * nl);
    if (ligne == NULL) {
        fputs("ERREUR LORS DE L'ALLOCATION DU TABLEAU DE LIGNE!\n", stderr);
        exit(EXIT_FAILURE);
    }
    
    descripteur *pdesc = malloc(sizeof(descripteur));
    if (pdesc == NULL) {
        fputs("ERREUR LORS DE L'ALLOCATION DU DESCRIPTEUR!\n", stderr);
        free(ligne);
        exit(EXIT_FAILURE);
    }
    
    while (i < nl) {
        ligne[i] = malloc(sizeof(double) * nc);
        if (ligne[i] == NULL) {
            fputs("ERREUR LORS DE L'ALLOCATION DES LIGNES!\n", stderr);
            // Correction : libérer toutes les lignes déjà allouées
            for (int j = 0; j < i; j++) {
                free(ligne[j]);
            }
            free(ligne);
            free(pdesc);
            exit(EXIT_FAILURE);
        }
        i++;
    }
    
    // Définition du descripteur
    pdesc->nl = nl;
    pdesc->nc = nc;
    pdesc->ligne = ligne;
    
    return pdesc;
}

// 2. Fonction acces
double acces(SUPERMRT a, int i, int j) {
    if (a == NULL) {
        fputs("Le supermrt n'existe pas.\n", stderr);
        exit(EXIT_FAILURE);
    }
    if (i < 0 || i >= a->nl || j < 0 || j >= a->nc) {
        fputs("Cet element n'existe pas.\n", stderr);
        exit(EXIT_FAILURE);
    }
    return a->ligne[i][j];
}

// 3. Fonction permuterLignes
void permuterLignes(SUPERMRT a, int i, int j) {
    if (i <= 0 || j <= 0 || a == NULL || a->nl < i || a->nl < j) { // indices non valides
        printf("Erreur : Les donnees saisies sont erronees\n");
        return;
    }
    // Conversion : de l'indice usager (commence à 1) vers l'indice tableau (commence à 0)
    i = i - 1;
    j = j - 1;
    int nbrColonnes = a->nc;
    // Correction : accès correct aux lignes
    double* pi = a->ligne[i];
    double* pj = a->ligne[j];
    for (int k = 0; k < nbrColonnes; k++) {
        double temp = pi[k];
        pi[k] = pj[k];
        pj[k] = temp;
    }
    printf("Les lignes %d et %d ont ete permutees avec succes\n", i + 1, j + 1);
}

// 4. Fonction sousMatrice
SUPERMRT sousMatrice(SUPERMRT a, int l1, int l2, int c1, int c2) {
    
    SUPERMRT newA = (SUPERMRT)malloc(sizeof(descripteur));
    if(newA == NULL){
        fputs("ERREUR LORS DE L'ALLOCATION DU DESCRIPTEUR DE LA SOUS-MATRICE\n", stderr);
        exit(EXIT_FAILURE);
    }
    newA->nl = l2 - l1 + 1;
    newA->nc = c2 - c1 + 1;
    // Correction : allocation correcte pour un tableau de pointeurs
    newA->ligne = malloc(newA->nl * sizeof(double*));
    if(newA->ligne == NULL){
        fputs("ERREUR LORS DE L'ALLOCATION DU TABLEAU DE LIGNE POUR LA SOUS-MATRICE\n", stderr);
        free(newA);
        exit(EXIT_FAILURE);
    }
    l1 = l1 - 1; // conversion indice usager -> indice tableau
    c1 = c1 - 1;
    for (int i = 0; i < newA->nl; i++) {
        // La sous-matrice pointe sur les éléments de la matrice d'origine
        newA->ligne[i] = a->ligne[l1] + c1;
        l1 = l1 + 1;
    }
    return newA;
}

// 5. Fonction matSupermat
SUPERMRT matSupermat(double *m, int nld, int ncd, int nle, int nce) {
    SUPERMRT superMat = (SUPERMRT)malloc(sizeof(descripteur));
    if(superMat == NULL){
        fputs("ERREUR LORS DE L'ALLOCATION DU DESCRIPTEUR POUR matSupermat\n", stderr);
        exit(EXIT_FAILURE);
    }
    // Correction : allocation d'un tableau de pointeurs
    superMat->ligne = malloc(nle * sizeof(double*));
    if(superMat->ligne == NULL){
        fputs("ERREUR LORS DE L'ALLOCATION DU TABLEAU DE LIGNE POUR matSupermat\n", stderr);
        free(superMat);
        exit(EXIT_FAILURE);
    }
    superMat->nl = nle;
    superMat->nc = nce;
    double *temp = m;
    for (int i = 0; i < nle; i++) {
        superMat->ligne[i] = temp;
        temp += ncd;
    }
    return superMat;
}

// 6. Fonction supermatMat
void supermatMat(SUPERMRT sm, double *m, int nld, int ncd) {
    for (int i = 0; i < nld; i++) {
        for (int j = 0; j < ncd; j++) {
            m[i * ncd + j] = sm->ligne[i][j];
        }
    }
}

// 7. Fonction contiguite
int contiguite(SUPERMRT a) {
    int nbrl = a->nl;
    int nbrc = a->nc;
    double **ligne = a->ligne;
    for (int i = 0; i < nbrl - 1; i++) {
        if (ligne[i] + nbrc != ligne[i + 1]) {
            return 1;
        }
    }
    return 2;
}

// Fonction rendreSupermat (libération de la supermatrice)
// Bien que cette fonction ne fasse pas partie du "menu" demandé (question 9), 
// elle est utile pour libérer l'espace alloué.
void rendreSupermat(SUPERMRT sm) {
    int nbrl = sm->nl;
    double **ligne = sm->ligne;
    for (int i = 0; i < nbrl; i++) {
        free(ligne[i]);
    }
    free(ligne);
    free(sm);
}

// Fonction pour afficher une matrice (pour tests)
void afficherMatrice(SUPERMRT m) {
    if(m == NULL) return;
    for (int i = 0; i < m->nl; i++) {
        for (int j = 0; j < m->nc; j++) {
            printf("%lf ", m->ligne[i][j]);
        }
        printf("\n");
    }
}

// Fonction pour initialiser la supermatrice avec des valeurs croissantes (pour tests)
void remplirMatrice(SUPERMRT m) {
    int value = 1;
    for (int i = 0; i < m->nl; i++) {
        for (int j = 0; j < m->nc; j++) {
            m->ligne[i][j] = value++;
        }
    }
}

//////////////////////////
// Menu principal
//////////////////////////
int main() {
    int choix;
    int nl, nc;
    SUPERMRT sm = NULL, sm2 = NULL;
    double *mat;
    int i, j, l1, l2, c1, c2;

    do {
        printf("\n---------- Menu ----------\n");
        printf("1. Allouer une supermatrice et remplir\n");
        printf("2. Acceder a un element d'une supermatrice\n");
        printf("3. Permuter deux lignes d'une supermatrice\n");
        printf("4. Extraire une sous-matrice\n");
        printf("5. Creer une supermatrice a partir d'une matrice\n");
        printf("6. Copier une supermatrice dans une matrice classique\n");
        printf("7. Tester la contiguite des lignes\n");
        printf("8. Liberer la supermatrice allouee\n");
        printf("0. Quitter\n");
        printf("-------------------------\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez le nombre de lignes et de colonnes : ");
                scanf("%d %d", &nl, &nc);
                // Allocation
                sm = allouerSupermat(nl, nc);
                remplirMatrice(sm);
                printf("Supermatrice allouee et remplie:\n");
                afficherMatrice(sm);
                break;
            case 2:
                if (sm == NULL) {
                    printf("Pas de supermatrice allouee. Veuillez choisir l'option 1 d'abord.\n");
                    break;
                }
                printf("Entrez les indices (ligne et colonne) (en commencant a 0) : ");
                scanf("%d %d", &i, &j);
                printf("L'element a[%d][%d] vaut %lf\n", i, j, acces(sm, i, j));
                break;
            case 3:
                if (sm == NULL) {
                    printf("Pas de supermatrice allouee. Veuillez choisir l'option 1 d'abord.\n");
                    break;
                }
                printf("Entrez les numéros des deux lignes a permuter (commencent a 1) : ");
                scanf("%d %d", &i, &j);
                permuterLignes(sm, i, j);
                printf("Matrice apres permutation:\n");
                afficherMatrice(sm);
                break;
            case 4:
                if (sm == NULL) {
                    printf("Pas de supermatrice allouee. Veuillez choisir l'option 1 d'abord.\n");
                    break;
                }
                printf("Entrez les bornes l1, l2, c1 et c2 (lignes et colonnes, indices debutant a 1) : ");
                scanf("%d %d %d %d", &l1, &l2, &c1, &c2);
                sm2 = sousMatrice(sm, l1, l2, c1, c2);
                printf("Sous-matrice extraite:\n");
                afficherMatrice(sm2);
                // Attention : dans ce cas, la sous-matrice n'a pas ses propres allocations pour les lignes, ne pas liberer sm2->ligne !
                free(sm2);  // Seul le descripteur a été alloue dynamiquement dans sousMatrice.
                break;
            case 5:
                printf("Création d'une matrice classique pour test\n");
                printf("Entrez les dimensions de la matrice (nld ncd) et de la supermatrice (nle nce) : ");
                scanf("%d %d %d %d", &nl, &nc, &l1, &c1);
                // Allocation d'une matrice dynamique classique (tableau unidimensionnel)
                mat = malloc(nl * nc * sizeof(double));
                if(mat == NULL){
                    fputs("Erreur d'allocation de la matrice classique\n", stderr);
                    exit(EXIT_FAILURE);
                }
                // Remplissage de la matrice classique avec des valeurs
                for (i = 0; i < nl * nc; i++) {
                    mat[i] = i + 1;
                }
                sm2 = matSupermat(mat, nl, nc, l1, c1);
                printf("Supermatrice creee a partir de la matrice classique:\n");
                afficherMatrice(sm2);
                free(mat);
                // On libère la structure de sm2 mais pas les lignes car elles pointent dans mat
                free(sm2->ligne);
                free(sm2);
                break;
            case 6:
                if (sm == NULL) {
                    printf("Pas de supermatrice allouee. Veuillez choisir l'option 1 d'abord.\n");
                    break;
                }
                // Copier la supermatrice dans une matrice classique
                printf("Copie de la supermatrice dans une matrice classique.\n");
                mat = malloc(sm->nl * sm->nc * sizeof(double));
                if(mat == NULL){
                    fputs("Erreur d'allocation pour la matrice classique\n", stderr);
                    exit(EXIT_FAILURE);
                }
                supermatMat(sm, mat, sm->nl, sm->nc);
                printf("Matrice classique obtenue:\n");
                for (i = 0; i < sm->nl; i++) {
                    for (j = 0; j < sm->nc; j++) {
                        printf("%lf ", mat[i * sm->nc + j]);
                    }
                    printf("\n");
                }
                free(mat);
                break;
            case 7:
                if (sm == NULL) {
                    printf("Pas de supermatrice allouee. Veuillez choisir l'option 1 d'abord.\n");
                    break;
                }
                if (contiguite(sm) == 2)
                    printf("Les lignes de la supermatrice sont contigues et bien ordonnees.\n");
                else
                    printf("Les lignes de la supermatrice sont contigues mais dans le desordre (ou non contigues).\n");
                break;
            case 8:
                if (sm == NULL) {
                    printf("Aucune supermatrice a liberer.\n");
                    break;
                }
                rendreSupermat(sm);
                sm = NULL;
                printf("Supermatrice liberee avec succes.\n");
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 0);

    return 0;
}
