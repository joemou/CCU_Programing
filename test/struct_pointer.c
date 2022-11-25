#include <stdio.h>
int main()
{
    int action_num = 0;
    char action[10000];
    char ch;

    printf("num of actions:");
    scanf("%d", &action_num);

    for (int i = 0; i < action_num; i++)
    {
        scanf("%s", &action[i]);

        
        
    }

    printf("%c", action[1]);
}