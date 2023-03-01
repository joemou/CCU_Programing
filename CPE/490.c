#include <stdio.h>
#include <string.h>

int main(){
    char str[101][101]={0};
    int row = 0,max=0;
    

    while(gets(str[row])){
        if(strlen(str[row]) > max){
        max = strlen(str[row]);
    }
    row++;
    }

    for (int i = 0; i < max;i++){
        for (int k = row-1; k >= 0;k--){
            if(i >= strlen(str[k])){
                printf(" ");
            }
            else{
                printf("%c", str[k][i]);
            }
        }
        printf("\n");
    }
}