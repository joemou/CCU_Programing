#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

node *getnode(int data){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

node *insert(node *root, int data){
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

int search(node *root,int data){
    if (root==NULL){
        return 0;
    }
    else if(root->data==data){
        return 1;
    }
    else if(data<=root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }

}

int main(){
    int action = -1,num,data;
    node *root = NULL;

    while (action != 0)
    {
        printf("Plz input the action\n1.insert data\n2.search data\n");
        scanf("%d", &action);
        switch(action){
            case 1:
                printf("how many data?\n");
                scanf("%d", &num);
                for (int i = 0; i < num;i++){
                    printf("Plz input data %d\n",i+1);
                    scanf("%d", &data);
                    root = insert(root,data);
                }
                break;
            case 2:
                if(root==NULL){
                    printf("u need at least one data\n");
                    break;
                }
                scanf("%d", &data);
                if(search(root,data)==1){
                    printf("found it\n");
                }
                else{
                    printf("not found it\n");
                }
                break;

        }
    }    
}