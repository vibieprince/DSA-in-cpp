#include<iostream>
using namespace std;
class student{
    public:
    string name;
    int roll;
};
class teacher{
    public:
    string subject;
    double salary;
};
class TeacherAssistant : public student, public teacher{

};
int main(){
    TeacherAssistant t1;
    t1.name = "Prince Singh";
    t1.subject = "Engineering";

    cout<<"Name : "<<t1.name<<endl;
    cout<<"Subject : "<<t1.subject<<endl;
}