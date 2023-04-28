#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char name[21];
    int score;
    struct node *next;
} node;

void create(node **head,char *name,int score){
    node *temp = (node *)malloc(sizeof(node));
    strcpy(temp->name, name);
    temp->score = score;
    if(head==NULL){
        *head = temp;
    }
    else{
        temp->next = *head;
        *head = temp;
    }
}

void mergesort (node **head){
    node *first = *head;
    node *a;
    node *b;

    if((first==NULL)||(first->next==NULL)){
        return;
    }

}

void partition()




int main(){
    int time,score;
    scanf("%d", &time);
    node **head = NULL;
    char name[21];

    while(time--){
        scanf("%s %d", name, &score);
        create(head, name, score);
    }
    Mergesort(head);
}