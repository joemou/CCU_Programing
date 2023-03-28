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

    for (int i = 0; i < how_many; i++)
    {
        if (prev[i] == -1)
        {
            head = getnode(str[i]);
            flag = i;
        }
    }
    course *temp = head;
    course *temp2;

    for (int i = 0; i < how_many; i++)
    {
        for (int j = 0; j < how_many; j++)
        {
            if (next[flag] == num[j])
            {
                temp->next = getnode(str[j]);
                temp2 = temp;
                temp = temp->next;
                temp->prev = temp2;
                flag = j;
                break;
            }
        }
    }
    return head;
}

int main(int argc, char *argv[])
{
    printf("123\n");
    int num1[100], num2[100], num3[100];
    char *str[100];
    course *head = NULL;
    int k = 0;
    for (int i = 1; i < argc; i += 4)
    {
        num1[k] = atoi(argv[i]);
        num2[k] = atoi(argv[i + 1]);
        num3[k] = atoi(argv[i + 2]);
        str[k] = argv[i + 3];
        k++;
    }

    head = create(num1, num2, num3, str, head, k);

    course *temp = head;

    char action;

    printf("Current Course: %s", temp->subject);
    while (scanf(" %c", &action) && action != 'q')
    {
        if (action == 'n')
        {
            temp = temp->next;
        }
        else if (action == 'p')
        {
            temp = temp->prev;
        }
        printf("Current Course: %s", temp->subject);
    }
    return 0;
}
