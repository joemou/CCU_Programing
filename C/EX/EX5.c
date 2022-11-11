#include <stdio.h>

int main(void){

    int money=100, time=15,price=30,action=0,day_money=0,power=0,j=1,k=1;

    printf("Welcome, young boss!\n");
do{
    printf("Chop chop, It's dawn.\n");

    for (int i = 1; i < 5; i++)
    {

        printf("You are at Area %d.\n", i);
        printf("You have %d dollars.\n", money);
        printf("You need %d minutes to make a hotdog.\n", time);
        printf("The price of a hotdog is $%d.\n", price);

        printf("Please choose which action you want to take:\n");
        printf("  [1] Sell the hotdogs (+ $%d)\n",180/time*price);
        printf("  [2] Improve your cooking speed (- $%d / - 1 min for making a hotdog)\n", j*50);
        printf("  [3] Improve your hotdog flavor (- $%d / + $10 for each hotdog)\n", k*100);
        printf("Enter the number: ");
        scanf("%d", &action);
        

        while(action!=1&&action!=2&&action!=3){
             printf("Invalid input!!!!\n");
             printf("Please choose which action you want to take:\n");
             printf("  [1] Sell the hotdogs (+ $%d)\n",180/time*price);
             printf("  [2] Improve your cooking speed (- $%d / - 1 min for making a hotdog)\n", j*50);
             printf("  [3] Improve your hotdog flavor (- $%d / + $10 for each hotdog)\n", k*100);
             printf("Enter the number: ");
             scanf("%d", &action);
        }
        switch(action)
        {
           case 1:{
               money = money + 180/time*price;
               printf("You make %d hotdogs here!\nYou earn $%d!\n", 180 / time, 180/time*price); //price * 180 / time(?)
               day_money += 180/time*price;
               break;
            }         
           
           case 2:{
               
               if(money-j*50>=0){
                if(time-1>=1){
                  money = money - j * 50;
                  time = time - 1;
                  printf("You glimpse the secret of wind.\nYour hands can move faster now.\n");
                  j = j * 2;
                } 
                else{
                  printf("Do you want to travel through time?\nGO WORK!!\n");
                  money += 180/time*price;
                  printf("You make %d hotdogs here!\nYou earn $%d!\n", 180 / time, 180/time*price); 
                  day_money += 180/time*price;
                }
                }
               else{
                 printf("Can't you tell how poor you are?\nGo vending your hotdogs instead of thinking about\nself-improvement!\n");
                 money +=180/time*price;
                 printf("You make %d hotdogs here!\nYou earn $%d!\n", 180 / time, 180/time*price);
                 day_money += 180/time*price;           
               }

               
               
               break;
            }
            case 3:{
                
                if(money-k*100>=0){
                    printf("You feel the soul of the ingredients.\nYour hotdogs are more appetizing now.\n");
                    money = money-100*k;
                    price = price + 10;
                    k = k * 2;
                    
                }
                else{
                 printf("Can't you tell how poor you are?\nGo vending your hotdogs instead of thinking about\nself-improvement!\n");
                 money = money + 180/time*price;
                 printf("You make %d hotdogs here!\nYou earn $%d!\n", 180 / time, 180/time*price);
                 day_money += 180/time*price;                 
               }
              
               break;
            }
              
                
        }

        
        
    }
  
  
        printf("Well done, you earn $%d today.\n",day_money);
        day_money = 0;

        printf("Do you want to continue or exit?\n  [1] Continue\n  [2] Exit\nEnter the number: ");
        scanf("%d", &power);
        if(power==2){
            printf("We will miss you. Bye!\n");
        }
        while(power!=1&&power!=2){
             printf("Invalid input!!!!\n");
             printf("Do you want to continue or exit?\n  [1] Continue\n  [2] Exit\nEnter the number: ");
             scanf("%d", &power);}
             if(power==0){
             printf("We will miss you. Bye!\n");
        }



} while (power==1);
    return 0;
}