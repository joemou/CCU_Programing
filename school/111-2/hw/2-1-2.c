#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct course
{
    char subject[10000];
    struct course *prev;
    struct course *next;
} course;

course *create(int *num, int *next, int *prev, course *mycourse[], int how_many)
{
    for (int i = 0; i < how_many; i++)
    {
        for (int j = 0; j < how_many; j++)
        {
            if (next[i] == num[j])
            {
                mycourse[i]->next = mycourse[j];
            }
            if (prev[i] == num[j])
            {
                mycourse[i]->prev = mycourse[j];
            }
        }
    }

    return mycourse[0];
}

int main(int argc, char *argv[])
{
    int num1[1000], num2[1000], num3[1000];

    int k = 0;
    int times = 0;
    scanf("%d", &times);
    course *mycourse[999];
    for (int i = 0; i < 999; i++)
    {
        mycourse[i] = (course *)malloc(sizeof(course));
        mycourse[i]->next = NULL;
        mycourse[i]->prev = NULL;
    }
    while (times--)
    {
        scanf("%d %d %d %s", &num1[k], &num2[k], &num3[k], mycourse[k]->subject);

        k++;
    }

    course *head = NULL;

    head = create(num1, num2, num3, mycourse, k);

    course *temp = head;

    char action;

    printf("Current Course: %s\n", head->subject);
    printf("[n] Next course. [p] Prior course [q] Quit: ");
    while (scanf(" %c", &action) && action != 'q')
    {
        if (action == 'n')
        {
            if (temp->next != NULL)
            {
                temp = temp->next;
            }
            else
            {
                printf("There is no next course.\n");
            }
        }
        else if (action == 'p')
        {
            if (temp->prev != NULL)
            {
                temp = temp->prev;
            }
            else
            {
                printf("There is no previous course.\n");
            }
        }
        printf("Current Course: %s\n", temp->subject);
        printf("[n] Next course. [p] Prior course [q] Quit: ");
    }
    return 0;
}
