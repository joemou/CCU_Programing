#include <stdio.h>
int factorial(int a);
int fibonacci(int a);
int binomial_coefficient(int a,int b);
int power(int a,int b,int c);

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
                printf("%d",power(a, b, c));
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
    if(a<=1){
        return 1;
    }
    if(a>1){
        return fibonacci(a - 1) + fibonacci(a - 2);
    }
    return 0;
}

int binomial_coefficient(int a, int b){

    if(a-1==1){
        return 1;
    }
    if(a>1){
        return 
    }

}
int power(int a,int b,int c){

}