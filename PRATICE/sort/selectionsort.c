#include <stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionsort(int a[],int n){
    for (int i = 0; i < n - 1;i++){
        int min = i;
        for (int j = i+1; j < n;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        swap(&a[min], &a[i]);
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
    selectionsort(a, n);
    printf("\n");
    for (int i = 0; i < n;i++){
        printf("%d ", a[i]);
    }
}
