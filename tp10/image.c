#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "image.h"

struct sImage
{
        int NbLig;
        int NbCol;
        tType Type;
        Matrice Rouge;
        Matrice Vert;
        Matrice Bleu;
};

Matrice ImRouge(Image Im)
{
        return Im->Rouge;
}

Matrice ImVert(Image Im)
{
        return Im->Vert;
}

Matrice ImBleu(Image Im)
{
        return Im->Bleu;
}

Image ImAllouer(int NbLignes, int NbColonnes)
{
        Image image = malloc(sizeof(Image));
        image->NbLig = NbLignes; image->NbCol = NbColonnes;
        image->Rouge = MatAllouer(NbLignes, NbColonnes);
        return image;
}

Image ImAllouerCoul(int NbLignes, int NbColonnes)
{
        Image image = malloc(sizeof(Image));
        image->NbLig = NbLignes; image->NbCol = NbColonnes;
        image->Rouge = MatAllouer(NbLignes, NbColonnes);
        image->Vert = MatAllouer(NbLignes, NbColonnes);
        image->Bleu = MatAllouer(NbLignes, NbColonnes);
        return image;
}

void ImLiberer(Image *pIm)
{
        if( *pIm != NULL )
        {
            MatLiberer((*pIm)->Rouge);

            if( (*pIm)->Type == Couleur )
            {
                    MatLiberer((*pIm)->Vert);
                    MatLiberer((*pIm)->Bleu);
            }
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
        return Im->Rouge;
}

Image ImLire(char NomFichier[])
{
        FILE *file = fopen(NomFichier, "rt"); //ouverture du fichier
        if( file==NULL ) return NULL;
       
        int NbLignes, NbColonnes, val;
        char extension[2];
        
        //fseek(file, 3, 0);
        fscanf(file, "%s", extension);
        fscanf(file, "%d", &NbColonnes);
        fscanf(file, "%d", &NbLignes);
        fscanf(file, "%d", &val);


        if( extension[1] == '6' ) // P6 - Binaire
        {
                Image image = ImAllouerCoul(NbLignes, NbColonnes);
            
                long position = ftell(file);
                fclose(file);
                
                file = fopen(NomFichier, "rb");
                fseek(file, position, 0);
                
                for( int i=0; i<image->NbLig; i++ )
                {
                    fread(image->Rouge[i], sizeof(unsigned char), image->NbCol, file); 
                }
        }
        else if( extension[1] == '3' ) // P3
        {
                Image image = ImAllouerCoul(NbLignes, NbColonnes);
                int temp;
                for( int i=0; i<image->NbLig; i++ )
                {
                    fread(image->Rouge[i], sizeof(unsigned char), image->NbCol, file); 
                }
        }

        else if( extension[1] == '5' ) // P5 - Binaire
        {
                Image image = ImAllouer(NbLignes, NbColonnes);
                
                long position = ftell(file);
                fclose(file);
                
                file = fopen(NomFichier, "rb");
                fseek(file, position, 0);
                
                for( int i=0; i<image->NbLig; i++ )
                {
                    fread(image->NivGris[i], sizeof(unsigned char), image->NbCol, file); 
                }
        }
        else // P2
        {
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

void ImEcrireBin(Image Im, char NomFichier[])
{
        FILE *file = fopen(NomFichier, "wt");
        fputs("P5\n", file);
        fprintf(file, "%d %d\n", Im->NbCol, Im->NbLig);
        fputs("255\n", file);

        long position = ftell(file); printf("%ld\n", position);
        fclose(file);
        file = fopen(NomFichier, "ab");
        fseek(file, position, 0);

        for( int i=0; i<Im->NbLig; i++ )
        {
                fwrite(Im->NivGris[i], sizeof(unsigned char), Im->NbCol, file);
        }
}
