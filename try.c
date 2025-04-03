
#include "supermatrice.h"

int main(){
    
    descripteur* desc = allouerSupermat(5,2);

    /* double t1 = {1,2};
    double t2 = {3,4};
    double t3 = {5,6};
    double t4 = {7,8};
    double t5 = {9,10};

    double* tab[5] = {t1,t2,t3,t4,t5}; */

    double* tab = desc->ligne ;

    double t1[] = tab[0];
    double t2[]= tab[1];
    double t3[] = tab[2];
    double t4[]= tab[3];
    double t5[] = tab[4];


    t1[0] = 0;
    t2[0] = 0;
    t3[0] = 0;
    t4[0] = 0;
    t5[0] = 0;

    t1[1] = 0;
    t2[1] = 0;
    t3[1] = 0;
    t4[1] = 0;
    t5[1] = 0;

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