#include<iostream>
using namespace std;  //Constructor is declared in public only
class Teacher{
    private:
    double sal;
    // protected:
    public: // below is non-parameterised constructor
    Teacher() { // This is our self-made constructor
        depart = "Computer Science"; // here depart is set so now we'll not have to set it again and again
        cout<<"Hi, i'm constructor"<<endl;
    }
    Teacher(string n,string d,string s,double salary){ // So, here it is a parameterised constructor
        name = n;
        sal = salary;
        depart = d;
        subject = s;
    }
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

    void getinfo(){
        cout<<"Name : "<<name<<endl;
        cout<<"Department : "<<depart<<endl;
    }
};
int main(){
    // Teacher t1; //here constructor is called automatically so that memmory can be allocated
    // and if we've made our own constructor then it is called
    // t1.name = "Prince";
    // t1.depart = "Computer Science";
    // cout<<t1.depart<<endl;

    Teacher t1("Prince","Computer Science","C++",25000); // calling paramterised constrcutor
    t1.getinfo();
}