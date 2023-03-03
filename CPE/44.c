#include <stdio.h>
#include <string.h>
#include <ctype.h>




int main(){
    int times,store[100][2]={0},i=0;   
    char str[200000];
    fgets(str, 150, stdin);
    sscanf(str, "%d", &times);
    while(times--){
        i = 0;
        fgets(str, 200000, stdin);
        while (str[i] != '\n'){
            if (toupper(str[i]) >= 65 && toupper(str[i]) <= 91){
                store[(int)toupper(str[i])][0]++;
            }
            i++;
        }
    }
    
    for (int k = 100; k > 0;k--){
        for (int l = 65; l <=91;l++){
            if(store[l][0]==k){
                printf("%c %d\n", (char)l, store[l][0]);
            }
        }
    }
}
