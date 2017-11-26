#ifndef MOD_H
#define MOD_H

//Importacao de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>

//Sructs
typedef struct tagPPMPixel{
	int R,G,B;
}PPMPixel;

typedef struct tagPPMImage{
	int data;
	PPMPixel pixel;
}PPMImage;

void lerPPM(FILE *imagem);

void salvarImage(PPMImage **imagem,char cod[3],int lin,int col,int intens);

#endif