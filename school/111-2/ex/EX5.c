#include <stdio.h>
#include <stdlib.h>


signed main()
{

    
    char **str = (char **)malloc(sizeof(char *) * 10000);
    for (int i = 0; i < 10000; i++)
    {
        *(str+i) = (char *)malloc(1000 * sizeof(char));
    }
    char *longest_sen = NULL;
    int numStrings = 0;
    int longest_len = 0;

    while (numStrings < 10000 &&fgets(*(str + numStrings), 1000, stdin) != NULL)
    {
        int current_len = 0;
        char *current_char = *(str + numStrings);

        while(*current_char!='\0'){
            current_len++; //count len
            current_char++;//move char
        }
        numStrings++;//count sentence
        

        if(current_len>longest_len){//if longer
            longest_sen = *(str + numStrings - 1);
            longest_len = current_len;
        }
        else if(current_len==longest_len&&longest_sen!=NULL){//if equal,check each alphabet
            int num=0;
            char *long_char = longest_sen;
            char *current_char = *(str + numStrings - 1);

            while(*long_char!='\0'){
                if(*long_char!=*current_char){
                    num = *long_char - *current_char;
                    break;
                }
                long_char++;
                current_char++;
            }
            if(num<0){
                longest_sen = *(str + numStrings - 1);
            }
        }

    }
    printf("number of sentence: %d\n", numStrings);
    printf("longest sentence: %s",longest_sen);
    printf("longest length: %d\n", longest_len);
    for (int i = 0; i < numStrings; i++) {
        char *current = *(str + i);
        for (int j = 0; *(current + j) != '\n'&&*(current + j) != '\0';j++){//printw without newline
            printf("%c", *(current+j));
        }
    }
    printf("\n");

    for (int i = 0; i < 10000; i++)
    {
        free(*(str + i));
    }

    free(str);

    return 0;

}

