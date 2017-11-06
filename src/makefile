PROG = catarata
CC = gcc
CFLAGS = -Wall -ansi -pedantic -std=c11
OBJS = main.o lerPPM.o

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

	main.o:
		$(CC) $(CFLAGS) -c main.c
	lerPPM.o:
		$(CC) $(CFLAGS) -c lerPPM.c
	clean:
		rm -f core $(PROG) $(OBJS)