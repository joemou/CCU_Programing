#include <stdio.h>

unsigned int getRangeBits(unsigned int A, int i, int j) {
    unsigned int mask = ((1 << (j - i + 1)) - 1) << i;
    unsigned int rangeBits = (A & mask) >> i;
    return rangeBits;
}

unsigned int concatenate(unsigned int A, int i, int j, unsigned int B, int x, int y) {
    unsigned int rangeA = ((A >> i) & ((1 << (j - i + 1)) - 1));
    unsigned int rangeB = ((B >> x) & ((1 << (y - x + 1)) - 1));
    unsigned int concatenated = (rangeA << (y - x + 1)) | rangeB;
    return concatenated;
}   

int main() {
    int times;
    unsigned int num, c, v = 520;

    scanf("%d", &times);

    while (times > 0) {
        scanf("%u", &num);
        c = num ^ 3610409;
        c = c ^ getRangeBits(c, 1, 8);
        v = concatenate(v, 9, 32, c, 1, 8);
        times--;
        printf("%d ", v);

    }

    return 0;
}
