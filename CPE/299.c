#include <stdio.h>

int main(){
    int times,nums,sort[100],count;

    scanf("%d", &times);

    while(times--){
        count = 0;
        scanf("%d", &nums);
        for (int i = 0; i < nums;i++){
            scanf("%d", &sort[i]);
        }
        for (int i = 0; i < nums;i++){
            for (int k = 0; k < nums-i-1; k++){
                if(sort[k]>sort[k+1]){
                    int temp = sort[k];
                    sort[k] = sort[k + 1];
                    sort[k + 1] = temp;
                    count++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", count);
    }
}