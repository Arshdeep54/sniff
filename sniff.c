#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){
    if(argc!=3){
        fprintf(stderr,"Usage: %s \"search_string\" filename\n",argv[0]);
        return EXIT_FAILURE;
    }
    FILE *file=fopen(argv[2],"r");
    if(file == NULL){
       perror("Error opening file");
       return EXIT_FAILURE;
    }
    char line[1024];
    int line_number=0;
    while(fgets(line,sizeof(line),file)){
       line_number++;
       if(strstr(line, argv[1])!=NULL){
           printf("Line %d : %s ",line_number,line);
       }
    }
    fclose(file);
    return EXIT_SUCCESS;
}
