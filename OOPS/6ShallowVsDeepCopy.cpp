#include<iostream>
using namespace std;
class Student{

    public:
    double *cgpaPtr;
    string name;
    long long int roll;
    string section;

    Student(string name,string section,long long int roll,double cgpa){
        this->name = name;
        this->section = section;
        this->roll = roll;
        cgpaPtr = new double; // pointed to heap 
        *cgpaPtr = cgpa;
    }
    // Shallow Copy Constructor
    // Student(Student &obj){
    //     this->name = obj.name;
    //     this->cgpaPtr = obj.cgpaPtr;
    // }

    // Deep Copy Constructor 
    Student(Student &obj){
        this->name = obj.name;
        cgpaPtr = new double;
        *cgpaPtr = *obj.cgpaPtr;
    }

    void getInfo(){
        cout<<"Name : "<<name<<endl;
        cout<<"Section : "<<section<<endl;
        cout<<"Roll number : "<<roll<<endl;
        cout<<"SGPA : "<<*cgpaPtr<<"\n"<<endl;
    }
};
int main(){
    Student s1("Prince Singh","T",2301921540131,7.82);
    Student s2(s1); // default constructor called

    s1.getInfo();
    *(s2.cgpaPtr) = 9.2; // here shallow copy occurs
    s2.getInfo();

    s2.name = "Akash";
    s2.getInfo(); // cgpa affected by s2 
    return 0;
}