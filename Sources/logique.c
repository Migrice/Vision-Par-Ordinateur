#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../Headers/image.h"

// etLogique
Image etLogique(Image img_bin, Image img_gris)
{
    Image im5;
    strcpy(im5.comment, img_gris.comment);
    strcpy(im5.type, img_gris.type);

    if (img_bin.height <= img_gris.height)
    {
        im5.height = img_bin.height;
    }
    else
    {
        im5.height = img_gris.height;
    }

    if (img_bin.width <= img_gris.width)
    {
        im5.width = img_bin.width;
    }
    else
    {
        im5.width = img_gris.width;
    }

    im5.max_value_pixels = img_gris.max_value_pixels;
    im5.matriceImage = MatrixAllocation(im5.height, im5.width);

    for (int i = 0; i < im5.height; i++)
    {
        for (int j = 0; j < im5.width; j++)
        {

            if (img_bin.matriceImage[i][j] == 0)
            {
                im5.matriceImage[i][j] = 0;
            }
            else
            {
                im5.matriceImage[i][j] = img_gris.matriceImage[i][j];
            }
            // im5.matriceImage[i][j] = img.matriceImage[i][j] | img2.matriceImage[i][j];
        }
    }
    printf("Et logique bien effectué\n");
    return im5;
}

// ou logique
Image ouLogique(Image img_bin, Image img_gris)
{
    Image ou_logique;

    strcpy(ou_logique.comment, img_gris.comment);
    strcpy(ou_logique.type, img_gris.type);

    if (img_bin.height <= img_gris.height)
    {
        ou_logique.height = img_bin.height;
    }
    else
    {
        ou_logique.height = img_gris.height;
    }

    if (img_bin.width <= img_gris.width)
    {
        ou_logique.width = img_bin.width;
    }
    else
    {
        ou_logique.width = img_gris.width;
    }

    ou_logique.max_value_pixels = img_gris.max_value_pixels;
    ou_logique.matriceImage = MatrixAllocation(ou_logique.height, ou_logique.width);

    for (int i = 0; i < ou_logique.height; i++)
    {
        for (int j = 0; j < ou_logique.width; j++)
        {

            if (img_bin.matriceImage[i][j] == 255)
            {
                ou_logique.matriceImage[i][j] = 255;
            }
            else
            {
                ou_logique.matriceImage[i][j] = img_gris.matriceImage[i][j];
            }
        }
    }
    printf("Ou logique bien effectué\n");
    return ou_logique;
}

Image nonImage(Image img)
{

    Image im5;
    strcpy(im5.comment, img.comment);
    strcpy(im5.type, img.type);

    im5.height = img.height;
    im5.width = img.width;
    im5.max_value_pixels = img.max_value_pixels;
    im5.matriceImage = MatrixAllocation(img.height, img.width);

    for (int i = 0; i < im5.height; i++)
    {
        for (int j = 0; j < im5.width; j++)
        {
            if (img.matriceImage[i][j] == 0)
            {
                im5.matriceImage[i][j] = 255;
            }
            else
            {
                im5.matriceImage[i][j] = 0;
            }
        }
    }
    return im5;
}

Image andImage(Image img, Image img2)
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
            if ((img.matriceImage[i][j] == 0) && (img2.matriceImage[i][j] == 0))
            {
                im7.matriceImage[i][j] = 0;
            }
            else
            {
                im7.matriceImage[i][j] = 255;
            }
        }
    }
    return im7;
}

// ou logique
Image orImage(Image img, Image img2)
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
            if ((img.matriceImage[i][j] == 0) || (img2.matriceImage[i][j] == 0))
            {
                im7.matriceImage[i][j] = 0;
            }
            else
            {
                im7.matriceImage[i][j] = 255;
            }
        }
    }
    return im7;
}
Image xorImage(Image img, Image img2)
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
            if ((img.matriceImage[i][j]) == (img2.matriceImage[i][j]))
            {
                im7.matriceImage[i][j] = 255;
            }
            else
            {
                im7.matriceImage[i][j] = 0;
            }
        }
    }
    return im7;
}