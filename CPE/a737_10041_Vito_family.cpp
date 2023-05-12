#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        int a[k];

        for (int i = 0; i < k;i++){
            cin >> a[i];
        }

        sort(a, a+k);

        int median;

        if(k%2==0){
            median = (a[(k / 2)-1] + a[((k / 2) + 1)-1]) / 2;
        }
        else{
            median = a[((k + 1) / 2)-1];
        }

        int sum = 0;

        for (int i = 0; i < k;i++){
            sum += abs(a[i] - median);
        }

        printf("%d\n", sum);
    }
}