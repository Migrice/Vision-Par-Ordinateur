#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Headers/seuillage.h"

int *TableauSeuil(int nbre_seuils)
{
    int *tab = calloc(nbre_seuils, sizeof(int *));

    for (int i = 0; i < nbre_seuils; i++)
    {
        printf("Entrer le seuil numero %d :", i + 1);
        scanf("%d", &tab[i]);
    }

    // for (int i = 0; i < nbre_seuils; i++)
    // {
    //     printf("%d", tab[i]);
    // }
    return tab;
}

Image seuillage_fixe(Image img, int nbseuils)
{

    Image img_finale;
    int k;
    strcpy(img_finale.comment, img.comment);
    strcpy(img_finale.type, img.type);
    img_finale.height = img.height;
    img_finale.width = img.width;
    img_finale.max_value_pixels = img.max_value_pixels;
    img_finale.matriceImage = MatrixAllocation(img_finale.height, img_finale.width);

    int *tableau = TableauSeuil(nbseuils);

    for (int i = 0; i < img_finale.height; i++)
    {
        for (int j = 0; j < img_finale.width; j++)
        {
            k = 0;
            while (k < nbseuils && img.matriceImage[i][j] >= tableau[k])
            {
                k++;
            }

            img_finale.matriceImage[i][j] = tableau[k];
        }
    }

    printf("Seuillage bien effectue\n");

    return img_finale;
}
