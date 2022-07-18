#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include "image.h"

// interpolation du plus proche voisin
Image interpolation_plus_proche_voisin(Image img, int ratio);

// interpolation bilineaire
Image interpolation_bilineaire(Image img, int ratio);

#endif