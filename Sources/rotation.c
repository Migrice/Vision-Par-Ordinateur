#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Headers/rotation.h"
Image rotation(Image img)
{

    Image img_finale;
    strcpy(img_finale.comment, img.comment);
    strcpy(img_finale.type, img.type);
    img_finale.height = img.height;
    img_finale.width = img.width;
    img_finale.max_value_pixels = img.max_value_pixels;
    img_finale.matriceImage = MatrixAllocation(img_finale.height, img_finale.width);

    int rotation;
    printf("De combien voulez vous roter 90 ou 180 dégrées? ");
    scanf("%d", &rotation);

    if (rotation == 90)
    {
        for (int i = 0; i < img_finale.height; i++)
        {
            for (int j = 0; j < img_finale.width; j++)
            {
                img_finale.matriceImage[i][j] = img.matriceImage[j][i];
            }
        }
    }

    if (rotation == 180)
    {
        for (int i = 0; i < img_finale.height; i++)
        {
            for (int j = 0; j < img_finale.width; j++)
            {
                img_finale.matriceImage[i][j] = img.matriceImage[img.height - 1 - i][img.width - 1 - j];
            }
        }
    }

    printf("Operation bien effectuee\n");
    return img_finale;
}
