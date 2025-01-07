// Fully Encapsulated class --- all data members are private
// Encapsulation -- information/data hiding
// By Encapsulation we can make our class read only
// Increased Security
// Code Reusability
#include <iostream>
using namespace std;
class Student{
    string name;
    int age;
    int height;

    public:
    int getAge(){
        return this->age;
    }
};
class Human{

    public:
    float height;
    int weight;
    int age;

    int getAge(){
        return this->age;
    }
    
    void setHeight(float height){
        this->height = height;
    }

    void setWeight(int weight){
        this->weight = weight;
    }
    void speak(){
        cout<<"Speaking"<<endl;
    }

};

// Inheritance
// Note : Any Private member of super class can't be inherited
// class Male:public Human{ // kyunki aapne isko public mode mein inherit kiya toh wo yahan bhi public rahegi
//     public:
//     string colour;

//     void sleep(){
//         cout<<"Male is sleeping";
//     }
// };

// Single Inheritance
class Male:protected Human{ // kyunki aapne isko public mode mein inherit kiya toh wo yahan bhi public rahegi
    public:
    string colour;

    void sleep(){
        cout<<"Male is sleeping";
    }

    int getHeight(){
        return this->height;
    }
};

// Multi-level Inheritance
class Animal{
    public:
    int weight;
    int height;

    void bark(){
        cout<<"Barking"<<endl;
    }
};

class dog:public Animal{

};

class GermanSephard:public dog{

};

// Multiple Inheritance
class Hybrid:public Animal,public Human{

};

// Hierachical Inheritance --- One class serve as parent class for more than 1 class
class Parent{
    public:
    void func1(){
        cout<<"Inside function 1"<<endl;
    }
};
class Son:public Parent{
    public:
    void func2(){
        cout<<"Inside function 2"<<endl;
    }
};
class Daughter:public Parent{
    public:
    void func3(){
        cout<<"Inside function 3"<<endl;
    }
};

// Hybrid Inheritance ---- Combination of more than one type of inheritance
class GrandFather{
    public:
    void callGrandFather(){
        cout<<"I AM GRAND FATHER"<<endl;
    }
};

class Father:public GrandFather{
    public:
    void callFather(){
        cout<<"I AM FATHER"<<endl;
    }
};

class Son2:public Father{
    public:
    void callSon(){
        cout<<"I AM SON"<<endl;
    }
};

// Inheritance Ambiguity
class A{
    public:
    void print(){
        cout<<"I AM A"<<endl;
    }
};
class B{
    public:
    void print(){
        cout<<"I AM B"<<endl;
    }
};
class C : public A,public B{

};
// Compile time - static
// Compile time Polymorphirsm (Function Overloading)
class Poly{
    public:
    void sayHello(){
        cout<<"Hello Prince Singh"<<endl;
    }
    // void sayHello(){ --- Not acceptable
    //     cout<<"Hello Prince Singh"<<endl;
    // }
    // int sayHello(){ --- Not acceptable
    //     cout<<"Hello Prince Singh"<<endl;
    //     return 1;
    // }
    void sayHello(string name){
        cout<<"Hello "<<name<<endl;
    }
};

// Compile time Polymorphism (Operator Overloading)
class Overload{
    public:
    int a;
    int b;

    int add(){
        return a+b;
    }

    void operator+(Overload &obj){
        int val1 = this->a;
        int val2 = obj.a;
        cout<<"Output "<<val2 - val1<<endl;
    }

    void operator()(){
        cout<<"mai too bracket hoon "<<this->a<<endl;
    }
};
// Runtime polymorphism ---- Dyanmic
// Runtime Polymorphism - function/method Overriding
class donkey{
    public:
    void show(){
        cout<<"Inside Parent class"<<endl;
    }
};
class Car: public donkey{
    public:
    void speak(){
        cout<<"Inside child class"<<endl;
    }
};

// Abstraction - Implementation hiding
// (i.e showing only essential things)


int main(){
    // Student fisrt;
    // cout<<"Sab sahi chal raha hai";

    // Male object1;
    // cout<<object1.age<<endl;
    // object1.setHeight(5.4);
    // object1.setWeight(65);
    // cout<<object1.weight<<endl;
    // cout<<object1.height<<endl;

    // cout<<object1.getHeight()<<endl;
    // cout<<object1.colour<<endl;
    // object1.sleep();

    // GermanSephard g;
    // g.bark();

    // Hybrid h;
    // h.speak(); 
    // h.bark();

    // Parent obj1;
    // obj1.func1();

    // Son obj2;
    // obj2.func1();
    // obj2.func2();

    // Daughter obj3;
    // obj3.func1();
    // // obj3.func2(); //---> ERROR
    // obj3.func3();

    // GrandFather g;
    // g.callGrandFather();

    // Father f;
    // f.callGrandFather();
    // f.callFather();

    // Son2 s;
    // s.callGrandFather();
    // s.callFather();
    // s.callSon();

    // C c;
    // c.print(); // ERROR ---> print is Ambiguious
    // To resolve this
    // c.A::print();

    // Poly p;
    // p.sayHello();
    // p.sayHello("Prince Singh");

    // Overload obj1,obj2;
    // obj1.a = 4;
    // obj2.a = 7;
    // obj1 + obj2;
    // obj1();

    Car c;
    c.speak();
    return 0;
}