#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Headers/image.h"

// ALlocation dynamique de la matrice
// int **MatrixAllocation(int height, int width)
// {
//     int **matrice = (int **)malloc(height * sizeof(int *));
//     if (matrice == NULL)
//         exit(1);
//     for (int i = 0; i < height; i++)
//     {
//         matrice[i] = (int *)malloc(width * sizeof(int));
//         if (matrice[i] == NULL)
//             exit(1);
//     }
//     return matrice;
// }

int **MatrixAllocation(int height, int width)
{
    int **matrice = calloc(height, sizeof(int *));
    if (matrice == NULL)
        exit(1);
    for (int i = 0; i < height; i++)
    {
        matrice[i] = calloc(width, sizeof(int));
        if (matrice[i] == NULL)
            exit(1);
    }
    return matrice;
}

// Lecture de l'image
Image readImage(char *path)
{
    char ligne[30000];
    int largeur, longueur;
    int taille_pixel;
    Image img;

    FILE *fichier = NULL; // lecture du fichier

    fichier = fopen(path, "r");

    if (fichier != NULL)
    {
        // printf("fichier ouvert\n");
        fscanf(fichier, "%[^\n]\n", ligne);
        // printf("%s\n", ligne);
        strcpy(img.type, ligne);

        fscanf(fichier, "%[^\n]\n", ligne);
        strcpy(img.comment, ligne);
        // printf("%s\n", ligne);

        fscanf(fichier, "%d %d\n", &largeur, &longueur);
        img.height = longueur;
        img.width = largeur;
        // printf("%d\n", longueur);
        // printf("%d\n", largeur);

        fscanf(fichier, "%d\n", &taille_pixel);
        img.max_value_pixels = taille_pixel;
        // printf("%d\n", taille_pixel);

        img.matriceImage = MatrixAllocation(longueur, largeur);
        // lire les differents pixels et les stocker dans une matrice
        for (int i = 0; i < longueur; i++)
        {
            for (int j = 0; j < largeur; j++)
            {
                fscanf(fichier, "%d\n", &img.matriceImage[i][j]);
            }
        }

        // Affichage des valeurs de la matrice
        /* for (int i = 0; i < longueur; i++)
        {
            for (int j = 0; j < largeur; j++)
            {
                printf(" %d ", img.matriceImage[i][j]);
            }
            printf("\n\n");
        } */

        fclose(fichier);
        return img;
    }
    else
    {
        printf("le fichier ne peut etre ouvert");
        exit(EXIT_FAILURE);
    }
}

// Ecriture de l'image
void WriteImage(Image img, char *path)
{
    FILE *fichier = NULL;
    fichier = fopen(path, "w");

    if (fichier != NULL)
    {
        // On peut écrire dans le fichier

        fprintf(fichier, "%s\n", img.type);
        fprintf(fichier, "# Made by Emelda\n");
        fprintf(fichier, "%d %d\n", img.width, img.height);
        fprintf(fichier, "%d\n", img.max_value_pixels);

        for (int i = 0; i < img.height; i++)
        {
            for (int j = 0; j < img.width; j++)
            {
                fprintf(fichier, "%d\n", img.matriceImage[i][j]);
            }
        }

        fclose(fichier); // On ferme le fichier qui a été ouvert
    }
    else
    {
        // On affiche un message d'erreur
        printf("Impossible d'ouvrir le fichier");
    }
}
