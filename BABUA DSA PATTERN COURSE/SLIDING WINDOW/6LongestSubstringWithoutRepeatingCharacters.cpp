//  Uber   Zoho   Apple   Adobe   Yahoo   Amazon   Google   VMware   Oracle   Paypal   Intuit   Yandex   Spotify   Samsung   Facebook   JPMorgan   Microsoft   Bloomberg   Salesforce   Goldman Sachs   Walmart Global Tech  

// Given a string s, find the length of the longest substring without duplicate characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;

// Approach 1
int lengthOfLongestSubstring(string s) {
    int i=0,j=0,n=s.length();
    int maxLen = 0;
    unordered_set<char> set;
    for(int j=0;j<n;j++){
        while(set.count(s[j])){
            
            set.erase(s[i]);
            i++;
        }
        set.insert(s[j]);
        maxLen = max(maxLen,j-i+1);
    }
    return maxLen;
}

// Approach 2
int lengthOfLongestSubstring(string s) {
    int i = 0;
    int maxLength = 0;
    unordered_map<char,int> map;
    for(int j=0;j<s.length();j++){
        char c = s[j];
        if(map.count(c) && map[c]>=i)
            i = map[c] + 1;
        map[c] = j;
        maxLength = max(maxLength,j-i+1);
    }
    return maxLength;
}

int main(){
    string s;
    cin>>s;

    cout<<lengthOfLongestSubstring(s);
    return 0;
}