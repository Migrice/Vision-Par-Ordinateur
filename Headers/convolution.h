#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include "image.h"

// convolution
Image Imageconvolution(Image img, int masqX, int masqY, int masque[masqY][masqX], int division);

// filtre moyenneur
Image filtreMoyenneur(Image image, int taille);

// filtre gaussien
Image filtreGaussien(Image image, int flou);

// filtre median
Image filtreMedian(Image img, int masqX, int masqY);

Image filtreMedian5(Image img, int masqX, int masqY);

#endif