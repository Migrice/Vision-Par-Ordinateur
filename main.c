#include <stdio.h>
#include <stdlib.h>

#include "Headers/image.h"
#include "Headers/traitement.h"
#include "Headers/operation.h"
#include "Headers/logique.h"
#include "Headers/convolution.h"
#include "Headers/contour.h"
#include "Headers/binarisation.h"
#include "Headers/interpolation.h"
#include "Headers/seuillage.h"
#include "Headers/hough.h"
#include "Headers/otsu.h"
#include "Headers/rotation.h"

int main()
{
    printf("\n\n\n");
    printf("****************************************************************\n");
    printf("*                                                              *\n");
    printf("*                  TP VISION PAR ORDINATEUR                    *\n");
    printf("*                                                              *\n");
    printf("****************************************************************\n\n");

    printf("          LISTE DES OPERATIONS IMPLEMENTEES          \n");
    printf("----------------------------------------------------------------\n\n");
    printf("1-  OPERATIONS ARITHMETIQUES \n");
    printf("2-  OPERATIONS LOGIQUES\n");
    printf("3-  INVERSE DE L'IMAGE\n");
    printf("4-  BINARISATION\n");
    printf("5-  HISTOGRAMME \n");
    printf("6-  INTERPOLATION\n");
    printf("7-  TRANSFORMATIONS LINEAIRES\n");
    printf("8-  CONVOLUTION\n");
    printf("9-  DETECTION DE CONTOURS\n");
    printf("10- SEGMENTATION\n");
    printf("11- CALCUL DU CONTRASTE\n");
    printf("12- TRANSFORMEE DE HOUGH\n");
    printf("13- ROTATION\n\n");

    printf("Quelle operation voulez vous effectuer ? \n\n");

    int nombre = 0;
    int choix1 = 0;
    int choix2 = 0;

    char path1[100];
    char path2[100];

    scanf("%d", &nombre);
    switch (nombre)
    {
    case 1:
        printf("      OPERATIONS ARITHMETIQUES \n\n");
        printf("1- ADDITION\n");
        printf("2-SOUSTRACTION\n");
        printf("3-MULTIPLICATION\n");

        printf("Choisir une operation : \n");
        scanf("%d", &choix1);

        switch (choix1)
        {
        case 1:;

            printf("Entrer le chemin d'acces à la premiere image: ");
            scanf("%s", path1);
            printf("Entrer le chemin d'acces à la deuxieme image: ");
            scanf("%s", path2);
            Image img_add1 = readImage(path1);
            Image img_add2 = readImage(path2);
            Image add = addition(img_add1, img_add2);
            WriteImage(add, "./Images/NouvellesImages/addition.pgm");
            break;

        case 2:;
            printf("Entrer le chemin d'acces à la premiere image: ");
            scanf("%s", path1);
            printf("Entrer le chemin d'acces à la deuxieme image: ");
            scanf("%s", path2);
            Image img_sous1 = readImage(path1);
            Image img_sous2 = readImage(path2);
            Image sous = soustraction(img_sous1, img_sous2);
            WriteImage(sous, "./Images/NouvellesImages/soustraction.pgm");
            break;

        case 3:;
            printf("Entrer le chemin d'acces à l'image: ");
            scanf("%s", path1);
            float ratio_mult;

            printf("Entrer le ratio : ");
            scanf("%f", &ratio_mult);
            Image img_mult = readImage(path1);
            Image mult = multiplication(img_mult, ratio_mult);
            WriteImage(mult, "./Images/NouvellesImages/multiplication.pgm");
            break;

        default:;
            break;
        }

        break;
    case 2:;
        printf("     1- OPERATIONS LOGIQUES \n\n");
        printf("1- ET LOGIQUE\n");
        printf("2- OU LOGIQUE \n");
        printf("3- AND \n");
        printf("4- OR \n");
        printf("5- XOR \n");
        printf("6- NOT\n");

        printf("Choisissez une operation \n");
        scanf("%d", &choix2);

        printf("Entrer le chemin d'acces à la premiere image: ");
        scanf("%s", path1);
        printf("Entrer le chemin d'acces à la deuxieme image: ");
        scanf("%s", path2);

        Image img = readImage(path1);
        Image img2 = readImage(path2);

        switch (choix2)
        {
        case 1:;

            Image etlog = etLogique(img, img2);
            WriteImage(etlog, "./Images/NouvellesImages/EtLogique.pgm");
            break;

        case 2:;

            Image oulog = ouLogique(img, img2);
            WriteImage(oulog, "./Images/NouvellesImages/ouLogique.pgm");
            break;

        case 3:;

            Image andimage = andImage(img, img2);
            WriteImage(andimage, "./Images/NouvellesImages/andImage.pgm");
            break;

        case 4:;
            Image ori = orImage(img, img2);
            WriteImage(ori, "./Images/NouvellesImages/orImage.pgm");
            break;

        case 5:;
            Image xor = xorImage(img, img2);
            WriteImage(xor, "./Images/NouvellesImages/xorImage.pgm");
            break;

        case 6:;
            Image not = nonImage(img);
            WriteImage(not, "./Images/NouvellesImages/nonImage.pgm");
            break;

        default:;
            break;
        }
        break;

    case 3:;
        printf("INVERSE DE L'IMAGE\n");

        printf("Entrer le chemin d'acces à l'image: ");
        scanf("%s", path1);
        Image lena = readImage(path1);
        Image inv = inverse(lena);
        WriteImage(inv, "./Images/NouvellesImages/inverse.pgm");
        break;

    case 4:;
        printf("BINARISATION\n ");

        printf("Entrer le chemin d'acces à l'image: ");
        scanf("%s", path1);
        Image img_bin = readImage(path1);
        int seuil = 0;
        printf("entrer le seuil : ");
        scanf("%d", &seuil);

        Image bin = binarisation(img_bin, seuil);
        WriteImage(bin, "./Images/NouvellesImages/binarisation.pgm");
        break;
    case 5:;

        printf("HISTOGRAMME\n\n");
        printf("1- HISTOGRAMME DE L'IMAGE\n");
        printf("2- EGALISATION D'HISTOGRAMME\n");

        printf("Entrer le chemin d'acces à l'image: ");
        scanf("%s", path1);
        Image img_histo = readImage(path1);
        int choix5 = 0;
        printf("Choisir une operation : \n");
        scanf("%d", &choix5);

        switch (choix5)
        {
        case 1:;
            histogram(img_histo);
            break;
        case 2:;
            Image histogram_egalise = egalisation_histogramme(img_histo);
            WriteImage(histogram_egalise, "./Images/NouvellesImages/egalisationHistogram.pgm");
            break;

        default:;
            break;
        }

        break;

    case 6:;
        printf("INTERPOLATION\n\n");
        printf("1- INTERPLATION DES QUATRES PLUS PROCHES VOISINS\n");
        printf("2-INTERPLATION BILIEAIRE\n");

        int choix6 = 0;
        int ratio = 0;
        printf("Choisir une operation : \n");
        scanf("%d", &choix6);

        printf("choisir le ratio : ");
        scanf("%d", &ratio);

        switch (choix6)
        {

        case 1:;

            printf("Entrer le chemin d'acces à l'image: ");
            scanf("%s", path1);
            Image img_inter = readImage(path1);

            Image inter_plus_proche = interpolation_plus_proche_voisin(img_inter, ratio);
            WriteImage(inter_plus_proche, "./Images/NouvellesImages/interpolationPlusProcheVoisin.pgm");
            break;

        case 2:;
            printf("Entrer le chemin d'acces à l'image: ");
            scanf("%s", path1);

            Image img_intere = readImage(path1);

            Image inter_bili = interpolation_bilineaire(img_intere, ratio);
            WriteImage(inter_bili, "./Images/NouvellesImages/interpolationBilineaire.pgm");
            break;

        default:
            break;
        }
    case 7:;

        printf("TRANSFORMATIONS LINEAIRES\n\n");
        printf("1- TRANSFORMATION LINEAIRE \n");
        printf("2- TRANSFORMATIONS LINEAIRE AVEC SATURATION\n");

        int choix7 = 0;
        printf("Choisir une operation : \n");
        scanf("%d", &choix7);

        printf("Entrer le chemin d'acces à l'image: ");
        scanf("%s", path1);

        Image img_lin = readImage(path1);
        switch (choix7)
        {
        case 1:;
            Image trans_lineaire = transformation_lineaire(img_lin);
            WriteImage(trans_lineaire, "./Images/NouvellesImages/transformationLineaire.pgm");
            break;

        case 2:;
            int min, max;
            printf("Entrer le seuil min: ");
            scanf("%d", &min);
            printf("Entrer le seuil max: ");
            scanf("%d", &max);
            Image trans_saturation = transformation_lineaire_avec_saturation(img_lin, min, max);
            WriteImage(trans_saturation, "./Images/NouvellesImages/transformationLineaireAvecSaturation.pgm");
            break;

        default:
            break;
        }
        break;

    case 8:;
        printf("CONVOLUTION\n\n");
        printf("1- FILTRE MOYENNEUR\n");
        printf("2- FILTRE GAUSSIEN\n");
        printf("3- FILTRE MEDIAN\n");

        int choix8 = 0;
        int long_filtre = 0;
        printf("Choisir une operation : ");
        scanf("%d", &choix8);

        printf("Entrer le chemin d'acces à l'image: ");
        scanf("%s", path1);
        Image img_conv = readImage(path1);

        switch (choix8)
        {
        case 1:;
            printf("Entrer la longueur du filtre: ");
            scanf("%d", &long_filtre);
            Image filtre_moy = filtreMoyenneur(img_conv, long_filtre);
            WriteImage(filtre_moy, "./Images/NouvellesImages/filtreMoyenneur.pgm");
            break;

        case 2:;
            printf("Entrer la longueur du filtre: ");
            scanf("%d", &long_filtre);
            Image filtre_gauss = filtreGaussien(img_conv, long_filtre);
            WriteImage(filtre_gauss, "./Images/NouvellesImages/filtreGaussien.pgm");
            break;
        case 3:;

            int choices = 0;
            Image img_med = readImage(path1);

            printf("Filtre 3*3 ou 5*5 ? 1 pour 3 et 2 pour 5\n");
            scanf("%d", &choices);

            if (choices == 1)
            {
                Image median = filtreMedian(img_med, 3, 3);
                WriteImage(median, "./Images/NouvellesImages/filtreMedian3.pgm");
            }
            else if (choices == 2)
            {
                Image median = filtreMedian5(img_med, 5, 5);
                WriteImage(median, "./Images/NouvellesImages/filtreMedian5.pgm");
            }

            break;

        default:

            break;
        }
        break;

    case 9:;
        int choix10 = 0;
        printf("DETECTION DE CONTOURS\n\n");
        printf("1- FILTRE DE ROBERT\n");
        printf("2- FILTRE DE PREWITT\n");
        printf("3- FILTRE DE SOBEL\n");
        printf("4- FILTRE LAPLACIEN\n");

        printf("Choisir une opération : ");
        scanf("%d", &choix10);

        printf("Entrer le chemin d'acces à l'image: ");
        scanf("%s", path1);
        Image img_cont = readImage(path1);

        switch (choix10)
        {
        case 1:;
            printf("1- FILTRE DE ROBERT\n");

            Image robert_x = filtreRobert(img_cont, 1);
            Image robert_y = filtreRobert(img_cont, 2);

            Image robert_final = addition(robert_x, robert_y);
            WriteImage(robert_final, "./Images/NouvellesImages/filtreRobert.pgm");

            break;
        case 2:;
            printf("FILTRE DE PREWITT\n");
            int value = 0;
            printf("contours verticaux ou horizontaux ? 1 pour verticaux et 2 pour horizontaux : ");
            scanf("%d", &value);

            if (value == 1)
            {
                Image prewitt_x = filtrePrewitt(img_cont, 1);
                WriteImage(prewitt_x, "./Images/NouvellesImages/filtrePrewittx.pgm");
            }
            else if (value == 2)
            {
                Image prewitt_y = filtrePrewitt(img_cont, 2);
                WriteImage(prewitt_y, "./Images/NouvellesImages/filtrePrewitty.pgm");
            }

            // Image prewitt_x = filtrePrewitt(img_cont, 1);
            // Image prewitt_y = filtrePrewitt(img_cont, 2);

            // Image prewitt_final = addition(prewitt_x, prewitt_y);
            // WriteImage(prewitt_final, "./Images/NouvellesImages/filtrePrewitt.pgm");
            break;

        case 3:;
            int val = 0;
            printf("FILTRE DE SOBEL\n");

            printf("contours verticaux ou horizontaux ? 1 pour verticaux et 2 pour horizontaux : ");
            scanf("%d", &val);

            if (val == 1)
            {
                Image sobel_x = filtreSobel(img_cont, 1);
                WriteImage(sobel_x, "./Images/NouvellesImages/filtreSobelx.pgm");
            }
            else if (val == 2)
            {
                Image sobel_y = filtreSobel(img_cont, 2);
                WriteImage(sobel_y, "./Images/NouvellesImages/filtreSobely.pgm");
            }

            // Image sobel_x = filtreSobel(img_cont, 1);
            // Image sobel_y = filtreSobel(img_cont, 2);
            // Image sobel_final = addition(sobel_x, sobel_y);

            // WriteImage(sobel_x, "./Images/NouvellesImages/filtreSobel.pgm");
            break;
        case 4:;
            printf("FILTRE LAPLACIEN\n");
            Image laplacien = filtreLaplacien(img_cont);
            WriteImage(laplacien, "./Images/NouvellesImages/filtreLaplacien.pgm");
            break;

        default:
            break;
        }

        break;

    case 10:;

        int choice = 0;
        printf("SEGMENTATION\n\n");
        printf("1- SEUILLAGE\n");
        printf("2- OTSU\n\n");

        printf("choisir une operation: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:;
            printf("Entrer le chemin d'acces à l'image: ");
            scanf("%s", path1);
            Image img_seg = readImage(path1);
            int nbseuils;
            // Image img_seuil = seuillage(img_seg);

            printf("Entrer le nombre de seuils :");
            scanf("%d", &nbseuils);
            Image img_seuil = seuillage_fixe(img_seg, nbseuils);
            WriteImage(img_seuil, "./Images/NouvellesImages/ImageSeuillee.pgm");

            break;

        case 2:;

            char path4[50];
            int nb_seuil = 254;
            int *seuils;

            seuils = malloc(254 * sizeof(int));
            for (int i = 0; i < nb_seuil; i++)
            {
                seuils[i] = i + 1;
            }

            printf("Entrer le chemin d'acces à l'image: ");
            scanf("%s", &path4);
            Image ots = readImage(path4);
            int seuil = Otsu(ots, seuils, nb_seuil);

            printf("Meilleur seuil : %d", seuil);
            Image finale = binarisation(ots, seuil);
            WriteImage(finale, "./Images/NouvellesImages/ImageOtsu.pgm");

            printf("\nOpération effectuée avec succes\n");

            break;

        default:
            break;
        }

        break;

    case 11:;
        printf("CALCUL DU CONTRASTE\n");

        printf("Entrer le chemin d'acces à l'image: ");
        scanf("%s", path1);
        Image img_con = readImage(path1);
        float con = contraste(img_con);
        printf("le contraste est %f : ", con);

        break;
    case 12:;
        printf("\nTRANSFORMEE DE HOUGH\n");
        printf("Entrer le chemin d'acces à l'image: ");
        scanf("%s", path1);
        Image imge = readImage(path1);
        Image hou = transformeeHough(imge);
        WriteImage(hou, "./Images/NouvellesImages/ImageHough.pgm");
        break;

    case 13:;
        printf("\nROTATION\n");
        printf("Entrer le chemin d'acces à l'image: ");
        scanf("%s", path1);
        Image img_rot = readImage(path1);
        Image rot = rotation(img_rot);
        WriteImage(rot, "./Images/NouvellesImages/ImageRotee.pgm");
        break;
    }

    return 0;
}
