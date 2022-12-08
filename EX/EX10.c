#include <stdio.h>

int main (){
    int size=0,times=0,check=1;
    
    

    /*
    //query 1
    printf("What is the size of the matrix:");

    scanf("%d", &size);
    int matrix[size][size];

    printf("Please enter the matrix:");

    for (int i = 0; i < size;i++){
        for (int k = 0; k < size;k++){
            scanf(" %d", &matrix[i][k]);
        }
    
    }
    //get the matrix value



    for (int i=0; i < size;i++){
        for (int k = size-1; k >= 0;k--){
            printf("%d ", matrix[k][i]);
        }
    }
    //sort it to transform it 90 degree, and print it out
    */
   
/*

    printf("\n");
    //query 2

    printf("Enter the number of input data:");

    scanf("%d", &times);

    while(times--){
        printf("What is the size of the matrix:");
        scanf("%d", &size);
        int matrix[size][size];
        printf("Please enter the matrix:");

        for (int i = 0; i < size;i++){
            for (int k = 0; k < size;k++){
                scanf(" %d", &matrix[i][k]);
         }
    
        }
        //get matrix value
   

        int *a = &matrix[0][0];//a get matrix[0][0]address
        int *b = &matrix[size - 1][size - 1];//a get matrix[size-1][size-1]address

        for (int i = 0; i < size * size;i++){
            if(*a!=*b){
                check = 0;
                break;
            }
            a++;
            b--;
            
        }
        //compare whether their value(*a and *b) are difference or not. if they are difference, they are not symmetric

        if(check==1){
            printf("The matrix is symmetric!\n");
        }
        else if (check==0){
            printf("The matrix is not symmetric!\n");
        }
        
        */
        printf("Enter the number of input data:");
        scanf("%d", &times);
        
        while(times--){
        printf("What is the size of the matrix:");
        scanf("%d", &size);
        
        int matrix[size][size];
        int matrix2[size][size];
        int *c = &matrix[0][0], *d = &matrix2[0][0];
       
        printf("the first matrix:");
        for (int i = 0; i < size;i++){
                scanf("%d", c + i);
        }
        printf("the second matrix:");
        for (int i = 0; i < size;i++){
                scanf("%d", d + i);
        }

        for (int i = 0; i < size;i++){
                printf("%d ", (*(c+i))*(*(d+i)));
        }

    
        

        //get matrix value

        

        }
    }
}