#include <stdio.h>

int main(){
    int x=0, miarr[10];
    /*
    f:
    if(x<10){
        printf("%d", x);
        x++;
        goto f;
    }
*/

while(x<10){
    printf("Ingresa el valor %d entero del arreglo\n", x);
    scanf("%d",&miarr[x]);
    //miarr[x]=x;
    x++;
}

x=0;
while(x<10){
    printf("El valor %d es: %d\n", x, miarr[x]);
    x++;
}
    return 0;
}
