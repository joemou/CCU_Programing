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

    int at = 0;

    while (how_many--)
    {
        course *temp = head;
        if (head == NULL)
        {
            head = getnode(str[at]);
        }
        else
        {
            for (int j = 0; j < how_many; j++)
            {
                if (num[at] == next[j])
                {
                    temp->next = getnode(str[j]);
                }
            }
        }

        at++;
    }
}

int main(int argc, char *argv[])
{
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
    return 0;
}
