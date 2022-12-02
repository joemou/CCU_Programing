#include<stdio.h>
#include<stdbool.h>

int main(){

    int N;
    int f[40] = {0, 1};
    int i;

    for(i = 2; i < 40; i++){
        f[i] = f[i - 1] + f[i - 2];
    }

    scanf("%d", &N);

    while(N--){

        int num;
        bool flag = false;

        scanf("%d", &num);
        printf("%d = ", num);

        for(i = 39; i >= 2; i--){
            if(num >= f[i]){
                num = num - f[i];
                flag = true;
                printf("1");
            }
            else if(flag){
                printf("0");
            }
        }

        printf(" (fib)\n");
    }

    return 0;
}