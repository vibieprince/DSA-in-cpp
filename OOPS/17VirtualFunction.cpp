#include<iostream>
using namespace std;
class Parent{
    public:
    virtual void Hello(){
        cout<<"Hello from parent"<<endl;
    }
};
class Child : public Parent{
    public:
    void Hello(){
        cout<<"Hello from child"<<endl;
    }
};
int main(){
    Parent p1;
    Child c1;
    p1.Hello();
    c1.Hello();
}