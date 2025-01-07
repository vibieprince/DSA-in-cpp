#include<iostream>
using namespace std;
// void fun(){
//     static int x = 0;
//     cout<<"X : "<<x<<endl;
//     x++;
// }
class A{
    public:
    int x;
    void increment(){
        x = x + 1;
    }
};
int main(){
    // fun(); --> 0
    // fun(); --> 1
    // fun(); --> 2
    A obj1;
    A obj2;

    obj1.x = 100;
    cout<<obj1.x<<endl;
    obj1.increment();

    obj2.x = 200;
    cout<<obj1.x<<endl;
    cout<<obj2.x<<endl;
    return 0;
}