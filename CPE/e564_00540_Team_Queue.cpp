#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
 
int main(){
    int n,Case;
    while(cin>>n){
        
        
        queue<int> team[10001], q;
        int mates,num;
        int id[1000000];
        

        if(n==0)
            break;
        Case++;
        cout << "Scenario #" << Case << "\n";
        for (int i = 0;i<n;i++){
            cin >> mates;   
            for (int j = 0; j < mates;j++){
                cin >> num;
                id[num] = i;
            }
        }

        string s;

        while(cin>>s){
            if (s == "STOP") 
                break;
            else if (s == "ENQUEUE"){
                int a;
                cin >> a;
                if((team[id[a]]).empty()){
                    q.push(id[a]);
                }
                team[id[a]].push(a);
            }
            else if (s == "DEQUEUE"){
                int front = q.front();

                cout << team[front].front()<<"\n";
                team[front].pop();

                if(team[front].empty()){
                    q.pop();
                }
            }
        }

        //clean time to next senaario
        cout << "\n";

        while(!q.empty()){
            int front = q.front();
            while(!team[front].empty()){
                team[front].pop();
            }
            q.pop();
        }  
    }   
}