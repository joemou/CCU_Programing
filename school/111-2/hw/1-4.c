#include <stdio.h>
#include <ctype.h>

int main(){
    char str1[1000001],str2[100];
    int i = 0,k=0,flag=1,flag2=0,ans=1;

    fgets(str1, 1000001, stdin);
    fgets(str2, 100, stdin);

    for(int i = 0; str1[i]; i++){
        str1[i] = tolower(str1[i]);
    }
    for(int i = 0; str2[i]; i++){
        str2[i] = tolower(str2[i]);
    }

    while(str1[i]!='\0'){
        
        if(str1[i]==str2[k]){
            flag = 1;
            k++;
        }

        else if(!isspace(str1[i])){
            flag = 0;
            k = 0;
        }

        if(flag==1&&isspace(str1[i])){
            flag2 = 1;
            break;
        }


        
        if(isspace(str1[i])){
            ans++;
        }
        i++;
    }

    if (flag2){
        printf("%d\n", ans);
    }
    else{
        printf("0\n");
    }
}