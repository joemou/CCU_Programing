#include <stdio.h>

int main(){
    char c;
    int flag=0;
    while((c=getchar())!=EOF){
        if(c=='"'&&flag==0){
            printf("``");
            flag = 1;
        }
        else if(c=='"'&&flag==1){
            printf("''");
            flag = 0;
        }
        else{
            printf("%c",c);
        }
    }
}