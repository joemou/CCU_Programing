#include <stdio.h>
#include <ctype.h>
#include <string.h>

int HAND_MAKE_STRCMP(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}


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
        if (HAND_MAKE_STRCMP(word , split[i])==0){
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

}

