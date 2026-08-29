#include <stdio.h>
#include <stdlib.h>

struct persona{
    int id;
    char aPaterno[10];
    char aMaterno [10];
    char nombre[20];
    float estatura;
    char email[20];
};

int main(){
    int i=0, persona[20];
    struct persona;

    FILE*fp;

    for (i=0; i<20; i++)
           persona[i]=i;
    fp=fopen("binario.dat","wb");

    if(fp==NULL){
        printf("\nError de apertura del archivo. \n");
    }
    else{
        fwrite(persona, sizeof(int), 20, fp);
    }
    fclose(fp);


    return 0;
}