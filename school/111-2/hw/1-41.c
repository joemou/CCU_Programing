#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char str1[1000001],str2[100];
    int i=0 ,k=0,ans=0,len;

    fgets(str1, 1000001, stdin);
    fgets(str2, 100, stdin);

    if(str2[strlen(str2) - 1] == '\n')
        str2[strlen(str2) - 1] = '\0';
    
    if(str1[strlen(str1) - 1] == '\n')
    str1[strlen(str1) - 1] = '\0';

    len = strlen(str2);
    while(str1[i]!='\0'){
        
        if(str1[i]==str2[k]){
            if(k==len-1&&((isspace(str1[i+1])&&isspace(str1[i-len+1]))||(i-k==0)||(str1[i+1]=='\n'))){
                k = 0;
                ans++;
            }
            k++;
        }
        else{
            k = 0;
        }
        i++;
    }

    
    printf("%d\n", ans);
}