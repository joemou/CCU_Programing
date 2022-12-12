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


/*void swap(int *num1, int *num2); //先告訴電腦說我有一個函式
int main()
{
    int a = 10;
    int b = 25;
    printf("a is %d\n, b is %d", a, b);
    swap(&a, &b); // 分別傳入記憶體位址
    printf("a is %d\n, b is %d", a, b);
    return 0;
}
void swap(int *num1, int *num2)
{
     int temp;
     temp = *num1;
     *num1 = *num2;
     *num2 = temp;
}
*/