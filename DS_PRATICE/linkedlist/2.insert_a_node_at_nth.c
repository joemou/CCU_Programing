#include <stdio.h>
#include <stdlib.h>

//https://youtu.be/IbvsNF22Ud0

typedef struct node{
    int data;
    struct node *next;
}node;

node *insert(node *head, int data, int position){
    node *temp1 = (node *)malloc(sizeof(node));
    temp1->data = data;
    temp1->next = NULL;
    if(position==1){
        temp1->next = head;
        head = temp1;
        return head;
    }
    node *temp2 = head;//due to not to destroy head pointer ,set a new pointer to modify the data
    for (int i = 0; i < position - 2;i++){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
    return head;//due to the head is not global, need to return the head
};

void print(node *head){
    while(head!=NULL){
        printf(" %d", head->data);
        head = head->next;
    }

};

int main(){
    int num,data,position;
    node *head = NULL;
    printf("Plz input how many data!\n");
    scanf("%d", &num);

    for (int i = 0; i < num;i++){
        printf("Plz input the data!\n");
        scanf("%d", &data);
        printf("Plz input the position!\n");
        scanf("%d", &position);
        head = insert(head, data, position);
        printf("The data is:");
        print(head);
        printf("\n");

    }

}