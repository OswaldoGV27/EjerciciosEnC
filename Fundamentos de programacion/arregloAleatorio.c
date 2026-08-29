#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){

    int x, y, elDoble, miarr[16];
    float division;
    srand((NULL));
    
x=1;
while(x<16){
    y=-100+rand()%101;
    printf("El valor %d es: %d\n", x, miarr[y]);
    elDoble=miarr[y]*2;
    printf("El doble del arreglo es: %d\n", elDoble, miarr[y]);
    division=(float)miarr[y]/(float)3;
    printf("El resultado de la division entre 3 del arreglo es: %.2f \n", division);
    x++;
}
    return 0;
}