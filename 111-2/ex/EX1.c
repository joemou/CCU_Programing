#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define STR_LEN 150

int main(){
    char str1[STR_LEN];
    char str2[STR_LEN];
    char str3[STR_LEN];
    char str4[STR_LEN];
    int num,i,check,space;

    fgets (str1, 150, stdin);
    fgets (str2, 150, stdin);
    str1[strcspn(str1, "\n")] = 0;//remove"\n"
    str2[strcspn(str2, "\n")] = 0;

    while((scanf("%d",&num))!=EOF){
        switch(num){
            case 1:
                strcpy(str3,str1);
                strcpy(str4,str2);
                printf ("Reverse A: %s\n", strrev(str3));
                printf ("Reverse B: %s\n", strrev(str4));    
                break;
            case 2:
                printf ("The length of A: %d\n", strlen(str1));
                printf ("The length of B: %d\n", strlen(str2));  
                break;
            case 3:
                strcpy(str3,str1);
                printf ("The string after concatenates: %s\n", strcat(str3,str2));
                break;
            case 4:
                i = 0,check=0;
                while (str1[i] != '\0' && str2[i] != '\0') { 
                    if (str1[i] > str2[i]){
                        check = 1;
                        printf("A is greater than B.\n");
                        break;
                    } 

                    else if (str1[i] < str2[i]){
                        check = 1;
                        printf("A is less than B.\n");
                        break;
                    } 
                    i++; 
                }
                if(check==0){
                    printf("A is equal to B.\n");
                } 
                break;
            case 5:
                space = 0;
                for (int i = 0; i < strlen(str1); i++) {
                    int c = str1[i];
                    if (isspace(c)){
                         space++;
                    } 
                }
                printf("Whitespace of A: %d\n", space);

                break;

            case 6:
                space = 0;
                for (int i = 0; i < strlen(str2); i++) {
                    int c = str2[i];
                    if (isspace(c)){
                         space++;
                    } 
                }
                printf("Whitespace of B: %d\n", space);
                break;
            
            default:
                printf("Error!\n");
                break;
        }
    }
}


