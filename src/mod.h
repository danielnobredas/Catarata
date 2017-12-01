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

void escrever(PPMPixel **imagem,char nome[80],int lin,int col);

void lerPPM(FILE *imagem);

void pretoBranco(PPMPixel **imagem,char cod[3],int lin,int col,int intens);

void convolucao(PPMPixel **imagem,int alt,int larg,int lin,int col,int kernel[][col],int intens);

void gaussiano(PPMPixel** imagem,int lin, int col);


#endif