#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int selection,money=1000000,price=30; //可能重複

    int gamelotterysize =1;
    int gamelotteryshow[100][100]={0};
    int gamelotterydigit[100][100]={0};
    int gamelotteryreal[100][100]={0};
    int booster_owned[3]={0,0,0}; //0 speed 1 price 2 area
    int booster_have = 0;
    int i = 0;

    int amountlotteryfree=0,amountlotterycost=500;
    int amountlotteryremain=0;

    int flag;

    int tmpprizetype;
    int tmpmaxdigitcnt,tmpnowdigitcnt;
    int tmpmaxdigit,tmpnowdigit;
    int selectrow,selectcolumn;

    printf("You get one free choice.\n");
    amountlotteryfree++;
    flag=1;
    time_t t;

    srand(time(&t));
    int booster_slot=((rand() % 11)+5);
    int booster_record[booster_slot];

    printf("%d\n", booster_slot);

    while(flag){
        srand(time(&t));
        //初始化
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
                    tmpnowdigitcnt++;
                }
                
                gamelotteryreal[i][j]=((rand() % 9)+1);
                gamelotterydigit[i][j]=tmpnowdigitcnt;
                }

            }
        }
   
    

     //準備印樂透
     tmpmaxdigit = gamelotterysize * gamelotterysize;
     tmpmaxdigitcnt = 0;
    
     while(tmpmaxdigit){
        tmpmaxdigit /= 10;
        tmpmaxdigitcnt++;
     }
     //印樂透

     for (int i = 0; i < gamelotterysize;i++){
        printf("+");
        for (int j = 0; j < gamelotterysize;j++){
            for (int k = 0; k < tmpmaxdigitcnt + 2;k++)printf("-");
            printf("+");
        }


        printf("\n|");

        for (int j = 0; j < gamelotterysize;j++){
         if(gamelotteryreal[i][j]==-1){
                for (int k = 0; k < tmpmaxdigitcnt - 1;k++){printf(" ");}
                printf(" x |");
            }
         else{
                for (int k = 0; k < tmpmaxdigitcnt - gamelotterydigit[i][j];k++){ printf(" ");}
                printf(" %d |", gamelotteryshow[i][j]);
            }
        }
        printf("\n");


     }
    
     printf("+");
     for (int j = 0; j < gamelotterysize;j++){
        for (int k = 0; k < tmpmaxdigitcnt + 2;k++)printf("-");
            printf("+");
     }

     printf("\n");

     //choose lottery

     printf("You can choose\n");
     printf("  [number on cell] to open (- %d)\n", amountlotteryfree == 0 ? amountlotterycost : 0);
     printf("  [0] to continue the game\n");
     printf("Enter the number(s): ");
     scanf("%d", &selection);
     selectrow = (selection - 1) / gamelotterysize;
     selectcolumn = (selection - 1) % gamelotterysize;
     if(selection<0||selection>gamelotterysize*gamelotterysize||gamelotteryreal[selectrow][selectcolumn]==-1){
        printf("Invalid input!!!!\n");
        continue;
     }
     if(selection==0)break;

     //dertermine money
     if(amountlotteryfree==0&&amountlotterycost>money){
        printf("You have no money!\n");
        break;
     }
     if(amountlotteryfree==0){
        money -= amountlotterycost;
        amountlotterycost += 500;
     }
     else{
        amountlotteryfree--;
     }
    

     //run lottery

     while(flag){
        int lotterycontent = gamelotteryreal[selectrow][selectcolumn];
        gamelotteryreal[selectrow][selectcolumn] = -1;
        amountlotteryremain--;
        
        if (lotterycontent==1){
            printf("Fortune, fortune! You get $%d!\n", 100 * price);
            money += 100 * price;
        }
        else if(lotterycontent==2){
            printf("You get an extra choice!\n");
            amountlotteryfree++;
        }
        else if(lotterycontent>=7){
            printf("You get a booster!!\n");
            
            if( booster_have<booster_slot){

            booster_have++;
            booster_owned[lotterycontent - 7]++;
            booster_record[i] = lotterycontent - 7;
            i++;
            printf("speed %d price %d area %d\n",booster_owned[0],booster_owned[1],booster_owned[2]);
            }

    
            else {
            booster_owned[booster_record[0]]--;
            booster_owned[lotterycontent - 7]++;
            printf("discard %d get %d\n", booster_record[0], lotterycontent - 7);

            for (int k = 0; k < booster_slot;k++){
                booster_record[k] = booster_record[k + 1];
            }
            booster_record[booster_slot - 1] = lotterycontent - 7;
            
            printf("speed %d price %d area %d\n",booster_owned[0],booster_owned[1],booster_owned[2]);
            }
        }
        else if(lotterycontent>=3&&lotterycontent<=6){
            if(lotterycontent==3)selectrow = (selectrow - 1 + gamelotterysize) % gamelotterysize;
            else if(lotterycontent==4)selectrow = (selectrow + 1) % gamelotterysize;
            else if(lotterycontent==5)selectcolumn = (selectcolumn -1+gamelotterysize) % gamelotterysize;
            else if(lotterycontent==6)selectcolumn = (selectcolumn + 1) % gamelotterysize;
            if(gamelotteryreal[selectrow][selectcolumn]==-1){
                printf("Bad Luck :(\n");
                break;
            }
            printf("Another open on %d!\n", selectrow * gamelotterysize + selectcolumn + 1);
            flag = 1;
            continue;
        }
        break;
     }

    }



}