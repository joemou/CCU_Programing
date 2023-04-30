#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char name[25];
    int score;

    int height;
    struct node *next;
    struct node *right;
    struct node *left;
} node;

/*for create the node*/

//insert node at head
void create(node **head,char *name,int score){
    node *temp = (node *)malloc(sizeof(node));
    strcpy(temp->name, name);
    temp->score = score;
    temp->next = NULL;
    temp->right = NULL;
    temp->left = NULL;
    temp->height = 1;
    if(head==NULL){
        *head = temp;
    }
    else{
        temp->next = *head;
        *head = temp;
    }
}


/*for merge sort*/

//find mid and split
void split(node *first,node **a,node **b){

    node *fast;
    node *slow;

    fast = first->next;
    slow = first;

    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }

    *b = slow->next;

    *a = first;
    slow->next = NULL;

    
}
//merge the node
node *merge(node *a,node *b){

    node *result;

    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }

    if(a->score>b->score){
        result = a;
        result->next = merge(a->next, b);
    }
    else{
        result = b;
        result->next = merge(b->next, a);
    }

    return result;
}
void mergesort (node **head){
    node *first = *head;
    node *a;
    node *b;

    if((first==NULL)||(first->next==NULL)){
        return;
    }

    split(first, &a, &b);

    mergesort(&a);
    mergesort(&b);

    *head = merge(a,b);
}

/*for AVL tree
https://www.youtube.com/watch?v=jDM6_TnYIqE*/

//detect height
int height(struct node *node) {
  if (node == NULL)
    return 0;
  return node->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// Right rotate
struct node *RR(struct node *y) {
  node *x = y->left;
  node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

// Left rotate
struct node *LL(struct node *x) {
  struct node *y = x->right;
  struct node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

// Get the balance factor
int getBalance(struct node *node) {
  if (node == NULL)
    return 0;
  return height(node->left) - height(node->right);
}

// Insert node
struct node *insertNode(struct node *node, int key) {
  // Find the correct position to insertNode the node and insertNode it
  if (node == NULL)
    return (newNode(key));

  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  // Update the balance factor of each node and
  // Balance the tree
  node->height = 1 + max(height(node->left),
               height(node->right));

  int balance = getBalance(node);
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);

  if (balance < -1 && key > node->right->key)
    return leftRotate(node);

  if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}


void print_player(node *node){


} 

void AVL_STRING_SEARCH(node *root,char *name){
    int flag = strcmp(name, root->name);
    if (root==NULL){
        printf("Not found\n");
    }
    else if(flag==0){
        print_player(root);
    }
    else if(flag<0){
        return AVL_STRING_SEARCH(root->left, name);
    }
    else{
        return AVL_STRING_SEARCH(root->right, name);
    }
}




void print_linklist(node **head){

    node *temp = *head;
    printf("name score\n");
    while(temp!=NULL){
        printf("%s %d\n",temp->name,temp->score);
        temp = temp->next;
    }
}

int main(){
    int time,score;

    printf("Number of records you want to key in:");
    scanf("%d", &time);
    node *head = NULL;

    char name[25];

    while(time--){
        printf("Enter name & score:");
        scanf(" %s %d", name, &score);
        create(&head, name, score);
    }
    mergesort(&head);
    print_linklist(&head);
}



