#include <stdio.h>
#include <stdlib.h>

#define NBLIGMAX 100
#define NBCOLMAX 100

typedef unsigned char **Matrice;

Matrice MatAllouer(int NbLig, int NbCol)
{
        unsigned char *temp = malloc(NbLig * NbCol * sizeof(unsigned char));
        Matrice mat = malloc(NbLig * sizeof(unsigned char*));
        for( int i = 0; i < NbLig; i++ )
                mat[i] = &temp[i * NbCol];
        return mat;
}

Matrice MatLire(int *pNbLig, int *pNbCol)
{
        printf("Combien de lignes : "); scanf("%d", pNbLig);
        printf("Combien de colonnes : "); scanf("%d", pNbCol);
        Matrice mat = MatAllouer(*pNbLig, *pNbCol);
        for( int i = 0; i < *pNbLig; i++ )
                for( int j = 0; j < *pNbCol; j++ )
                        scanf("%hhu", &(mat[i][j]));
        printf("Lignes : %d, Colonnes : %d\n", *pNbLig, *pNbCol);
        return mat;
}
        

void MatAfficher(Matrice Mat, int NbLig, int NbCol)
{
        for( int i = 0; i < NbLig; i++ )
            for( int j = 0; j < NbCol; j++ )
                    printf("[%d]%s", Mat[i][j], ( j == NbCol-1 ) ? "\n" : "");
}
        
Matrice MatCopier(Matrice Mat, int NbLig, int NbCol)
{
        Matrice copie = MatAllouer(NbLig, NbCol);
        for( int i = 0; i < NbLig; i++ )
                for( int j = 0; j < NbCol; j++ )
                        copie[i][j] = Mat[i][j];
        return copie;
}

void MatLiberer(Matrice *pMat)
{
        
}

int main()
{
        int NbLig, NbCol;
        Matrice mat = MatLire(&NbLig, &NbCol);
        MatAfficher(mat, NbLig, NbCol);
        Matrice copie = MatCopier(mat, NbLig, NbCol);
        MatLiberer(&mat);
        return 0;
}
