#include <stdio.h>

void UpperTriangularMatrix(int row, int col)
{
       int a[row][col];
       printf("\nEnter the Elements \n");
      
       // Nested loop to input array elements from the user
       for(int i = 0; i<row; i++)
       {
         for(int j = 0; j<col; j++)
         {
       		scanf("%d", &a[i][j]);
         }
       }
       
       printf("Required Matrix : "); 
       // Nested loop to print upper triangular matrix  
 	   for(int i = 0; i<row; i++)
       {
         printf("\n");
         for(int j = 0; j<col; j++)
         {
             // Check if column >= row
     		 if(j >= i)
    		 printf(" %d ", a[i][j]);
    		 else
    		 printf(" 0 ");
          }
       }
}




int main()
{
  int row, col;
  
  // Input number of rows and columns by the user
  printf("\nEnter Number of rows : ");
  scanf("%d", &row); 

  printf("\nEnter Number of columns : ");
  scanf("%d", &col);
  
  // Calling Upper triangular Matrix function 
  UpperTriangularMatrix(row,col);
  
  return 0;
}
