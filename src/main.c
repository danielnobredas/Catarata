#include "mod.h"

int main(int argc, char **argv){
	//Variaveis do GETOPT
	int c,aflag=0,bflag=0,index;
	char *tipoImg = NULL;
	//Variaveis normais
	FILE *img;

	opterr = 0;


	//GETOPT recebendo as variaveis
	while ((c = getopt (argc,argv, "i:f:oh")) != -1)
		switch (c){
			case 'i':
				aflag=1;
				break;
			case 'f':
				tipoImg = optarg;
				if (strcmp(tipoImg,"ppm"));
				else printf("Arquivo de imagem invalido ou nao suportado.\n");
				break;
			case 'h':
				printf("\v%s\v\n\t%s %50s\n\t%s %45s\n\t%s %62s\n","Uso padrao: ./catarata -i imagem.ppm -f ppm -o texto.txt","-i <input-image>","Nome do arquivo de imagem.","-f <input-image-format>","Formato do arquivo de imagem","-o <diagnose-file>","Nome do arquivo de texto de diagnostico.");
				break;
			default:
				fprintf(stderr, "%s\n","Parametro invalido. Digite -h para ajuda");
		}	

	return 0;
}

//				fprintf(stderr, "%s\n","Parametro invalido. Digite -h para ajuda");
