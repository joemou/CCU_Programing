#include <stdio.h>

int main(){

    int a[9][9];
    		for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			a[i][j]=0;
		}
}
a[0][0] = 4;

for (int i = 0; i < 8; i++)
{
        printf("\n");
        for (int j = 0; j < 8; j++)
        {
			if(a[i][j]==1){
				printf("+ ");
			}else if(a[i][j]==2){
				printf("- ");
			}else if(a[i][j]==3){
				
			printf("| ");
			}else if(a[i][j]==4){
				printf("P");
			}else{
				printf(". ");
		      }
			}	
		  }	
}