
#include <stdio.h>



int main(){

    char input;
    int i=0;
    char str[10000];

    while ((input = getchar()) != '\n')
    {
        
        str[i] = input;
        i++;
}

for (i = 0; i < 5;i++){
    printf("%c",str[2]);
}
}