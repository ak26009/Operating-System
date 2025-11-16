#include<stdio.h>

int main(){

    FILE *src;
    char msg[] = "Atharva" ;
    src = fopen("file.txt","w");

    fprintf(src,"From :%s",msg);
    // fputs(msg,src);

    fclose(src);


}
