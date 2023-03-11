#include <stdio.h>

void moveZeroes(int* nums, int numsSize){
    int p = 0;
    for(int i = 0;i<numsSize-p;i++){
        if(nums[i]==0){
            for(int k=i;k<numsSize-p;k++){
                nums[k]=nums[k+1];
            }
            i=0;
            p++;
        }      
    }
    for (int i = 0; i < numsSize;i++){
        printf("%d", nums[i]);
    }
}

int main(){
    int number[7] = {0, 1, 0, 3, 12};

    moveZeroes(number, 5);
}