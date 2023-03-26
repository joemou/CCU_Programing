#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct course
{
    char *subject;
    struct node *prev;
    struct node *next;
} node;

node *getnode(char *str)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->subject = strdup(str);
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

node *create(int *num, int *next, int *prev, char *str[], node *head, int how_many)
{

    int at = 0;

    while (how_many--)
    {
        node *temp = head;
        if (head == NULL)
        {
            head = getnode(str[at]);
        }
        else
        {
            for (int i = 0; i < how_many; i++)
            {
                if (num[at] == next[i])
                {
                    temp->next = getnode(str[i]);
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
    node *head = NULL;
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
