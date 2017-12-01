//Escrever a saida PPm
#include "mod.h"

void escrever(PPMPixel **imagem,char nome[80],int lin,int col){
	FILE *saida=fopen(nome,"w+");
	int i,j;
	//impressao da imagem
	fprintf(saida, "%s\n","P3" );//Essa sessao foi para imprimir a imagem em preto e branco e testar se funcionou o codigo
	fprintf(saida, "%d\n",lin );
	fprintf(saida, "%d\n",col );
	fprintf(saida, "%d\n",255);		
	
	for(i = 0; i < lin; i++){
		for(j=0;j<col;j++){
			fprintf(saida,"%d\n%d\n%d\n",imagem[i][j].R,imagem[i][j].G,imagem[i][j].B);
		}
	}
}
void pretoBranco(PPMPixel **imagem,char cod[3],int lin,int col,int intens){
	//FILE *saida=fopen("PretoEBranco.ppm","w+");
	int pretoEbranco,i,j;
	//impressao da imagem
/*	fprintf(saida, "%s\n",cod );//Essa sessao foi para imprimir a imagem em preto e branco e testar se funcionou o codigo
	fprintf(saida, "%d\n",lin );
	fprintf(saida, "%d\n",col );
	fprintf(saida, "%d\n",intens);
*/

	//Para a imagem ficar preto e branco foi utilizada o metodo passado no arquivo do projeto
	for(i = 0; i < lin; i++){
		for(j=0;j<col;j++){
			pretoEbranco=(imagem[i][j].R*0.3)+(imagem[i][j].G*0.59)+(imagem[i][j].B*0.11);
			imagem[i][j].R=imagem[i][j].G=imagem[i][j].B=pretoEbranco;
			//fprintf(saida,"%d\n%d\n%d\n",pretoEbranco,pretoEbranco,pretoEbranco);
		}
	}
	gaussiano(imagem,lin,col);
	escrever(imagem,"PretoEBranco.ppm",lin,col);
}
//Funcao convolucao adaptada do codigo do professor disponibilizado no sigaa
//Juntamente com o site https://docs.gimp.org/2.8/pt_BR/plug-in-convmatrix.html
void convolucao(PPMPixel **imagem,int alt,int larg,int lin,int col,int kernel[][col],int intens){
	// FILE *gaussiano=fopen("gaussiano.ppm","w+");
	int offLinha, offColuna;
	int i,j,m,n;
	PPMPixel imgAux;
	//Area de verificacao do filtro
	for(i = 0; i<lin; i++){
		for(j = 0; j<col; j++){
			imgAux.R = imgAux.G = imgAux.B = 0;

			for(m=0,offLinha=-lin/2; m<lin; m++,offLinha++){
				for(n=0,offColuna=-col/2; n<col;n++,offColuna++){
					//O pixel esta na borda?
					if (i+offLinha >= 0 && i+offLinha < alt && j+offColuna >= 0 && j+offColuna < larg){
						imgAux.R += (imagem[i+offLinha][j+offColuna].R * kernel[m][n])/intens;
						imgAux.G += (imagem[i+offLinha][j+offColuna].G * kernel[m][n])/intens;
						imgAux.B += (imagem[i+offLinha][j+offColuna].B * kernel[m][n])/intens;					
					}
				}
			}
			//Atualizacao da imagem
			imagem[i][j]=imgAux;
		}
	}
	escrever(imagem,"Gaussiano.ppm",alt,larg);
}
//Embassa a imagem
void gaussiano(PPMPixel** imagem,int lin, int col){
//Inclui uma matriz predefinida no projeto
	int filtro[5][5] = {{2,4,5,4,2},
						{4,9,12,9,4},
						{5,12,15,12,5},
						{4,9,12,9,4},
						{2,4,5,4,2}};

	convolucao(imagem,lin,col,5,5,filtro,159); //159 foi o valor sugerido pelo projeto
}