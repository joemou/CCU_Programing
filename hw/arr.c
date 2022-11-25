#include<stdio.h>
int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


int inserction();
int updation();
int traversing();
int deletion();

int main(){
    int action_num = 1;
    char action[] = {0};

    printf("num of actions:");
    

    for (int i = 0; i < action_num;i++){
        scanf("%c",action[i]);
    }


    for (int i = 0; i < action_num;i++){
        if(action[i]=='i'){
            int inserction();

        }
        else if(action[i]=='u'){
            int updation();

        }
        else if(action[i]=='s'){
            int traversing();
            
        }
        else if(action[i]=='t'){
            int deletion();
            
        }
        else{
            printf("INVALID ACTION\n");
        }
    }
}
int inserction(){

    int position;
    int num;
    printf("position to insert:");
    scanf("%d", &position);
    printf("enter the value to insert:");
    scanf("%d", &num);
}
