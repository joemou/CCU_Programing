#include <stdio.h>
int main(){
    int i,row, space, star;

    scanf("%d", &row);

    for (i=1;i<=row;i++){
        for (space = 1; space <= row - i;space++){
            printf(" ");
        }
        for (star = 1; star <= 2*i - 1;star++){
            printf("*");
        }
        printf("\n");
    }

        return 0;
}