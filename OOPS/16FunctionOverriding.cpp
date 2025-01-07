#include<iostream>
using namespace std;
class Parent{
    public:
    void getInfo(){
        cout<<"Parent Class"<<endl;
    }
};
class Child : public Parent{
    public:
    void getInfo(){
        cout<<"Child Class"<<endl;
    }
};
int main(){
    Parent p1;
    Child c1;
    c1.getInfo(); //Function overriding
    p1.getInfo(); //Function overriding
}