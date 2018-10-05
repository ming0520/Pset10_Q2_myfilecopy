/*
 ============================================================================
 Name        : Pset10_Q2_myfilecopy.c
 Author      : Zhong Ming Tan
 Version     :
 Copyright   : Zhong Ming Tan @ 2018
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    setvbuf(stdout,NULL,_IONBF,0);
    setvbuf(stderr,NULL,_IONBF,0);

    if(argc != 3){
        system("color 0C");
        printf("myfilecopy source.c target.c\n");
        printf("Press <ENTER> to exit\n");
        getchar();
        return 1;
    }

    FILE *source,*target;
    char ch;

    source = fopen(argv[1],"r");
    target = fopen(argv[2],"w");

    if(source == NULL){
        printf("The file is invalid!\n");
        printf("Press <ENTER> to exit\n");
        getchar();
        exit(0);
    }

    /*printf("Enter the source file\n");
    scanf("%s",path);
    fflush(stdin);

    source = fopen(path,"r");

    if(source == NULL){
        printf("File are not exist!\n");
        exit(0);
    }

    printf("Enter the target file\n");
    scanf("%s",path);
    fflush(stdin);

    target = fopen(path,"w");

    if(target == NULL){
        printf("File are not exist!\n");
        exit(0);
    }*/

    ch = fgetc(source);
    printf("Coping file....\n");

    while (ch != EOF){
        fputc (ch, target);
        ch = getc(source);
    }

    printf("Copied successfully\n");

    fclose(source);
    fclose(target);
    return 0;
}
