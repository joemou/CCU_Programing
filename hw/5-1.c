#include <stdio.h>

int gcd(int i,int j);

int main(){
    int N = 1,G=0;
    
    while(N!=0){
        scanf("%d", &N);
        if(N==0)
            break;
        for(int i=1;i<N;i++){

         for(int j=i+1;j<=N;j++){

             G += gcd(i, j);
         }

        }

        printf("%d\n", G);
        G = 0;
    }

}

int gcd(int i,int j){

    int gcf = 0;
    for (int k = 1; k <= (i >= j ? i : j); k++)
    {
        if(i%k==0&&j%k==0){
         gcf=k;
         
        }
    }
    return gcf;
}