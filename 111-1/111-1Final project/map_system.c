#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void map(int i, int j,int *b,int *money,int *booster_owned);
int main(){
    int start = 1;
    int i=0;
    int x = 0, y = 0;
    int money = 1000000;
    int booster_owned[3];
    time_t t;
    int  b[4];//money and booster coordinate
    srand(time(&t));   
    do{

        for (int l = 0; l < 4;l++){
            b[l] = rand() % 8;
        }
    
    } while ((b[0]==b[1]==b[2]==b[3])); //generate random number for coordinate and prevent their coordinate to overlaping

        map(x, y, b,&money,booster_owned);

    while(start!=0){
     printf("\nPlease input (1: up, 2: down, 3: left, and 4: right 5: finished) to indicate move action.\n25$ for each action.\nENTER:");

     scanf("%d", &i);

     if(i==1){

    		y=y-1;//up
            if(y!=-1){
                map(y,x,b,&money,booster_owned);
                money -= 25;
            }

            else{ 
                printf("\n\nyou touch the board\nplease choose again\n");
                y = y + 1;
            }
            

        }
	 else if(i==2){
			y=y+1;//down

            if(y!=8){
                map(y,x,b,&money,booster_owned);
                money -= 25;
            }

            else{ 
                printf("\n\nyou touch the board\nplease choose again\n");
                y = y -1;
            }
		}
	 else if(i==3){

			x=x-1;//left

            if(x!=-1){
                map(y,x,b,&money,booster_owned);
                money -= 25;
            }

            else{ 
                printf("\n\nyou touch the board\nplease choose again\n");
                x = x + 1;
            }
		}
	 else if(i==4){

			x=x+1;//right

            if(x!=8){
                map(y,x,b,&money,booster_owned);
                money -= 25;
            }

            else{ 
                printf("\n\nyou touch the board\nplease choose again\n");
                x = x - 1;
            }
		}
     else if(i==5){
            start=0;
     }
	 

    }
}



void map(int i, int j,int *b,int *money,int *booster_owned){
    int a[9][9];
    int x, y;
    time_t t;
    srand(time(&t)); 

     

    for (x = 0; x < 8;x++){
     
     for (y = 0; y < 8;y++){
            a[x][y]=0; //determine the dot is 0
    }
    }


    a[b[0]][b[1]] = 2;//determine the place of money award is 2
    a[b[2]][b[3]] = 3;//determine the plcae of booster award is 3
    a[i][j] = 1;//determine the person place. person is 1.
        


    
    
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
    printf("\n");
    printf("%d %d %d %d\n", b[0], b[1], i, j);
     
     
     if ((b[0] == i)&&(b[1]== j)){
        printf("Fortune!Fortune! You earn %d !!!!\n", (b[0] + 1) * (b[1] + 1) * 10);
        *money += (b[0] + 1) * (b[1] + 1) * 10;
        b[0] = b[1] = -1; //let it outside the board
        }

     if((b[2]==i)&&(b[3]==j)){
        printf("Congratulation, you earn a booster\n");
        booster_owned[rand() % 3] += 1;
        printf("You owned speed %d price %d area %d\n",booster_owned[0],booster_owned[1],booster_owned[2]);
        b[2] = b[3] = -1; //let it outside the board
    }
    
}
