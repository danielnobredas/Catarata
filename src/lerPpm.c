/* PARA LER E GUARDAR OS DADOS DA IMAGEM PPM */

#include "mod.h"

void lerPPM(FILE *imagem){
	int i,j;
	char codigo[3];
	int linha, coluna, tamanhoImg,intensidade;
	PPMImage **ppm;
	fscanf(imagem,"%s",codigo);
	fscanf(imagem,"%d",&linha);
	fscanf(imagem,"%d",&coluna);
	fscanf(imagem,"%d",&intensidade);
	printf("%s %d %d\n",codigo,linha,coluna );
	ppm=(PPMImage**)calloc(linha,sizeof(PPMImage*));
	for (int i = 0; i < linha; ++i) ppm[i]=(PPMImage*)calloc(coluna,sizeof(PPMImage));

	for(i = 0; i < linha; i++){
		for(j=0;j<coluna;j++){
			fscanf(imagem,"%d %d %d",&(ppm[i])[j].pixel.R,&(ppm[i])[j].pixel.G,&(ppm[i])[j].pixel.B);
			printf("%d\n %d\n %d\n",(ppm[i])[j].pixel.R,(ppm[i])[j].pixel.G,(ppm[i])[j].pixel.B);
		}
	}
}
