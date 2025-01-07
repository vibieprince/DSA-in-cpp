// Problem statement : You are given a three integers 'X','N' and 'M'. Your task is to find ('X' ^ 'N')%'M'. A ^ B is defined as A raised to powwer B and A % C is the remainder when A is divided by C.
#include<iostream>
using namespace std;
// Fast Exponentitaion
// a^b = For even : (a-^b/2)^2
// For Odd : (a^b/2)^2 * a
int modularExponentiation(int X,int N,int M){
    int result = 1;
    while(N){
        if(N&1)
          //i.e odd
          result = (1LL*(result)*(X)%M)%M;
        X = (1LL* (X)%M * (X)%M)%M;
        N = N>>1; // Divide by 2;
    }
    return result;
}
int main(){
    // cout<<modularExponentiation(8,2,3)<<endl;
    cout<<modularExponentiation(8,2,4)<<endl;
}