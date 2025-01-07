#include <iostream>
#include<string.h>
using namespace std;
using namespace std;
class Hero{
    // default Private
    // Properties
    int health;
    public:
    char *name;
    // private:
    char level;
    static int timeToComplete; // Creates a data member that belongs to class
    // We can access it without making any object
    // Behaviour
    void print(){
        cout<<"Name : "<<this->name<<endl;
        cout<<"Health : "<<this->health<<endl;
        cout<<"Level : "<<this->level<<endl;
    }

    // Getter 
    int getHealth(){
        return health;
    }

    char getLevel(){
        return level;
    }

    // Setter
    void setLevel(char l){
        level = l;
    }

    void setHealth(int val){
        health = val;
    }

    void setName(char name[]){
        strcpy(this->name,name);
    }
    // Default Constructor is dead when we make our any constructor
    // Self Made Constructor
    Hero(){
        cout<<"Self made constructor called"<<endl;
        name = new char[100];
    }
    
    // Parameterised Constructor
    Hero(int health){
        cout<<"this -> "<<this<<endl;
        // health = health; // This is bad i.e unefficient
        this->health = health; // Better 
        // this keyword stores the address of current object
    }

    // Another Parameterised Constructor
    Hero(int health,char level){
        this->level = level;
        this->health = health;
    }

    // Own copy constructor (Shallow)
    // Hero(Hero &temp){
    //     cout<<"Own Copy Constructor called"<<endl;
    //     this->health = temp.health;
    //     this->level = temp.health;
    // }

    // Own copy constructor (Deep)
    Hero(Hero &temp){
        char *ch = new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name = ch;
        cout<<"Own Copy{Deep} Constructor called"<<endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    // Self Made Destructor - works for memory deallocation
    ~Hero(){
        cout<<"Self made Destructor called"<<endl;
    }

    // Static function ke paas this keyword nhi hota
    static int random(){
        // aur static function sirf static member ko hee access kar sakta hai
        return timeToComplete;
    }
};
int Hero::timeToComplete = 5; // :: - scope resolution operator

class EmptyClass{
    // kuch nahi hai
};
int main(){

    // Static Allocation
    // cout<<"Hi, we're studying OOPS"<<endl;
    // Hero Prince; // Object Prince of type Hero
    // cout<<"Yes!"<<endl;

    // Hero Prince(90);
    // cout<<"Address of Prince : "<<&Prince<<endl;
    // Prince.print();

    // // Dynamic Allocation
    // Hero *PrinceS = new Hero(55);

    // // Size of Classes
    // cout<<"Size of Hero Class : "<<sizeof(Prince)<<endl; 
    // cout<<"Size of Hero Class : "<<sizeof(PrinceS)<<endl;

    // // Empty class instantiation
    // EmptyClass Prince1;
    // cout<<"Size of empty Class : "<<sizeof(Prince1)<<endl; // 1 : Minimum 1 byte is required to keep a track of the class

    // Prince.level = 'A';
    // PrinceS->level = 'B';
    // PrinceS->print();

    // // Prince.health = 70; // Can set the health because it's Private
    // // Instead use SETTER
    // Prince.setHealth(70);
    // PrinceS->setHealth(80); // OR (*PrinceS).setHealth(80);

    // // cout<<"Health is : "<<Prince.health<<endl; // Error : health is private
    // cout<<"Prince's Level is : "<<Prince.level<<endl;
    // cout<<"PrinceS's Level is : "<<PrinceS->level<<endl; // OR (*PrinceS).level

    // // Getter 
    // cout<<"Prince's Heath is : "<<Prince.getHealth()<<endl; // Even health is Private, we can still access it by getter
    // cout<<"PrinceS's Heath is : "<<PrinceS->getHealth()<<endl; // OR (*PrinceS).getHealth()

    // Hero temp(78,'R');
    // temp.print();

    // Hero Suresh(90,'C');
    // Suresh.print();
    // Hero Ritesh(Suresh); // In-built copy constructor in 'Class Hero'
    // Ritesh.print();
    // Ritesh.health = Suresh.health;
    // Ritesh.level = Suresh.level;

    // Hero h1;
    // h1.setHealth(74);
    // h1.setLevel('D');
    // char name[13] = "Prince Singh";
    // h1.setName(name);

    // h1.print();

    // // Use deafult copy constructoor -- It does the shallow copy
    // Hero h2(h1);
    // // Hero h2 = h1;
    // // here let's change name of h1
    // h1.name[0] = 'R';
    // h1.print();
    // // h2.print(); // Because of shallow copy, the change in h1 has reflected in h2 also
    // // You may see h2's name is also changed
    // h2.print(); // After calling deep copy constructor, we've encountered the change in h1 not to affect h2

    // h1 = h2; // copy Assignment operator
    // h1.print();
    // h2.print();

    // Hero hero; // Static allocation ke liye Destructor automatically call hota hai
    // Hero *hero1 = new Hero; // Dynamic wale ke manually Destructor ko call karna padega

    // // Manually calling destructor.
    // delete hero1;
    // cout<<Hero::timeToComplete<<endl;
    // Hero a;
    // cout<<a.timeToComplete<<endl; // chal to jaygea but recommended nhi hota
    // Hero b;
    // b.timeToComplete = 10;
    // cout<<b.timeToComplete<<endl; // chal to jaygea but recommended nhi hota

    cout<<Hero::random()<<endl;
    return 0;
}