#include <stdio.h>

//Prototipos
int elDoble();
int SumandoDosNumeros(int *, int *);

//Funcion Principal
//Tipo de retorno nombreDeFunción(parametros){Cuerpo;retorno}
int main (){
    int doble, a=100, b=200;
    //doble=elDoble();
    //printf("el doble es: %d", doble)
    /*/
    printf("Ingresa el primer valor a sumar\n");
    scanf("%d", &var1);
    printf("Ingresa el segund valor a sumar\n");
    scanf("%d", &var2);
    */
   printf("El resultado de la suma es: %d", SumandoDosNumeros(&a,&b));
   return 0;
}

   //definiendo las funciones
   int elDoble(){
    int x;
    printf("Ingresa el primer valor entero\n");
    scanf("%d", &x);
    return x*2;
   }

   int SumandoDosNumeros( int *a, int *b){
    *a=1000; *b=500;
    return *a+*b;
   }



