#ifndef __MATRICE_H__
#define __MATRICE_H__

typedef unsigned char ** Matrice;

//Exercice 1
extern Matrice MatAllouer(int NbLig, int NbCol);

extern Matrice MatLire(int*pNbLig, int *pNbCol);

extern void MatAfficher(Matrice Mat, int NbLig, int NbCol);

extern Matrice MatCopier(Matrice Mat, int NbLig, int NbCol);

extern void MatLiberer(Matrice *pMat);

#endif
