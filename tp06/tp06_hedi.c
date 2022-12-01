#include <stdio.h>
#include <stdlib.h>

typedef unsigned char ** Matrice;

//Exercice 1
Matrice MatAllouer(int NbLig, int NbCol)
{
    Matrice M = malloc (NbLig * sizeof(unsigned char*));

    if (M == NULL)
    {
        return NULL;
    }

    unsigned char * tab = malloc(NbLig*NbCol*sizeof(unsigned char));

    if (tab == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < NbLig; i++)
    {
        M[i] = &(tab[i*NbCol]);

    }
    return M;
}

//Exercice 2
Matrice MatLire(int*pNbLig, int *pNbCol)
{
    Matrice M;
    M = MatAllouer(*pNbLig, *pNbCol);

    for (int i = 0; i < *pNbLig; i++)
    {
        for (int j = 0; j < *pNbCol; j++)
        {
            printf("Valeur pour [%d][%d] : \n", i, j);
            scanf("%hhu", &(M[i][j]));
        }

    }
    return M;
    
}

//Exercice 3
void MatAfficher(Matrice Mat, int NbLig, int NbCol)
{
    for (int i = 0; i < NbLig; i++)
    {
        for (int j = 0; j < NbCol; j++)
        {
            printf("[%d][%d] = %d \n", i, j, Mat[i][j]);
        }
        
    }
}

//Exercice 4
Matrice MatCopier(Matrice Mat, int NbLig, int NbCol)
{
    Matrice M_temp;
    M_temp = MatAllouer(NbLig, NbCol);

    for (int i = 0; i < NbLig; i++)
    {
        for (int j = 0; j < NbCol; j++)
        {
            M_temp[i][j] = Mat[i][j];
        }

    }
    printf("La matrice copiée : \n");
    return M_temp;
}

//Exercice 5
void MatLiberer(Matrice *pMat)
{
    free(**pMat);
    free(*pMat);
    (*pMat) = NULL;
}

int main (void)
{
    Matrice M = NULL;
    int NbLig;
    int NbCol;

    printf("Taille de la matrice : \n");
    scanf("%1d %1d", &NbLig, &NbCol);

    M = MatLire(&NbLig, &NbCol);
    printf("La matrice : \n");
    MatAfficher(M, NbLig, NbCol);
    printf("\n");

    Matrice M_temp = NULL;

    printf("\n");

    M_temp = MatCopier(M, NbLig, NbCol);
    MatAfficher(M_temp, NbLig, NbCol);

    MatLiberer(&M);
    printf("\n");
    printf("%p", M);
    printf("\n");

    M = Permutelignes(M, 1, 2, NbLig, NbCol);
    printf("\n");


    return 0;
}
