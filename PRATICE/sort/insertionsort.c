#include <stdio.h>

void insertionsort(int a[],int n){
    for (int i =1; i < n;i++){
        int pin = i;
        int value = a[i];

        while(pin>0&&value<a[pin-1]){
            a[pin] = a[pin - 1];
            pin--;
        }

        a[pin] = value;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n;i++){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n;i++){
        printf("%d ", a[i]);
    }
    insertionsort(a, n);
    printf("\n");
    for (int i = 0; i < n;i++){
        printf("%d ", a[i]);
    }
}
