#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NBETU 100

typedef struct {
    int num;
    char nom[10]; 
    float note;
} Etudiant;
Etudiant VETU[NBETU];
int chargerEtudiant();
void sauvegarderEtudiant();

//test des deux fonctions
int main(int argc, char const *argv[])
{   
    int sortie = chargerEtudiant();
        
    if(sortie==1){
        printf("Apres l'affectation: \n");
        for(int i=0; i<NBETU; i++){
            if(i!=0 && VETU[i].num==0)
                continue;
            printf("%d %s %.2f\n", VETU[i].num, VETU[i].nom, VETU[i].note);
        }
    }
    
    //test de la fonction chargerEtudiant
    VETU[0] = (Etudiant){0, "", 0.0};//conversion en Etudiant avant affcectation
    VETU[1] = (Etudiant){2, "David", 15.5};
    VETU[2] = (Etudiant){3, "Alice", 10.5};
    VETU[3] = (Etudiant){4, "Charlie", 14.5};
    VETU[4] = (Etudiant){5, "Eve", 13.5};
    VETU[5] = (Etudiant){6, "Bob", 11.5};

    sauvegarderEtudiant();

    return 0;
}

//fonction pour charger les etudiants en memoire
int chargerEtudiant(){
    FILE *f = fopen("etudiants.dat", "rb");//un fichier binaire (rb et wb)? pcq Contrairement à un fichier texte, un fichier binaire stocke les structures C telles qu'elles sont en mémoire, sans avoir à les convertir en chaînes de caractères.
    if(f==NULL){
        printf("Erreur d'ouverture du fichier ou fichier inexistant\n");
        return -1;
    }
    //fread permet de lire des données binaires à partir d'un fichier
    fread(VETU, sizeof(Etudiant), NBETU, f);
    fclose(f);
    return 1;
}

//fonction pour sauvegarder les etudiants dans notre fichier
void sauvegarderEtudiant(){
    FILE *f = fopen("etudiants.dat", "wb");
    if(f==NULL){
        printf("Erreur d'ouverture du fichier\n");
        return;
    }
    //fwrite permet d'écrire des données binaires dans un fichier
    fwrite(VETU,sizeof(Etudiant),NBETU,f);
    fclose(f);
}