#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char fruit[1026];
    struct node *next;

} node; // define node

void insert(node **head, char name[])
{
    node *temp = (node *)malloc(sizeof(node)); // malloce a memory for temp
    strcpy(temp->fruit, name);
    temp->next = NULL;

    if (*head == NULL)
    { // if first
        *head = temp;
        return;
    }

    node *temp2 = *head; // insert a the end
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
}

void delete(node **head, char name[])
{
    node *cur = *head;
    node *prev = NULL;

    if (strcmp(cur->fruit, name) == 0)
    { // if first
        *head = (*head)->next;
    }
    else
    { // if else
        while (strcmp(cur->fruit, name) != 0)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        free(cur);
    }
}

void search(node **head, char *deduct[], int num)
{
    node *current = *head;
    while (current != NULL)
    {
        char target[1026];
        strcpy(target, current->fruit);

        int count = 0, deduct_count = 0;
        node *temp = current;

        while (temp != NULL)
        {
            if (strcmp(target, temp->fruit) == 0)
            {
                count++;
                node *next = temp->next;
                delete (head, target);
                temp = next;
            }
            else
            {
                temp = temp->next;
            }
        }

        int i = 0;
        while (i < num)
        {
            if (strcmp(target, deduct[i]) == 0)
            {
                deduct_count++;
            }
            i++;
        }
        printf("%s: %d\n", target, count - deduct_count);
        // Move to the next node
        current = current->next;
    }
}

int main()
{
    node *head = NULL;
    char name[1026];
    char *deduct[1026];
    int num = 0;

    for (int i = 0; i < 1026; i++)
    {
        deduct[i] = (char *)malloc(1026 * sizeof(char));
    }

    while (fgets(name, 1026, stdin) != NULL)
    {
        name[strlen(name) - 1] = '\0';
        if (name[0] == '-')
        {
            for (int i = 0; i < strlen(name); i++)
            {
                name[i] = name[i + 1];
            }
            strcpy(deduct[num++], name);
        }
        else
        {
            insert(&head, name);
        }
    }
    search(&head, deduct, num);

    return 0;
}