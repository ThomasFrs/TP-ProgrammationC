#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ti.h"

Image Rotation(Image Im)
{
        Image imtemp = ImAllouer(ImNbCol(Im), ImNbLig(Im));
        
        int NbColonnes = ImNbCol(Im);
        for( int i=0; i<ImNbLig(Im); i++ )
                for( int j=0; j<ImNbCol(Im); j++ )
                        ImNivGris(imtemp)[NbColonnes-j-1][i] = ImNivGris(Im)[i][j];
        return imtemp;
}

Image AppliquerTable(unsigned char Table[256], Image Im)
{

        Image imtemp = ImAllouer(ImNbLig(Im), ImNbCol(Im));
        
        for( int i=0; i<ImNbLig(Im); i++ )
                for( int j=0; j<ImNbCol(Im); j++ )
                        ImNivGris(imtemp)[i][j] = Table[ImNivGris(Im)[i][j]];
        return imtemp;
}

void RemplirTableInversion(unsigned char Table[256])
{
        for( int i=0; i<256; i++ ) Table[i] = 255-i;
}

void RemplirTableGamma(double Gamma, unsigned char Table[256])
{
        for( int i=0; i<256; i++ ) Table[i] = round(pow(255.0f * (i / 255.0f), Gamma));
}
