#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
} node;

//malloc new node in heap
node *getnode(int data){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}


node *insert_begining(node *head,int data){
    node *newnode = getnode(data);
    if(head==NULL){
        head = newnode;
        return head;
    }
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
    return head;
}

node *insert_nth(node *head,int data,int position){
    if(position==1){
        head = insert_begining(head, data);
        return head;
    }
    node *newnode = getnode(data);
    node *temp1 = head;
    for (int i = 0; i < position - 2;i++){
        temp1 = temp1->next;
    }
    node *temp2 = temp1->next;
    
    //if insert to the tail
    if(temp2==NULL){
        newnode->prev = temp1;
        temp1->next = newnode;
        return head;
    }

    newnode->prev = temp1;
    temp1->next = newnode;
    temp2->prev = newnode;
    newnode->next = temp2;
    return head;
}

node *deletion_nth(node *head,int position){
    if(position==1){
        head = head->next;
        head->prev = NULL;
        return head;
    }
    node *temp1 = head;
    for (int i = 0; i < position - 2;i++){
        temp1 = temp1->next;
    }
    node *temp2 = temp1->next;
    
    //if delete the tail
    if(temp2->next==NULL){
        temp1->next = NULL;
        temp2->prev = NULL;
        return head;
    }
    if(temp2->prev==NULL){
        temp1->prev = NULL;
        temp2->next = NULL;
        return head;        
    }
    temp1->next = temp2->next;

    node *temp3 = temp2;
    temp2 = temp2->next;
    temp2->prev = temp3->prev;

    return head;
}
node *reverse(node *head){
    node *temp = head;
    //head at head
    if(temp->prev==NULL){
        while(temp->next!=NULL){
            temp = temp->next;
        }
    }
    //head at tail
    else if(temp->next==NULL){
        while(temp->prev!=NULL){
            temp = temp->prev;
        }        
    }
    head = temp;
    return head;
}

void print(node* head){
    if (head->next == NULL){
        while (head != NULL)
        {
            printf(" %d", head->data);
            head = head->prev;
        }
    }
    else if(head->prev==NULL){
        while(head!=NULL)
        {
            printf(" %d", head->data);
            head = head->next;
        }
    }
    else{
        printf("NO DATA\n");
    }

}



int main(){
    int action=-1,data,num,position;
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
                    head = insert_begining(head,data);
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
                printf("The list is:");
                head = reverse(head);
                print(head);
                printf("\n\n");
                break;
        }           
    }
}