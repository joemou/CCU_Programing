#include <stdio.h>
#include <stdlib.h>

//https://www.youtube.com/watch?v=cAZ8CyDY56s&t=429s

typedef struct node{
    int data;
    struct node *next;
}node;//define node

node *insert(node *head, int x){
    node *temp =  (node *)malloc(sizeof(node));//malloce a memory for temp
    temp->data = x;
    temp->next = head;
    head = temp;
    return head;
};

void print(node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head = head->next;
    }

};

int main(){
    int num,input;
    node *head = NULL;
    printf("Plz input how many nums to input\n");
    scanf("%d", &num);
    for (int i = 0; i < num;i++){
        printf("\nPlz input the %d Num\n", i + 1);
        scanf("%d", &input);
        head = insert(head, input);
        print(head);
    }
}