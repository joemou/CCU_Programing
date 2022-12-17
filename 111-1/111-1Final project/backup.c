#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>



//definiation for aircaft_game
#define high 25 //background hight
#define width 60 //background with
#define border -1 //the edge of the game
#define blank 0 //blank space
#define plane 1 //plane
#define bullet 2 //bullet
#define enemy 3 //enemy plane
#define destroy 4 //plane destroyed

//function for the part of selling hot dog 
void selling_hotdog(int *money, int *price,int *start, int *booster_owned);
void lottery(int *money, int *price, int *booster_slot, int *booster_owned);

//function for the map system
void map_control(int *money,int *booster_owned);
void map_print(int i, int j,int *b,int *money,int *booster_owned);

//function for the aircraft game
void aircraft_main(int *money, int *booster_slot, int *booster_owned,int *day);
void UpdateInput(int *money, int *booster_slot, int *booster_owned,int canvas[high+2][width+2],int *pos_h,int *pos_w,int *enemynum,
int *interval ,int *itv_move, int *itv_new ,int *score, int *IsOver);
void UpdateNormal(int *money, int *booster_slot, int *booster_owned,int canvas[high+2][width+2],int *pos_h,int *pos_w,int *enemynum,
int *interval ,int *itv_move, int *itv_new ,int *score, int *IsOver);
void Show(int *money, int *booster_slot, int *booster_owned,int canvas[high+2][width+2],int *pos_h,int *pos_w,int *enemynum,
int *interval ,int *itv_move, int *itv_new ,int *score, int *IsOver);

//set the output place
void gotoxy(int x, int y);
//function to hide cursor
void HideCursor();
//simulate system pause
void Waiting();
//Becaue the buffer from the aircrat game (using kbhit()), we need to clean buffer
void clean_buffer();


int main(){
    system("C:\\Users\\zxc12\\Desktop\\CCU.png");//output image
    int money = 100, price = 30, day = 1; // set the variable day to increase difficulty
    int booster_owned[3] = {0, 0, 0};     // 0 speed 1 price 2 area
    int start = 1;
    time_t t;
    srand(time(&t));                        // set seed
    int booster_slot = ((rand() % 11) + 5); // create random slot space

    printf("You have %d slot for booster\n", booster_slot);
    while (start == 1)
    {

    selling_hotdog(&money, &price,&start, booster_owned);
    if(start==2)break;
    lottery(&money, &price,&booster_slot, booster_owned);
    aircraft_main(&money,&booster_slot, booster_owned,&day);  
}

}






void selling_hotdog(int *money, int *price,int *start, int *booster_owned){
int speed = 15;//default making hot dog speed
int booster_switch=0;//using to turn on or off the booster
int area = 1;
int activity[5]={0};//using to 
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
                        map_control(&*money, booster_owned);
                        printf("Can't you tell how poor you are?\n");
				        printf("Go vending your hotdogs instead of thinking about self-improvement!\n");
                        
                        
                     }    
                     else if(result[check_selection]==2){
                        map_control(&*money, booster_owned);
                        printf("Do you want to travel through time?\n");
			            printf("GO WORK!!\n");

                        
                     }
                      else if (result[check_selection] == 4){
                        map_control(&*money, booster_owned);
                        printf("You glimpse the secret of wind.\n");
				        printf("Your hands can move faster now.\n");

                     }
                     else if (result[check_selection] == 5){
                        map_control(&*money, booster_owned);
                        printf("You feel the soul of the ingredients.\n");
				        printf("Your hotdogs are more appetizing now.\n");

                        }
                     if(result[check_selection]<=3){
                        if(check_selection==5&&booster[2]==0)
                            break;
                        if(check_selection==6&&booster[2]==1)
                            break;
                        map_control(&*money, booster_owned);
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
    system("pause");
  }






}


