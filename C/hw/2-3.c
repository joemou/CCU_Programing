#include <stdio.h>
int main(){
    int score;

    scanf("%d", &score);
    
    switch(score){
    case 90 ... 100:
        printf("A");
        break;
    case 75 ... 89:
        printf("B");
        break;
    case 60 ... 74:
        printf("C");
        break;
    case 0 ... 59:
        printf("D");
        break;
    default:
        printf("error");
        break;
    }
    return 0;
}