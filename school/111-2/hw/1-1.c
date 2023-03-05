#include <stdio.h>
int isprime(int num){
    for (int i = 2; i < num / 2;i++){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int num;

    scanf("%d", &num);

    for (int i = 2; i <= num;i++){
        if(num%i==0&&isprime(i)){
            printf("%d ", i);
            num /= i;
            i--;
        }
    }
}