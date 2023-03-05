#include <stdio.h>
#include <stdlib.h>

void up(char str[]){
    int i = 0;
    while(str[i]!='\0'){
        if((int)str[i]>96&&(int)str[i]<123){
            printf("%c", str[i] - 32);
        }
        else{
            printf("%c", str[i]);
        }
        i++;
    }
}

void low(char str[]){
    int i = 0;
    while(str[i]!='\0'){
        if((int)str[i]>64&&(int)str[i]<91){
            printf("%c", str[i] + 32);
        }
        else{
            printf("%c", str[i]);
        }
        i++;
    }

}

void wave(char str[]){
    int up = 1,i=0;

    while(str[i]!='\0'){
        if(up){
            if((int)str[i]>96&&(int)str[i]<123){
                printf("%c", str[i] - 32);
            }
            else{
                printf("%c", str[i]);
            }
            up = 0;
        }
        else{
            if((int)str[i]>64&&(int)str[i]<91){
                printf("%c", str[i] + 32);
            }
            else{
                printf("%c", str[i]);
            }
            up = 1;
        }
        i++;
    }

}


int main(){
    char str[100001];
    int num;

    scanf("%s", str);
    scanf("%d", &num);

    switch(num){
        case 1:
        up(str);
        break;
        case 2:
        low(str);
        break;
        case 3:
        wave(str);
        break;
    }
}