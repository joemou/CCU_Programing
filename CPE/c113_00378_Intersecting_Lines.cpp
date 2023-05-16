#include <iostream>
#define inf 9.9e9;
using namespace std;



struct line{
    double x1, x2, y1, y2;
    double a, b;
}l1, l2, l3;

//記得&
void calcslope(line &l){
    if(l.x1==l.x2){
        l.a = inf;
        l.b = inf;
    }
    //y=ax+b
    else{
        l.a = (l.y2 - l.y1) / (l.x2 - l.x1);
        l.b = l.y1 -l.a * l.x1;
    }
}
int main(){
    int time;
    cout << "INTERSECTING LINES OUTPUT\n";
    cin >> time;
    while(time--){
        cin >> l1.x1 >> l1.y1;
        cin >> l1.x2 >> l1.y2;
        cin >> l2.x1 >> l2.y1;
        cin >> l2.x2 >> l2.y2;

        l3.x1 = l1.x1; l3.y1 = l1.y1; l3.x2 = l2.x2; l3.y2 = l2.y2;

        calcslope(l1);
        calcslope(l2);
        calcslope(l3);

        if(l1.a==l2.a){
            if(l1.b==l3.b){
                printf("LINE\n");
            }
            else{
                printf("NONE\n");
            }
        }
        else{
            double x, y;
            if ((l1.x1 == l1.x2) && (l2.y1 == l2.y2)){
                x = l1.x1;
                y = l2.y2;
            } 
            else if ((l2.x1 == l2.x2) && (l1.y1 == l1.y2)){
                x = l2.x1;
                y = l1.y2;
            }    
            else {
                x = (l2.b - l1.b) / (l1.a - l2.a);
                y = l1.a * x + l1.b;
            }
            cout << "POINT ";
            printf("%.2lf %.2lf\n", x, y);
        }
    }
    cout << "END OF OUTPUT\n";
    return 0;
}