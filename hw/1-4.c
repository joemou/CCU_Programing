#include <stdio.h>
int main(){
    int arr[4][4];
    int row[4] = {0};
    int col[4] = {0};
    
    for (int i= 0; i < 4;i++){
        
        for (int k = 0; k < 4;k++){
            scanf("%d", &arr[i][k]);
        }
    }

    for (int i= 0; i < 4;i++){
        
        for (int k = 0; k < 4;k++){
            printf("%d",arr[i][k]);
            printf("\t");
        }

        printf("\n");
    }
    
    for (int i= 0; i < 4;i++){
        
        for (int k = 0; k < 4;k++){
            row[i] = row[i] + arr[i][k];
        }
        printf("%d\t", row[i]);
    }
     printf("\n");
     for (int i= 0; i < 4;i++){
        
        for (int k = 0; k < 4;k++){
            col[i] = col[i] + arr[k][i];
        }
        printf("%d\t", col[i]);
    }
    printf("\n");
    printf("%d\t",arr[0][0]+arr[1][1]+arr[2][2]+arr[3][3]);
    printf("%d",arr[0][3] + arr[1][2] + arr[2][1] + arr[3][0]);
    return 0;
}