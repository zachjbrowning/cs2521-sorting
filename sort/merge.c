#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define MAXLINE 10000

/*
    This file reads in line by line from two files, and merges them 
    based on the string. Output to stdout.
*/
int main(int argc, char *argv[]) {
    //Ensure file usage is correct
    if (argc < 3) {
        fprintf(stderr, "Usage: ./merge  File1  File2\n");
        return -1;  // error code
    }
    //Open files
    FILE *f1 = fopen(argv[1],"r");
    FILE *f2 = fopen(argv[2],"r");
    //Check files were opened properly
    if (f1 == NULL || f2 == NULL) {
        fprintf(stderr, "Couldn't open file(s)\n");
        return -1;  // error code
    }
    // initialise place to save lines, and checks to see if there is more lines
    char input1[MAXLINE], input2[MAXLINE];
    bool isInput1 = fgets(input1,MAXLINE,f1);
    bool isInput2 = fgets(input2,MAXLINE,f2);
    //While there is still lines from both inputs
    //Only output the lesser input, then get more input
    while (isInput1 && isInput2) {
        if (strcmp(input1,input2) <= 0) {
            fputs(input1,stdout);
            isInput1 = fgets(input1,MAXLINE,f1);
        }
        else {
            fputs(input2,stdout);
            isInput2 = fgets(input2,MAXLINE,f2);
        }
    }
    //One of the inputs has diminished, output all that is left
    while (fgets(input1,MAXLINE,f1) != NULL) fputs(input1,stdout);
    while (fgets(input2,MAXLINE,f2) != NULL) fputs(input2,stdout);
    //clean up
    fclose(f1);  fclose(f2);
}