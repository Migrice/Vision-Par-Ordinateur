#include <stdio.h>
#include <stdlib.h>

#include "../Headers/otsu.h"

float Moyenne(int *hist, int T, int classe)
{
    float temp = 0;
    float result = 0;

    if (classe == 0)
    {
        for (int i = 0; i < T; i++)
        {
            temp += hist[i];
        }
        result = temp / T;
    }
    else
    {
        for (int i = T; i < 256; i++)
        {
            temp += hist[i];
        }
        result = temp / (256 - T);
    }

    return result;
}

float Variance(int *hist, float mean, int T, int classe)
{
    float temp = 0;
    float result = 0;
    if (classe == 0)
    {
        for (int i = 0; i < T; i++)
        {
            temp += (hist[i] - mean) * (hist[i] - mean);
        }
        result = temp / T;
    }
    else
    {
        for (int i = T; i < 256; i++)
        {
            temp += (hist[i] - mean) * (hist[i] - mean);
        }
        result = temp / (256 - T);
    }

    return result;
}

float Proportion(int l, int L, int *hist, int T, int classe)
{
    float temp = 0;
    float result = 0;

    if (classe == 0)
    {
        for (int i = 0; i < T; i++)
        {
            temp += hist[i];
        }
        result = temp / (l * L);
    }
    else
    {
        for (int i = T; i < 256; i++)
        {
            temp += hist[i];
        }
        result = temp / (l * L);
    }

    return result;
}

float Variance_intra(float p1, float v1, float p2, float v2)
{
    float result = (p1 * v1 + p2 * v2);
    return result;
}

int Otsu(Image img, int *seuils, int nb_seuil)
{
    float intra[nb_seuil];
    int *hist = histogram(img);

    float m1, m2, v1, v2, p1, p2, v_intra;

    for (int i = 0; i < nb_seuil; i++)
    {
        m1 = Moyenne(hist, seuils[i], 0);
        m2 = Moyenne(hist, seuils[i], 1);

        v1 = Variance(hist, m1, seuils[i], 0);
        v2 = Variance(hist, m2, seuils[i], 1);

        p1 = Proportion(img.width, img.height, hist, seuils[i], 0);
        p2 = Proportion(img.width, img.height, hist, seuils[i], 1);

        v_intra = Variance_intra(p1, v1, p2, v2);

        intra[i] = v_intra;
    }

    // tri des seuils candidats en fonction de leurs variances intra

    int temp = 0;
    for (int i = 0; i < nb_seuil; i++)
    {
        for (int j = i + 1; j < nb_seuil; j++)
        {
            if (intra[i] > intra[j])
            {
                temp = seuils[i];
                seuils[i] = seuils[j];
                seuils[j] = temp;
            }
        }
    }

    return seuils[0];
}
