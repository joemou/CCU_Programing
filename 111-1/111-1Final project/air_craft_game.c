#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define high 25 //畫布高
#define width 60 //畫布寬
#define border -1 //邊界
#define blank 0 //空白
#define plane 1 //飛機
#define bullet 2 //子彈
#define enemy 3 //敵機
#define destroy 4 //摧毀標記

int canvas[high+2][width+2]; //game background scope
int pos_h,pos_w; //飛機位置
int enemynum; //敵機數量
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
system("pause");
return 0;
}

void Startup(){ //遊戲數值初始化
IsOver=1;
score=0; //初始化分數
for(int i=0;i<high+2;i++){ //初始化畫布
    for(int j=0;j<width+2;j++){
        if(i==0 || i==high+1 ||j==0 || j==width+1){
            canvas[i][j]=border;
        }
        else canvas[i][j]=blank;
    }
}

pos_h=high/2; //初始化飛機豎直座標
pos_w=width/2; //初始化飛機水平座標
canvas[pos_h][pos_w]=plane; //初始化飛機位置
enemynum=3; //敵機數量
srand(time(NULL));
interval=4; //初始化時間間隔計數
itv_move=5; //初始化敵機移動時間間隔
itv_new =40; //初始化敵機重新整理時間間隔
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
            printf("#");
        }
        else if( canvas[i][j] == blank ){ //當前位置無物，且在邊界內
            printf(" ");
        }
        else if( canvas[i][j] == destroy ){ //當前位置無物，且在邊界內
            printf("x");
        }
    }
 printf("\n");
}
 printf("\nscore:%d",score);
}

void UpdateInput(){ //與輸入無關的遊戲狀態更新
 
 // detect user input. if user input return false
 char key_W = GetKeyState('W'),
      key_S = GetKeyState('S'),
      key_A = GetKeyState('A'),
      key_D = GetKeyState('D'),
      key_attack = GetKeyState(' ');

 if (kbhit())
 { // 當有鍵按下時
 if (key_W < 0)
 { // 當按下 W 鍵，上移
        if(pos_h>1){
            canvas[pos_h][pos_w]=blank;
            if(canvas[pos_h-1][pos_w] == enemy){ //下個位置是敵機，撞毀
                canvas[pos_h-1][pos_w]= destroy;
                IsOver=0;
            }
            else canvas[--pos_h][pos_w]=plane;
        }
    }
    if(key_S<0){ //當按下 S 鍵，下移
        if(pos_h<high){
            canvas[pos_h][pos_w]=blank;
            if(canvas[pos_h+1][pos_w] == enemy){ //下個位置是敵機，撞毀
                canvas[pos_h+1][pos_w]= destroy;
                IsOver=0;
            }
            else canvas[++pos_h][pos_w]=plane;
        }
    }
    if(key_A<0){ //當按下 A 鍵，左移
        if(pos_w>1){
            canvas[pos_h][pos_w]=blank;
            if(canvas[pos_h][pos_w-1] == enemy){ //下個位置是敵機，撞毀
                canvas[pos_h][pos_w-1]= destroy;
                IsOver=0;
            }
            else canvas[pos_h][--pos_w]=plane;
        }
    }
    if(key_D<0){ //當按下 D 鍵，右移
        if(pos_w<width){
            canvas[pos_h][pos_w]=blank;
            if(canvas[pos_h][pos_w+1] == enemy){ //下個位置是敵機，撞毀
                canvas[pos_h][pos_w+1]= destroy;
                IsOver=0;
            }
            else canvas[pos_h][++pos_w]=plane;
        }
    }
    if(key_attack<0){ //當按下空格鍵，發射子彈
        if(pos_h!=1)canvas[pos_h-1][pos_w]=bullet;
    }
}
}
void UpdateNormal(){ //因輸入導致的遊戲狀態更新
int temp[high+2][width+2]; //用來判斷原位置的臨時陣列
for(int i=1;i<=high;i++){
    for(int j=1;j<=width;j++){
        temp[i][j]=canvas[i][j];
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