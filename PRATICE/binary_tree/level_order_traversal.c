#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
    struct node *next;
} node;

node *getnode(int data){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node *insert(node *root,int data){
    if(root==NULL){
        root = getnode(data);
    }
    else if(data<=root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }

    return root;
    
}

void push(node *target,node **front,node **rear){

    node *temp = (node *)malloc(sizeof(node));
    temp = target;
    temp->data = target->data;
    temp->next = NULL;
    if((*front)==NULL&&(*rear)==NULL){
        *front = target;
        *rear = target;
        return;
    }

    (*rear) -> next = temp;
    *rear = temp;

    return;
}

void pop(node **front,node **rear){
    struct node *temp = *front;//not declare double star temp

    if(*front==NULL){
        return;
    }

    if((*front)==(*rear)){
        *front = *rear = NULL;
        return;
    }

    *front = (*front)->next;


    free(temp);

    return;
}


void leveloreder(node *root,node* front,node *rear){
    if(root==NULL){
        return;
    }
    push(root,&front,&rear);
    while(1){
        node *current = front;
        printf(" %d", current->data);
        if(current->left!=NULL){
            push(current->left,&front,&rear);
        }
        if(current->right!=NULL){
            push(current->right,&front,&rear);
        }

        pop(&front, &rear);

        }
    return;
}


int main(){
    node *front = NULL;
    node *rear = NULL;
    node *root = NULL;

    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 3);
    root = insert(root, 7);
    

    leveloreder(root, front, rear);


    return 0;
}

