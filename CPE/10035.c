#include <stdio.h>



int main(){
    int a, b;
    int ans,flag;

    scanf("%d %d", &a, &b);

    while(a!=0||b!=0){
        ans = 0,flag=0;
        while(a!=0||b!=0){
            if((a%10+b%10)+flag>9){
                flag = 1;
                ans++;
            }
            else{
                flag = 0;
            }
            a /= 10;
            b /= 10;
        }
        if(ans==0){
            printf("No carry operation.\n");
        }
        else if(ans==1){
            printf("1 carry operation.\n");
        }
        else{
            printf("%d carry operations.\n",ans);
        }
        scanf("%d %d", &a, &b);
    
    }

}