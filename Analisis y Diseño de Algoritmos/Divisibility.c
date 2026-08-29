#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int M;
    scanf("%d", &M);

while (M--) {
        int N, K;
        scanf("%d %d", &N, &K);

        if( N < 1 || N > 10000 || K < 2 || K > 100){ /*Verificación de las condiciones de N y K*/
            return 0;
        }
        else
        {
            /*En esta parte del codigo guardamos los valores de N y K, y luego la secuencia de N enteros que 
            se almacenarán en el arreglo nums para hacer operaciones con ellos mas adelante, ademas de usar 
            el while como controlador de los casos de prueba. */
            int nums[10000];
            int i;
            for (i = 0; i < N; i++) {
                scanf("%d", &nums[i]);
            }
        
            /*Se utiliza una matriz dp de dos filas para almacenar los posibles restos (módulos) de las sumas 
            y restas de los números de la secuencia. La matriz dp se inicializa con ceros, excepto dp[0][0],
            que se establece en 1 como caso base.*/
            int dp[2][10000];
            memset(dp, 0, sizeof(dp));
            dp[0][0] = 1;
        
            int NumAct = 0, j;
            /*Se recorre cada número de la secuencia y se actualiza la matriz dp para cada posible resto, 
            alternando entre las dos filas para cada número.*/
            for (j = 0; j < N; j++) {
                NumAct = !NumAct; /*Alternamos entre 0 y 1*/
                memset(dp[NumAct], 0, sizeof(dp[NumAct]));
                int l;
                for (l = 0; l < K; l++) {
                    /*Para cada número, se calculan los nuevos restos sumando y restando el número actual a 
                    los restos previamente alcanzables.*/   
                    if (dp[!NumAct][l]) {
                        dp[NumAct][(l + nums[j] + K) % K] = 1;
                        dp[NumAct][(l - nums[j] + K) % K] = 1;
                    }
                }
            }
        
            if (dp[NumAct][0]) { /*Si el resto es 0, es divisible*/
                printf("Divisible\n");
            } else {
                printf("Not divisible\n");
            }
        }
    }
    
    return 0;
}