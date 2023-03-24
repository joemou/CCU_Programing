#include <stdio.h>
#include <stdlib.h>

typedef struct history
{
    char *crime_name;
    int date;
    int month;

    struct history *next;

} history;

typedef struct criminal_node
{
    char *criminal_name;
    struct history data;
    int count;

    struct criminal_node *next;
} criminal_node;

criminal_node *insert(criminal_node *head, criminal_node *new)
{
    criminal_node *temp = (criminal_node *)malloc(sizeof(criminal_node));
    temp->criminal_name = new->criminal_name;
    temp->data = new->data;
    temp->count = new->count;
    temp->next = head;
    head = temp;
    return head;
}
int main()
{
    int action, num = 0;
    criminal_node *head = NULL;
    criminal_node *new = NULL;

    printf("Enter a command: ");
    while (scanf("%d", &action) && action != 0)
    {
        switch (action)
        {
        case 1:
            printf("Enter a criminal's name: ");
            scanf("%s", new->criminal_name);
            insert(head, new);
            break;
        case 2:
            break;
        case 3:
            break;
        }
        printf("Enter a command: ");
    }
}