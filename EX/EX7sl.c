#include <stdio.h>

int main(){
    int gamelotterysize =1;
    int gamelotteryshow[100][100]={0};
    int gamelotterydigit[100][100]={0};
    int gamelotteryreal[100][100]={0};

    int amountlotteryfree=0,amountlotterycost=500;
    int amountlotteryremain=0;

    int flag;

    int tmpprizetype;
    int tmpmaxdigitcnt,tmpnowdigitcnt;
    int tmpmaxdigit=0,tmpnowdigit;
    int selectrow,selectcolumn;

    printf("You get one free choice.\n");
    amountlotteryfree++;
    flag=1;
    //初始化
    while(flag){
        if(amountlotteryremain==0){
            amountlotterycost=500;
            gamelotterysize+=2;
            amountlotteryremain=gamelotterysize*gamelotterysize;
            for(int i=0;i<gamelotterysize;i++){
                for(int j=0;j<gamelotterysize;j++){
                    gamelotteryshow[i][j]=i*gamelotterysize+j+1;
                    tmpnowdigit=gamelotteryshow[i][j];
                    tmpprizetype=0;
                    tmpnowdigitcnt=0;
                while(tmpnowdigit){
                    tmpprizetype=tmpprizetype*16+tmpnowdigit%10;
                    tmpnowdigit/=10;
                    tmpmaxdigitcnt++;
                }
                gamelotteryreal[i][j]=tmpprizetype%9+1;
                gamelotterydigit[i][j]=tmpnowdigitcnt;
                }

            }
        }
    }

    //印樂透
    tmpmaxdigit = gamelotterysize * gamelotterysize;
    tmpmaxdigitcnt = 0;
    while(tmpmaxdigit){
        tmpmaxdigit /= 10;
        tmpmaxdigitcnt++;
    }

    for (int i = 0; i < gamelotterysize;i++){
        printf("+");
        for (int j = 0; j < gamelotterysize;j++){
            for (int k = 0; k < tmpmaxdigitcnt + 2;k++)
                printf("-");
        }
    }
}