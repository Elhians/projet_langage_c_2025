#ifndef _ENTETE_H
#define _ENTETE_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<strings.h>
#include<time.h>
#include<ctype.h>
#include<unistd.h>

void vider_buffer();
int saisir_texte(char *chaine, long longueur_chaine);
int saisir_long(char *chaine, long longueur_chaine);
int saisir_double(char *chaine, long longueur_chaine);

#endif