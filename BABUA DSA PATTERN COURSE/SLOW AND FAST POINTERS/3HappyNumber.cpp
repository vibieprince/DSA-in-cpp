//  Uber   Apple   Adobe   Google   Amazon   Paypal  

// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.

#include<iostream>
#include<math.h>
using namespace std;

int sumNum(int n){
    int sum = 0;
    while(n){
        sum += pow(n%10,2);
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow = n;
    int fast = n;

    while(true){
        slow = sumNum(slow);
        fast = sumNum(sumNum(fast));
        if(fast==1) return true;
        if(slow==fast) return false;
    }
}

int main(){
    int n;
    cin>>n;
    cout<<(isHappy(n)?"Happy Number" : "Not a Happy Number");
    return 0;
}