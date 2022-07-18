#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../Headers/binarisation.h"

// binarisation

Image binarisation(Image img, int seuil)
{
    Image bin_image;

    int seuil_bin = seuil;
    strcpy(bin_image.comment, img.comment);
    strcpy(bin_image.type, img.type),
        bin_image.height = img.height;
    bin_image.width = img.width;
    bin_image.max_value_pixels = img.max_value_pixels;
    bin_image.matriceImage = MatrixAllocation(bin_image.height, bin_image.width);

    for (int i = 0; i < bin_image.height; i++)
    {
        for (int j = 0; j < bin_image.width; j++)
        {
            if (img.matriceImage[i][j] >= seuil_bin)
            {
                bin_image.matriceImage[i][j] = 255;
            }
            else
            {
                bin_image.matriceImage[i][j] = 0;
            }
        }
    }
    printf("binarisation bien effectuee\n");
    return bin_image;
}
