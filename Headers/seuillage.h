#ifndef SEUILLAGE_H
#define SEUILLAGE_H

#include "image.h"

int *TableauSeuil(int nbre_seuils);

Image seuillage_fixe(Image img, int nbseuils);

#endif