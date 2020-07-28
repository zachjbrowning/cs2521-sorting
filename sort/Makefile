CC = gcc
CFLAGS = -Wall -Werror -std=c11 -g

.PHONY: all
all: tester merge stuSort

tester: tester.c list.c 
	$(CC) $(CFLAGS) list.c tester.c -o tester

merge: merge.c 
	$(CC) $(CFLAGS) merge.c -o merge

stuSort: stuSort.c 
	$(CC) $(CFLAGS) stuSort.c -o stuSort


.PHONY: clean
clean:
	rm -f tester merge stuSort