#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

//define the data for the air_craft game
#define high 25 //background hight
#define width 60 //background with
#define border -1 //the edge of the game
#define blank 0 //blank space
#define plane 1 //plane
#define bullet 2 //bullet
#define enemy 3 //enemy plane
#define destroy 4 //plane destroyed

int canvas[high+2][width+2]; //game background scope
int pos_h,pos_w; //the position of plane
int enemynum; //the number of planes
int interval; //同個計次來模擬時間間隔
int itv_move; //敵機移動的時間間隔
int itv_new; //敵機重新整理的時間間隔
int score; //分數
int IsOver; //判斷遊戲是否結束

void Startup(); //遊戲數值初始化
void Show(); //遊戲介面輸出
void UpdateInput(); //與輸入無關的遊戲狀態更新
void UpdateNormal(); //因輸入導致的遊戲狀態更新
void HideCursor(); //隱藏游標
void gotoxy(int x,int y); 

int main(){



Startup(); //初始化



while(IsOver){ //遊戲迴圈
    UpdateInput();

    UpdateNormal();

    Show();

}

printf("\t\tgame over!\n");
Sleep(2500); //暫停遊戲結束介面（毫秒）
return 0;
}



//initilize part
void Startup(){ //intialize the game
IsOver=1;
score=0; //initialize the score
for(int i=0;i<high+2;i++){ //initialize the canvas
    for(int j=0;j<width+2;j++){
        if(i==0 || i==high+1 ||j==0 || j==width+1){
            canvas[i][j]=border;//intitialize the border
        }
        else canvas[i][j]=blank;//initialize the blank
    }
}

pos_h=high/2; //inititlize and set the plane postion when game starts (y axis)
pos_w = width / 2;// initialize and set the position when game starts (x axis)
canvas[pos_h][pos_w]=plane; //initalize position
enemynum=3; //nums of enemty plane
srand(time(NULL));
interval=4; //set interval to simulate time interval
itv_move=5; //initialize the speed of enemy plane
itv_new =40; //initialize the time of enemy plane create
}






void Show(){ //遊戲介面輸出
HideCursor(); //隱藏游標
gotoxy(1,1); //回撥游標、重新整理畫面
for(int i=0;i<high+2;i++){
    for(int j=0;j<width+2;j++){
        if( canvas[i][j] == plane ){ //當前位置為飛機位置
            printf("*");
        }
        else if( canvas[i][j] == bullet ){ //當前位置為子彈位置
            printf("|");
        }
        else if( canvas[i][j] == enemy ){ //當前位置為敵機位置
            printf("@");
        }
        else if( canvas[i][j] == border ){ //當前位置為邊界
            printf("-");
        }
        else if( canvas[i][j] == blank ){ //當前位置無物，且在邊界內
            printf("0");
        }
        else if( canvas[i][j] == destroy ){ //當前位置無物，且在邊界內
            printf("x");
        }
    }
 printf("\n");
}
 printf("\nscore:%d",score);
}



 //the rule of the displayed
void UpdateInput(){ 

 
 // detect user input. if user input return false
 char key_W = GetKeyState('W'),
      key_S = GetKeyState('S'),
      key_A = GetKeyState('A'),
      key_D = GetKeyState('D'),
      key_attack = GetKeyState(' ');

 if (kbhit()){ //when user input something
    if (key_W < 0){ //when w become flase
        if(pos_h>1){
            canvas[pos_h][pos_w]=blank;//setting the place before input be blank
            if(canvas[pos_h-1][pos_w] == enemy){ //if the place moving to is enemy plane then destroyed and game over
                canvas[pos_h-1][pos_w]= destroy;
                IsOver=0;
            }
            else canvas[--pos_h][pos_w]=plane;//else if nothing happend then move
        }
    }
    if(key_S<0){ //when s become false
        if(pos_h<high){
            canvas[pos_h][pos_w]=blank;
            if(canvas[pos_h+1][pos_w] == enemy){ 
                canvas[pos_h+1][pos_w]= destroy;
                IsOver=0;
            }
            else canvas[++pos_h][pos_w]=plane;
        }
    }
    if(key_A<0){ //when a become false
        if(pos_w>1){
            canvas[pos_h][pos_w]=blank;
            if(canvas[pos_h][pos_w-1] == enemy){ 
                canvas[pos_h][pos_w-1]= destroy;
                IsOver=0;
            }
            else canvas[pos_h][--pos_w]=plane;
        }
    }
    if(key_D<0){ //when d become false
        if(pos_w<width){
            canvas[pos_h][pos_w]=blank;
            if(canvas[pos_h][pos_w+1] == enemy){ 
                canvas[pos_h][pos_w+1]= destroy;
                IsOver=0;
            }
            else canvas[pos_h][++pos_w]=plane;
        }
    }
    if(key_attack<0){ //when space become false
        if(pos_h!=1)canvas[pos_h-1][pos_w]=bullet;//if the the place in fornt of the plane is not the border then print the bullet in front of plane
    }
}
}



void UpdateNormal(){ //因輸入導致的遊戲狀態更新
int temp[high+2][width+2]; //用來判斷原位置的臨時陣列

for(int i=1;i<=high;i++){
    for(int j=1;j<=width;j++){
        temp[i][j]=canvas[i][j];//copy data from canvas to create temp
    }
}


for(int i=1;i<=high;i++){ //遍歷臨時陣列，修改畫布
    for(int j=1;j<=width;j++){
        if(temp[i][j]==enemy && interval%itv_move==0){ //當前位置為敵機
            canvas[i][j]=blank;
            if(temp[i+1][j]==bullet){ //下面為子彈，敵機被擊中
                canvas[i+1][j]=blank;
                score++;
                printf("\a"); //擊中音效
            }
            else if(i<high){
                canvas[i+1][j]=enemy;
            }
            if(i+1==pos_h&&j==pos_w){ //下面為飛機，玩家飛機被撞毀
                canvas[i+1][j]=destroy;
                IsOver=0;
            }
        }
        if(temp[i][j]==bullet){ //當前位置為子彈
            canvas[i][j]=blank;
            if(temp[i-1][j]==enemy){ //下個位置是敵機，敵機被擊毀
                canvas[i-1][j]=blank;
                score++;
                printf("\a");
            }
            else if(i>1){
                canvas[i-1][j]=bullet;
            }
        }
    }
}

if(interval%itv_new==0){ //剛好到時間間隔
    for(int i=0;i<enemynum;i++){ //新增敵機群
        canvas[rand()%2+1][rand()%width+1]=enemy;
    }
}

if(interval<=100){ //時間間隔計次
     interval++;
}
else{ //時間間隔計次清零
 interval=0;
}
}



void gotoxy(int x,int y){ //回撥游標
COORD pos;
pos.X=x-1;
pos.Y=y-1;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void HideCursor(){ //隱藏游標函式
CONSOLE_CURSOR_INFO cursor;
cursor.bVisible = FALSE;
cursor.dwSize = sizeof(cursor);
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorInfo(handle,&cursor);
}