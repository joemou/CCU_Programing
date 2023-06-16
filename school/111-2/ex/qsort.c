#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b){
   return *(int*)a-*(int*)b;
}

int main(){
    int values[] = { 88, 56, 100, 2, 25 };

    qsort(values, 5,sizeof(int), cmp);

    for (int i = 0; i < 5;i++){
        printf(" %d" ,values[i]);
    }
}