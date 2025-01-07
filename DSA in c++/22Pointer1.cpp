#include<iostream>
using namespace std;
int main(){
    // int *p; //Pointer to int is created, and pointing to some garbage address
    // (which is a bad practice)
    // int *p = 0; // Which is better practice
    // cout << *p << endl; // Segementation fault
    
    int num = 78;
    int *ptr = &num;

    cout<<*ptr<<endl;
    cout<<ptr<<endl;

    cout<<sizeof(num)<<endl;
    cout<<sizeof(ptr)<<endl;

    int *p = 0;
    p = &num;

    cout<<*p<<endl;
    cout<<p<<endl;

    int n = 5;
    int a = num;
    cout<<"Before "<<num<<endl;
    a++;
    cout<<"After "<<num<<endl;

    cout<<num<<endl;

    int *q  = &n;
    cout<<"Before "<<n<<endl;
    (*q)++;
    cout<<"After "<<n<<endl;

    // Copying a Pointer
    int *newP = p;
    cout<<p<<" - "<<newP<<endl;
    cout<<*p<<" - "<<*newP<<endl;

    // Important concept
    int i= 3;
    int *t = &i;
    // *t++;
    // cout<<(*t)++<<endl;
    *t = *t + 1;
    cout<<*t<<endl;
    t = t + 1; // Next int i.e 100 -> 104 -> 108 ... and so on.
    return 0;
}