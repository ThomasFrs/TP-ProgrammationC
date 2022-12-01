#ifndef __TI_H__
#define __TI_H__

#include "image.h"

extern Image Rotation(Image Im);

extern Image AppliquerTable(unsigned char Table[256], Image Im);

extern void RemplirTableInversion(unsigned char Table[256]);

extern void RemplirTableGamma(double Gamma, unsigned char Table[256]);

#endif
