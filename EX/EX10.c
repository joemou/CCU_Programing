#include <stdio.h>

int main (){
    int size=0,times=0,check=1;
    
    

    
    //query 1
    printf("What is the size of the matrix: ");

    scanf("%d", &size);
    int matrix[size][size];

    printf("Please enter the matrix: ");

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
    //change its order to transform it rotating to 90 degree clockwise, and print it out
    
   

    printf("\n");
    //query 2

    printf("Enter the number of input data: ");

    scanf("%d", &times);

    while(times--){
        printf("What is the size of the matrix: ");
        scanf("%d", &size);
        int matrix[size][size];
        printf("Please enter the matrix: ");

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
        //compare the difference between their value(*a and *b). if they are difference, they are not symmetric

        if(check==1){
            printf("The matrix is symmetric!\n");
        }
        else if (check==0){
            printf("The matrix is not symmetric!\n");
        }
        check = 1;
    }
        
        //query 3
        printf("Enter the number of input data: ");
        scanf("%d", &times);
        
    while(times--){
        printf("What is the size of the matrix: ");
        scanf("%d", &size);
        
        int matrix[size][size];
        int matrix2[size][size];
        int *c = &matrix[0][0], *d = &matrix2[0][0]; //set  matrix1[0][0] matrix2[0][0] address to *c *d
       
        printf("the first matrix: ");//get the value of first matrix
        for (int i = 0; i < size*size;i++){
                scanf(" %d", c + i);
        }
        printf("the second matrix: ");//get the value of second matrix
        for (int i = 0; i < size*size;i++){
                scanf(" %d", d + i);
        }
   
        for (int i = 0; i < size;i++){//i use to change first matrix row when we finished the a row space
            
            for (int k = 0; k < size;k++){//k use to change second matrix column when we finished a answer
                int sum = 0; //initialize sum
                    for (int l = 0; l < size;l++){//l use to multiply each matrix element to get a answer
                        sum += (*(c + size*i + l)) * (*(d + k + (size * l)));//l use to 
                    }
                printf("%d ", sum);
            

                }

            
            }


        
        printf("\n");
    }
        
}