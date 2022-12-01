#include <stdio.h>
#include <math.h>

void exercice1()
{
        unsigned int length;
        double moyenne = 0;
        printf("Entrez le nombre de valeurs : ");
        scanf("%d", &length);
        
        double valeurs[length];
        for( int i = 0; i < length; i++ )
        {
                printf("Entrez la valeur (%d/%d) : ", i+1, length);
                scanf("%lf", &valeurs[i]);
                moyenne += valeurs[i]; 
        }
        moyenne /= length;
        printf("Moyenne : %lf\n", moyenne);
        
        for( int i = 0; i < length; i++ )
            if( valeurs[i] > moyenne ) printf("%d: %lf\n", i, valeurs[i]);
}



int exercice2()
{
        int ordre;
        do
                printf("Entrez l'ordre de la matrice carrée : ");
        while( !(scanf("%d", &ordre) && ordre <= 10) );
        
        double matrice[ordre][ordre];        
        for( int i = 0; i < ordre; i++ )
        {
                printf("Ligne %d : ", i+1);
                for( int j = 0; j < ordre; j++ ) scanf("%lf", &matrice[i][j]);
        }
        
        double ecart = 10E-10;        
        for( int i = 0; i < ordre; i++ )
                for( int j = 0; j < ordre; j++ )
                {
                        if( fabs(matrice[i][j] - matrice[j][i]) < ecart )
                        {
                                if( i == ordre-1 && j == ordre-1) printf("Cette matrice est symetrique\n");
                        }
                        else
                        {
                            printf("Cette matrice n'est pas symetrique\n");
                            return 0;
                        }
                }
        return 1;
}


void exercice3()
{
        char chaine[80], i = 0;
        while( i < 80 && scanf("%c", &chaine[i]) && (( chaine[i] >= 'a' && chaine[i] <= 'z' ) || chaine[i] == ' ')) i++;
        
        int palindrome = 1;
        for( int j = 0; j < i; j++ )
        {
                printf("%c", chaine[j]);
                if( chaine[j] != chaine[i-j-1] ) palindrome = 0;
        }
                
        printf("\nLa chaine contient %d caracteres\n", i);
        printf("La chaine %sest %sun palindrome\n", (palindrome == 1) ? "" : "n'", (palindrome == 1) ? "" : "pas "); 
        
}


int main()
{
        exercice3();
        return 0;
}
