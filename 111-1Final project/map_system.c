#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int map(int i, int j);
int transfrom(int input);
int main(){
    int start = 1;
    int i=0;
    int x = 0, y = 0;
    int money = 1000000;

    map(x,y);
    while(start!=0){
     printf("\nPlease input (1: up, 2: down, 3: left, and 4: right 5: finished) to indicate move action.\n25$ for eachaction.");

     scanf("%d", &i);
	 if(y==0 || x==0){

			printf("\n\nyou touch the board\nplease choose again\n");

			continue; 
		}
	 if(y==9 || x==9){

			printf("\n\nyou touch the board\nplease choose again\n");
			continue;
		}    

     if(i==1){
    		map(x,x);
    		y=y-1;
            money -= 25;
        }
	 else if(i==2){
			map(y+1,x);
			y=y+1;
            money -= 25;
		}
	 else if(i==3){
			map(y,x-1);
			x=x-1;
            money -= 25;
		}
	 else if(i==4){
			map(y,x+1);
			x=x+1;
            money -= 25;
		}
     else if(i==5){
            break;
     }

    }
}
int map(int i, int j){
    int a[9][9];
    int x, y;
    time_t t;
    srand(time(&t));

    for (x = 0; x < 8;x++){
     
     for (y = 0; y < 8;y++){
            a[x][y]=0; //determine the dot
     }
    }

    a[i][j] = 1;//determine the person place. person is 1.
    a[rand() % 9][rand() % 9] = 2;//determine the place of money award
    a[rand() % 9][rand() % 9] = 3;//determine the plcae of booster award
    
    
    for (x = 0; x < 8;x++){
        printf("\n");
     for (y = 0; y < 8;y++){
     if(a[x][y]==0)
         printf(". ");
     
     else if(a[x][y]==1)
         printf("P ");
     
     else if(a[x][y]==2)
         printf("M ");
     
     else if(a[x][y]==3)
         printf("B ");
     }

    }

    return 0;
}
