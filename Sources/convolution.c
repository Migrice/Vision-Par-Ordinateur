#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../Headers/convolution.h"

Image Imageconvolution(Image img, int masqX, int masqY, int masque[masqY][masqX], int division)
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
                imageFinale.matriceImage[y][x] = 0;
            }
        }
    }
    printf("convolution bien effectuée\n");
    return imageFinale;
}

// filtre moyenneur
Image filtreMoyenneur(Image image, int taille)
{
    // creation d'un masque moyenneur avec une division par taille*taille
    int moyenneur[taille][taille];
    for (int i = 0; i < taille; i++)
    {
        for (int j = 0; j < taille; j++)
        {
            moyenneur[i][j] = 1;
            // printf("%d ", moyenneur[i][j]);
        }
        printf("\n");
    }
    Image conv = Imageconvolution(image, taille, taille, moyenneur, taille * taille);
    return conv;
}

// filtre gaussien
Image filtreGaussien(Image image, int flou)
{
    Image convo;
    // creation d'un masque gaussien avec une division par taille*taille
    if (flou == 5)
    {
        int gaussien[5][5] = {{1, 2, 3, 2, 1}, {2, 6, 8, 6, 2}, {3, 8, 10, 8, 3}, {2, 4, 8, 6, 2}, {1, 2, 3, 2, 1}};
        convo = Imageconvolution(image, 5, 5, gaussien, 98);
    }
    else if (flou == 3)
    {
        int gaussien2[3][3] = {{1, 2, 1}, {2, 4, 2}, {1, 2, 1}};
        convo = Imageconvolution(image, 3, 3, gaussien2, 16);
    }
    // // gaussien flou
    // int gaussien2[5][5] = {{1, 2, 3, 2, 1}, {2, 4, 6, 4, 2}, {3, 6, 9, 4, 3}, {2, 4, 6, 4, 2}, {1, 2, 3, 2, 1}};
    return convo;
}

Image filtreMedian(Image img, int masqX, int masqY)
{

    Image imageFinale;

    // initialisation de l'image
    strcpy(imageFinale.type, img.type);
    strcpy(imageFinale.comment, img.comment);
    imageFinale.height = img.height;
    imageFinale.width = img.width;
    imageFinale.max_value_pixels = img.max_value_pixels;
    imageFinale.matriceImage = MatrixAllocation(imageFinale.height, imageFinale.width);

    // // centre du masque
    int msqx = masqX;
    int msqy = masqY;

    int *tab = calloc(3 * 3, sizeof(int));

    int masqueX = (msqx / 2);
    int masqueY = (msqy / 2);
    int k = 0;

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
                        tab[k] = img.matriceImage[indeY][indeX];
                        k = k + 1;
                    }
                }
            }
            k = 0;

            // tri du tableau
            int l, m, c;
            for (l = 0; l < 9 - 1; l++)
                for (m = l + 1; m < 9; m++)
                    if (tab[l] > tab[m])
                    {
                        c = tab[l];
                        tab[l] = tab[m];
                        tab[m] = c;
                    }
            imageFinale.matriceImage[y][x] = tab[4];
            // imageFinale.matriceImage[y][x] = (int)abs(accumulator / division);
        }
    }
    printf("Filtre median bien effectuée\n");
    return imageFinale;
}

Image filtreMedian5(Image img, int masqX, int masqY)
{

    Image imageFinale;

    // initialisation de l'image
    strcpy(imageFinale.type, img.type);
    strcpy(imageFinale.comment, img.comment);
    imageFinale.height = img.height;
    imageFinale.width = img.width;
    imageFinale.max_value_pixels = img.max_value_pixels;
    imageFinale.matriceImage = MatrixAllocation(imageFinale.height, imageFinale.width);

    // // centre du masque
    int msqx = masqX;
    int msqy = masqY;

    int *tab = calloc(5 * 5, sizeof(int));

    int masqueX = (msqx / 2);
    int masqueY = (msqy / 2);
    int k = 0;

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
                        tab[k] = img.matriceImage[indeY][indeX];
                        k = k + 1;
                    }
                }
            }
            k = 0;

            // tri du tableau
            int l, m, c;
            for (l = 0; l < 25 - 1; l++)
                for (m = l + 1; m < 25; m++)
                    if (tab[l] > tab[m])
                    {
                        c = tab[l];
                        tab[l] = tab[m];
                        tab[m] = c;
                    }
            imageFinale.matriceImage[y][x] = tab[13];
            // imageFinale.matriceImage[y][x] = (int)abs(accumulator / division);
        }
    }
    printf("Filtre median bien effectuée\n");
    return imageFinale;
}
