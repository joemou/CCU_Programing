#include <stdio.h>
#include <stdlib.h>

unsigned short swap_bytes(unsigned short i) {
    return (i << 8) | (i >> 8);
}



int main() {

    unsigned short number;
    scanf("%hx", &number);

    unsigned short ans = swap_bytes(number);
    printf("%hx\n", ans);

    return 0;
}
