#include <stdio.h>
int main(){

    float a, b;
    
    char ch,equal;

    for (int i = 1; i < 5; i++)
    {
        scanf("%f %c %f %c", &a, &ch, &b,&equal);
        
        switch(ch){
        
        case'+':
        printf("%.0f\n", a + b);
        break;

        case'-':
        printf("%.0f\n", a - b);
        break;
        
        case'*':
        printf("%.0f\n", a * b);
        break;

        case'/':
        printf("%.2f\n", a/b);
        break;

        }

    }

        return 0;
}