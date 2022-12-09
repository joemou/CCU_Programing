#include <stdio.h>

void swap(int **arr1,int **arr2,int n);

int main(){

    int n = 0;
    scanf("%d", &n);
    int array1[n], array2[n];
    for (int i = 0; i < n;i++){
        scanf("%d", &array1[i]);
    }
    for (int i = 0; i < n;i++){
        scanf("%d", &array2[i]);
    }
    
    int *a = array1;
    int *b = array2;
   
    swap(&a, &b, n);
    
    
    printf("1st array: ");
    for (int i = 0; i < n;i++){
        printf("%d ", *(a + i));
    }
    printf("\n2nd array: ");
    for (int i = 0; i < n;i++){
        printf("%d ", *(b + i));
    }
}
void swap(int **arr1,int **arr2,int n){
    int *temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}