#include "entete.h"

// char* toLowerCase(char* chaine, char* copieChaine);
char* firstInDictionnaryOrder(char* mot1, char* mot2);

int main(){
    
    char chaine1[] = "x";
    char chaine2[] = "y";

    printf("%s et %s -> %s\n", "chainea", "chaineb", firstInDictionnaryOrder("chainea", "chaineb"));
    
    return 0;
}

/* char* toLowerCase(char* chaine, char* copieChaine){

    for (int i = 0; chaine[i] != '\0'; i++)
    {
        copieChaine[i] = tolower(chaine[i]);
        
    }

    return copieChaine;
    
} */

char* firstInDictionnaryOrder(char* mot1,char* mot2){

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
    
}