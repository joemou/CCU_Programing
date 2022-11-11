#include <stdio.h>
#include <ctype.h>

int main(){

    char input,input2;
    int words=1, vowel_nums=0;

    while((input=getchar())!='\n'){

        if(input==EOF)break;


        switch(toupper(input)){
            
         case'A':case'E':case'I':case'O':case'U':
             vowel_nums += 1;
        }

        
        if (input == ' '&&input2!=input)
        {

            words += 1;
       }
        input2 = input;
    
    }
  

    printf("%d %d", vowel_nums, words);
}