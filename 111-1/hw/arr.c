
#include <stdio.h>
#include <string.h>
int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


int inserction();
int updation();
int traversing();
int deletion();

int main(){
    int action_num = 0,i=0;
    char action[10000];
    char input;

    printf("num of actions:\n");
    scanf("%d", &action_num);

    while(strlen(action)!=action_num){

        while ((input = getchar()) != '\n')
     {
        
        action[i] = input;
        i++;
    }
    }

    for (int i = 0; i < action_num;i++){
        if(action[i]=='i'){
            inserction();

        }
        else if(action[i]=='u'){
            updation();

        }
        else if(action[i]=='t'){
            traversing();
            
        }
        else if(action[i]=='d'){
            deletion();
            
        }
        else{
            printf("INVALID ACTION\n");
        }
    }
}
int inserction(){

    int position;
    int num;
    
    printf("position to insert:\n");
    scanf("%d", &position);
    
    if(position<0||position>9){
        printf("INVALID POSITION\n");
        return 0;
    }

    printf("enter the value to insert:\n");
    scanf("%d", &num);

    for (int i=9; i>=position;i--){
        arr[i+1]=arr[i];
    }

    arr[position] = num;

    for (int i = 0; i < 10;i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}

int updation(){

    int position;
    int num;
    
    printf("position to update:\n");
    scanf("%d", &position);
    
    if(position<0||position>9){
        printf("INVALID POSITION\n");
        return 0;
    }

    printf("enter the value to update:\n");
    scanf("%d", &num);


    arr[position] = num;
    
    for (int i = 0; i < 10;i++){
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    return 0;
}

int traversing(){

    for (int i = 0; i < 10;i++){
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    return 0;
}

int deletion(){

    int position;

    
    printf("position to delete:\n");
    scanf("%d", &position);
    
    if(position<0||position>9){
        printf("INVALID POSITION\n");
        return 0;
    }

    arr[position] = 0;
    
    for (int i = 0; i < 10;i++){
        printf("%d ", arr[i]);
    }
    
    printf("\n");

    return 0;
}