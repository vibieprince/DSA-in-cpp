// Problem Statement : Find the factorial of 212 using %m [m=10^9 + 7]
#include<iostream>
#define M 1000000007
using namespace std;

long long factorial(int n){
    long long result = 1;
    for(int i=2;i<=n;i++)
       result = (result*i)%M;
    return result;
}
int main(){
    int n = 212;
    cout<<"Factorial of "<<n<<" modulo "<<M<<" is : "<<
    factorial(n)<<endl;
    return 0;
}