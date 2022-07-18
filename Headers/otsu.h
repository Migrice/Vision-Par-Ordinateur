#ifndef OTSU_H
#define OTSU_H

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "image.h"
#include "traitement.h"

float Moyenne(int *hist, int T, int classe);

float Variance(int *hist, float mean, int T, int classe);

float Proportion(int l, int L, int *hist, int T, int classe);

float Variance_intra(float p1, float v1, float p2, float v2);
int Otsu(Image img, int *seuils, int nb_seuil);

#endif