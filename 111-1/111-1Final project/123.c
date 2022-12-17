#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

int b = 0;
int t = 5;

int main(){
while(t){
    if(kbhit()){
        printf("hello\n");
        getch();
        t--;
    }
}
printf("in");
scanf("%D", &b);
printf("on");
}