
#include "supermatrice.h"

int main(){
    
    descripteur* desc = allouerSupermat(5,2);

    double t1[2] = {1,2};
    double t2[2] = {3,4};
    double t3[2] = {5,6};
    double t4[2] = {7,8};
    double t5[2] = {9,10};

    double* tab[5] = {t1,t2,t3,t4,t5};

    desc->ligne = tab;

    printf("%p\n", desc);
    printf("%d\n", desc->nl);
    printf("%d\n", desc->nc);
    printf("%p\n", desc->ligne);
    
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