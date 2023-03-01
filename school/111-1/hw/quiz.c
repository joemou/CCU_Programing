#include <stdio.h>
struct student {
    int score[5];
    int score_total;
    int score_average;
} s[5];

int main(){

    for (int i = 0; i < 5;i++){
        for (int k = 0; k < 5;k++){
            scanf("%d", &s[i].score[k]);
            s[i].score_total += s[i].score[k];
        }

        s[i].score_average = s[i].score_total/5;
    }
    for (int i = 0; i < 5;i++){
        printf("%d %d %d\n",i+1,s[i].score_total,s[i].score_average);
    }
}