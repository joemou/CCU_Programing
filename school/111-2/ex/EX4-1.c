#include <stdio.h>
#include <stdlib.h>

typedef struct history//def node of history
{
    char *crime_name;
    int date;
    int month;

    struct history *next;//FOR NEXT CRINMINAL CRIMES DATA

} history;

typedef struct criminal_node//def node of criminal
{
    char *criminal_name;
    struct history *data;
    int count;

    struct criminal_node *next;//FOR NEXT CRIMINAL

} criminal_node;

history *his_insert(history *head, history *new)//insert histroy node
{
    history *temp = (history *)malloc(sizeof(history));
    temp->crime_name = new->crime_name;
    temp->date = new->date;
    temp->month = new->month;
    temp->next = NULL;
    history *temp2=head;
    while(temp2->next!=NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp;
    return head;
}


criminal_node *cri_insert(criminal_node *head, criminal_node *new)//insert criminal node
{
    criminal_node *temp = (criminal_node *)malloc(sizeof(criminal_node));
    temp->criminal_name = new->criminal_name;
    temp->data = new->data;
    temp->count = new->count;
    temp->next = NULL;
    criminal_node *temp2=head;
    while(temp2->next!=NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp;
    return head;
}
int main()
{
    int action, num = 0,crim_num;

    criminal_node *new = (criminal_node*)malloc(sizeof(criminal_node));
    history *new_his = (history*)malloc(sizeof(history));
    criminal_node *head = NULL;
    criminal_node *temp = head;


    printf("Enter a command: ");
    while (scanf("%d", &action) && action != 0)
    {
        switch (action)
        {
        case 1:
            printf("Enter a criminal's name: ");
            scanf("%s", new->criminal_name);
            head = cri_insert(head, new);
            printf("Created new criminal data (number %d).\n", num);
            num++;
            break;
        case 2:
            printf("Enter a number of the criminal: ");
            scanf("%d", &crim_num);
            for (int i = 0; i < crim_num-1;i++){
                temp = temp->next;
            }
            printf("Enter crime: ");
            scanf("%s",new_his->crime_name);
            printf("Enter date: ");
            scanf("%d",new_his->date);
            printf("Enter penalty: ");
            scanf("%d",new_his->month);
            temp->data = his_insert(temp->data, new_his);
            break;
        case 3:
            printf("Enter a number of the criminal: ");
            scanf("%d", &crim_num);
            for (int i = 0; i < crim_num-1;i++){
                temp = temp->next;
            }
            printf("Name: %s\n====================\n",temp->criminal_name);
            while(temp->data->next!=NULL){
                printf("Year: %d, Crime: %s, Penalty: %d months\n",temp->data->date,temp->data->crime_name,temp->data->month);
                temp->data = temp->data->next;
            }
            printf("====================\n");
            break;
        }
        printf("Enter a command: ");
    }
}