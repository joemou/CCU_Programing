#include <iostream>

using namespace std;

long long mod(long long b,long p,long long m){
    if(p==0){
        return 1;
    }
    else if(p==1){
        return b % m;
    }
    else{
        if(p%2==0){
            long long temp = mod(b, p / 2, m);
            return (temp * temp) % m;
        }
        else{
            long long temp = mod(b, (p - 1) / 2,m);
            return (temp * temp * b) % m;
        }
    }

}

int main(){
    long long b, p, m;

    while(cin>>b>>p>>m){
        cout << mod(b, p, m) << endl;
    }
}