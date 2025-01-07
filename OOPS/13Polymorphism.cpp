#include<iostream>
using namespace std;
class student{
    public:
    string name;

    //Non-paramterised constructor
    student(){
        cout<<"Hi, I'm non-paramterised constructor";
    }
    
    //Parameterised constructor
    student(string name){
        this->name = name;
        cout<<"Hi, I'm parameterised constructor";
    }
};
int main(){
    //student s1; //non-parameterised constructor is called
    student s1("Prince Singh"); //Here, non-parameterised constructor is called
    // So, depending on the context the object can change its form which is an example of Polymorphism (constructor overloading)
    return 0;
}