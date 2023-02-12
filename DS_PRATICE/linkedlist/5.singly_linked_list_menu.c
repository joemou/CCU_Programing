#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

void print(node *head){
    while(head!=NULL){
        printf("%d", head->data);
        head = head->next;
    }
}

node *insert(node* head, int data){
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}

node *insert_nth(node*head,int data,int position){
    if(position==1){
        insert(head, data);
        return head;
    }
    node *temp1 = (node *)malloc(sizeof(node));
    node *temp2 = head;
    temp1->data = data;
    temp1->next = NULL;
    for (int i = 0; i < position - 2;i++){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
    return head;
}

node *deletion_nth(node *head,int position){
    if(position==1){
        head = head->next;
        return head;
    }
    node *temp = head;
    for (int i = 0; i < position - 2;i++){
        temp = temp->next;
    }
    node *temp2 = temp->next;
    temp->next = temp2->next;
    return head;
}

node *reverse(node *head){
    node *now = head;
    node *prev = NULL;
    node *next;
    while(now!=NULL){
        next = now->next;
        now->next = prev;
        prev = now;
        now = next;
    }
    head = prev;
    return head;
}

int main(){
    int action=-1,data,position,num;
    node *head = NULL;
    while(action!=0){
        printf("Plz input the action\n1.insert data\n2.insert data at nth\n3.delete data at nth\n4.reverse data\n0.exit\n");
        scanf("%d", &action);
        switch(action){
            case 1:
                printf("how many data?\n");
                scanf("%d", &num);
                for (int i = 0; i < num;i++){
                    printf("Plz input data %d\n",i+1);
                    scanf("%d", &data);
                    head = insert(head,data);
                }
                printf("\n");
                printf("The list is:");
                print(head);
                printf("\n\n");
                break;
            case 2:
                if(head==NULL){
                    printf("u need at least one data\n");
                    break;
                }
                printf("Plz give the data\n");
                scanf("%d", &data);
                printf("Plz give the position\n");
                scanf("%d", &position);
                head = insert_nth(head, data, position);
                printf("The list is:");
                print(head);
                printf("\n\n");
                break;
            case 3:
                if(head==NULL){
                    printf("u need at least one data\n");
                    break;
                }
                printf("Plz give the position\n");
                scanf("%d", &position);
                head = deletion_nth(head,position);
                printf("The list is:");
                print(head);
                printf("\n\n");
                break;
            case 4:
                if(head==NULL){
                    printf("u need at least one data\n");
                    break;
                }
                head = reverse(head);
                printf("The list is:");
                print(head);
                printf("\n\n");
                break;
        }
    }
}