// Arnab has given me a challenge. I have to calculate the number of numbers which are less than a certain value n, and have exactly k set bits in its binary form. As you are a Prepster like me, help me write a code that will take input for n and k and give the expected output.

// Constraints :
// 1<=n<=10000
// 1<=k<=10
// Input Format :
// First line containing n and k space separated
// Output Format :
// Number of numbers present in a single line

// Sample Input:
// 7 2
// Sample Output:
// 3
// Explanation:
// 11,110,101 -> These three numbers

#include<iostream>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    int count = 0;
    for(int i=1;i<n;i++){
        if(__builtin_popcount(i)==k)
            count++;
    }

    cout<<count;
}