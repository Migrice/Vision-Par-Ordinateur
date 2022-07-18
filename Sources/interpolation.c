#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Headers/interpolation.h"

Image interpolation_plus_proche_voisin(Image img, int ratio)
{
    int ration_interpolation = ratio;
    Image im8;
    strcpy(im8.comment, img.comment);
    im8.height = img.height * ration_interpolation;
    im8.width = img.width * ration_interpolation;
    im8.max_value_pixels = img.max_value_pixels;
    strcpy(im8.type, img.type);
    im8.matriceImage = MatrixAllocation(im8.height, im8.width);

    for (int i = 0; i < img.height; i++)
    {
        for (int j = 0; j < img.width; j++)
        {
            im8.matriceImage[i * ration_interpolation][j * ration_interpolation] = img.matriceImage[i][j];
        }
    }

    for (int i = 0; i < im8.height; i++)
    {
        for (int j = 0; j < im8.width; j++)
        {

            im8.matriceImage[i][j] = img.matriceImage[i / ratio][j / ratio];
        }
    }
    printf("interpolation plus proche voisins bien effectuee\n");
    return im8;
}

// interpolation bilineaire
Image interpolation_bilineaire(Image img, int ratio)
{

    int ration_interpolation = ratio;
    Image im8;
    strcpy(im8.comment, img.comment);
    im8.height = img.height * ration_interpolation;
    im8.width = img.width * ration_interpolation;
    im8.max_value_pixels = img.max_value_pixels;
    strcpy(im8.type, img.type);
    im8.matriceImage = MatrixAllocation(im8.height, im8.width);

    for (int i = 0; i < img.height; i++)
    {
        for (int j = 0; j < img.width; j++)
        {
            im8.matriceImage[i * ration_interpolation][j * ration_interpolation] = img.matriceImage[i][j];
        }
    }

    for (int i = 0; i < im8.height; i++)
    {
        for (int j = 0; j < im8.width; j++)
        {
            if (im8.matriceImage[i][j] == 0)
            {
                int i_ratio = i / ratio;
                int j_ratio = j / ratio;

                if (i_ratio <= img.height - 2 && j_ratio <= img.width - 2)
                {
                    im8.matriceImage[i][j] = (int)((img.matriceImage[i_ratio][j_ratio] + img.matriceImage[i_ratio][j_ratio + 1] + img.matriceImage[i_ratio + 1][j_ratio] + img.matriceImage[i_ratio + 1][j_ratio + 1]) / 4);
                }
                else if ((i_ratio <= img.height - 2) && (j_ratio = img.width - 1))
                {

                    im8.matriceImage[i][j] = (int)((img.matriceImage[i_ratio][j_ratio] + img.matriceImage[i_ratio][j_ratio - 1] + img.matriceImage[i_ratio + 1][j_ratio - 1] + img.matriceImage[i_ratio + 1][j_ratio]) / 4);
                }
                else if ((i_ratio = img.height - 1) && (j_ratio <= img.width - 2))
                {
                    im8.matriceImage[i][j] = (int)((img.matriceImage[i_ratio][j_ratio] + img.matriceImage[i_ratio][j_ratio + 1] + img.matriceImage[i_ratio - 1][j_ratio] + img.matriceImage[i_ratio - 1][j_ratio + 1]) / 4);
                }
                else if ((i_ratio = img.height - 1) && (j_ratio = img.width - 1))
                {

                    im8.matriceImage[i][j] = (int)((img.matriceImage[i_ratio][j_ratio] + img.matriceImage[i_ratio][j_ratio - 1] + img.matriceImage[i_ratio - 1][j_ratio] + img.matriceImage[i_ratio - 1][j_ratio - 1]) / 4);
                }
            }
        }
    }
    printf("interpolation bilineaire bien effectuee\n");
    return im8;
}