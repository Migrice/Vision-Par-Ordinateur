#ifndef CONTOUR_H
#define CONTOUR_H

#include "image.h"

// convolution
Image ImageContour(Image img, int masqX, int masqY, int masque[masqY][masqX], int division);

// filtre de prewitt
Image filtrePrewitt(Image image, int axe);

// filtre de robert
Image filtreRobert(Image image, int axe);

// filtre de sobel
Image filtreSobel(Image image, int axe);

// laplacien
Image filtreLaplacien(Image image);
#endif