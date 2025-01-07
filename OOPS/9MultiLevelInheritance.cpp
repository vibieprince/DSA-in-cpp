#include<iostream>
using namespace std;
class person{
    public:
    string name;
    int age;
};
class student : public person{
    public:
    int roll;
};
class gradstudent : public student{
    public:
    string researcharea;

};
int main(){
    gradstudent s1;
    s1.name = "Prince";
    s1.researcharea = "Internet of things";
    cout<<"Name : "<<s1.name<<endl;
    cout<<"Research area : "<<s1.researcharea<<endl;
    return 0;
}