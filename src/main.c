#include "mod.h"

int main(int argc, char **argv){
	//Variaveis normais
	FILE *img;
	FILE *output;
	char *nomeImg = malloc(82*sizeof(char));
	char *formImg = malloc(10*sizeof(char));
	char *diagImg = malloc(82*sizeof(char));
	//Variaveis do GETOPT adatado de: http://mindbending.org/pt/argumentos-e-parametros-em-c
	short imagem = 0, formato = 0, diagnostico=0;
	char optc = 0;

	//Para os parametros longos
	struct option Longas[] = {
		{"imagem", required_argument, NULL, 'i'},
		{"formato", required_argument, NULL, 'f'},
		{"diagnostico", required_argument, NULL, 'o'},
		{"help", no_argument, NULL, 'h'},
		{0,0,0,0}
	};

	//Caso nao exista argumentos
	if(argc == 1){
		printf("Parametros faltando. Digite -h ou --help para obter ajuda.\n");
		exit(0);
	}

	//GETOPT recebendo os parametros
	while ((optc = getopt_long(argc,argv, "i:o:f:h", Longas, NULL)) != -1)
		switch (optc){
			case 'h': //Help
				printf("\v%s\v\n\t%s %50s\n\t%s %78s\n\t%s %59s\v\n","Uso padrao: ./catarata -i imagem.ppm -f ppm -o texto.txt","-i|--imagem","Nome do arquivo de imagem.","-f|--formato","Formato do arquivo de imagem.(Formatos suportados: PPM)","-o|--diagnostico","Nome do arquivo de texto de diagnostico.");
				return 1;
				break;
			case 'i'://Nome da imagem
				nomeImg = optarg;
				break;
			case 'f'://formato da imagem
				formImg = optarg;
				if (strncmp(formImg,"ppm",3)!=0){ 
					printf("Arquivo de imagem invalido ou nao suportado. Digite -h ou --help para obter ajuda.\n");
					return 1;
				}
				break;
			case 'o'://arquivo de saida.txt
				diagImg = optarg;
				break;
			default:
				fprintf(stderr, "%s\n","Parametros invalidos. Digite -h ou --help para obter ajuda.");
				return 1;
		}	

	//Criacao dos arquivos com base nos argumentos antes dados
	img = fopen(nomeImg,"r");
	if (!img){
		fprintf(stderr, "Nao foi possivel abrir o arquivo '%s'.\nCertifique-se de que foi digitado corretamente ou se o arquivo se encontra nesta pasta.\n",nomeImg );
		return 1;
	}
	output = fopen(diagImg,"w+");
	
	
	return 0;
}

//				fprintf(stderr, "%s\n","Parametro invalido. Digite -h para ajuda");