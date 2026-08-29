#include <stdio.h>
#include <stdlib.h>

int main (){

     char str1[10], str2[10], str3[10], caracter;

     int year, en1;
     float f1, f2, f3, f4;
      FILE* fp;

      fp= fopen("notas2.txt", "w+");

      if(fp==NULL){
        printf("\nError de apertura del archivo. \n");
      }
      //fputs("Estamos eng jggj 2020", fp);

      rewind(fp); //rebobinar enrrollar hacia atras la cinta o carrete

      fprintf(fp, "%d\t%f\t%f\t%f\t%f",5,6.33,-0.325,66.30,100.0);
      //fscanf(fp, "%s %s %s %d", str1, str2, str3, &year);

      fclose(fp);

      fp=fopen("notas2.txt", "r");

      if(fp==NULL){
        printf("\nError de apertura del archivo. \n");
      }
      else{
        printf("\nEl contenido del archivo prueba es \n");
        while((caracter=fgetc(fp)) !=EOF){
            fscanf(fp,"%d\t%f\t%f\t%f\t%f", &en1, &f1, &f2, &f3, &f4);
        }
      }

      printf("%d\n", en1);
      printf("%f\n",f1);
      printf("%f\n",f2);
      printf("%f\n",f3);
      printf("%f\n",f4);

      fclose(fp);
return 0;
}
