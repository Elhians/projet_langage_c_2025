#ifndef SUPERMATRICE_H
#define SUPERMATRICE_H

typedef struct {
    int nl;
    int nc;
    double **ligne;
} descripteur;

typedef descripteur* SUPERMRT;

#endif /* SUPERMATRICE_H */
