#include <stdio.h>

void minMax(int x, int y, int *min, int *max) {
    if (x < y) {
        *min = x;
        *max = y;
    } else {
        *min = y;
        *max = x;
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int x, y;
        scanf("%d %d", &x, &y);

        int min, max;
        minMax(x, y, &min, &max);

        printf("%d %d\n", min, max);
    }

    return 0;
}