#include <stdio.h>
#include <ctype.h>
#include <string.h>

unsigned count(char *str,char *word){
    char *p;
 

    char *split[300];
    int k=0;
    int ans = 0;
 
    p = strtok(str, " ");
    while (p != NULL)
    {
        split[k++]=(p);
        p = strtok(NULL, " ");
        //The while loop then iterates through the remaining tokens by calling strtok() again with the first argument as NULL (to indicate that it should continue where it left off) and the second argument as the delimiter string. This continues until there are no more tokens left, at which point strtok() returns NULL.
    }
 

    
    for (int i = 0; i < k; i++)
        if (strcmp(word , split[i])==0){
            ans++;
        }
    return ans;

}

int main(){
    char str1[10001], str2[1001];

    fgets(str1, 10000, stdin);
    fgets(str2, 1000, stdin);
    str1[strcspn(str1, "\n")] = 0;//remove"\n"
    str2[strcspn(str2, "\n")] = 0;   

    
    printf("%d", count(str1,str2));


    /*
    char str1[1000001],str2[100];
    int i=0 ,k=0,ans=0,len;

    fgets(str1, 1000001, stdin);
    fgets(str2, 100, stdin);


    len = strlen(str2);
    while(str1[i]!='\0'){
        
        if(str1[i]==str2[k]){
            if(k==len-2&&((isspace(str1[i+1])&&isspace(str1[i-len+1]))||(i-k==0)||(str1[i+1]=='\n'))){
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

    
    printf("%d\n", ans);*/
}