#include "entete.h"

int main(){
    Etudiant etudiants[] = {
        {000, "", 0.0},
        {101, "David", 18.2},
        {102, "Alice", 12.5},
        {103, "Charlie", 9.0},
        {104, "Eve", 14.8},
        {105, "Bob", 15.0}
    };
    int DEB = 1;
    int SUIVANT[] = {0,5,3,0,2,4};
    int tab[6];

    affichageAleatoire(etudiants, 6);
    //afficherParOrdreAlphabetique(etudiants, 6);

    //affichageParOrdreDeMerite(etudiants, SUIVANT, 6, DEB);

    //printf("%d\n", firstInDictionnaryOrder("Alice", "David"));
    
    return 0;
}


/* char* firstInDictionnaryOrder(char* mot1,char* mot2){

    int i = 0, s1 = 0, s2 = 0;

    while(mot1[i] != '\0' || mot2[i] != '\0'){
        s1 += tolower(mot1[i]);
        s2 += tolower(mot2[i]);
        if (s1 > s2)
        {
            return mot2;
        }
        if (s2 > s1)
        {
            return  mot1;
        }
        
        i++;
    }
    return mot1;
    
} */