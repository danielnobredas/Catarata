//Escrever a saida PPm
#include "mod.h"

void salvarImage(PPMImage **imagem,char cod[3],int lin,int col,int intens){
	FILE *saida=fopen("saida.ppm","w+");
	int pretoEbranco,i,j;
	fprintf(saida, "%s\n",cod );
	fprintf(saida, "%d\n",lin );
	fprintf(saida, "%d\n",col );
	fprintf(saida, "%d\n",intens);


	//Para a imagem ficar preto e branco foi utilizada o metodo passado no arquivo do projeto
	for(i = 0; i < lin; i++){
		for(j=0;j<col;j++){
			pretoEbranco=(imagem[i][j].pixel.R*0.3)+(imagem[i][j].pixel.G*0.59)+(imagem[i][j].pixel.B*0.11);
			fprintf(saida,"%d\n%d\n%d\n",pretoEbranco,pretoEbranco,pretoEbranco);
		}
	}
	fclose(saida);
}

void convolucao(PPMImage **imagem,char cod[3],int lin,int col,int intens){
	FILE *gaussiano=fopen("gaussiano.ppm","w+");
	for(i = 0; i<lin; i++){
		for(j = 0; j<col; j++){
			
		}
	}
}