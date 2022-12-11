#include <stdio.h>
void selling_hotdog(int *money, int *price,int *start, int *booster);
void lottery(int *money, int *price, int *booster);

int main(){
int money = 100, price = 30;
int booster_owned[3]={0,0,0}; //0 speed 1 price 2 area
int start = 1;

while (start==1){
selling_hotdog(&money, &price,&start, booster_owned);
if(start==2)break;
lottery(&money, &price, booster_owned);
}

}




void selling_hotdog(int *money, int *price,int *start, int *booster_owned){
int speed = 15;
int booster_switch=0;
int area = 1;
int activity[5]={0};
int game_time = 180;
int number_of_hotdog = 0;
int result[5] = {0};
int speedcost = 50, tastecost = 100;
int hotdog_make[6] = {0};
int money_make[6] = {0};
int earn = 0,total_earn=0;
int check_selection=0;
int booster[3] = {0, 0, 0};

printf("Welcome, young boss!\n");


    booster_switch = 0;
    area = 0;
    check_selection = 0;
    printf("Chop chop, It's dawn.\n");
    printf("You have %d dollars.\n", *money);
    printf("You need %d minutes to make a hotdog.\n", speed);
    printf("The price of a hotdog is $%d.\n", *price);
    printf("You have %d speed booster(s), %d price booster(s), %d area booster(s).\n", booster_owned[0], booster_owned[1], booster_owned[2]);

    while (booster_switch != 4)
    {

        earn = 0, total_earn = 0;
        // choose booster
        printf("Open/Close boosters:\n");
        if (booster[0] == 1)
            printf("  [1] Speed booster (now open)\n"); // if booster open
        if (booster[0] == 0)
            printf("  [1] Speed booster (now close)\n");
        if (booster[1] == 1)
            printf("  [2] Price booster (now open)\n"); // if booster open
        if (booster[1] == 0)
            printf("  [2] Price booster (now close)\n");
        if (booster[2] == 1)
            printf("  [3] Area  booster (now open)\n"); // if booster open
        if (booster[2] == 0)
            printf("  [3] Area  booster (now close)\n");
        printf("  [4] Finish\n");
        printf("Enter the number(s): ");

        scanf("%d", &booster_switch);

        if (booster_switch < 1 || booster_switch > 4)
            printf("Invalid input!!!!\n");
        if (booster_switch == 1)
        {
            if (booster[0] == 0)
            {
                booster[0] = 1;
                booster_owned[0]--;
            }
            else
            {
                booster[0] = 0;
                booster_owned[0]++;
            }
        }
        if (booster_switch == 2)
        {
            if (booster[1] == 0)
            {
                booster[1] = 1;
                booster_owned[1]--;
            }
            else
            {
                booster[1] = 0;
                booster_owned[1]++;
            }
        }
        if (booster_switch == 3)
        {
            if (booster[2] == 0)
            {
                booster[2] = 1;
                booster_owned[2]--;
            }
            else
            {
                booster[2] = 0;
                booster_owned[0]++;
            }
        }

    
    }

 if(booster_owned[0]==-1){
     booster[0] = 0;
     booster_owned[0]++;
 }
 if(booster_owned[1]==-1){
     booster[1] = 0;
     booster_owned[1]++;
 }
 if(booster_owned[2]==-1){
     booster[2] = 0;
     booster_owned[2]++;
 }


 while(0<=area&&area<=3){
    // choose action            
     printf("Actions you can take for each area:\n");
     printf("  [1] Sell the hotdogs\n");
     printf("  [2] Improve your cooking speed\n");
     printf("      (- $%d, - $%d, - $%d, - $%d for next four upgrades)\n",speedcost ,speedcost*2 ,speedcost*4 ,speedcost*8 );
     printf("  [3] Improve your hotdog flavor\n");
     printf("      (- $%d, - $%d, - $%d, - $%d for next four upgrades)\n", tastecost,tastecost*2 ,tastecost*4 ,tastecost*8 );
     printf("Enter the number(s): ");
      for (int i = 0; i < 4; i++){//0:area1....
                    scanf("%d", &activity[i]);
                }
      
      for (int i = 0; i < 4; i++){
                    while ((activity[i]>3)||(activity[i]<1)){
                    printf("Invalid input!!!!\n");
                    printf("Actions you can take at Area %d:\n",i+1 );
                    printf("  [1] Sell the hotdogs\n");
                    printf("  [2] Improve your cooking speed\n");
                    printf("  [3] Improve your hotdog flavor\n");
                    printf("Enter the number(s): ");
                    scanf("%d", &activity[i]);
                    }
                    
                    
                }
      for (area=1; area<=4 ;area++){
                    number_of_hotdog = game_time / speed;
                    earn = number_of_hotdog * *price;

                    if(booster[0]==1){
                        number_of_hotdog = number_of_hotdog * 2;
                    }
                    else if(booster[0]==0){
                        number_of_hotdog = game_time / speed;
                    }
                     if(booster[1]==1){
                        earn = number_of_hotdog * *price*2;
                    }
                      
                    else if(booster[1]==0){  earn = number_of_hotdog * *price;
                    }
                    
                    if((activity[area-1]==2&&*money<speedcost)||(activity[area-1]==3&&*money<tastecost))
                    result[area] = 1;
                    else if((activity[area-1]==2&&speed==1))
                    result[area] = 2;
                    else if (activity[area-1]==1)
                    result[area] = 3;
                    else if (activity[area-1]==2){
                    result[area] = 4;
                    speed--;
                    *money -= speedcost;
                    speedcost *= 2;
                    }
                    else if (activity[area-1]==3){
                    result[area] = 5;
                    *price += 10;
                    *money -= tastecost;
                    tastecost *= 2;
                    }

                    if(result[area]==1||result[area]==2||result[area]==3){
                    hotdog_make[area] = number_of_hotdog;
                    money_make[area] = earn;
                    total_earn += earn;
                    }

                    

                    
        
         }
    }                    
                  
                    if(booster[2]==1){
                    number_of_hotdog = game_time / speed;
                    earn = number_of_hotdog * *price;
                    if(booster[0]==1){
                        number_of_hotdog = number_of_hotdog * 2;
                    }
                    else if(booster[0]==0){
                        number_of_hotdog = game_time / speed;
                    }
                     if(booster[1]==1){
                        earn = number_of_hotdog * *price*2;
                    }
                      
                    else if(booster[1]==0){  earn = number_of_hotdog * *price;
                    }
                 
                    hotdog_make[5] = number_of_hotdog;
                    money_make[5] = earn;
                    total_earn += earn;
                    *money += earn;
                    }
                    printf("Well done, you earn $%d today.\n", total_earn);
                    *money += total_earn;
                    
                    while(check_selection!=(5+booster[2])){
                      
                        
                        printf("Which result of the area you want to check?\n");
                        printf("  [1] Area 1\n");
                        printf("  [2] Area 2\n");
                        printf("  [3] Area 3\n");
                        printf("  [4] Area 4\n");
                        if (booster[2]==1){
                            printf("  [5] Area 5\n");
                    }   // if booster open
                        
                        if(booster[2]!=1){
                        printf("  [5] Done\n");
                        }
                        
                        if(booster[2]==1){
                        printf("  [6] Done\n");
                    } // if booster open
                        
                        
                        printf("Enter the number(s): ");
                        scanf("%d", &check_selection);
                     if(check_selection>6||check_selection<1){
                            printf("Invalid input!!!!\n");
                            continue;
                     }   
                     if(result[check_selection]==1){
                        
                            printf("Can't you tell how poor you are?\n");
				            printf("Go vending your hotdogs instead of thinking about self-improvement!\n");
                        
                     }    
                     else if(result[check_selection]==2){
                            printf("Do you want to travel through time?\n");
			                printf("GO WORK!!\n");
                        
                     }
                      else if (result[check_selection] == 4){
                        printf("You glimpse the secret of wind.\n");
				        printf("Your hands can move faster now.\n");
                     }
                     else if (result[check_selection] == 5){
                        printf("You feel the soul of the ingredients.\n");
				        printf("Your hotdogs are more appetizing now.\n");
                        }
                     if(result[check_selection]<=3){
                        if(check_selection==5&&booster[2]==0)
                            break;
                        if(check_selection==6&&booster[2]==1)
                            break;
                        printf("You make %d hotdogs here!\n", hotdog_make[check_selection]);
				        printf("You earn $%d!\n", money_make[check_selection]);
                        
                     }
                     }


  printf("Do you want to continue or exit?\n");
  printf("  [1] Continue\n");
  printf("  [2] Exit\n");
  printf("Enter the number(s): ");
  scanf("%d",start);
  if(*start==2){
    printf("We will miss you. Bye!\n");
  }






}


void lottery(int *money, int *price, int *booster_owned){
int selection; 

int gamelotterysize =1;
int gamelotteryshow[100][100]={0};
int gamelotterydigit[100][100]={0};
int gamelotteryreal[100][100]={0};


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
    
    while(flag){
        
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
                gamelotteryreal[i][j]=tmpprizetype%9+1;
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
     if(amountlotteryfree==0&&amountlotterycost>*money){
        printf("You have no money!\n");
        break;
     }
     if(amountlotteryfree==0){
        *money -= amountlotterycost;
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
            printf("Fortune, fortune! You get $%d!\n", 100 * *price);
            *money += 100 * *price;
        }
        else if(lotterycontent==2){
            printf("You get an extra choice!\n");
            amountlotteryfree++;
        }
        else if(lotterycontent>=7){
            printf("You get a booster!!\n");
            booster_owned[lotterycontent - 7]++;
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
            printf("Another open on %d!\n", selectrow * gamelotterysize * selectcolumn + 1);
            flag = 1;
            continue;
        }
        break;
     }

    }

}
