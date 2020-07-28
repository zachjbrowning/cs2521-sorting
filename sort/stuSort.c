#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAME 1000
#define MAXSTUDES 100
#define MAXLINE 1000

typedef struct _student {
   int  zid;            // 7-digit number
   char name[MAXNAME];  // names are stored *within* the struct
   int  prog;           // 4-digit number
   int  magic;          // random number?
} Student;
 
// return -ve if a < b, +ve if a > b, 0 if a == b
int stuCmp(const void *a, const void *b);



/*
    BEST USAGE : ./stuSort < stuRec
    sorts using stuCmp and qsort, then prints out results.

*/
int main(int argc, char **argv) {
    Student students[MAXSTUDES];
    int nstudes = 0;
    char line[MAXLINE];
 
    // read stdin line-by-line into students[]
    while (fgets(line, MAXLINE, stdin) != NULL) {
        //tokenise each word in the line
        char *token = strtok(line, " ");
        //get zid
        students[nstudes].zid = atoi(token);
        token = strtok(NULL, " ");

        //get name
        memcpy(students[nstudes].name, token, strlen(token));
        token = strtok(NULL, " ");

        //get prog
        students[nstudes].prog = atoi(token);
        token = strtok(NULL, " ");

        //get magic
        students[nstudes].magic = atoi(token);
        nstudes++;
    }
 
    // sort the students[] array
    qsort(students, nstudes, sizeof(Student), stuCmp);



    // print the contents of the students[] array
    for (int i = 0; i < nstudes; i++) printf("%d %s %d %d\n", students[i].zid, students[i].name, students[i].prog, students[i].magic);
     
    return 0;
}




int stuCmp(const void *a, const void *b) {
    
    //return ((*(Student *)a).zid - (*(Student *)b).zid); //ZID
    //return strcmp((*(Student *)a).name,(*(Student *)b).name); //name
    //return ((*(Student *)a).prog - (*(Student *)b).prog); //prog
    return ((*(Student *)a).magic - (*(Student *)b).magic); //magic
}