#include<iostream>
using namespace std;
class person{
    public:
    string name;
    int age;

    person(string name,int age){
        this->name = name;
        this->age = age;
    }

    ~person(){
        cout<<"Parent Destructor"<<endl;
    }
};
class student : public person{
    //name,age,roll no
    public:
    long long roll;
    
    student(string name,int age,long long roll) : person(name,age){
        this->roll = roll;
    }

    ~student(){
        cout<<"Child Destructor"<<endl;
    }

    void getInfo(){
        cout<<"Name : "<<name<<endl;
        cout<<"Roll no. "<<roll<<endl;
        cout<<"Age : "<<age<<endl;
    }
};
int main(){
    student s1("Prince Singh",19,2301921540131);
    s1.getInfo();
    return 0;
}