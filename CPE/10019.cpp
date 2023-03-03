#include <iostream>
using namespace std;
 
int main() {
    int T, N,x1,temp,a=0,b=0;
    cin >> T;
    while (T--){
        cin >> N;
        x1 = N;
        while(x1>0){
            if(x1%2==1){
                a += 1;
            }
            x1 /= 2;
        }
        x1 = N;
        while(x1>0){
            temp = x1 % 10;
            while(temp>0){
                if(temp%2==1){
                    b += 1;
                }
                temp /= 2;

            }
            x1 /= 10;
        }

    }
    cout << a << " " <<b<< endl;

    return 0;
}