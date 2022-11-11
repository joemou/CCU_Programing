#include <stdio.h>
int main(){
    int hour,minutes;

   
        scanf("%d:%2d", &hour, &minutes);

    if(hour>=1&&hour<12&&minutes<60&&minutes>=0){
        printf("%d:%02d AM\n", hour, minutes);
    }
    
    else if(hour==0&&minutes<60&&minutes>=0){
        printf("%d:%02d AM\n",hour+12,minutes);
    }
    else if(hour==12&&minutes<60&&minutes>=0){
        printf("%d:%02d PM\n",hour,minutes);
    }
    
    else if(hour>12&&hour<24&&minutes<60&&minutes>=0){
        printf("%d:%02d PM\n", hour-12, minutes);
    }



    else{
        printf("Incorrect Input\n");
    
    }
    return 0;
}