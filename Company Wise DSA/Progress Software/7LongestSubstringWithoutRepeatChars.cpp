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
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int maxlen = 0;
        unordered_map<int,int> map;
        for(int j=0;j<s.length();j++){
            while(map.find(s[j])!=map.end()){
                // i++; wrong -- not here
                map[s[i]]--;
                if(map[s[i]]==0)
                    map.erase(s[i]);
                i++; // increment after delete
            }
            map[s[j]]++;
            maxlen = max(maxlen,j-i+1);
        }
        return maxlen;
    }
};

int main(){
    Solution obj;
    string s = "abcabcbb";
    cout<<obj.lengthOfLongestSubstring(s);
    return 0;
}