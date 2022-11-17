#include <stdio.h>

int main(){
    // game begins
printf("Welcome, young boss!\n");

// each day begins
printf("Chop chop, It's dawn.\n");
printf("You have %d dollars.\n", );
printf("You need %d minutes to make a hotdog.\n", );
printf("The price of a hotdog is $%d.\n", );
printf("You have %d speed booster(s), %d price booster(s), %d area booster(s).\n", , , );

// invalid for all input
printf("Invalid input!!!!\n");

// choose booster
printf("Open/Close boosters:\n");
printf("  [1] Speed booster (now open)\n"); // if booster open
printf("  [1] Speed booster (now close)\n");
printf("  [2] Price booster (now open)\n"); // if booster open
printf("  [2] Price booster (now close)\n");
printf("  [3] Area  booster (now open)\n"); // if booster open
printf("  [3] Area  booster (now close)\n");
printf("  [4] Finish\n");
printf("Enter the number(s): ");
            
// choose action            
printf("Actions you can take for each area:\n");
printf("  [1] Sell the hotdogs\n");
printf("  [2] Improve your cooking speed\n");
printf("      (- $%d, - $%d, - $%d, - $%d for next four upgrades)\n", , , , );
printf("  [3] Improve your hotdog flavor\n");
printf("      (- $%d, - $%d, - $%d, - $%d for next four upgrades)\n", , , , );
printf("Enter the number(s): ");

// re-enter action
printf("Actions you can take at Area %d:\n", );
printf("  [1] Sell the hotdogs\n");
printf("  [2] Improve your cooking speed\n");
printf("  [3] Improve your hotdog flavor\n");
printf("Enter the number(s): ");


// end of actions a day
printf("Well done, you earn $%d today.\n", );

printf("Which result of the area you want to check?\n");
printf("  [1] Area 1\n");
printf("  [2] Area 2\n");
printf("  [3] Area 3\n");
printf("  [4] Area 4\n");
printf("  [5] Area 5\n");   // if booster open
printf("  [5] Done\n");
printf("  [6] Done\n");     // if booster open
printf("Enter the number(s): ");

// lack of money to upgrade
printf("Can't you tell how poor you are?\n");
printf("Go vending your hotdogs instead of thinking about self-improvement!\n");

// cannot reduce any time
printf("Do you want to travel through time?\n");
printf("GO WORK!!\n");

// speed upgrade
printf("You glimpse the secret of wind.\n");
printf("Your hands can move faster now.\n");

// taste upgrade
printf("You feel the soul of the ingredients.\n");
printf("Your hotdogs are more appetizing now.\n");

// sell hotdogs
printf("You make %d hotdogs here!\n", );
printf("You earn $%d!\n", );

// continue or not
printf("Do you want to continue or exit?\n");
printf("  [1] Continue\n");
printf("  [2] Exit\n");
printf("Enter the number(s): ");

// continue, so get one free choice
printf("You get one free choice.\n");

// choose cell on the lottery table
printf("You can choose\n");
printf("  [number on cell] to open (- $0)\n", );    // if free choice remains
printf("  [number on cell] to open (- $%d)\n", );
printf("  [0] to continue the game\n");
printf("Enter the number(s): ");

// no money to choose
printf("You have no money!\n");

// prize type 1
printf("Fortune, fortune! You get $%d!\n", );

// prize type 2
printf("You get an extra choice!\n");

// prize type 3 ~ 6 success
printf("Another open on %d!\n", );

// prize type 3 ~ 6 failed
printf("Bad Luck :(\n");
                    
// prize type 7 ~ 9
printf("You get a booster!!\n");

// end game                        
printf("We will miss you. Bye!\n");

/*hint for print the lottery table*/
for (int i = 0; i < ; i++){
    printf();
    for (int j = 0; j < ; j++){
        for (int k = 0; k <  + 2; k++) printf();
        printf();
    }
    printf("\n|");
    for (int j = 0; j < ; j++){
        if () printf(" %*c |", /*here is digit of maxima number*/, 'x');
        else printf(" %*d |", /*here is digit of maxima number*/, );
    }
    printf();
}
printf();
for (int j = 0; j < ; j++){
    for (int k = 0; k <  + 2; k++) printf();
    printf();
}
printf("\n");
}