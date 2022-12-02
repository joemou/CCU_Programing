#include<stdio.h>
#include<stdbool.h>

int factorial(int a){

    if(a==1){
        return 1;
    }

    if(a>1){
        return a * factorial(a - 1);
    }

    return 0;
};

int main(){
    long long int a = 0;

    scanf("%d", &a);
    printf("%d",factorial(a));
}

    