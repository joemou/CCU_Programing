#include <stdio.h>

int main(){
    int a[3][3] = {
     {1,2,3}
    ,{4,5,6}
    ,{7,8,9}};

    int (*p)[3], i=0;

    for (p = a; p < a + 3; p++){
        (*p)[i+1] = 0;
        i++;
    }

    int *b = &a[0][0];

    for (int k = 0; k < 9;k++){
        printf("%d", *(b + k));
        if(k==2||k==5)
            printf("\n");
    }
}