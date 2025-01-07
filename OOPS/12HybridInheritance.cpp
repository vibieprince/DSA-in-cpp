#include<iostream>
using namespace std;
class Person{
    string name;
    int age;
};
class Student : public Person{
    int roll;
};
class Teacher : public Person{
    string subject;
};
class GradStudent : public Student{
    string researcharea;
};
class TeacherAssistant : public Student, public Teacher{
    string department;
};
