#include<iostream>
using namespace std;

class Shape{ // Abstract class automatically because of 
    virtual void draw() = 0; //pure virtual function
};
class Circle : public Shape{
    public:
    void draw(){
        cout<<"Drawing a circle"<<endl;
    }
};
int main(){
    Circle c1;
    c1.draw();
    return 0;
    // can't call Shape class because it's abstract 
}