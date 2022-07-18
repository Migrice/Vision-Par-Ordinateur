//#pragma once
#ifndef TRAITEMENT_H
#define TRAITEMENT_H

#include "image.h"

// histogramme de l'image
int *histogram(Image img);

// contraste
float contraste(Image img);

// maximum
int maximum(Image img);

// minimum
int minimum(Image img);

// transformation lineaire
Image transformation_lineaire(Image img);

// transformation lineaire avec saturation
Image transformation_lineaire_avec_saturation(Image img, int smin, int smax);

// egalisation d'histogramme
Image egalisation_histogramme(Image img);

#endif