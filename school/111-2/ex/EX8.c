#include <stdio.h>
#define MAX_ARRAY_LENGTH 100
#include <stdlib.h>

typedef struct {
    /* determine the structure by yourself. e.g, container of data, index... */
    int size;
    int *num;

} darray;

void initialize(darray *d);
void push_back(darray *d, int value);
int pop_back(darray *d);
int erase(darray *d, int position);
void insert(darray *d, int position, int value);
void clear(darray *d);
int sum(darray *d);
int length(darray *d);

void initialize(darray *d) {
    d->num = (int *)malloc(MAX_ARRAY_LENGTH * sizeof(int));
    d->size = 0;
}

void push_back(darray* d, int value) {
    d->num[d->size] = value;
    d->size++;
}

int pop_back(darray* d) {
    if(d->size>0){
        int value = d->num[d->size-1];
        d->size--;

        return value;
    }
    else{
        return 0;
    }
    
}

int erase(darray *d, int position) {
    // return 1, if successfully erase the element.
    // return 0, if fail erase the element.

    if(position>=d->size||position<0){
        return 0;
    }
    else{
        for (int i = position; i < d->size - 1;i++){
            d->num[i] = d->num[i + 1];
        }
        d->size--;
        return 1;
    }

}

void insert(darray *d, int position, int value) {
    for (int i = d->size-1 ; i >= position;i--){
        d->num[i + 1] = d->num[i];

    }
    d->num[position] = value;
    d->size++;
}

void clear(darray *d) {
    d->size = 0;
}

int sum(darray *d) {

    int sum=0;
    for (int i = 0; i < d->size;i++){
        sum += d->num[i];
    }

    return sum;
}

int length(darray *d) {
    return d->size;
}

//YOU CAN'T MODIFY THE main() FUNCTION!!!
int main() {
    darray d;
    initialize(&d);
    int operation, param1, param2;
    while(scanf("%d", &operation)) {
        switch (operation)
        {
        case 1: //push_back
            scanf("%d", &param1);
            push_back(&d, param1);
            break;
        case 2: //pop_back
            printf("popped: %d\n", pop_back(&d));
            break;
        case 3: //erase
            scanf("%d", &param1);
            if(erase(&d, param1))
                printf("erase OK\n");
            else
                printf("erase not OK\n");
            break;
        case 4: //insert
            scanf(" %d %d ", &param1, &param2);
            insert(&d, param1, param2);
            break;
        case 5:
            clear(&d);
            break;
        case 6:
            printf("sum: %d\n", sum(&d));
            break;
        case 7:
            printf("length: %d\n", length(&d));
            break;
        case 0:
            return 0;
        default:
            break;
        }
    }
}