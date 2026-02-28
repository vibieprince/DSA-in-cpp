// Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

 

// Example 1:

// Input: left = 5, right = 7
// Output: 4
// Example 2:

// Input: left = 0, right = 0
// Output: 0
// Example 3:

// Input: left = 1, right = 2147483647
// Output: 0
#include<iostream>
using namespace std;

int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    while(right != left){
        // yahan humne how to find longest common prefix ka logic bhi seekh liya
        left >>= 1;
        right >>= 1;
        shift++;
    }
    return right<<shift;
}

int rangeBitwiseAnd2(int left, int right) {
    while(right>left)
        right = (right & (right - 1));
    return right;
}

int main(){
    int left,right;
    cin>>left>>right;

    cout<<rangeBitwiseAnd(left,right);
    return 0;
}