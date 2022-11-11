#include <stdio.h>
int main(){
    int gram; //coffee gram


    scanf("%d", &gram);

    int a = gram / 100;
    int b = gram % 100 / 50;
    int c = gram % 50 / 10;
    int d = gram % 10 / 5;
    int e = gram % 5;

    printf("100g bags: %d\n50g bags: %d\n10g bags: %d\n5g bags: %d\n1g bags: %d\n", a, b, c, d, e);

    return 0;
}