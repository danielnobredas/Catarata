#include "mod.h"

int main(int argc, char **argv){
	//Variaveis normais
	FILE *img;
	char *nomeImg = malloc(82*sizeof(char));
	char *formImg = malloc(10*sizeof(char));
	char *diagImg = malloc(82*sizeof(char));
	//Variaveis do GETOPT adatado de: http://mindbending.org/pt/argumentos-e-parametros-em-c
	short imagem = 0, formato = 0, diagnostico=0;
	char optc = 0;

	//Para os parametros longos
	struct option Longas[] = {
		{"imagem", no_argument, NULL, 'i'},
		{"formato", no_argument, NULL, 'f'},
		{"diagnostico", no_argument, NULL, 'o'},
		{"help", no_argument, NULL, 'h'},
		{0,0,0,0}
	};

	//Caso nao exista argumentos
	if(argc == 1){
		printf("Parametros faltando. Digite -h ou --help para obter ajuda.\n");
		exit(0);
	}

	//GETOPT recebendo os parametros
	while ((optc = getopt_long(argc,argv, "ifho:", Longas, NULL)) != -1)
		switch (optc){
			case 'i':
				*nomeImg = optc;
				break;
			case 'f':
				*formImg = optc;
				if (!strcmp(formImg,"ppm")) printf("Arquivo de imagem invalido ou nao suportado. Digite -h ou --help para obter ajuda.\n");
				break;
			case 'o':
				*diagImg = optc;
			case 'h':
				printf("\v%s\v\n\t%s %50s\n\t%s %45s\n\t%s %62s\n","Uso padrao: ./catarata -i imagem.ppm -f ppm -o texto.txt","-i, -image>","Nome do arquivo de imagem.","-f <input-image-format>","Formato do arquivo de imagem","-o <diagnose-file>","Nome do arquivo de texto de diagnostico.");
				break;
			default:
				fprintf(stderr, "%s\n","Parametros invalidos. Digite -h ou --help para obter ajuda.");
				exit(0);
		}	
	printf("%s\n",*nomeImg);
	return 0;
}

//				fprintf(stderr, "%s\n","Parametro invalido. Digite -h para ajuda");