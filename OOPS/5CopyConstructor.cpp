#include<iostream>
using namespace std;
class Teacher{
    private:
    double sal;

    public:
    string name;
    string sub;
    string depart;

    // Parameterized constructor
    Teacher(string name,string sub,string depart,double sal){
        this->name = name;
        this->sub = sub;
        this->depart = depart;
        this->sal = sal;
    }

    // Copy constructor
    Teacher(Teacher &obj){
        cout<<"I'm custom copy constructor"<<endl;
        this->name = obj.name;
        this->depart = obj.depart;
        this->sub = obj.sub;
        this->sal = obj.sal;
    }

    void getInfo(){
        cout<<"Name : "<<name<<endl;
        cout<<"Subject : "<<sub<<endl;
        cout<<"Department : "<<depart<<endl;
        cout<<"Salary : "<<sal<<endl;
    }
};
int main(){
    Teacher t1("Prince","C++","Computer Science",25000);
    //Teacher t2(t1); // by default copy constructor is called
    Teacher t2(t1); // Here our own copy constuctor is called
    t2.getInfo();
    return 0;
}