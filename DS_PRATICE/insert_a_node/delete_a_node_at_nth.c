#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *insert(node *head, int data){//forget the star usually
    node *temp = (node *)malloc(sizeof(node));//forget the star usually
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
};

node *delete(node *head, int position){
    node *temp1 = head;

    if(position==1){//forget
        head = head->next;
        return head;
    }

    for (int i = 0; i < position - 2;i++){
        temp1 = temp1->next;//n-1
    }
    node *temp2 = temp1->next;//temp2=n
    temp1->next = temp2->next;//temp1->mext=n+1

    free(temp2);

    return head;
};

void print(node *head){
    while(head!=NULL){
        printf("%d ", head->data);
        head = head->next;
    }
};

int main(){

    int data_num,data,position;
    node *head = NULL;
    printf("How many data you want to input\n");
    scanf("%d", &data_num);
    printf("Plz input the data\n");

    for (int i = 0; i < data_num;i++){
        scanf("%d", &data);
        head = insert(head,data);
        print(head);
        printf("\n");
    }



    printf("How many data you want to delete\n");
    scanf("%d", &data_num);
    printf("Plz input the positions\n");

    for (int i = 0; i < data_num;i++){
        scanf("%d", &position);
        head = delete(head,position);
        print(head);
        printf("\n");
    }

    
}