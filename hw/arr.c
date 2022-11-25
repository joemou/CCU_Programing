#include<stdio.h>
int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


int inserction();
int updation();
void traversing();
int deletion();

int main(){
    int action_num = 0;
    char action[] = {0};

    printf("num of actions:");
    scanf("%d", &action_num);

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
            void traversing();
            
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
    
    if(position<0||position>9){
        printf("INVALID POSITION\n");
        return 0;
    }

    printf("enter the value to insert:");
    scanf("%d", &num);

    for (int i=position; i<10;i++){
        arr[i+1]=arr[i];
    }

    arr[position] = num;

    for (int i = 0; i < 10;i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int updation(){

    int position;
    int num;
    
    printf("position to update:");
    scanf("%d", &position);
    
    if(position<0||position>9){
        printf("INVALID POSITION\n");
        return 0;
    }

    printf("enter the value to update:");
    scanf("%d", &num);


    arr[position] = num;
    
    for (int i = 0; i < 10;i++){
        printf("%d ", arr[i]);
    }
    
    printf("\n");
}

void traversing(){

    for (int i = 0; i < 10;i++){
        printf("%d ", arr[i]);
    }
    
    printf("\n");
}

int deletion(){

    int position;

    
    printf("position to delete:");
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
}