#include<stdio.h>
#include<time.h>		//time()
#include<stdlib.h>		//srand() rand()
#include<Windows.h>		//system("command")//執行dos命令“command”
#include<conio.h>		//getch();//從鍵盤讀取字符並返回，但不顯示在屏幕上
typedef struct x_y {	//用來存放一個座標
	int x;
	int y;
}x_y;
static x_y get_xy();
int a[4][4];
int empty;		//數組中空格的數目

void init();	//初始化數組
void show();	//打印4X4方格及數組數據
void to_up();	//接收鍵盤輸入，來控制數據移動方向
void to_down();
void to_left();
void to_right();
int  add_num();		//隨機添加一個數字到數組
void play();



int main(void)						
{
	printf("++++++++++++++++++++++++++++\n");
	printf("            2048            \n\n");
	printf("Control by:\n"
		" w/s/a/d or W/S/A/D\n");
	printf("press q or Q quit game!\n");
	printf("++++++++++++++++++++++++++++\n");
	printf("Any key to continue . . .\n");
	getch();
	system("cls");
	init();
	show();
	while(1)
		play();
	return 0;
}
void init()
{
	int i,j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			a[i][j] = 0;
	srand(time(NULL));
	i = rand()%4;
	j = rand()%4;
	a[i][j] = 2;
	empty = 15;
}
void show()
{
	int i ,j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
			printf("|     ");
		printf("|\n");
		for (j = 0; j < 4; j++)
			if (a[i][j] ==0)
				printf("|     ");
			else
				printf("|%5d", a[i][j]);
		printf("|\n");
		for (j = 0; j < 4; j++)
			printf("|_____");
		printf("|\n");
	}
}
void play()
{
	switch (getch()){
	case 'W':
	case 'w':
		system("cls");		//cls命令清空屏幕
		to_up();
		add_num();
		show();
		break;
	case 'A':
	case 'a':
		system("cls");
		to_left();
		add_num();
		show();
		break;
	case 'S':
	case 's':
		system("cls");
		to_down();
		add_num();
		show();
		break;
	case 'D':
	case 'd':
		system("cls");
		to_right();
		add_num();
		show();
		break;
	case 'q':
	case 'Q':
		puts("quiting");
		exit(EXIT_FAILURE);
		
	default:
		printf("\nwrong type!!!\n\n");
		printf("please type :\n");
		printf("w/s/a/d or W/S/A/D\n");
		break;
	}
}


