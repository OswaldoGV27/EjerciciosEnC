#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        if(n < 21){ 
            for (int i = 0; i < n*2; ++i) {
                for (int j = 0; j < n; ++j) {
                    if ((i/2 + j) % 2 == 0){
                        printf("##");
                    }else{
                        printf("..");
                    }
                }printf("\n");
            }
        }else return printf("n debe ser menor o igual a 20");
    }
    return 0;
}