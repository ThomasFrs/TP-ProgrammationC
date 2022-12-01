#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "image.h"

struct sImage
{
        int NbLig;
        int NbCol;
        Matrice NivGris;
};

Image ImAllouer(int NbLignes, int NbColonnes)
{
        Image image = malloc(sizeof(Image));
        image->NbLig = NbLignes; image->NbCol = NbColonnes;
        image->NivGris = MatAllouer(NbLignes, NbColonnes);
        return image;
}

void ImLiberer(Image *pIm)
{
        if( *pIm != NULL )
        {
            free((*pIm)->NivGris);
            *pIm = NULL;
        }
}

int ImNbLig(Image Im)
{
        return Im->NbLig;
}

int ImNbCol(Image Im)
{
        return Im->NbCol;
}

Matrice ImNivGris(Image Im)
{
        return Im->NivGris;
}

Image ImLire(char NomFichier[])
{
        FILE *file = fopen(NomFichier, "rt"); //ouverture du fichier
        if( file==NULL ) return NULL;
       
        int NbLignes, NbColonnes, val;
        fseek(file, 3, 0); // on part du début du fichier et on va 3 octets plus loin, jusqu'au "\n"
        fscanf(file, "%d", &NbColonnes);
        fscanf(file, "%d", &NbLignes);
        fscanf(file, "%d", &val);

        Image image = ImAllouer(NbLignes, NbColonnes);

        int temp;
        for( int i=0; i<image->NbLig; i++ )
        {
                for( int j=0; j<image->NbCol; j++ )
                {
                        fscanf(file, "%d", &temp);
                        image->NivGris[i][j] = round(255.0*temp/val);
                }
        }
        
        return image;
}

void ImEcrire(Image Im, char NomFichier[])
{
        FILE *file = fopen(NomFichier, "wt");
        fputs("P2\n", file);
        fprintf(file, "%d %d\n", Im->NbCol, Im->NbLig);
        fputs("255\n", file);

        for( int i=0; i<Im->NbLig; i++ )
        {
                for( int j=0; j<Im->NbCol; j++ )
                {
                        fprintf(file, "%d%s", Im->NivGris[i][j], (j == Im->NbCol-1) ? "\n" : " ");
                }
        }
}
