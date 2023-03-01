#include <stdio.h>

int flavor_level=0;


void base_wind(){
    int i=0;
    flavor_level=0;
    printf("Let's select the base wine!\n");
    printf("Please Enter flavor level of the base wine: ");
    scanf("%d", &i);
    flavor_level += i;
    printf("The flavor level is %d!\n", i);
};
void two_wine(){
    int w1=0, w2=0;
    int GCF = 1;//greatest common factor
    printf("Now add two kinds of wines.\n");
    printf("Please Enter two types representing each wine: ");
    scanf("%d %d", &w1, &w2);
    for(int i=1;i<=(w1>w2?w2:w1);i++){
        if(w1%i==0&&w2%i==0){
            GCF = i;
        }
    }
    flavor_level += GCF;
    printf("The flavor level increased %d!\n", GCF);
};
void add_juice(){
    int i=0;
    printf("Now add some juice.\n");
    printf("Please Enter flavor level of the juice: ");
    scanf("%d", &i);
    flavor_level += i;
    printf("The flavor level increased %d!\n", i);
};
void add_co2(){
    int c=0,co2=0;
    printf("Now add some CO2.\n");
    printf("The current flavor level is %d.\n",flavor_level);
    printf("Please Enter power of CO2: ");
    scanf("%d", &c);
    if(c<=flavor_level/2){
        co2+=2 * c;
    }
    else if(flavor_level/2<c&&c<=flavor_level){
        co2+=3 * c;
    }
    else if(c>flavor_level){
        co2+= c;
    }
    flavor_level += co2;
    printf("The flavor level increased %d!\n", co2);
}
void shake(){
    int shake = 0,shake_amount=0;
    printf("Now shake.\n");
    do{
        printf("Please enter the power of a shake(0 to stop): ");
        scanf("%d", &shake);
        flavor_level += shake;
        shake_amount += shake;
    } while (shake != 0);
    printf("The flavor level increased %d!\n", shake_amount);
};
void pull_into_glass(){
    int cup = 0, price = 0,final_price=0;
    printf("Finally, select a wine glass to pull your cocktail in.\n");
    printf("Please enter the number of wine glass(1 to 5): ");
    scanf("%d", &cup);
    switch(cup){
        case 1:
            price += 10;
            break;
        case 2:
            price += 15;
            break;
        case 3:
            price += 17;
            break;
        case 4:
            price += 23;
            break;
        case 5:
            price += 40;
            break;
    }
    final_price += flavor_level + price;
    printf("The price increased %d!\nWell done! The Price of this cocktail is %d!\n", price,final_price);
};

int main(){

    printf("Let's make our first cocktail!\n");
    base_wind();
    two_wine();
    two_wine();
    shake();
    add_juice();
    add_co2();
    pull_into_glass();
    printf("Let's make our second cocktail!\n");
    base_wind();
    two_wine();
    shake();
    add_juice();
    shake();
    add_co2();
    two_wine();
    add_co2();
    add_juice();
    shake();
    two_wine();
    shake();
    two_wine();
    add_juice();
    add_co2();
    shake();
    add_co2();
    two_wine();
    shake();
    add_juice();
    add_juice();
    two_wine();
    two_wine();
    add_co2();
    shake();
    two_wine();
    shake();
    two_wine();
    shake();
    pull_into_glass();
}