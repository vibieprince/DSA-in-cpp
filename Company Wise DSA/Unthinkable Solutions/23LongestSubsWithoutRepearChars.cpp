// Problem statement
// Given a string input of length n, find the length of the longest substring without repeating characters i.e return a substring that does not have any repeating characters.

// Substring is the continuous sub-part of the string formed by removing zero or more characters from both ends.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
//  1<= n <=10^5

// Time Limit: 1 sec
// Sample Input 1:
//  abcabcbb 
// Sample Output1:
//  3
// Explanation For Sample Input 1:
// Substring "abc" has no repeating character with the length of 3.
// Sample Input 2:
//  aaaa
// Sample Output 2:
// 1

#include<iostream>
#include<climits>
#include<unordered_map>
using namespace std;

int main(){
    string str;
    cin>>str;

    int n = str.length(),i=0,maxlen=INT_MIN;
    unordered_map<char,int> map;
    for(int j=0;j<n;j++){
        if(map.find(str[j])!=map.end() && map[str[j]]>= i)
            i = str[j]+1;
        map[str[j]] = j;
        maxlen = max(maxlen,j-i+1);
    }
    cout<<maxlen;
    return 0;
}

