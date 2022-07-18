#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "../Headers/hough.h"
#include "../Headers/contour.h"
#include "../Headers/binarisation.h"

Image transformeeHough(Image img)
{

    int **transforme_inverse = MatrixAllocation(img.height, img.width);

    Image img_finale;

    // char tab[181];
    int *tab = calloc(181, sizeof(int *));

    //
    for (int i = 1; i < 181; i++)
    {
        tab[i] = tab[i - 1] + 1;
    }

    int rho = 0;
    int y = 0;
    int rho_max = (int)sqrt((img.height * img.height) + (img.width * img.width));
    printf("rho max %d", rho_max);

    int **matrice_vote = MatrixAllocation(rho_max, 181);

    Image image_contour = filtreLaplacien(img);
    Image image_binarisee = binarisation(image_contour, 100);

    Image img_hough;
    strcpy(img_hough.type, image_binarisee.type);
    strcpy(img_hough.comment, image_binarisee.comment);
    img_hough.height = rho_max;
    img_hough.width = 181;
    img_hough.max_value_pixels = image_binarisee.max_value_pixels;

    strcpy(img_finale.type, image_binarisee.type);
    strcpy(img_finale.comment, image_binarisee.comment);
    img_finale.height = img.height;
    img_finale.width = img.width;
    img_finale.max_value_pixels = img.max_value_pixels;
    img_finale.matriceImage = MatrixAllocation(img_finale.height, img_finale.width);

    for (int i = 0; i < image_binarisee.height; i++)
    {
        for (int j = 0; j < image_binarisee.width; j++)
        {
            if (image_binarisee.matriceImage[i][j] != 0)
            {
                for (int k = 0; k < 181; k++)

                {
                    rho = (int)((i * cos((tab[k] * 3.14) / 180)) + (j * sin((tab[k] * 3.14) / 180)));
                    if (rho > 0)
                        matrice_vote[rho][k] += 1;
                }
            }
        }
    }
    img_hough.matriceImage = matrice_vote;

    printf("jjjjjj\n");
    // printf("jjjjj\n");

    // for (int i = 0; i < rho_max; i++)
    // {
    //     for (int j = 0; j < 181; j++)
    //     {
    //         printf("%d ", matrice_vote[i][j]);
    //     }
    // }

    // detection des contours

    float kj = 0.0;
    int x = 0;
    for (int i = 0; i < rho_max; i++)
    {
        for (int j = 0; j < 181; j++)
        {
            if (matrice_vote[i][j] > 100)
            {
                for (int k = 0; k < img.width; k++)

                {

                    // printf("a");
                    kj = (j * 3.14) / 180;
                    // x = 0;

                    if (cos(kj) != 0)
                    {
                        x = (i / cos(kj)) - (y * tan(kj));
                        // printf("%d ...\n", x);
                        if (x > 0 && x < img.height)
                        {
                            // printf("v\n");
                            transforme_inverse[x][k] = 255;
                        }
                    }
                    // printf("%d ;!;;;!;\n", x);
                }
            }
        }
    }

    for (int i = 0; i < img.height; i++)
    {
        for (int j = 0; j < img.width; j++)
        {
            img_finale.matriceImage[i][j] = img.matriceImage[i][j] + transforme_inverse[i][j];

            if (img_finale.matriceImage[i][j] > 255)
            {
                img_finale.matriceImage[i][j] = 255;
            }
        }
    }

    return img_hough;
}