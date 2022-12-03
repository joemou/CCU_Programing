#include<stdio.h>
#include<stdbool.h>

int fib(int f);


int main(){
    int inputs = 0,num=0,sum=0,on_off=0;

    scanf("%d", &inputs);
    
    for (int k = 0; k < inputs;k++){
        
        scanf("%d", &num);
        printf("%d = ", num);

        for (int i = num;i>0;i--){
            sum += fib(i);
            if(sum<=num){
                printf("1");
                num -= fib(i);

                on_off = 1;//開啟印0
            }
            else if(on_off==1){
                printf("0");
            }
            sum = 0;
            
        }
        printf(" (fib)\n");
        on_off = 0;
        

    }
}


int fib(int f){
    if(f<=1){
        return 1;
    }
    if(f>1){
        return fib(f - 1) + fib(f - 2);
    }
    return 0;
}
    