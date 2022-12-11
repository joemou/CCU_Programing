
#include<stdio.h>
#include<windows.h>
#include<conio.h> 
 
//this is the add function 
int drawroom(int length,int height,int x,int y);
int transform(int tran);
 
//begin the function
int main()
{     
    
     int p=10;
	 int q=10;
     printf("control player to move up“8” down“2” left“4” right“6”\n");//control the player
     
     int y,x;
     int ret=1;
     int a,b;
     printf("input\n");
     scanf("%d %d",&p,&q);
     printf("input”\n"); //get the first player place
	 scanf("%d %d",&y,&x);
    drawroom(p,q,y,x);
    printf("\n");
   
    while(ret!=0){
	    printf("\n");
    	int i;
    	i=0;
    	int tran;
    	tran=getch();
    	i=transform(tran);
    	
    	if(i==8){
    		drawroom(p,q,y-1,x);
    		y=y-1;
		}
		 else if(i==2){
			drawroom(p,q,y+1,x);
			y=y+1;
		}
		  else if(i==4){
			drawroom(p,q,y,x-1);
			x=x-1;
		}
		else if(i==6){
			drawroom(p,q,y,x+1);
			x=x+1;
		}
		if(y==0 || x==0){
			ret=0;
			printf("\n\nyou touch the board game over");
			break; 
		}
		if(y==p+1 || x==q+1){
			ret=0;
			printf("\n\nyou touch the board game over");
			break;
		}
		
}
    
    
	getchar();
	system("pause");
	return 0;
}
 
int drawroom(int length,int height,int y,int x)
{   int ret=1;
	int size1=height+2;
	int size2=length+2;
	int a[size1][size2];
	int i,j;
	int count=1;
	
		for(i=0;i<size1;i++){
		for(j=0;j<size2;j++){
			a[i][j]=0;
		}
}
	a[0][0]=1;
	a[0][size2-1]=1;
	a[size1-1][0]=1;
	a[size1-1][size2-1]=1;
	
    for(j=1;j<size2-1;j++){
		a[0][j]=2;
	}	
	for(j=1;j<size2-1;j++){
		a[size1-1][j]=2;
	}
	for(i=1;i<size1-1;i++){
		a[i][0]=3;
	}
	for(i=1;i<size1-1;i++){
		a[i][size2-1]=3;
	}
	a[y][x]=4;
		for(i=0;i<size1;i++){
			printf("\n");
		for(j=0;j<size2;j++){
			if(a[i][j]==1){
				printf("+ ");
			}else if(a[i][j]==2){
				printf("- ");
			}else if(a[i][j]==3){
				
			printf("| ");
			}else if(a[i][j]==4){
				printf("@ ");
			}else{
				printf(". ");
		      }
			}	
		  }	
		  printf("\n\n\n\n\n\n\n\n\n\n");
		  return 0;
		}
 
int transform(int tran)
{
	int tot;
	if(tran==52)tot=4;
	if(tran==54)tot=6;
	if(tran==50)tot=2;
	if(tran==56)tot=8;
	return tot;
}
