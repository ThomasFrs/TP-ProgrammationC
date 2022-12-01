#include <stdio.h>

void AfficherTab( int Tab[], int NbElt )
{
        for( int i = 0; i < NbElt ; i++ ) printf("%d%s", Tab[i], (i == NbElt - 1) ? "\n" : " ");
}

int Min( int Tab[], int NbElt)
{
        int min = Tab[0];
        for( int i = 0; i < NbElt ; i++ )
                if( Tab[i] < min ) min = Tab[i];
        return min;
}

int Max( int Tab[], int NbElt)
{
        int max = Tab[0];
        for( int i = 0; i < NbElt ; i++ )
                if( Tab[i] > max ) max = Tab[i];
        return max;
}

void MinMax( int Tab[], int NbElt, int *pMin, int *pMax)
{
        *pMin = Min(Tab, NbElt);
        *pMax = Max(Tab, NbElt);
}

int SupprimerVal( int Tab[], int *pNbElt, int Val)
{
        int suppressions = 0;
        for( int i = 0; i < *pNbElt-suppressions; i++ )
                if( Tab[i] == Val )
                {
                        for( int j = i; j < *pNbElt-1; j++ )
                        {
                                int temp = Tab[j+1];
                                Tab[j+1] = Tab[j];
                                Tab[j] = temp;
                        }
                        if( Tab[i] == Val ) i--;
                        suppressions++;
                }
        *pNbElt -= suppressions;
        return suppressions;
}

int main()
{
        int tableau[] = {1, 4, 4, 4, 2, 3, 4, 5, -1, 4, 4};
        int length = sizeof(tableau)/sizeof(int);

        printf("\nExercice 1.1\n");
        AfficherTab(tableau, length);

        printf("\nExercice 1.2\n");
        printf("Min = %d\n", Min(tableau, length));
        
        printf("\nExercice 1.3\n");
        printf("Max = %d\n", Max(tableau, length));

        printf("\nExercice 1.4\n");
        int min = 0, max = 0;
        printf("Min = %d, Max = %d\n", min, max);
        MinMax( tableau, length, &min, &max );
        printf("Min = %d, Max = %d\n", min, max);

        printf("\nExercice 1.5\n");
        AfficherTab( tableau, length );
        printf("Longueur = %d\n", length);
        printf("Suppressions = %d\n", SupprimerVal(tableau, &length, 4));
        printf("Nouvelle longeur = %d\n", length);
        AfficherTab(tableau, length);
        return 0;
}
