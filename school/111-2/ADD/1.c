#include <stdio.h>
#include <string.h>


void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int array[], int times) {
    int i, j;
    for (i = 0; i < times - 1; i++) {
        int swaps_made = 0;
        for (j = 0; j < times - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                printf("%d %d\n", array[j + 1], array[j]);
                swap(&array[j], &array[j + 1]);
                swaps_made = 1;
            }
        }
        if (!swaps_made) {
            break;
        }
    }
}   

void insertionsort(int a[],int n){
    for (int i =1; i < n;i++){
        int pin = i;
        int value = a[i];

        while(pin>0&&value<a[pin-1]){
            a[pin] = a[pin - 1];
            pin--;
        }
        printf("%d\n", pin);
        a[pin] = value;
    }
}

void selectionsort(int a[],int n){
    for (int i = 0; i < n - 1;i++){
        int min = i;
        for (int j = i+1; j < n;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        swap(&a[min], &a[i]);
        printf("%d %d\n", a[i], a[min]);
    }
}

int main(){
    int times;
    char option[20];

    scanf("%d", &times);

    int nums[times];

    for (int i = 0; i < times;i++){
        scanf(" %d", &nums[i]);
    }


    scanf("%s", option);

    if(strcmp(option,"BubbleSort")==0){
        bubblesort(nums, times);
    }
    else if(strcmp(option,"SelectionSort")==0){
        selectionsort(nums, times);
    }
    else if (strcmp(option, "InsertionSort") == 0) {
        insertionsort(nums, times);
    }

}