void lottery(int *money, int *price,int *booster_slot, int *booster_owned){
int booster_record[*booster_slot];

int selection;
int booster_have = 0, i = 0;

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
time_t t;
    

    printf("You get one free choice.\n");
    amountlotteryfree++;
    flag=1;
    
    while(flag){
        system("cls");
        HideCursor(); //hide cursor
        gotoxy(1,1); //set the print space

        srand(time(&t));//set seed


        //initialize
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
     if(amountlotteryfree==0&&amountlotterycost>*money){
        printf("You have no money!\n");
        Waiting();
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
            
            if( booster_have<*booster_slot){

            booster_have++;
            booster_owned[lotterycontent - 7]++;
            booster_record[i] = lotterycontent - 7;
            i++;
            printf("You owned speed %d price %d area %d\n",booster_owned[0],booster_owned[1],booster_owned[2]);
            }

    
            else {
            booster_owned[booster_record[0]]--;
            booster_owned[lotterycontent - 7]++;
            printf("Due to slot space, automatically discard %d and get %d (0=speed 1=price 2=area)\n", booster_record[0], lotterycontent - 7);

            for (int k = 0; k < *booster_slot;k++){
                booster_record[k] = booster_record[k + 1];
            }
            booster_record[*booster_slot - 1] = lotterycontent - 7;
            
            printf("You owned speed %d price %d area %d\n",booster_owned[0],booster_owned[1],booster_owned[2]);
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
     Waiting();
    }



}

void map_control(int *money,int *booster_owned){
    int start = 1;
    int i=0;
    int x = 0, y = 0;
    time_t t;
    int  b[4];//money and booster coordinate
    srand(time(&t));   
    
    //generate random number for coordinate and prevent their coordinate to overlaping
    system("cls");
    printf("You have entered the mysterious CCU maze,you can find the treasure at here\n");
    Waiting();
    do{

        for (int l = 0; l < 4;l++){
            b[l] = rand() % 8;
        }
    
    } while ((b[0]==b[1]==b[2]==b[3]));

        map_print(y, x, b,money,booster_owned);
    

    while(start!=0){
     printf("Please input (1: up, 2: down, 3: left, and 4: right 5: finished) to indicate move action.\n25$ for each action.\nENTER:");

     scanf("%d", &i);

     if(i==1){

    		y=y-1;//up
            if(y!=-1){
                system("cls");
                map_print(y,x,b,money,booster_owned);
                *money -= 25;
            }

            else{ 
                printf("\n\nyou touch the board\nplease choose again\n");
                y = y + 1;
                
            }
            

        }
	 else if(i==2){
			y=y+1;//down

            if(y!=8){
                system("cls");
                map_print(y,x,b,money,booster_owned);
                *money -= 25;
            }

            else{ 
                printf("\n\nyou touch the board\nplease choose again\n");
                y = y -1;
                
            }
		}
	 else if(i==3){

			x=x-1;//left

            if(x!=-1){
                system("cls");
                map_print(y,x,b,money,booster_owned);
                *money -= 25;
            }

            else{ 
                printf("\n\nyou touch the board\nplease choose again\n");
                x = x + 1;
                
            }
		}
	 else if(i==4){

			x=x+1;//right

            if(x!=8){
                system("cls");
                map_print(y,x,b,money,booster_owned);
                *money -= 25;
            }

            else{ 
                printf("\n\nyou touch the board\nplease choose again\n");
                x = x - 1;
                
            }
		}
     else if(i==5){
            system("cls");
            start=0;
            
     }
    
	 

    }
}

void map_print(int i, int j,int *b,int *money,int *booster_owned){
    system("cls");
    HideCursor(); 
    gotoxy(1,1); 
    int a[9][9];
    int x, y;
    time_t t;
    srand(time(&t)); 

     

    for (x = 0; x < 8;x++){
     
     for (y = 0; y < 8;y++){
            a[x][y]=0; //determine the dot is 0
    }
    }


    a[b[0]][b[1]] = 2;//determine the place of money award is 2
    a[b[2]][b[3]] = 3;//determine the plcae of booster award is 3
    a[i][j] = 1;//determine the person place. person is 1.
        


    
    
    for (x = 0; x < 8;x++){
        printf("\n");
      for (y = 0; y < 8;y++){
        if(a[x][y]==0)
            printf(". ");
        else if(a[x][y]==1)
            printf("P ");
        else if(a[x][y]==2)
            printf("M ");
        else if(a[x][y]==3)
            printf("B ");

     }
    }
    printf("\n");
    printf("money you have: $%d\n",*money);
     
     
     if ((b[0] == i)&&(b[1]== j)){
        printf("Fortune!Fortune! You earn %d !!!!\n", (b[0] + 1) * (b[1] + 1) * 10);
        *money += (b[0] + 1) * (b[1] + 1) * 10;
        b[0] = b[1] = -1; //let it outside the board
        }

     if((b[2]==i)&&(b[3]==j)){
        printf("Congratulation, you earn a booster\n");
        booster_owned[rand() % 3] += 1;
        printf("You owned speed %d price %d area %d\n",booster_owned[0],booster_owned[1],booster_owned[2]);
        b[2] = b[3] = -1; //let it outside the board
    }
    
}

void aircraft_main(int *money, int *booster_slot, int *booster_owned,int *day){
    
    system("cls");
    printf("Warning!!!!!on your way home,you have been besieged by space hot dog pirates.\n");
    printf("Try to elminate (%d) hot dog pirates then you can escape and home back to CCU\n\n",(*day)*10);
    printf("Please notice:\nOne laser bullet cost $30\nElminate one enemy plane can get $100\nThe difficulty will be harder when the day passes by\n"
    "IF YOU ARE ELIMINATED,YOU WILL LOOSE ALL PROPERTIES\n\n");
    Waiting();
    system("cls");

    int pos_h = high / 2, pos_w = width / 2; // the position of plane
    int canvas[high + 2][width + 2];         // game background scope
    int enemynum = 3;                        // the number of planes
    int interval = 4;                        // simulate time gap
    int itv_move = 6;                        // the time gap of enemy aircraft
    int itv_new = 50;                        // the time of enemy  plane refreshing
    int score = 0;                           // score
    int IsOver = 1;                          // determine the game if end

    //set difficulty according to day passing by
    if(itv_move>1){//increase enemy speed
        itv_move -= *day; 
    }
    if(itv_new>10){//decrease interval time
        itv_new -= (*day)*10;
    }

    for (int i = 0; i < high + 2; i++)
    { // initialize the canvas
        for (int j = 0; j < width + 2; j++)
        {
            if(i==0 || i==high+1 ||j==0 || j==width+1){
                canvas[i][j]=border;//intitialize the border
            }
            else canvas[i][j]=blank;//initialize the blank
        }
    }
canvas[pos_h][pos_w]=plane; //initalize position
srand(time(NULL));


//game loop
while(IsOver&&(score<((*day)*10))){ 
    //update when user input
    UpdateInput(money,booster_slot,booster_owned,canvas,&pos_h,&pos_w,&enemynum,
    &interval ,&itv_move,&itv_new ,&score,&IsOver);

    //the infunce of user input
    UpdateNormal(money,booster_slot,booster_owned,canvas,&pos_h,&pos_w,&enemynum,
    &interval ,&itv_move,&itv_new ,&score,&IsOver);

    //print out the result
    Show(money,booster_slot,booster_owned,canvas,&pos_h,&pos_w,&enemynum,
    &interval ,&itv_move,&itv_new ,&score,&IsOver);


}


if (IsOver == 0)
{
    printf("\nGAME OVER!\nYOU LOOSE EVERYTHING!\nPOOR YOU!\n");
    *money = 0;
    for (int i = 0; i < 3; i++)
    {
            booster_owned[i] = 0;
    }
    }
    else if ((score >= ((*day) * 10)))
    {
            printf("\nCongratulation!You break through the enemy barricade\n");
            printf("You earned %d from the hot dog pirate\n", (*day) * 100 * 10);
    }

    clean_buffer();


    printf("See you next day\n5 seconds to next day");
    Sleep(5000); //pause 5 sec to next part 


    system("cls");//clean the terminal
    (*day)++;
}

void UpdateInput(int *money, int *booster_slot, int *booster_owned,int canvas[high+2][width+2],int *pos_h,int *pos_w,int *enemynum,
int *interval ,int *itv_move, int *itv_new ,int *score, int *IsOver){

 // detect user input. if user input return false
 char key_W = GetKeyState('W'),
      key_S = GetKeyState('S'),
      key_A = GetKeyState('A'),
      key_D = GetKeyState('D'),
      key_attack = GetKeyState(' ');


 if (kbhit()){ //when user input something
    if (key_W < 0){ //when w become flase
        if(*pos_h>1){//make sure the place in front of plane is not border
            canvas[*pos_h][*pos_w]=blank;//setting the position where plane previous stayed be blank
            if(canvas[*pos_h-1][*pos_w] == enemy){ //if the place moving to is enemy plane then destroyed and game over
                canvas[*pos_h-1][*pos_w]= destroy;
                *IsOver=0;
            }
            else canvas[--(*pos_h)][*pos_w]=plane;//else nothing happend then move

            
        }
    }
    if(key_S<0){ //when s become false
        if(*pos_h<high){
            canvas[*pos_h][*pos_w]=blank;
            if(canvas[*pos_h+1][*pos_w] == enemy){ 
                canvas[*pos_h+1][*pos_w]= destroy;
                *IsOver=0;
            }
            else canvas[++(*pos_h)][*pos_w]=plane;

            
        }
    }
    if(key_A<0){ //when a become false
        if(*pos_w>1){
            canvas[*pos_h][*pos_w]=blank;
            if(canvas[*pos_h][*pos_w-1] == enemy){ 
                canvas[*pos_h][*pos_w-1]= destroy;
                *IsOver=0;
            }
            else canvas[*pos_h][--(*pos_w)]=plane;

            
        }
    }
    if(key_D<0){ //when d become false
        if(*pos_w<width){
            canvas[*pos_h][*pos_w]=blank;
            if(canvas[*pos_h][*pos_w+1] == enemy){ 
                canvas[*pos_h][*pos_w+1]= destroy;
                *IsOver=0;
            }
            else canvas[*pos_h][++(*pos_w)]=plane;
            
        }
    }
    if(key_attack<0){ //when space become false
        if(*pos_h!=1){canvas[*pos_h-1][*pos_w]=bullet;}//if the the place in fornt of the plane is not the border then print the bullet in front of plane
        (*money) -= 20;
        
        }
        


    }



}
void UpdateNormal(int *money, int *booster_slot, int *booster_owned,int canvas[high+2][width+2],int *pos_h,int *pos_w,int *enemynum,
int *interval ,int *itv_move, int *itv_new ,int *score, int *IsOver){

int temp[high+2][width+2]; 

for(int i=1;i<=high;i++){
    for(int j=1;j<=width;j++){
        temp[i][j]=canvas[i][j];//copy data from canvas to create temp canvas but not copy the border
    }
}


for(int i=1;i<=high;i++){ 
    for(int j=1;j<=width;j++){
        if(temp[i][j]==enemy && *interval%*itv_move==0){ //the code for the enemy plane
            canvas[i][j]=blank;
            if(temp[i+1][j]==bullet){ //if laser is in front of the plane
                canvas[i+1][j]=blank;// then enemy plane destroyed at i+1
                (*score)++;
                (*money) += 100;
                printf("\a"); //the windows system sound
            }
            else if(i<high){
                canvas[i+1][j]=enemy;//if the place in fornt of the enemy plane is not border then i+1 is enemy plane
            }
            if(i+1==*pos_h&&j==*pos_w){ //is i+1 and j is player then player destroyed
                canvas[i+1][j]=destroy;
                *IsOver=0;
            }
        }
        if(temp[i][j]==bullet){ //the code for bullet
            canvas[i][j]=blank;
            if(temp[i-1][j]==enemy){ //if enemy is in fornt of bullet then destroyed and bullet disaapear
                canvas[i-1][j]=blank;
                (*score)++;
                (*money) += 100;
                printf("\a");
            }
            else if(i>1){
                canvas[i-1][j]=bullet;//else bullet keep flying
            }
        }
    }
}

if(*interval%*itv_new==0){ //if time go through a interval create enemynum enemy at random space
    for(int i=0;i<*enemynum;i++){
        canvas[rand()%2+1][rand()%width+1]=enemy;
    }
}

if(*interval<=100){ //simulate time
    (*interval)++;
}
else{ //when count to 100 go to zero again
 *interval=0;
}

}

void Show(int *money, int *booster_slot, int *booster_owned,int canvas[high+2][width+2],int *pos_h,int *pos_w,int *enemynum,
int *interval ,int *itv_move, int *itv_new ,int *score, int *IsOver){
HideCursor(); 
gotoxy(1,1); 
for(int i=0;i<high+2;i++){
    for(int j=0;j<width+2;j++){
        if( canvas[i][j] == plane ){ //the position of plane
            printf("A");
        }
        else if( canvas[i][j] == bullet ){ //the position of bullet
            printf("|");
        }
        else if( canvas[i][j] == enemy ){ //the position of enemy plane
            printf("W");
        }
        else if( canvas[i][j] == border ){ //the position of border
            printf("-");
        }
        else if( canvas[i][j] == blank ){ //the position of blank space
            printf(" ");
        }
        else if( canvas[i][j] == destroy ){ //plane destroyed
            printf("X");
        }
    }
 printf("\n");
}
 printf("\nscore:%d money:%d",*score,*money);
}
void gotoxy(int x,int y){ 
COORD pos;
pos.X=x-1;
pos.Y=y-1;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void HideCursor(){ 
CONSOLE_CURSOR_INFO cursor;
cursor.bVisible = FALSE;
cursor.dwSize = sizeof(cursor);
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorInfo(handle,&cursor);
}
void Waiting(){
    char c;
    printf("\nPleae press space to continue\n");
    while (1)
    {
        if ((c = getch()) == ' ')
        {
            break;
        }
    }
}
void clean_buffer(){
    char clean;
    printf("\n\nPress Enter To Next Day\n\n");
    while((clean=(getch()))=='a'||clean=='w'||clean=='s'||clean=='d'||clean==' '){
    
    }

}

