#include <stdio.h>
long long int factorial(long long int a);
long long int fibonacci(int a);
long long int binomial_coefficient(long long int a,long long int b);
long long int power_module(long long int a,long long int b,long long int c);

int main(){

    int times=0, query=0;
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
                printf("%d\n", power_module(a, b, c));

                break;    
        }
    }
}


long long int factorial(long long int a){

    if(a==1){
        return 1;
    }

    if(a>1){
        return a * factorial(a - 1);
    }

    return 0;
}

long long int fibonacci(int a){
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

long long int binomial_coefficient(long long int a,long long int b){
    if(a==b||b==0){
        return 1;
    }
    if(a>b){
        return binomial_coefficient(a - 1, b) + binomial_coefficient(a - 1, b - 1);
    }
    return 0;
}

long long int power_module(long long int a,long long int b,long long int c){
    if(b==1){
        return a%c;
    }
    if(b%2==1){

        return (a * power_module(a, (b - 1),c))%c;
    }
    if(b%2==0){
        return (power_module(a, b/2,c) * power_module(a, b/2,c))%c;
    }

    return 0;
}