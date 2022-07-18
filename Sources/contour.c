#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../Headers/contour.h"

// convolution
Image ImageContour(Image img, int masqX, int masqY, int masque[masqY][masqX], int division)
{

    Image imageFinale;

    // initialisation de l'image
    strcpy(imageFinale.type, img.type);
    strcpy(imageFinale.comment, img.comment);
    imageFinale.height = img.height;
    imageFinale.width = img.width;
    imageFinale.max_value_pixels = img.max_value_pixels;
    imageFinale.matriceImage = MatrixAllocation(imageFinale.height, imageFinale.width);

    // // int mon_masque = masque[masqY][masqX];

    // // centre du masque
    int msqx = masqX;
    int msqy = masqY;
    int masqueX = (msqx / 2);
    int masqueY = (msqy / 2);

    // // convolution

    for (int x = 0; x < imageFinale.width; x++)
    {
        for (int y = 0; y < imageFinale.height; y++)
        {
            // valeur calculée pour chaque pixel de l'image
            double accumulator = 0;

            for (int i = -masqueX; i <= masqueX; i++)
            {
                // On prend chaque Pixel
                for (int j = -masqueY; j <= masqueY; j++)
                {

                    int indeX = x + i;
                    int indeY = y + j;
                    // Si l'index n'est pas compris dans l'image
                    if (indeX < 0 || indeY < 0 || indeX >= imageFinale.width - 1 || indeY >= imageFinale.height - 1)
                    {

                        // On lui donne la valeur Zero
                        accumulator += 0;
                    }

                    else
                    {

                        accumulator += masque[i + masqueX][j + masqueY] * (img.matriceImage[indeY][indeX]);
                    }
                }
            }

            imageFinale.matriceImage[y][x] = (int)abs(accumulator / division);

            if (imageFinale.matriceImage[y][x] > 255)
            {
                imageFinale.matriceImage[y][x] = 255;
            }
            else if (imageFinale.matriceImage[y][x] < 0)
            {
                imageFinale.matriceImage[y][x] = imageFinale.matriceImage[y][x] * -1;
            }
        }
    }
    printf("convolution bien effectuée\n");
    return imageFinale;
}
// filtre de prewitt
Image filtrePrewitt(Image image, int axe)
{
    if (axe == 1)
    {

        int prewitt_x[3][3] = {
            {-1, -1, -1},
            {0, 0, 0},
            {1, 1, 1}};
        return ImageContour(image, 3, 3, prewitt_x, 1);
    }
    else
    {
        int prewitt_y[3][3] = {
            {-1, 0, 1},
            {-1, 0, 1},
            {-1, 0, 1}};
        return ImageContour(image, 3, 3, prewitt_y, 1);
    }
}

// filtre de robert
Image filtreRobert(Image image, int axe)
{
    if (axe == 1)
    {
        int robert_x[3][3] = {
            {0, 1},
            {-1, 0},
        };
        return ImageContour(image, 2, 2, robert_x, 1);
    }
    else
    {
        int roberty[2][2] = {{1, 0}, {0, -1}};
        return ImageContour(image, 2, 2, roberty, 1);
    }
}

// filtre de sobel
Image filtreSobel(Image image, int axe)
{
    int sobelx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int sobely[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         sobely[i][j] = sobelx[j][i];
    //     }
    // }
    if (axe == 1)
    {
        return ImageContour(image, 2, 2, sobelx, 1);
    }
    else if (axe == 2)
    {
        return ImageContour(image, 2, 2, sobely, 1);
    }
}

// le laplacien
Image filtreLaplacien(Image image)
{

    int laplacien[3][3] = {{0, 1, 0}, {1, -4, 1}, {0, 1, 0}};
    int laplacien2[3][3] = {{1, 1, 1}, {1, -8, 1}, {1, 1, 1}};
    return ImageContour(image, 3, 3, laplacien2, 1);
}
