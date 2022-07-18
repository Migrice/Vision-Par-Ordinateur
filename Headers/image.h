#ifndef IMAGE_H
#define IMAGE_H

// definition de la structure d'une image
typedef struct Image
{
    char type[5];
    char comment[30];
    int height;
    int width;
    int max_value_pixels;
    int **matriceImage;
} Image; // alias

// definition de la fonction de lecture de l'image
Image readImage(char *path);

// definition de la fonction qui va stocker les pixels dans la matrice
int **MatrixAllocation(int height, int width);

// definition de la fonction qui va ecrire les données dans un fichier
void WriteImage(Image img, char *path);

#endif