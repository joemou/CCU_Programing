#include <stdio.h>

void congruence_modulo(int a, int b, int c, int m) {
    for (int x = a; x <= b; x++) {
        if ((x - c) % m == 0) {
            printf("%d ", x);
        }
    }
}

int main() {
    int a, b, c, m;
    scanf("%d %d %d %d", &a, &b, &c, &m);
    congruence_modulo(a, b, c, m);
    return 0;
}

