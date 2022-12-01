#include <stdio.h>

void fct(int t[], int n)
{
        for( int i = 0; i < n; i++ ) t[i] = 0;
}

int main()
{
        char ch[5] = "abcd";
        int tab[3] = {3, 2, 1};
        fct(tab, 2);

        for( int i = 0; i < 3; i++ ) printf("%d ", tab[i]);

        //que vaut p? (p = 12134 + 1) -> p vaut 12135, on demande ce que p vaut, pas la valeur de ce quoi p pointe
        return 0;
}
