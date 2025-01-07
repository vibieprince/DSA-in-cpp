#include<iostream>
using namespace std;
class Person{
    public:
    string name;
    int age;
};
class Student : public Person{
    public:
    int roll;
};
class Teacher : public Person{
    public:
    string subject;
};