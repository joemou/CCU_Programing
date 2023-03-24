#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct history {
    char *crime_name;
    int date;
    int month;
    struct history *next;
} history;

typedef struct criminal_node {
    char *criminal_name;
    struct history *data;
    int count;
    struct criminal_node *next;
} criminal_node;

history *his_insert(history *head, history *new) {
    history *temp = (history *) malloc(sizeof(history));
    temp->crime_name = strdup(new->crime_name);
    temp->date = new->date;
    temp->month = new->month;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        history *temp2 = head;
        while (temp2->next != NULL) {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
    return head;
}

criminal_node *cri_insert(criminal_node *head, criminal_node *new) {
    criminal_node *temp = (criminal_node *) malloc(sizeof(criminal_node));
    temp->criminal_name = strdup(new->criminal_name);
    temp->data = new->data;
    temp->count = new->count;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        criminal_node *temp2 = head;
        while (temp2->next != NULL) {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
    return head;
}

int main() {
    int action, num = 0, crim_num;
    criminal_node *head = NULL;
    criminal_node *new_crim = NULL;
    criminal_node *temp = head;
    history *new_his = NULL;

    printf("Enter a command: ");
    while (scanf("%d", &action) && action != 0) {
        switch (action) {
            case 1:
                new_crim = (criminal_node *) malloc(sizeof(criminal_node));
                printf("Enter a criminal's name: ");
                new_crim->criminal_name = (char *) malloc(sizeof(char) * 50);
                scanf("%s", new_crim->criminal_name);
                new_crim->data = NULL;
                new_crim->count = 0;
                head = cri_insert(head, new_crim);
                printf("Created new criminal data (number %d).\n", num);
                num++;

                break;
            case 2:
                new_his = (history *) malloc(sizeof(history));
                printf("Enter a number of the criminal: ");
                scanf("%d", &crim_num);
                temp = head;//initialize
                for (int i = 0; i < crim_num; i++) {
                    temp = temp->next;
                }
                printf("Enter crime: ");
                new_his->crime_name = (char *) malloc(sizeof(char) * 50);
                scanf("%s", new_his->crime_name);
                printf("Enter date: ");
                scanf("%d", &new_his->date);
                printf("Enter penalty: ");
                scanf("%d", &new_his->month);
                temp->data = his_insert(temp->data, new_his);
                temp->count++;

                break;
            case 3:
                printf("Enter a number of the criminal: ");
                scanf("%d", &crim_num);
                temp = head;//initialize
                for (int i = 0; i < crim_num; i++) {
                    temp = temp->next;
                }
                printf("Name: %s\n====================\n",temp->criminal_name);
                history* history_temp = temp->data;
                while (history_temp != NULL) {
                    printf("Year: %d, Crime: %s, Penalty: %d months\n",history_temp->date,history_temp->crime_name,history_temp->month);
                    history_temp = history_temp->next;
                }
                printf("====================\n");
                break;
        }
        printf("Enter a command: ");
    }
}

/*
1
NoodleEater
1
JHChen
1
Edwina
2
0
Murder
2000
36
2
0
Steal
2005
24
2
1
sleeo
2023
1
3
0
3
1
0
*/