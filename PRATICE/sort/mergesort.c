#include <stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void mergesort(int a[],int n){
    for (int i = 0; i < n ;i++){
        for (int k = 0; k < n-1-i;k++){
            if(a[k]>a[k+1]){
                swap(&a[k], &a[k + 1]);

            }
        }

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
    bubblesort(a, n);
    printf("\n");
    for (int i = 0; i < n;i++){
        printf("%d ", a[i]);
    }
}
