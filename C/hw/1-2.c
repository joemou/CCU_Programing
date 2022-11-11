#include <stdio.h>
int main(){
    int m, d, y, item;
    float price;

    scanf("%d %f %d/%d/%d", &item, &price, &m, &d, &y);

    printf("Item\tUnit\tPurchase\n");
    printf("    \tPrice\tDate\n");
    printf("%d\t$%.2f\t%02d\\%02d\\%04d", item, price, m, d, y);

    return 0;
}