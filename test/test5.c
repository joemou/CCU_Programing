#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

void booster_gain_record(int *booster_slot, int *booster_owned, int *booster_have, int *booster_record, int type);
int booster_decrease_record(int *booster_slot, int *booster_owned, int *booster_have, int *booster_record, int type);
int main(){


    int money = 100, price = 30, day = 1; // set the variable day to increase difficulty
    time_t t;
    srand(time(&t));                        // set seed
    int booster_slot = 6; // create random slot space
    int booster_owned[3] = {0, 0, 0},booster_record[booster_slot],booster_have=0;    
    int start = 1;

    int G = 12,k=12,l=12;

    while(G--){

        char type;

        scanf("%d",&type);

        booster_gain_record(&booster_slot, booster_owned, &booster_have, booster_record, type);
        printf("%d %d %d\n", booster_owned[0], booster_owned[1], booster_owned[2]);
    }


     while(k--){

        char type;

        scanf("%d",&type);

        booster_decrease_record(&booster_slot, booster_owned, &booster_have, booster_record, type);
        printf("%d %d %d\n", booster_owned[0], booster_owned[1], booster_owned[2]);
    }

    while(l--){

        char type;

        scanf("%d",&type);

        booster_gain_record(&booster_slot, booster_owned, &booster_have, booster_record, type);
        printf("%d %d %d\n", booster_owned[0], booster_owned[1], booster_owned[2]);
    }


}



void booster_gain_record( int *booster_slot,int *booster_owned,int *booster_have,int *booster_record,int type){
    
    if(*booster_have<*booster_slot){
        booster_record[*booster_have] = type;
        (*booster_have)++;
    }
    else{
        printf("\nDue to slot space, automatically discard %d and get %d (0=speed 1=price 2=area)\n", booster_record[0], type);
        booster_owned[booster_record[0]]--;
        for (int i = 0; i < *booster_slot;i++){
        booster_record[i] = booster_record[i + 1];
        }
        booster_record[(*booster_slot) - 1] = type;
        
    }
    booster_owned[type]++;

}

int booster_decrease_record( int *booster_slot,int *booster_owned, int *booster_have,int *booster_record,int type){
    int temp=-1;
    for (int i = 0; i < *booster_slot;i++){
        if(booster_record[i]==type){
            temp = i;
        }
    }

    if(temp==-1){
        return 0;
    }


    for (int k = temp; k < *booster_slot;k++){
        booster_record[k] = booster_record[k + 1];
    }
    (*booster_have)--;
    booster_owned[type]--;

    return 0;
}
