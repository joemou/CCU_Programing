#include <iostream>
#include <string>

int main(){

    int x, y;

    scanf("%d %d", &x, &y);

    int position_x, position_y;
    char direction;
    int scent[x+1][y+1];
    int check = 0;

    while((scanf("%d %d %c",& position_x, &position_y, &direction))!=EOF){

        int lost = 0;
        char insert[101];
        scanf("%s", insert);

        for (int i = 0; insert[i]; ++i){
            switch(insert[i]){
                case 'L':
                    if(direction=='N'){
                        direction = 'W';
                        break;
                    }
                    if(direction=='W'){
                        direction = 'S';
                        break;
                    }
                    if(direction=='S'){
                        direction = 'E';
                        break;
                    }
                    if(direction=='E'){
                        direction = 'N';
                        break;
                    }

                case 'R':
                    if(direction=='N'){
                        direction = 'E';
                        break;
                    }
                    if(direction=='E'){
                        direction = 'S';
                        break;
                    }
                    if(direction=='S'){
                        direction = 'W';
                        break;
                    }
                    if(direction=='W'){
                        direction = 'N';
                        break;
                    }
                case 'F':
                    if(scent[position_x][position_y]==1){
                        check = 1;
                    }
                    if(direction=='N'){
                        position_y += 1;
                        break;
                    }
                    if(direction=='E'){
                        position_x += 1;
                        break;
                    }
                    if(direction=='S'){
                        position_y -= 1;
                        break;
                    }
                    if(direction=='W'){
                        position_x -= 1;
                        break;
                    }
                    


            }

            if(check==1){

                if(position_x>x){
                    position_x -= 1;
                }
                if(position_y>y){
                    position_y -= 1;
                }
                if(position_x<0){
                    position_x += 1;
                }
                if(position_y<0){
                    position_y += 1;
                }

            }

            if (position_x > x || position_y > y || position_x < 0||position_y<0)
            {
                
                lost = 1;
                if(position_x>x){
                    position_x -= 1;
                }
                if(position_y>y){
                    position_y -= 1;
                }
                if(position_x<0){
                    position_x += 1;
                }
                if(position_y<0){
                    position_y += 1;
                }
                scent[position_x][position_y] = 1;
                break;
            }
        }
        if(lost==1){
            printf("%d %d %c LOST\n", position_x, position_y, direction);
        }
        else{
            printf("%d %d %c\n", position_x, position_y, direction);
        }
    }   
}