//to_up()，將4x4方格陣向上移，並將相鄰的大小相等的數據相加合併
void to_up()
{
	int i, j,tmp; //i爲行數，j爲列數，tmp爲中間變量
	int lasti, lastj;
	//思路：
	//向上移動，則每一列爲一個單元，每次操作，只考慮一列
	//對於一列，考慮第一個元素爲當前元素，
	//如果當前元素爲0，直接賦值爲第一個相鄰元素值，並置0該相鄰元素
	//如果下一個元素（此時爲第二個）爲0，則，考慮下一個
	//如果下一個元素，與它相等，則相加合併（下一個元素要置0），
	//如果下一個元素，與它不等，則將它移到當前元素的相鄰位置
	for (j = 0; j < 4; j++)
	{
		lasti = 0;
		lastj = j;			//當前元素座標
		for (i = 1; i < 4; i++)								
			if (a[i][j] == 0)								//考慮下一個
				continue;									
			else {											
				if (a[lasti][lastj] == 0) {					//當前元素爲0
					a[lasti][lastj] = a[i][j];				
					a[i][j] = 0;							
				}											
				else if (a[lasti][lastj] == a[i][j]) {		//當前元素與下一個相等
					a[lasti][lastj] *= 2;					
					a[i][j] = 0;							
					empty += 1;								
				}											
				else {										//當前元素與第一個非0相鄰元素不等
					tmp = a[i][j];
					a[i][j] = 0;	
					a[++lasti][lastj] = tmp;				//置當前元素的相鄰位（此時已被賦值）爲當前元素
				}											
			}
	}
}					
//void to_up(void) {				//網上的另一種方法，多重循環造成的時間代價很大
//	int x, y, i;
//
//	for (y = 0; y < 4; ++y) {     // 從上向下合併相同的方塊 
//		for (x = 0; x < 4; ++x) {
//			if (a[x][y] == 0)
//				;
//			else {
//				for (i = x + 1; i < 4; ++i) {
//					if (a[i][y] == 0)
//						;
//					else if (a[x][y] == a[i][y]) {
//						a[x][y] += a[i][y];
//						a[i][y] = 0;
//						++empty;
//						x = i;
//						break;
//					}
//					else {
//						//x = i - 1;
//						break;
//					}
//				}
//			}
//		}
//	}
//
//	for (y = 0; y < 4; ++y)    // 向上移動箱子
//		for (x = 0; x < 4; ++x) {
//			if (a[x][y] == 0)
//				;
//			else {
//				for (i = x; (i > 0) && (a[i - 1][y] == 0); --i) {
//					a[i - 1][y] = a[i][y];
//					a[i][y] = 0;
//				}
//			}
//		}
//}
void to_down()
{
	int i, j, tmp; //i爲行數，j爲列數，tmp爲中間變量
	int lasti, lastj;
	for (j = 0; j < 4; j++)
	{
		lasti = 3;
		lastj = j;			//當前元素座標
		for (i = 2; i >-1; i--)
			if (a[i][j] == 0)								//考慮下一個
				continue;
			else {
				if (a[lasti][lastj] == 0) {					//當前元素爲0
					a[lasti][lastj] = a[i][j];
					a[i][j] = 0;
				}
				else if (a[lasti][lastj] == a[i][j]) {		//當前元素與下一個相等
					a[lasti][lastj] *= 2;
					a[i][j] = 0;
					empty += 1;
				}
				else {										//當前元素與第一個非0相鄰元素不等
					tmp = a[i][j];
					a[i][j] = 0;
					a[--lasti][lastj] = tmp;				//置當前元素的相鄰位（此時已被賦值）爲當前元素
				}
			}
	}
}
void to_left()
{
	int i, j, tmp; //i爲行數，j爲列數，tmp爲中間變量
	int lasti, lastj;
	for (i = 0; i < 4; i++)
	{
		lasti = i;
		lastj = 0;			//當前元素座標
		for (j = 1; j < 4; j++)
			if (a[i][j] == 0)								//考慮下一個
				continue;
			else {
				if (a[lasti][lastj] == 0) {					//當前元素爲0
					a[lasti][lastj] = a[i][j];
					a[i][j] = 0;
				}
				else if (a[lasti][lastj] == a[i][j]) {		//當前元素與下一個相等
					a[lasti][lastj] *= 2;
					a[i][j] = 0;
					empty += 1;
				}
				else {										//當前元素與第一個非0相鄰元素不等
					tmp = a[i][j];
					a[i][j] = 0;
					a[lasti][++lastj] = tmp;				//置當前元素的相鄰位（此時已被賦值）爲當前元素
				}
			}
	}
}
void to_right()
{
	int i, j, tmp; //i爲行數，j爲列數，tmp爲中間變量
	int lasti, lastj;
	for (i = 0; i < 4; i++)
	{
		lasti = i;
		lastj = 3;			//當前元素座標
		for (j = 2; j>-1; j--)
			if (a[i][j] == 0)								//考慮下一個
				continue;
			else {
				if (a[lasti][lastj] == 0) {					//當前元素爲0
					a[lasti][lastj] = a[i][j];
					a[i][j] = 0;
				}
				else if (a[lasti][lastj] == a[i][j]) {		//當前元素與下一個相等
					a[lasti][lastj] *= 2;
					a[i][j] = 0;
					empty += 1;
				}
				else {										//當前元素與第一個非0相鄰元素不等
					tmp = a[i][j];
					a[i][j] = 0;
					a[lasti][--lastj] = tmp;				//置當前元素的相鄰位（此時已被賦值）爲當前元素
				}
			}
	}
}

int add_num()
{
	x_y i_j;
	i_j=get_xy();
	if (i_j.x == -1)
	{
		return 0;
	}
	srand(time(NULL));

	a[i_j.x][i_j.y]= (rand()%2)?2:4;
	empty--;
	return 0;
}
static x_y get_xy()
{
	int count, newxy, i, j;
	x_y i_j;
	if (empty == 0)
	{
		i_j.x = -1;
		i_j.y = -1;
		return i_j;
	}

	srand(time(NULL));
	count = -1;
	newxy = rand() % empty;		//表示應在第幾個空添加新元素,newxy從0開始
	for (i = 0; i < 4; (i)++) {
		for (j = 0; j < 4; (j)++) {
			if (a[i][j] == 0) {
				count++;
				if (count == newxy)
				{
					i_j.x = i;
					i_j.y = j;
					return i_j;
				}
			}
		}
	}
}