PROG = Catarata
CC = gcc
CFLAGS = -Wall -ansi -pedantic -std=c11
OBJS = main.o ppm.o BMP.o bits.o

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

	main.o:
		$(CC) $(CFLAGS) -c main.c
	clean:
		rm -f core $(PROG) $(OBJS)