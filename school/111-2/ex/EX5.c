#include <stdio.h>
#include <stdlib.h>
#define maxbuff 10000

size_t my_strlen(const char *str)
{
}

char *my_strcpy(char *dest, const char *source)
{
}

char *my_strcat(char *dest, const char *source)
{
}

int my_strcmp(const char *str1, const char *str2)
{
}

signed main()
{

    int numStrings = 0;
    char **str = (char **)malloc(sizeof(char *) * maxbuff);
    for (int i = 0; i < 10000; i++)
    {
        *(str+numStrings) = (char *)malloc(maxbuff * sizeof(char));
    }

    while (fgets(*(str+numStrings), 50, stdin))
    {   
        
        numStrings++;
    }


}