#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v;
    vector<int>::iterator ptr;
    int times;

    cin >> times;

    while (times--) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    int position;

    cin >> position;

    v.erase(v.begin() + position - 1);



    int down, up;

    cin >> down >> up;

    v.erase(v.begin() + down - 1, v.begin() + up - 1);
    
    for (ptr = v.begin(); ptr != v.end(); ptr++) {
        cout << *ptr << " ";
    }

    return 0;
}
 
