// Problem Description :

// Stepping Numbers are numbers in which the adjacent digits differ by 1. For example, 123, 545, and 98 are stepping numbers, while 321, 444, and 75 are not. The task is to find all stepping numbers in a given range [n, m].

// For example
// Range: [100, 500]
// Stepping Numbers: 101, 121, 123, 210, 212, 232, 234, 321, 323, 343, 345
// Explanation: The stepping numbers between 100 and 500 are 101, 121, 123, 210, 212, 232, 234, 321, 323, 343, and 345. These numbers have adjacent digits that differ by 1.
// Write code to find out all the stepping numbers in the given range.

// Input Format: First line contains two numbers N,M

// Output Format: Print all the stepping numbers present in the range.

// Constraints: 0 <= N < M <= 1,000,000,000

#include<iostream>
using namespace std;

void generateStepNums(int num,int N,int M){
    if(num>M)
        return;
    if(num>=N)
        cout<<num<<" ";
    
    int lastDigit = num % 10;

    if(lastDigit>0)
        generateStepNums(num*10 + (lastDigit-1),N,M);
    
    if(lastDigit<9)
        generateStepNums(num*10 + (lastDigit+1),N,M);
}

int main(){
    int N,M;
    cin>>N>>M;
    
    for(int num=1;num<10;num++)
        generateStepNums(num,N,M);
        
    return 0;
}