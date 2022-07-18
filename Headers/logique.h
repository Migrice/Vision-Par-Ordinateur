#ifndef LOGIQUE_H
#define LOGIQUE_H

#include "image.h"

// etLogique
Image etLogique(Image img, Image img2);

Image ouLogique(Image img_bin, Image img_gris);

Image nonImage(Image img);

Image andImage(Image img, Image img2);

Image orImage(Image img, Image img2);

Image xorImage(Image img, Image img2);

#endif