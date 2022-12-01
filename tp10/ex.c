#include <stdio.h>
#include "image.h"
#include "matrice.h"
#include "ti.h"

int main(int argc, char *argv[])
{
        //printf("hey\n");
        Image imtest = ImAllouer(5, 10);
        ImLiberer(&imtest);
        imtest = ImAllouer(6, 11);
        printf("Lignes: %d\tColonnes: %d\n", ImNbLig(imtest), ImNbCol(imtest));
        
        Image img = ImLire(argv[1]);
        unsigned char Tab[256]; RemplirTableInversion(Tab);
        printf("Lignes: %d\tColonnes: %d\n", ImNbLig(img), ImNbCol(img));

        Image img_inv = ImAllouer(ImNbLig(img), ImNbCol(img)); 
        img_inv = AppliquerTable(Tab, img);
        ImEcrireBin(img_inv, argv[2]);

        return 0;
}
