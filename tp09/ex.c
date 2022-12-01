#include <stdio.h>
#include "image.h"
#include "matrice.h"
#include "ti.h"

int main()
{
        //printf("hey\n");
        Image imtest = ImAllouer(5, 10);
        ImLiberer(&imtest);
        imtest = ImAllouer(6, 11);
        printf("Lignes: %d\tColonnes: %d\n", ImNbLig(imtest), ImNbCol(imtest));

        Image paysage = ImLire("paysage.pgm");
        unsigned char Tab[256]; RemplirTableInversion(Tab);
        
        Image paysage_rotation = ImAllouer(ImNbCol(paysage), ImNbLig(paysage)); 
        paysage_rotation = Rotation(paysage);
        ImEcrire(paysage_rotation, "paysage_rotation.pgm");

        Image paysage_inverted = ImAllouer(ImNbLig(paysage), ImNbCol(paysage)); 
        paysage_inverted = AppliquerTable(Tab, paysage);
        ImEcrire(paysage_inverted, "paysage_inverted.pgm");

        RemplirTableGamma(0.4, Tab);
        Image paysage_gamma1 = ImAllouer(ImNbLig(paysage), ImNbCol(paysage)); 
        paysage_gamma1 = AppliquerTable(Tab, paysage);
        ImEcrire(paysage_gamma1, "paysage_gamma1.pgm");

        RemplirTableGamma(1.2, Tab);
        Image paysage_gamma2 = ImAllouer(ImNbLig(paysage), ImNbCol(paysage)); 
        paysage_gamma2 = AppliquerTable(Tab, paysage);
        ImEcrire(paysage_gamma2, "paysage_gamma2.pgm");
        
        return 0;
}
