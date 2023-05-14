#include <iostream>
#define inf 9.9e9;
using namespace std;



struct line{
    double x1, x2, y1, y2;
    double a, b;
}l1, l2, l3;

//記得&
double calcslope(line &l){
    if(l.x1==l.x2){
        l.a = inf;
        l.b = inf;
    }
    else{
        l.a = (l.y2 - l.y1) / (l.x2 - l.x1);
        l.b=
    }
}
int main(){

}