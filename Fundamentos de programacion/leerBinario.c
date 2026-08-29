#include <stdio.h>

int main(){

    FILE*fp;
    int i, v[20];

    for (i=0; i<20; i++)
           v[i]=i;
    fp=fopen("primeros.dat","wb");

    if(fp==NULL){
        printf("\nError de apertura del archivo. \n");
    }
    else{
        fwrite(v, sizeof(int), 20, fp);
    }
    fclose(fp);
    
    return 0;
}