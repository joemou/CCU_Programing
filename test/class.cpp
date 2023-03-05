#include <iostream>

using namespace std;

class car{
    public:
        int name;
        int num;
        void show();
};

void car::show(){
    printf("%d\n", name);
    cout<< "num" << num <<"\n";
}

int main(){
    car carl;
    carl.name = 1234;
    carl.num = 123;

    carl.show();

    return 0;
}