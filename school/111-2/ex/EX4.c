#include <stdio.h>
#include <stdlib.h>

typedef struct history{
    char *crime_name;
    int date;
    int month;

} history;
typedef struct criminal_node{
    char *criminal_name;
    struct history data;
    int count;
} criminal_node;

node *insert 
int main(){
    int action;
    criminal_node *head = NULL;

    while(scanf("%d",&action)&&action!=0){
        switch(action){
            case 1:
                printf("Enter a command: ");
                break;
            case 2:
                break;
            case 3:
                break;
        }
    }
}