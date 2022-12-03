#include <stdio.h>
int factorial(int a);
int fibonacci(int a);
int binomial_coefficient(int a,int b);
int power(long long int a,long long int b);

int main(){

    int times=0, query=0,power_ans=0;
    int a=0, b=0, c=0;
    
    printf("How many queries do you want: ");
    scanf("%d", &times);
    while(times--){
        printf("Which type of query do you want: ");
        scanf("%d", &query);
        switch(query){
            
            case 1:
                printf("Please enter N: ");
                scanf("%d",& a);
                printf("%d\n",factorial(a));
                break;

            case 2:
                printf("Please enter i: ");
                scanf("%d",& a);
                printf("%d\n",fibonacci(a));
                break;

            case 3:
                printf("Please enter n and k: ");
                scanf("%d %d",& a,&b);
                printf("%d\n",binomial_coefficient(a, b));
                break;
            case 4:
                printf("Please enter x, y and m: ");
                scanf("%d %d %d",& a,&b,&c);
                power_ans=power(a, b);
                for (int k = 1; k <= (power_ans >= c ? power_ans : c);k++){
                 
                    if(power_ans<c*k){
                        printf("%d\n", power_ans-c*(k-1));
                        break;
                    }
                }

                break;    
        }
    }
}


int factorial(int a){

    if(a==1){
        return 1;
    }

    if(a>1){
        return a * factorial(a - 1);
    }

    return 0;
}

int fibonacci(int a){
    if(a==0){
        return 0;
    }
    if(a==1){
        return 1;
    }
    else if(a>1){
        return fibonacci(a-1)+fibonacci(a-2);
    }
    return 0;
}

int binomial_coefficient(int a, int b){

    return factorial(a) / (factorial(b) *factorial(a -b));
}
int power(long long int a,long long int b){
    if(b==1){
        return a;
    }
    if(b%2==1){

        return a * power(a, (b - 1));
    }
    if(b%2==0){
        return power(a, 2 / b) * power(a, 2 / b);
    }

    return 0;
}