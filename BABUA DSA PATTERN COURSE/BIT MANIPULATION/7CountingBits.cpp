//  Apple   Adobe   Amazon   Infosys   Accenture   Goldman Sachs   JPMorgan & Chase 

// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

// Example 1:

// Input: n = 2
// Output: [0,1,1]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// Example 2:

// Input: n = 5
// Output: [0,1,1,2,1,2]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// 3 --> 11
// 4 --> 100
// 5 --> 101

#include<iostream>
#include<vector>
using namespace std;

vector<int> countBits(int n) {
//         i = even  → i/2 ka same bit count
// i = odd   → i/2 + 1
    vector<int> result(n+1,0);
    for(int i=1;i<=n;i++)
        result[i] = result[i>>1] + (i&1); 
    //     i >> 1  removes last bit
    // i & 1   tells if last bit 1 hai
    return result;
}

vector<int> countBits(int n) {
    vector<int> result(n+1,0);
    for(int bit=0;bit<32;bit++){
        int mask = (1<<bit);
        for(int i=0;i<=n;i++)
            if(i & mask) result[i]++;
    }
    return result;
}


int main(){
    int n;
    cin>>n;

    vector<int> result = countBits(n);
    for(int &i : result)
        cout<<i<<" ";
    return 0;
}