/*7. La fonction
void supermatMat(SUPERMRT sm, doubLe *m, int nld, int ncd);
effectue la transformation supermatrice ® matrice. La matrice ordinaire, dont m représente l’adresse du premier élément
(dimension déclarée : nld ´ ncd) est garnie avec les coefficients de la supermatrice sm.
*/
void supermatMat(SUPERMRT sm,double *m, int nld, int ncd){

//on parcours les éléments de la supermatrice et on les affecte à notre matrice.
//ici on a considéré notre matrice comme un tableau unidimensionnel donc on le parcours avec un seul indice.
 for (int i = 0; i < nld; i++)
    {
	    for (int j = 0; j < ncd; j++){
	       m[i*ncd+j]=sm.ligne[i][j];
	    }   
    }
}

/*9. Pensez-vous qu’il est possible d’écrire une fonction qui serait la « réciproque » de aLLouerSupermat, c’est-à-dire qui libérerait l’espace occupé par la supermatrice indiquée.*/

void rendreSupermat(SUPERMRT sm){
 /*supermrt est l'adresse du descripteur de la matrice et celle ci contient déja le nombre de lignes et de colonnes.
  Donc on doit d'abord désallouer les lignes ensuite le tableau de pointeurs et enfin l'espace du descripteur.*/
  //on récupére le nombre de ligne de la supermatrice et la variable ligne aussi
    int nbrl=sm -> nl;
    double* *ligne=sm->ligne;
    //ensuite on parcours le tableau de pointeurs pour désallouer l'espace de toutes les lignes 
    int i=0;
     while (i < nbrl)
    {
        free(ligne[i]);
        i++;
    }
    //ensuite on désalloue l'espace du tableau de pointeurs lui même
    free (ligne);
    //on désalloue l'espace du descripteur de la supermatrice
    free(sm);
}

/*8. La fonction
int contiguite(SUPERMRT a);
analyse la supermatrice a et rend :
2 si les lignes de a sont contiguës et placées dans l’ordre des indices : la deuxième ligne suit la première, la troisième
suit la seconde, etc. ;
1 si les lignes de a sont contiguës mais dans le désordre ;
0 dans les autres cas.*/


int contiguite(SUPERMRT a) {
    //on récupére le nombre de lignes et de colonnes de la supermatrice
    int nbrl=a -> nl;
    int nbrc=a -> nc;
    double* *ligne=a->ligne;
    //pour chaque ligne de la supermatrice, vérifie si son adresse + le nombre de colonne est égal à celle de la prochaine ligne du tableau de pointeurs,ce qui vérifie la contiguité
    for (int i = 0; i < nbrl-1; i++){
      if(ligne[i]+nbrc!=ligne[i+1]){
         return 1;
        }
    }
    return 2;
}