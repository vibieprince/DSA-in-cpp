#include<iostream>
using namespace std;
class Teacher{
    private:
    double salary;

    public:
    string name;
    string subject;
    string department;
    Teacher(string name,string subject,string department,double salary){
        this->department = department;
        this->name = name;
        this->subject = subject;
        this->salary = salary;
    }

    void getInfo(){
        cout<<"Name : "<<name<<endl;
        cout<<"Subject : "<<subject<<endl;
        cout<<"Department : "<<department<<endl;
        cout<<"Salary : "<<salary<<endl;
    }
};
int main(){
    Teacher t1("Prince Singh","C++","Computer Science",25000);
    t1.getInfo();
    return 0;
}