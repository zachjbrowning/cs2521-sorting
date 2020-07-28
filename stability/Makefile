CC = gcc
CFLAGS = -Wall -Werror -std=c99

.PHONY: all
all: tester 

tester: tester.c check.c sort.c 
	$(CC) $(CFLAGS) -o tester tester.c check.c sort.c



.PHONY: clean
clean:
	rm -f tester