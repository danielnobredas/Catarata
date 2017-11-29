# Catarata

# O que foi feito?
-Leitura e armazenamento da imagem PPM3
-Modularização do arquivo
-Comentários acerca do que está ocorrendo
-Structs e typedefs
-Arranjos e matrizes com alocação dinamica
-Parametros necessários para a execução da imagem incluindo o --help
-Imagem com saída em preto e branco
-Arquivo makefile

# O que não foi feito
-Aplicação do filtro Blur e Threshold
-A separação da iris através da binarização
-Diagnóstico de catarata baseado na porcentagem Threshold da pupila

# O que seria feito diferentemente
-Organização do tempo
-Uma aprofundada maior em como aplicar filtros na imagem

# Como compilar a imagem
Com os arquivos na página correta digitar make no terminal. Para executar o programa
pode se digitar ./catarata -h ou ./catarata --help em caso de precisar de ajuda.
A forma correta de executar o arquivo seria: ./catarata -i imagem.ppm -f ppm -o texto.txt
