#include <stdio.h>

int main(){
    char s1[100], s2[100];
    int a, b;
    int digit1, digit2,min;

    scanf("%s %s", s1, s2);
    sscanf(s1, "%d", &a);
    sscanf(s2, "%d", &b);
    while(a!=0&&b!=0){
        digit1 = a % 10;
        digit2 = b % 10;
        if(digit1>digit2){
            min = digit2;
        }
        else{
            min = digit1;
        }
        for (int i = min)
    }
}