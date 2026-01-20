// You are given two strings s and sub. You are also given a 2D character array mappings where mappings[i] = [oldi, newi] indicates that you may perform the following operation any number of times:

// Replace a character oldi of sub with newi.
// Each character in sub cannot be replaced more than once.

// Return true if it is possible to make sub a substring of s by replacing zero or more characters according to mappings. Otherwise, return false.

// A substring is a contiguous non-empty sequence of characters within a string.

 

// Example 1:

// Input: s = "fool3e7bar", sub = "leet", mappings = [["e","3"],["t","7"],["t","8"]]
// Output: true
// Explanation: Replace the first 'e' in sub with '3' and 't' in sub with '7'.
// Now sub = "l3e7" is a substring of s, so we return true.
// Example 2:

// Input: s = "fooleetbar", sub = "f00l", mappings = [["o","0"]]
// Output: false
// Explanation: The string "f00l" is not a substring of s and no replacements can be made.
// Note that we cannot replace '0' with 'o'.
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;

bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
    int n = s.length();
    int m = sub.length();

    unordered_map<char,unordered_set<char>> map;

    for(int i=0;i<mappings.size();i++)
        map[mappings[i][0]].insert(mappings[i][1]);

    for(int i=0;i<=n-m;i++){
        bool found = true;

        for(int j=i,k=0;k<m ;j++,k++){
            if(s[j]==sub[k]) continue;
            if(map.count(sub[k])==0|| map[sub[k]].count(s[j])==0){
                found = false;
                break;
            }
        }
        if(found) return true;
    }   
    return false;
}

int main(){
    string s = "fool3e7bar";
    string sub = "leet";

    vector<vector<char>> mappings = {
        {'e', '3'},
        {'t', '7'},
        {'t', '8'}
    };

    bool ans = matchReplacement(s, sub, mappings);

    cout << (ans ? "true" : "false") << endl;

    return 0;
}