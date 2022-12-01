#include <stdio.h>
#include <stdlib.h>

//Exercice 1
typedef unsigned char ** Matrice;

Matrice MatAllouer(int NbLig, int NbCol)
{
    Matrice M = malloc (NbLig * sizeof(unsigned char*));

    if (M == NULL)return NULL;

    unsigned char * tab = malloc(NbLig * NbCol * sizeof(unsigned char));

    if (tab == NULL) return NULL;
    for (int i = 0; i < NbLig; i++) M[i] = &(tab[i*NbCol]);
    return M;
}

void MatLiberer(Matrice *pMat)
{
    free(**pMat);
    free(*pMat);
    (*pMat) = NULL;
}

Matrice Triangle(int n)
{
        Matrice mat = MatAllouer(n, n);
        for( int i = 0; i < n; i++ )
        {
                mat[i][0] = 1;
                mat[i][i] = 1;
        }
        
        for( int i = 1; i < n; i++ )
                for( int j = 1; j < n; j++ )
                {
                        mat[i][j] = mat[i-1][j-1] + mat[i-1][j];
                }
        
        return mat;
}

void AffTriangle(Matrice A, int NbLig)
{
        for( int i = 0; i < NbLig; i++ )
                for( int j = 0; j <= i; j++ )
                        printf("%hhu%s", A[i][j], (j == i) ? "\n" : " ");
}

//Exercice 2
void Trier(int Tab[], int NbElts)
{
        for( int i = 0; i < NbElts; i++ )
        {
                for( int j = 0; j < NbElts - i - 1; j++ )
                {
                        if( Tab[j+1] < Tab[j] )
                        {
                                int temp = Tab[j];
                                Tab[j] = Tab[j+1];
                                Tab[j+1] = temp;
                        }
                }
        }
}
        
void Aff(int Tab[], int NbElts)
{
        for( int i = 0; i < NbElts; i++ ) printf("%d ", Tab[i]);
        printf("\n");
}

void TrierPtr(int Tab[], int NbElts, int *Ptr[])
{
        for( int i = 0; i < NbElts; i++ ) Ptr[i] = &Tab[i];
        Trier(*Ptr, NbElts);
}

int ** TrierPtr2(int Tab[], int NbElts)
{
        int **tabPtr = malloc( NbElts * sizeof(int *));
        for( int i = 0; i < NbElts; i++)
                *(tabPtr + i*sizeof(int)) = &Tab[i];
        Trier(*tabPtr, NbElts);
        return tabPtr;
}

void TrierPtr3(int Tab[], int NbElts, int *TabPtr);
        

void AffPtr(int *TabP[], int NbElts)
{
        for( int i = 0; i < NbElts; i++ ) printf("%d ", *TabP[i]);
        printf("\n");
}

int main()
{
        int NbLig; printf("Entrez le nombre de lignes : "); scanf("%d", &NbLig);
        Matrice triangle = Triangle(NbLig);
        AffTriangle(triangle, NbLig);
        MatLiberer(&triangle);
       
        int tab[] = {5, 2, 3, 4, 1, 0, 6, 9, 8}, len = sizeof(tab)/sizeof(int);
        Trier(tab, len);
        Aff(tab, len);
        
        int * TableauP[len];
        TrierPtr(tab, len, TableauP);
        AffPtr(TableauP, len);
        
        int ** tabPtr2 = TrierPtr2(tab, len);
        return 0;
}
