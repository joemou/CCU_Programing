#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t;

    cin >> t;

    while(t--){
        int d;
        cin >> d;
        int n;
        cin >> n;
        int p[n];

        for (int i = 0; i < n;i++){
            cin >> p[i];
        }

        int day[d+1];

        for (int i = 0; i < d+1;i++){
            day[i] = 0;
        }

        for (int i = 0; i < n;i++){
            for (int k = p[i]; k <= d;k+=p[i]){
                day[k] = 1;
            }
        }

        for (int g = 0; (6+7*g <= d) && (7+7*g <= d);g++){
            day[6+7*g] = 0;
            day[7+7*g] = 0;
        }

        int sum = 0;

        for (int i=1 ; i < d+1;i++){
            
            if(day[i]==1){
                sum += 1;
            }
        }
        printf("%d\n", sum);
    }
}