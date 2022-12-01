#include <stdio.h>

int ConversionDuree(int secondes)
{
        int heures = 0, minutes = 0;
        while( secondes >= 3600 )
        {
                heures++;
                secondes -= 3600;
        }
        while ( secondes >= 60 )
        {
                minutes++;
                secondes -= 60;
        }
        return heures, minutes, secondes;
}

int ConversionDuree2(int secondes)
{
        int duree[3] = {0, 0, 0};
        duree[2] = secondes;
        while( secondes >= 3600 )
        {
                duree[0]++;
                duree[2] -= 3600;
        }
        while ( secondes >= 60 )
        {
                duree[1]++;
                duree[2] -= 60;
        }
        return *duree;
}

int main()
{
        int secondes;
        printf("Entrez une durée en secondes : ");
        scanf("%d", &secondes);
        return 0;
}
