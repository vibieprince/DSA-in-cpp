// Problem Statement  :

// You will be given a left limit and a right limit. You need to Calculate the sum of all prime numbers between a given range x and y, both inclusive.

// Sample Test Case :
// Input :      Output :
// 30             68
// 40

// Explanation :
// 31 and 37 are the two prime numbers in the window.

#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    bool prime[m+1];
    prime[0] = prime[1] = false;
    for(int i=2;i<=m;i++)
        prime[i] = true;

    for(int i=2;i*i<=m;i++){
        if(prime[i])
            for(int k=i*i;k<=m;k+=i)
                prime[k] = false;
    }

    int sum = 0;

    for(int i=n;i<=m;i++)
        if(prime[i])
            sum += i;
        
    cout<<sum;
    return 0;
}