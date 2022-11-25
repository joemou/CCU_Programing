#include <stdio.h>
#include <math.h>

int main(){
    
    int long long number;
    int long long num[10]={0};

    scanf("%lld", &number);
    
    while(number){
        num[number % 10]++;
        number /= 10;
        
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", i);
    }

    printf("\n");

    for (int i = 0; i < 10;i++){
        printf("%d ",num[i]);
    }
}