#include <stdio.h>
int main(){
    int i, j;
    int a, b, c, d;


     scanf("%d (!) %d ", &i, &j);
    

        if (i % j == 0)
        {
        printf("%d\n", i);
            }

        while(i%j!=0)
        {
            i++;
            
            if(i%j==0){
            printf("%d\n", i);
            }
           
        }
        
        
     scanf("R%d", &a);
         b = a / 100,c = a % 100 / 10,d = a % 10;
         printf("%d%d%d", d, c, b);

        return 0;
}