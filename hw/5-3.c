#include <stdio.h>

int main(){
    int n;

    scanf("%d", &n);

    while(n--){
        int i=0, j=0, GCF=1;
        scanf("%d %d", &i, &j);
            
            for(int k=1;k<=(i>=j?i:j);k++){
                if(i%k==0&&j%k==0){
                    GCF = k;
                }
            }
            

            if (GCF != 1)
            {
                printf("Inverse doesn't exist\n");
                continue;
        }

        for (int k = 1; k <= (i >= j ? i : j);k++){
            if((i*k)%j==1){
                printf("multiplicative inverse is %d\n", k);
                break;
            }
        }
    }
}