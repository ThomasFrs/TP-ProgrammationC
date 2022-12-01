#include <stdio.h>

void exercice1()
{
        int year;
        printf("Entrez une annee : ");
        scanf("%d", &year);
        printf("%d %s\n", year, ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? "est bissextile" : "n'est pas bissextile");
}

void exercice2merdique()
{
        char texte[1000], voyelles_array[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
        int i = 0, lettres = 0, voyelles = 0;
        while( scanf("%c", &texte[i]) && texte[i++] != '#')
        {
                if( texte[i] != ' ' && ( texte[i] < 'a' || texte[i] > 'z')) printf("%c, %d", texte[i], texte[i]);
        }
        for( int j = 0; j < i; j++ )
        {
                if( texte[j] >= 'a' && texte[j] <= 'z')
                {
                        lettres++;
                        int k_count = 0;
                        for( int k = 0; k < 6; k++ )
                        {
                                if( texte[j] != voyelles_array[k]) k_count++;
                        }
                        if( k_count == 5) voyelles++;
                }
        }
        printf("%d lettres | %d voyelles\n", lettres, voyelles);
}

void exercice2()
{
        int voyelles = 0, lettres = 0;
        char voyelles_liste[6] = {'a', 'e', 'i', 'o', 'u', 'y'}; 
        
        char c;
        while( scanf("%c", &c) && c != '#')
        {
                if( (c <= 'a' || c >= 'z') && c != ' ') 
                {
                        printf("%c is not a valid input\n", c);
                        break;
                }
                else if( c >= 'a' && c <= 'z' )
                {
                        lettres++;
                        
                        int voyelles_liste_index = 0;
                        for( int i = 0; i < 6 ; i++ )
                                if( c != voyelles_liste[i] ) voyelles_liste_index++;
                        
                        if( voyelles_liste_index == 5) voyelles++;
                }
        }
        printf("%d lettres | %d voyelles\n", lettres, voyelles);
}

void exercice3()
{
        int valeurs;
        printf("How many values do you want : ");
        scanf("%d", &valeurs);
        
        double array[valeurs];
        for( int i = 0; i < valeurs ; i++ )
        {
                printf("Enter number (%d/%d) : ", i+1, valeurs);
                scanf("%lf", &array[i]);
                if( array[i] < 0 || array[i] > 20 )
                {
                        i--;
                        continue;
                }
        }
        double sum = 0;
        for( int i = 0; i < valeurs; i++ ) sum += array[i];
        printf("sum is %.3f\n", sum/valeurs);
}

void exercice4()
{
        int etages;
        printf("Entrez le nombre d'etages : ");
        scanf("%d", &etages);
        for( int i = 0; i < etages; i++ )
        {
                for( int j = 0; j < etages-1-i ; j++ ) printf(" ");
                for( int k = 0; k < (i * 2 + 1); k++ ) printf("*%s", (k == (i * 2) ? "\n": ""));
        }
}

void exercice5()
{
        int integers = 20;
        for( int i = 0; i < integers+1 ; i++ ) printf("%s%5d%s", (i == 0) ? "  x |" : "" , i, (i == integers) ? "\n" : "");
        for( int i = 0; i < integers+2 ; i++ ) printf("-----%s", (i == integers+1) ? "\n" : "");
        for( int i = 0; i < integers+1 ; i++)
                for( int j = 0; j < integers+2; j++ )
                       printf("%3d%2s%s", (j == 0) ? i : (j-1)*i, (j == 0) ? " |  " : "", (j == integers+1) ? "\n" : ""); 
}

int main()
{
        exercice5();
        return 0;
}
