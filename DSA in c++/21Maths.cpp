#include<iostream>
using namespace std;
int gcd(int a,int b){
    if(a==0)
      return b;
    if(b==0)
      return a;
    while(a!=b){
        if(a>b)
           a = a-b;
        else
           b = b-a;
    }
    return a;
}
// gcd(a,b)=gcd(a-b,b)=gcd(a%b,b)
// lcm(a,b) * gcd(a,b) = a*b;

// modulo arithmetic
// (a+b)%m = a%m + b%m
// a%m - b%m = (a-b)%m 
// a%m * b%m = (a*b)%m 
int main(){
    // GCD of two numbers
    int a,b;
    cout<<"Enter the two numbers : "<<endl;
    cin>>a>>b;

    int ans = gcd(a,b);
    cout<<"The GCD of "<<a<<" & "<<b<<" is : "<<ans<<endl;
}