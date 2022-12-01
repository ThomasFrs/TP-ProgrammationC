#include <stdio.h>
#include "matrice.h"

int main()
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

        return 0;
}
