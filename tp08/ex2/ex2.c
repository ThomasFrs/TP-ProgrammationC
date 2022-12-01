#include <stdio.h>
#include "image.h"
#include "matrice.h"

int main()
{
        //printf("hey\n");
        Image imtest = ImAllouer(5, 10);
        ImLiberer(&imtest);
        imtest = ImAllouer(6, 11);
        printf("Lignes: %d\tColonnes: %d\n", ImNbLig(imtest), ImNbCol(imtest));

        Image feep = ImLire("feep.pgm");
        printf("Lignes: %d\tColonnes: %d\n", ImNbLig(feep), ImNbCol(feep));
        MatAfficher(ImNivGris(feep), ImNbLig(feep), ImNbCol(feep));

        Image peef = ImRotation(feep); // rotation de feep
        MatAfficher(ImNivGris(peef), ImNbLig(peef), ImNbCol(peef));
        ImEcrire(peef, "peef.pgm");
        printf("Lignes: %d\tColonnes: %d\n", ImNbLig(peef), ImNbCol(peef));

        Image imtest3 = ImAllouer(4, 6);
        ImEcrire(imtest3, "blank.pgm");

        Image chien = ImLire("chien.pgm");
        Image niehc = ImRotation(chien);
        ImEcrire(niehc, "niehc.pgm");
        
        return 0;
}
