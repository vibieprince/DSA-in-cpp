#include<iostream>
using namespace std;
class Teacher{
    private:
    double sal;
    // protected:
    public:
    //Properties/ attributes
    string name;
    string depart;
    string subject;

    //methods/ member functions
    void changeDepart(string newDepart){
        depart = newDepart;
    }

    //setter
    void setSal(double s){
        sal = s;
    }

    //getter
    double getSal(){
        return sal;
    }
};
class student{
    public:
    string name;
    int roll;
    int age;
    string sec;
};
int main(){
    Teacher t1;
    t1.name = "Prince";
    t1.subject = "C++";
    t1.depart = "Computer Science";
    // t1.sal = 25000; ---> Error because its private 
    t1.setSal(25000);
    cout<<t1.getSal()<<endl;
    return 0;
}