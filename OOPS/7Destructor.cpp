#include<iostream>
using namespace std;
class student{
    private:
    double *cgpaPtr;

    public:
    string name;
    string section;
    long long roll;

    // Constructor
    student(string name,string section,long long roll,double cgpa){
        this->name = name;
        this->section = section;
        this->roll = roll;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }
    // Destructor
    ~student(){
        cout<<"Hi i'm mannual destructor"<<endl;
        delete cgpaPtr;
    }

    void getInfo(){
        cout<<"Name : "<<name<<endl;
        cout<<"Section : "<<section<<endl;
        cout<<"Roll no. : "<<roll<<endl;
        cout<<"SGPA : "<<*cgpaPtr<<endl;
    }
};
int main(){
    student s1("Prince Singh","T",2301921540131,7.8);
    s1.getInfo();
}