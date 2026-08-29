#include <stdio.h>

int main()
{
    int a,b,c,d,e,f,g,arr[3],arr2[3][2],*ptr;
    ptr=&a;

    printf("%p\n",&a);
    printf("%p\n",&b);
    printf("%p\n",&c);
    printf("%p\n",&d);
    printf("%p\n",&e);
    printf("%p\n",&f);
    printf("%p\n",&g);

    printf("Direcciones de memoria de un arreglo unidim\n");
    printf("%p\n",&arr[0]);
    printf("%p\n",&arr[1]);
    printf("%p\n",&arr[2]);

    printf("Direcciones de arreglo bidim\n");
    printf("%p\n",&arr2[0][1]);
    printf("%p\n",&arr2[1][0]);
    printf("%p\n",&arr2[1][1]);
    printf("%p\n",&arr2[2][0]);
    printf("%p\n",&arr2[2][1]);

for(int x=0;x<7;x++){
    *ptr=x; //accede a la direccion de la variable a la que apunta y se le asigna rl valor de x
    ptr--;
    }
    printf("%d\n",a);
    printf("%d\n",b);
    printf("%d\n",c);
    printf("%d\n",d);
    printf("%d\n",e);
    printf("%d\n",f);
    printf("%d\n",g);

return 0;
}