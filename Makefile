CC = gcc
CC_FLAG = -Wall -O2 -o
O_FILE = main.o levenshtein.o

install:$(O_FILE)
	$(CC) $(O_FILE) $(CC_FLAG) run

main.o:
	$(CC) main.c -c

levenshtein.o:
	$(CC) levenshtein.c -c 

.PRONY:clean
clean:
	rm -rf $(O_FILE)
