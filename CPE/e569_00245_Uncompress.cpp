#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    vector<string> v;
    vector<string>::iterator ptr,ptr2;
    
    string s,word;
    int num=0;
    while(getline(cin,s)){
        if(s=="0"){
            break;
        }
        s += "\n";
        for (int i = 0; i < s.size();i++){
            
            if(isalpha(s[i])){
                word += s[i];
            }
            else if(isdigit(s[i])){
                word = "";
                num *= 10;
                num += s[i] - '0';
            }
            else{
                if(word!=""){
                    cout << word;
                    ptr = find(v.begin(), v.end(), word);
                    if(ptr==v.end()){
                        v.push_back(word);
                    }
                    else{
                        v.erase(ptr);
                        v.push_back(word);
                    }
                    word = "";
                }
                if(num!=0&&num<=v.size()){
                    
                    ptr2 = v.end();
                    ptr2 = prev(ptr2, num);
                    
                    string str = *ptr2;
                    cout << str;
                    
                    v.push_back(str);
                    v.erase(ptr2);
                    num = 0;
                }
                cout << s[i];
            }
        }
    }
}