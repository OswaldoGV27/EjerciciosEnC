//Oswaldo Gil Valenín 1CV8 Ejercicio de lectura y escritura
#include <stdio.h>

int main() {

    float a, b, c, suma, producto;
    float promedio;
    printf("Ingrese el primer numero entero ");
    scanf("%f",&a);
    printf("Ingrese el segundo numero entero ");
    scanf("%f",&b);
    printf("Ingrese el tercer numero entero ");
    scanf("%f",&c);

    suma=a+b+c;
    producto=a*b*c;
    promedio=(a+b+c)/3;
    
    printf("La suma de los 3 numeros enteros es: %.0f \n", suma);
    printf("El producto de los 3 numeros entero es: %.0f \n", producto);
    printf("El promedio de los 3 numeros enteros es: %.2f \n", promedio);
}