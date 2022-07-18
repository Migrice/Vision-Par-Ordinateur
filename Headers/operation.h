#ifndef OPERATION_H
#define OPERATION_H

#include "image.h"

// inverse de l'image
Image inverse(Image img);

// etLogique
Image etLogique(Image img, Image img2);

// addition
Image addition(Image img, Image img2);

// ajout luminance
Image ajoutLuminance(Image img, int niveau);

// soustraction
Image soustraction(Image img, Image img2);

// multiplication
Image multiplication(Image img, float ratio);

#endif