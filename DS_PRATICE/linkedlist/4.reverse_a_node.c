#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *insert(node *head,int data){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
};

node *reverse(node *head){
    node *prev = NULL;
    node *current = head;
    node *next;

    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
};

void print(node *head){
    
    while(head!=NULL){   
        printf("%d ", head->data);
        head = head->next;
    }

};

int main(){
    int num, data;
    node *head = NULL;
    printf("How many data u want to input\n");
    scanf("%d", &num);
    for (int i = 0; i < num; i++){
        printf("Plz input data %d\n", i + 1);
        scanf("%d", &data);
        head = insert(head, data);
    }
    
    printf("The original data is:");
    print(head);
    printf("\n");
    head = reverse(head);
    printf("The reversing data is:");
    print(head);
}