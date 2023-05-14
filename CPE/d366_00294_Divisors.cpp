#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
/*sqrt(1e9) = 31622.8
利用質數篩法找出小於sqrt(1e9)的所有質數。
對每個 L <= n <= U 的 n 進行質因數分解。
n = b1^ p1 * b2 ^ p2 * b3^p3
則 n 有 (1+p1) * (1+p2) * (1+p3) 個因數。
*/
int main(){
    int prime[32000];

    vector<int> v;

    for (int i = 2; i < 32000;i++){
        for (int k = i * 2; k < 32000;k+=i){
            prime[k] = 1;
        }
    }

    for (int i = 2; i < 32000;i++){
        if(prime[i]==0){
            v.push_back(i);
        }
    }
    int time;
    cin >> time;
    
    vector<int>::iterator ptr;

    while(time--){
        int L, U;

        cin >> L >> U;
        int max = 0, num=0 ;
        for (int i = L; i <= U;i++){
            int cnt=1,n=i;
            for (ptr = v.begin(); ptr != v.end();++ptr){
                int power = 0;
                while(n%(*ptr)==0){
                    power++;
                    n /= (*ptr);
                }
                cnt *= (1 + power);
                if(n==1)
                    break;
            }
            if(max<cnt){
                max = cnt;
                num = i;
            }
        }
        cout << "Between " << L << " and " << U << ", " << num << " has a maximum of " << max << " divisors.\n";
    }
}

