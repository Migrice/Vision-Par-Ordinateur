#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../Headers/traitement.h"
#include "../Headers/image.h"

//  Histogramme de l'image
int *histogram(Image img)
{
    int *tab = malloc(256 * sizeof(int));
    for (int i = 0; i < 256; i++)
    {
        tab[i] = 0;
    }

    for (int i = 0; i < img.height; i++)
    {
        for (int j = 0; j < img.width; j++)
        {
            tab[img.matriceImage[i][j]]++;
        }
    }
    printf("Histogramme de l'image\n");
    for (int i = 0; i < 256; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
    return tab;
}

// valeur maximale des pixels
int maximum(Image img)
{

    int max = img.matriceImage[0][0];
    // int i, j, max = imginfo->data[0][0], dim = 800;
    for (int i = 0; i < img.height; i++)
    {
        for (int j = 0; j < img.width; j++)
        {
            if (img.matriceImage[i][j] > max)
            {
                max = img.matriceImage[i][j];
            }
        }
    }

    return max;
}

// valeur minimale des pixels
int minimum(Image img)
{
    int min = img.matriceImage[0][0];
    // int i, j, max = imginfo->data[0][0], dim = 800;
    for (int i = 0; i < img.height; i++)
    {
        for (int j = 0; j < img.width; j++)
        {
            if (img.matriceImage[i][j] < min)
            {
                // printf("%d\n",tab[i][j]);
                min = img.matriceImage[i][j];
            }
        }
    }
    return min;
}

// contraste
float contraste(Image img)
{
    int max = maximum(img);
    int min = minimum(img);
    float cont = (float)(max - min) / (max + min);

    return cont;
}

// transformation lineaire
Image transformation_lineaire(Image img)

{
    Image im;
    strcpy(im.comment, img.comment);
    // im.comment = img.comment;
    im.height = img.height;
    im.width = img.width;
    im.max_value_pixels = img.max_value_pixels;
    strcpy(im.type, img.type);
    // im.type = img.type;
    im.matriceImage = MatrixAllocation(img.height, img.width);

    int max = maximum(img);
    int min = minimum(img);

    for (int i = 0; i < img.height; i++)
    {
        for (int j = 0; j < img.width; j++)
        {
            im.matriceImage[i][j] = 255 * (img.matriceImage[i][j] - min) / (max - min);
        }
    }
    printf("Transformation lineaire bien effectuee\n");
    return im;
}

// transformation lineaire avec saturation
Image transformation_lineaire_avec_saturation(Image img, int smin, int smax)
{

    Image im2;
    strcpy(im2.comment, img.comment);
    // im.comment = img.comment;
    im2.height = img.height;
    im2.width = img.width;
    im2.max_value_pixels = img.max_value_pixels;
    strcpy(im2.type, img.type);
    // im.type = img.type;
    im2.matriceImage = MatrixAllocation(img.height, img.width);

    int seuil_min = smin, seuil_max = smax;

    int max = maximum(img);
    int min = minimum(img);

    if (smin < min)
    {
        seuil_min = min;
    }
    if (smax > max)
    {
        seuil_max = max;
    }

    for (int i = 0; i < img.height; i++)
    {
        for (int j = 0; j < img.width; j++)
        {
            im2.matriceImage[i][j] = 255 * (img.matriceImage[i][j] - seuil_min) / (seuil_max - seuil_min);

            if (im2.matriceImage[i][j] <= 0)
            {
                im2.matriceImage[i][j] = 0;
            }
            if (im2.matriceImage[i][j] >= 255)
            {
                im2.matriceImage[i][j] = 255;
            }
        }
    }
    return im2;
}

// egalisation d'histogramme
Image egalisation_histogramme(Image img)
{
    Image im3;

    strcpy(im3.comment, img.comment);
    im3.height = img.height;
    im3.width = img.width;
    stpcpy(im3.type, img.type);
    im3.max_value_pixels = img.max_value_pixels;
    im3.matriceImage = MatrixAllocation(img.height, img.width);

    int *hist = histogram(img);
    float hist_normalise[256];
    float densite_probabilte[256];

    for (int i = 0; i < 256; i++)
    {
        densite_probabilte[i] = 0;
    }
    // printf("Histogramme normalisé de l'image\n");

    // normalisation de l'histogramme
    for (int i = 0; i < 256; i++)
    {
        // printf("%d\n", hist[i]);

        hist_normalise[i] = (float)hist[i] / (im3.height * im3.width);
    }

    // printf("Histogramme normalisé de l'image\n");
    // for (int i = 0; i < 256; i++)
    // {
    //     printf("%f ", hist_normalise[i]);
    // }
    // printf("\n");

    // densite de probalite normalise
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < i; j++)
        {
            densite_probabilte[i] += hist_normalise[j];
        }
    }

    // printf("Densite de probabilite normalise de l'image\n");
    // for (int i = 0; i < 256; i++)
    // {
    //     printf("%f ", densite_probabilte[i]);
    // }
    // printf("\n");

    // transformation des niveaux de gris

    for (int i = 0; i < img.height; i++)
    {
        for (int j = 0; j < img.width; j++)
        {
            im3.matriceImage[i][j] = densite_probabilte[img.matriceImage[i][j]] * 255;
        }
    }

    return im3;
}