// you can slightly modify the sample code if you want

#include <stdio.h>
#include <stdlib.h>

struct tNode{
    int data;
    struct tNode *Lchild, *Rchild;
};

void insert(struct tNode *curNode, int newData) {
    while (1) {
         
        
        if (newData < curNode->data) {
            
            if (curNode->Lchild == NULL) {
                struct tNode *newNode = (struct tNode *)malloc(sizeof(struct tNode));
                newNode->data = newData;
                newNode->Lchild = NULL;
                newNode->Rchild = NULL;
                curNode->Lchild = newNode;
                printf("%d", newNode->data);
                break;
            } else {
                curNode = curNode->Lchild;
            }
            
        } 
        else if (newData > curNode->data) {
            
            if (curNode->Rchild == NULL) {
                struct tNode *newNode = (struct tNode *)malloc(sizeof(struct tNode));
                newNode->data = newData;
                newNode->Lchild = NULL;
                newNode->Rchild = NULL;
                curNode->Rchild = newNode;
                printf("%d", newNode->data);
                break;
            } else {
                curNode = curNode->Rchild;
            }
        }
        printf("%d ", curNode->data);
        
    }
    printf("\n");
}

// To determine whether the target data exists in the tree
int find(struct tNode *curNode, int target){
    if (curNode==NULL){
        return 0;
    }
    else if(curNode->data==target){
        return 1;
    }
    else if(target<=curNode->data){
        return find(curNode->Lchild, target);
    }
    else{
        return find(curNode->Rchild, target);
    }

}

void deleteTree(struct tNode* curNode){
    if (curNode == NULL) return;
    deleteTree(curNode->Lchild);
    deleteTree(curNode->Rchild);
    free(curNode);
}

int main(){
    int numQuery = 0;
    int tmpNum;
    scanf("%d", &numQuery);

    struct tNode *root = (struct tNode *) malloc(sizeof(struct tNode));
    (*root) = (struct tNode) {.data = 0, .Lchild = NULL, .Rchild = NULL};
    // use a virtual node represent the root (store 0)

    for(int i = 0; i < numQuery; i++) {
        int operation_type, data;
        scanf("%d%d", &operation_type, &data);
        if(operation_type == 1) {
            // insert data
            // To find the target position where to insert, we start from root and compare the data of root and new data.
            insert(root, data);
        } else if(operation_type == 2) {
            // To determine whether the target data exists in the tree.
            // To find the target data, we start from root and compare the data of root and new data like insert function.
            if(find(root, data)) {
                printf("%d is in tree\n", data);
            } else {
                printf("%d is not in tree\n", data);
            }
        }
    }

    // free memory
    deleteTree(root);
    return 0;
}

