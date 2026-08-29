#include<stdio.h>
//Oswaldo Gil Valentin 1CV6
int main() {
    int x, y;
    for(x=-9; x<=10; x++) {
        for(y=-9; y<=10; y++) {
            if(x > -10 && y < 10 && (x*y == 3)) {
                printf("-------------------------------------------\n");
                printf("Los valores que satisfacen la expres%cn son:\n", 162);
                printf("x = %d, y = %d\n", x, y);
                printf("-------------------------------------------\n");
                return 0;
            }
        }
    }
    printf("No existen valores X ni Y que satisfagan la expresi%cn.\n", 162);
    return 0;
}