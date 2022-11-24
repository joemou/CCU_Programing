
#include <stdio.h>
#include <stdlib.h>

int main(){
	int game_eachRound = 180;
    int game_boosters[3] = {0};  //0: speed, 1: price, 2: area
	int game_lottery = 3;
    int game_lottery_show[100][100] = {0};
    int game_lottery_real[100][100] = {0};

    int amount_money = 100, amount_earned = 0;
	int amount_speed = 15, amount_taste = 30;
	int amount_speedCost = 50, amount_tasteCost = 100;
	int amount_hotdog;
	int amount_booster[3] = {0}; //0: speed, 1: price, 2: area
    int amount_lotteryFree = 0;
    int amount_lotterySpend = 1;
    int amount_lotteryRemain = game_lottery * game_lottery;
    int result[5];
    int result_print[10];

    int go_on = 1;
	int selection = 1;
    int actions[5] = {0};
    int flag = 0;

    actions[4] = 1;
    for (int i = 0; i < game_lottery; i++){
        for (int j = 0; j < game_lottery; j++){
            int lotteryNumber = i * game_lottery + j + 1;
            game_lottery_show[i][j] = lotteryNumber;
            game_lottery_real[i][j] = 0;
            while(lotteryNumber){
                game_lottery_real[i][j] += game_lottery_real[i][j] * 8 + lotteryNumber % 10;
                lotteryNumber /= 10;
            }
            game_lottery_real[i][j] = game_lottery_real[i][j] % 9 + 1;
        }
    }

	printf("Welcome, young boss!\n");
	while(go_on == 1){
        // initial setting
        selection = 1;
		amount_earned = 0;

        // message each day
        printf("Chop chop, It's dawn.\n");
        printf("You have %d dollars.\n", amount_money);
        printf("You need %d minutes to make a hotdog.\n", amount_speed);
        printf("The price of a hotdog is $%d.\n", amount_taste);
		printf("You have %d speed booster(s), %d price booster(s), %d area booster(s).\n", amount_booster[0], amount_booster[1], amount_booster[2]);
        
        // booster choosing
        while(selection != 4){
            printf("Open/Close boosters:\n");
            printf("  [1] Speed booster (now %s)\n", game_boosters[0] ? "open" : "close");
            printf("  [2] Price booster (now %s)\n", game_boosters[1] ? "open" : "close");
            printf("  [3] Area  booster (now %s)\n", game_boosters[2] ? "open" : "close");
            printf("  [4] Finish\n");
            printf("Enter the number(s): ");
			   scanf("%d", &selection);
            
            if (selection < 1 || selection > 4) printf("Invalid input!!!!\n");
            if (selection == 1) game_boosters[0] = !game_boosters[0];
            else if (selection == 2) game_boosters[1] = !game_boosters[1];
            else if (selection == 3) game_boosters[2] = !game_boosters[2];
        }

        for (int i = 0; i < 3; i++){
            if (amount_booster[i] == 0) game_boosters[i] = 0;
            if (game_boosters[i]) amount_booster[i]--;
        }

        // action choosing
        flag = 0;
        while(flag != 5 + game_boosters[2]){
            if (flag == 0){
                printf("Actions you can to take for each area:\n");
                printf("  [1] Sell the hotdogs\n");
                printf("  [2] Improve your cooking speed\n");
                printf("      (- $%d, - $%d, - $%d, - $%d for next four upgrades)\n", amount_speedCost, amount_speedCost * 2, amount_speedCost * 4, amount_speedCost * 8);
                printf("  [3] Improve your hotdog flavor\n");
                printf("      (- $%d, - $%d, - $%d, - $%d for next four upgrades)\n", amount_tasteCost, amount_tasteCost * 2, amount_tasteCost * 4, amount_tasteCost * 8);
                printf("Enter the number(s): ");
                for (int i = 0; i < 4; i++){
                    scanf("%d", &actions[i]);
                }
                flag++;
            }
            else{
                printf("Actions you can to take at Area %d:\n", flag);
                printf("  [1] Sell the hotdogs\n");
                printf("  [2] Improve your cooking speed\n");
                printf("  [3] Improve your hotdog flavor\n");
                printf("Enter the number(s): ");
                scanf("%d", &actions[flag - 1]);
            }

            for (flag; flag <= 4 + game_boosters[2]; flag++){
                amount_hotdog = game_eachRound / amount_speed;
                if (actions[flag - 1] < 1 || actions[flag - 1] > 3){
                    printf("Invalid input!!!!\n");
                    break;
                }

                selection = actions[flag - 1];
                if ((selection == 2 && amount_money < amount_speedCost) || (selection == 3 && amount_money < amount_tasteCost)){
				    result[flag - 1] = 1;
                }
                else if (selection == 2 && amount_speed == 1){
                    result[flag - 1] = 2;
                }
                else if (selection == 1){
                    result[flag - 1] = 3;
                }
                else if (selection == 2){
                    result[flag - 1] = 4;
                    amount_speed--;
                    amount_money -= amount_speedCost;
                    amount_speedCost *= 2;
                }
                else if (selection == 3){
                    result[flag - 1] = 5;
                    amount_taste += 10;
                    amount_money -= amount_tasteCost;
                    amount_tasteCost *= 2;
                }
                if (result[flag - 1] == 1 || result[flag - 1] == 2 || result[flag - 1] == 3){
                    result_print[2 * (flag - 1)] = amount_hotdog * (game_boosters[0] ? 2 : 1);
                    result_print[2 * (flag - 1) + 1] = amount_taste * result_print[2 * (flag - 1)] * (game_boosters[1] ? 2 : 1);
                    amount_earned += result_print[2 * (flag - 1) + 1];
                    amount_money += amount_earned;
                }
            }
        }

        // check result of each area
        printf("Well done, you earn $%d today.\n", amount_earned);
		while(1){
            printf("Which result of the area you want to check?\n");
            for (int i = 1; i <= 4 + game_boosters[2]; i++){
                printf("  [%d] Area %d\n", i, i);
            }
            printf("  [%d] Done\n", 4 + game_boosters[2] + 1);
            printf("Enter the number(s): ");
			scanf("%d", &selection);
            if (selection == 5 + game_boosters[2]) break;
            if (selection < 1 || selection > 5 + game_boosters[2]){
                printf("Invalid input!!!!\n");
                continue;
            }

            selection = selection - 1;
            if (result[selection] == 1){
                printf("Can't you tell how poor you are?\n");
				printf("Go vending your hotdogs instead of thinking about self-improvement!\n");
            }
            else if (result[selection] == 2){
                printf("Do you want to travel through time?\n");
			    printf("GO WORK!!\n");
            }
            else if (result[selection] == 4){
                printf("You glimpse the secret of wind.\n");
				printf("Your hands can move faster now.\n");
            }
            else if (result[selection] == 5){
                printf("You feel the soul of the ingredients.\n");
				printf("Your hotdogs are more appetizing now.\n");
            }
            if (result[selection] <= 3){
                printf("You make %d hotdogs here!\n", result_print[2 * selection]);
				printf("You earn $%d!\n", result_print[2 * selection + 1]);
            }
        }

        // continue or not
		while(1){
			printf("Do you want to continue or exit?\n");
			printf("  [1] Continue\n");
			printf("  [2] Exit\n");
			printf("Enter the number(s): ");
			scanf("%d", &go_on);
			if (go_on == 1 || go_on == 2) break;
			printf("Invalid input!!!!\n");
		}
        if (go_on == 2) break;
        
        printf("You get one free choice.\n");
        amount_lotteryFree++;
        while(1){
            // show lottery
            int lotterySpace = 0;
            int lotteryDigit = game_lottery * game_lottery;
            if (go_on == 2) break;

            
            while(lotteryDigit){
                lotteryDigit /= 10;
                lotterySpace++;
            }
            for (int i = 0; i < game_lottery; i++){
                printf("+");
                for (int j = 0; j < game_lottery; j++){
                    for (int k = 0; k < lotterySpace + 2; k++) printf("-");
                    printf("+");
                }
                printf("\n|");
                for (int j = 0; j < game_lottery; j++){
                    if (game_lottery_show[i][j] == -1) printf(" %*c |", lotterySpace, 'x');
                    else printf(" %*d |", lotterySpace, game_lottery_show[i][j]);
                }
                printf("\n");
            }
            printf("+");
            for (int j = 0; j < game_lottery; j++){
                for (int j = 0; j < lotterySpace + 2; j++) printf("-");
                printf("+");
            }
            printf("\n");

            printf("You can choose\n");
            printf("  [number on grid] to open (- $%d)\n", amount_lotteryFree == 0 ? amount_lotterySpend * 500 : 0);
            printf("  [0] to continue the game\n");
            printf("Enter the number(s): ");
            scanf("%d", &selection);
            int selectRow = (selection - 1) / game_lottery;
            int selectColumn = (selection - 1) % game_lottery;
            if (selection < 0 || selection > game_lottery * game_lottery || game_lottery_show[selectRow][selectColumn] == -1){
                printf("Invalid input!!!!\n");
                continue;
            }

            if (selection == 0) break;
            if (amount_lotteryFree == 0 && amount_lotterySpend * 500 > amount_money){
                printf("You have no money!\n");
                break;
            }
            if (amount_lotteryFree == 0){
                amount_money -= amount_lotterySpend * 500;
                amount_lotterySpend++;
            }
            else amount_lotteryFree--;
            
            while(1){
                game_lottery_show[selectRow][selectColumn] = -1;
                amount_lotteryRemain--;

                int lotteryContent = game_lottery_real[selectRow][selectColumn];
                if (lotteryContent == 1){
                    printf("Fortune, fortune! You get $%d!\n", 100 * amount_taste);
                    amount_money += 100 * amount_taste;
                }
                else if (lotteryContent == 2){
                    printf("You get an extra choice!\n");
                    amount_lotteryFree++;
                }
                else if (lotteryContent >= 7){
                    printf("You get a booster!!\n");
                    amount_booster[lotteryContent - 7]++;
                }
                else if (lotteryContent >= 3 && lotteryContent <= 6){
                    if (lotteryContent == 3) selectRow = (selectRow - 1 + game_lottery) % game_lottery;
                    else if (lotteryContent == 4) selectRow = (selectRow + 1) % game_lottery;
                    else if (lotteryContent == 5) selectColumn = (selectColumn - 1 + game_lottery) % game_lottery;
                    else if (lotteryContent == 6) selectColumn = (selectColumn + 1) % game_lottery;
                    if (game_lottery_show[selectRow][selectColumn] == -1){
                        printf("Bad Luck :(\n");
                        break;
                    }
                    printf("Another open on %d!\n", selectRow * game_lottery + selectColumn + 1);
                    continue;
                }
                break;
            }

            if (amount_lotteryRemain == 0){
                game_lottery += 2;
                amount_lotteryRemain = game_lottery * game_lottery;
                amount_lotterySpend = 1;

                for (int i = 0; i < game_lottery; i++){
                    for (int j = 0; j < game_lottery; j++){
                        int lotteryNumber = i * game_lottery + j + 1;
                        game_lottery_show[i][j] = lotteryNumber;
                        game_lottery_real[i][j] = 0;
                        while(lotteryNumber){
                            game_lottery_real[i][j] = game_lottery_real[i][j] * 8 + lotteryNumber % 10;
                            lotteryNumber /= 10;
                        }
                        game_lottery_real[i][j] = game_lottery_real[i][j] % 9 + 1;
                    }
                }
            }
        }
	}

	printf("We will miss you. Bye!\n");
	return 0;
}
