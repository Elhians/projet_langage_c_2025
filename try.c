#include "supermatrice.h"

int main(){
    
    SUPERMRT a = allouerSupermat(5,2);

    printf("%lf\n", acces(a,1,1));

    ACCES(a,1,1) = 4.2;

    
    printf("%lf\n", acces(a,1,1));

    SUPERMRT b = allouerSupermat(2,5);

    SUPERMRT d = superProduit(a,b);

    printf("%lf\n", acces(d,1,1));

    return 0;
}

