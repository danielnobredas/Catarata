/* PARA LER E GUARDAR OS DADOS DA IMAGEM PPM */

#include "mod.h"

void lerPPM(FILE *imagem){
	FILE *saida=fopen("saida.ppm","w+");
	int i,j;
	char codigo[3];
	int linha, coluna,intensidade,pretoEbranco;
	PPMImage **ppm;
	fscanf(imagem,"%s",codigo);
	fscanf(imagem,"%d",&linha);
	fscanf(imagem,"%d",&coluna);
	fscanf(imagem,"%d",&intensidade);
	printf("%s %d %d\n",codigo,linha,coluna );
	ppm=(PPMImage**)calloc(linha,sizeof(PPMImage*));
	for (int i = 0; i < linha; ++i) ppm[i]=(PPMImage*)calloc(coluna,sizeof(PPMImage));
	if(!ppm) fprintf(stderr, "Erro ao alocar memoria\n");
	for(i = 0; i < linha; i++){
		for(j=0;j<coluna;j++){
			fscanf(imagem,"%d %d %d",&(ppm[i])[j].pixel.R,&(ppm[i])[j].pixel.G,&(ppm[i])[j].pixel.B);
			// fprintf(saida,"%d\n %d\n %d\n",(ppm[i])[j].pixel.R,(ppm[i])[j].pixel.G,(ppm[i])[j].pixel.B);
			
		}
	}

//Saida imagem	
	fprintf(saida, "%s\n",codigo );
	fprintf(saida, "%d\n",linha );
	fprintf(saida, "%d\n",coluna );
	fprintf(saida, "%d\n",intensidade);


	for(i = 0; i < linha; i++){
		for(j=0;j<coluna;j++){
			//Para a imagem ficar preto e branco foi utilizada o metodo passado no projeto
			pretoEbranco=(ppm[i][j].pixel.R*0.3)+(ppm[i][j].pixel.G*0.59)+(ppm[i][j].pixel.B*0.11);
			fprintf(saida,"%d\n%d\n%d\n",pretoEbranco,pretoEbranco,pretoEbranco);

		}
//# CREATOR: GIMP PNM Filter Version 1.1
	}
	fclose(saida);
}
