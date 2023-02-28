#include <stdio.h>
int main(){
    int arr[6];
    scanf("%d-%d-%d-%d-%d", &arr[1], &arr[2], &arr[3], &arr[4], &arr[5]);

    printf("%03d\n", arr[1]);
    printf("%03d\n", arr[2]);
    printf("%03d\n", arr[3]);
    printf("%03d\n", arr[4]);
    printf("%03d\n", arr[5]);

        
            return 0;
}