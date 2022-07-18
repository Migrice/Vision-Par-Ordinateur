#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Headers/operation.h"
#include "../Headers/traitement.h"
#include "../Headers/image.h"

// inverse
Image inverse(Image img)
{
    Image im4;
    strcpy(im4.comment, img.comment);
    im4.height = img.height;
    im4.width = img.width;
    im4.max_value_pixels = img.max_value_pixels;
    strcpy(im4.type, img.type);
    im4.matriceImage = MatrixAllocation(img.height, img.width);

    for (int i = 0; i < img.height; i++)
    {
        for (int j = 0; j < img.width; j++)
        {
            im4.matriceImage[i][j] = 255 - img.matriceImage[i][j];
        }
    }
    return im4;
}

Image addition(Image img, Image img2)
{

    Image im6;
    strcpy(im6.comment, img.comment);
    im6.height = img.height;
    im6.width = img.width;
    im6.max_value_pixels = img.max_value_pixels;
    strcpy(im6.type, img.type);
    im6.matriceImage = MatrixAllocation(img.height, img.width);

    if (img.height <= img2.height)
    {
        im6.height = img.height;
    }
    else
    {
        im6.height = img2.height;
    }

    if (img.width <= img2.width)
    {
        im6.width = img.width;
    }
    else
    {
        im6.width = img2.width;
    }

    for (int i = 0; i < im6.height; i++)
    {
        for (int j = 0; j < im6.width; j++)
        {
            im6.matriceImage[i][j] = img.matriceImage[i][j] + img2.matriceImage[i][j];
            if (im6.matriceImage[i][j] > 255)
            {
                im6.matriceImage[i][j] = 255;
            }
                }
    }
    printf("Addition bien deroulee\n");

    return im6;
}

// soustraction
Image soustraction(Image img, Image img2)
{
    Image im7;
    strcpy(im7.comment, img.comment);
    strcpy(im7.type, img.type);

    if (img.height <= img2.height)
    {
        im7.height = img.height;
    }
    else
    {
        im7.height = img2.height;
    }

    if (img.width <= img2.width)
    {
        im7.width = img.width;
    }
    else
    {
        im7.width = img2.width;
    }

    im7.max_value_pixels = img.max_value_pixels;
    im7.matriceImage = MatrixAllocation(im7.height, im7.width);

    for (int i = 0; i < im7.height; i++)
    {
        for (int j = 0; j < im7.width; j++)
        {
            im7.matriceImage[i][j] = img.matriceImage[i][j] - img2.matriceImage[i][j];
            if (im7.matriceImage[i][j] < 0)
            {
                im7.matriceImage[i][j] = 0;
            }
        }
    }
    printf("Soustraction bien deroulee\n");
    return im7;
}

// multiplication
Image multiplication(Image img, float ratio)
{
    float ratio_mult = ratio;
    Image im8;
    strcpy(im8.comment, img.comment);
    im8.height = img.height;
    im8.width = img.width;
    im8.max_value_pixels = img.max_value_pixels;
    strcpy(im8.type, img.type);
    im8.matriceImage = MatrixAllocation(img.height, img.width);

    for (int i = 0; i < im8.height; i++)
    {
        for (int j = 0; j < im8.width; j++)
        {
            im8.matriceImage[i][j] = img.matriceImage[i][j] * ratio_mult;
        }
    }
    printf("Multiplication bien effectuee\n");
    return im8;
}

// ajout luminance
Image ajoutLuminance(Image img, int niveau)
{

    int niveau_lum = niveau;
    Image im8;
    strcpy(im8.comment, img.comment);
    im8.height = img.height;
    im8.width = img.width;
    im8.max_value_pixels = img.max_value_pixels;
    strcpy(im8.type, img.type);
    im8.matriceImage = MatrixAllocation(img.height, img.width);

    for (int i = 0; i < im8.height; i++)
    {
        for (int j = 0; j < im8.width; j++)
        {
            im8.matriceImage[i][j] = img.matriceImage[i][j] + niveau_lum;
            if (im8.matriceImage[i][j] > 255)
            {
                im8.matriceImage[i][j] = 255;
            }
        }
    }
    printf("Ajout de luminance  bien deroulee\n");
    return im8;
}