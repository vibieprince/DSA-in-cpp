#include<iostream>
using namespace std;

// Macro - a piece of code in a program that is replaced by value of macro

#define PI 3.14 // Object like macros

#define INSTAGRAM FOLLOWERS // Chain Macro
#define FOLLOWERS 138

#define ELE 1,2,3 // Multi-line macro

#define min(a,b) (((a)<(b)) ? (a):(b)) // Function like macro

int main(){
    int r = 5;
    // double pi = 3.14; //---> takes storage 
    double area = PI*r*r;

    // PI = PI + 1 ---> cannot do this 
    cout<<"Area is : "<<area<<endl;
    
    cout<<INSTAGRAM<<endl;

    int arr[] = {ELE};
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;

    cout<<min(4,5);
}