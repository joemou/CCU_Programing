#include <stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int array[],int times){
    int i, j;
    for (i = 0; i < times-1;i++){
        for (j = 0; j < times -1 - i;j++){
            if(array[j]>array[j+1]){
                swap(&)
            }
        }
    }
}

void insertion_sort(int array[],int times){

    int i, j, min_pos;

    for ( i = 0; i < times-1;i++){
        min_pos = i;
        for (j = i + 1; j < times;j++){

            if(array[j]<array[min_pos]){
                min_pos = j;
            }

        }
        if(min_pos!=i){
            swap(&array[i],&array[min_pos])
        }
    }
}

void selection_sort(){

}

int main(){
    int times;

    scanf("%d", &times);

    int nums[times];

    for (int i = 0; i < times;i++){
        scanf(" %d", &nums[i]);
    }
    //test
    for (int i = 0; i < times;i++){
        printf("%d", nums[i]);
    }

}