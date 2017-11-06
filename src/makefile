PROG = catarata
CC = gcc
CFLAGS = -Wall -ansi -pedantic -std=c11
OBJS = main.o lerPpm.o

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

	main.o:
		$(CC) $(CFLAGS) -c main.c
	lerPpm.o:
		$(CC) $(CFLAGS) -c lerPpm.c
	clean:
		rm -f core $(PROG) $(OBJS)