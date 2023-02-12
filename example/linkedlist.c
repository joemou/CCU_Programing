
#include<stdio.h>
#include<malloc.h>
int value;
struct node
{
    int data;
    struct node *next;
}*new,*head,*tail,*temp,*current,*prev,*next;
void create()
{
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value:\n");
    scanf("%d",&value);
    new->data=value;
    new->next=NULL;
}
void insert()
{
    create();
    if(head==NULL)
    {
        head=new;
        tail=new;
    }
    else
    {
        tail->next=new;
        tail=new;
    }
   // display();
}
void display()
{
    printf("Updated link list is:\n");
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
void insertatbeg()
{
    if(head==NULL)
        printf("No Linked List found.");
    else
    {
        create();
        new->data=value;
        new->next=head;
        head=new;
        display();
    }
}
void insertatend()
{
    if(head==NULL)
        printf("No Linked List found.");
    else
    {
        create();
        new->data=value;
        tail->next=new;
        new->next=NULL;
        tail=new;
        display();
    }
}
void insertatmid()
{
    if(head==NULL)
        printf("No Linked List found.");
    else
    {
        create();
        temp=head;
        int pos,i;
        printf("Enter the position where new node is to be inserted:\n");
        scanf("%d",&pos);
        for(i=0;i<=pos-1;i++);
        {
            temp=temp->next;
        }
        new->data=value;
        new->next=temp->next;
        temp->next=new;
        display();
    }
}
void deleteatbeg()
{
    if(head==NULL)
        printf("No Linked List found.");
    else
    {
    temp=head;
    head=head->next;
    temp->next=NULL;
    display();
    }
}
void deleteatend()
{
    if(head==NULL)
        printf("No Linked List found.");
    else
    temp=head;
    while(temp->next!=tail)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    tail=temp;
    display();
}
void deleteatmid()
{
    if(head==NULL)
        printf("No Linked List found.");
    else
    {
    temp=head;
    int pos=0,i;
    printf("Enter the position which you want to delete.\n");
    scanf("%d",&pos);
    for(i=0;i<=pos-1;i++)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;
    display();
    }
}
void count()
{   if(head==NULL)
        printf("No Linked List found.");
    else
    {
        int count=0;
        temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
          printf("\nTotal number of nodes is : %d\n",count);
    }
}
void reverse()
{
    if(head==NULL)
        printf("No Linked List found.");
    else
    {
    current=head;
    while(current!=NULL)
        {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        }
    }
    head=prev;
    display();
}
int main()
{
    printf("Press:\n1.Insert a new value.\n2.Display all elements.\n3.Insert at beginning.\n4.Insert at End.\n5.Insert in middle.\n6.Delete at beginning.\n7.Delete at End.\n8.Delete in between.\n9.Count total number of nodes.\n10.Reverse\n11.Exit");
    int choice;
    do
    {
        printf("\nEnter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            insertatbeg();
            break;
        case 4:
            insertatend();
            break;
        case 5:
            insertatmid();
            break;
        case 6:
            deleteatbeg();
            break;
        case 7:
            deleteatend();
            break;
        case 8:
            deleteatmid();
            break;
        case 9:
            count();
            break;
        case 10:
            reverse();
            break;
        case 11:
            printf("Exited successfully");
            break;
        }
    }while(choice!=0);
}