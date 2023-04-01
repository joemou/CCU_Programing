#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct course
{
    char *subject;
    struct course *prev;
    struct course *next;
} course;

course *getnode(char *str)
{
    course *newnode = (course *)malloc(sizeof(course));
    newnode->subject = strdup(str);
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

course *create(int *num, int *next, int *prev, char *str[], course *head, int how_many)
{

    int flag = 0;
    int record[101];
    int k = 0;

    for (int i = 0; i < how_many; i++)//create head
    {
        if (prev[i] == -1)
        {
            head = getnode(str[i]);
            record[k] = num[i];
            flag = i;
            k++;
            break;
        }
    }
    
    course *temp = head;
    course *temp2;

    for (int i = 0; i < how_many; i++)
    {
        for (int j = 0; j < how_many; j++)
        {
            int exist = 0;
            if (next[flag] == num[j])//if equal
            {
                int placen=0,placep=0;

                for (int g=0 ; g < k;g++){
                    
                    if(record[g]==num[j]){//deal next.check whether it has already been created
                        exist = 1;
                        placen = g;
                        break;
                    }
                }
                
                
                if(exist==0){//if has not been created
                    temp2 = head;// initialize for prev
                    record[k] = next[flag];//record in has been created
                    k++;

                    temp->next = getnode(str[j]);
                    flag = j;//move flag
                    temp = temp->next;//move temp
                    
                    for (int g = 0 ; g < k;g++){
                        if(record[g]==prev[flag]){//deal prev.find prev place
                            placep = g;
                            break;
                        }
                    }
                    while(placep--){//traversal prev
                        temp2 = temp2->next;
                    }
                    temp->prev = temp2;

                }
                else if(exist==1){//has been created,find it and no prev to determine
                    temp2 = head;//initialize
                    while(placen--){
                        temp2 = temp2->next;
                    }   
                    temp->next = temp2;
                    break;
                }
            }
        }
    }
    return head;
}

int main(int argc, char *argv[])
{
    int num1[1000], num2[1000], num3[1000];
    char **str;

    str = (char **)malloc(sizeof(char *) * 100);
    for (int i = 0; i < 100; i++)
    {
        str[i] = (char *)malloc(100 * sizeof(char));
    }

    course *head = NULL;
    int k = 0;
    int times = 0;
    scanf("%d", &times);
    while (times--)
    {
        scanf("%d %d %d %s", &num1[k], &num2[k], &num3[k], str[k]);

        k++;
    }

    head = create(num1, num2, num3, str, head, k);

    course *temp = head;

    char action;

    printf("Current Course: %s\n", temp->subject);
    printf("[n] Next course. [p] Prior course [q] Quit:");
    while (scanf(" %c", &action) && action != 'q')
    {
        if (action == 'n')
        {
            if (temp->next != NULL)
            {
                temp = temp->next;
            }
            else
            {
                printf("There is no next course.\n");
            }
        }
        else if (action == 'p')
        {
            if (temp->prev != NULL)
            {
                temp = temp->prev;
            }
            else
            {
                printf("There is no previous course.\n");
            }
        }
        printf("Current Course: %s\n", temp->subject);
        printf("[n] Next course. [p] Prior course [q] Quit:");
    }
    return 0;
}
