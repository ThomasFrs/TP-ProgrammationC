#include "matrice.h"

#ifndef __IMAGE_H__
#define __IMAGE_H__

typedef struct sImage *Image;

extern Image ImAllouer(int NbLignes, int NbColonnes);

extern void ImLiberer(Image *pIm);

extern int ImNbLig(Image Im);

extern int ImNbCol(Image Im);

extern Matrice ImNivGris(Image Im);

extern Image ImLire(char NomFichier[]);

extern void ImEcrire(Image Im, char NomFichier[]);

extern Image ImRotation(Image Im);

#endif
