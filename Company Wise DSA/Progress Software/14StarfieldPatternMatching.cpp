// Problem Statement An astronomical cataloguing system classifies star names using a two-symbol pattern language. Each pattern may contain:

// Lowercase letters (a–z): match exactly one identical character in the star name. . (dot): matches exactly one character of any kind. * (star): a qualifier that must follow a letter or .. It means the preceding element can appear zero or more times. Given a star name observation and a pattern blueprint, determine whether the pattern matches the entire observation string from start to finish. Partial matches do not count.

// Input Format observation blueprint First line: string observation (lowercase letters only, may be empty) Second line: string blueprint (lowercase letters, ., and *; * always follows a letter or .) Output Format true if blueprint matches all of observation, false otherwise.

// Example 1 Input:

// aa a Output: false Explanation: Pattern a matches exactly one a. The observation aa has two characters, so the pattern does not cover the whole string.

// Example 2 Input aa a* Output true Example 3 Input ab .* Output true Example 4 Input aab c*a*b Output true Example 5 Input mississippi mis*is*p*. Output false

// Example 6 Input abc abc Output true

#include<iostream>
using namespace std;

class Solution {
    bool solve(string &s,int i,string &p,int j){
        if(j==p.length())
            return i==s.length();
        
        bool  firstMatch = false;
        if(i<s.length() && (s[i]==p[j] || p[j]=='.'))
            firstMatch = true;
        
        if(j+1<p.length() && p[j+1]=='*'){
            bool notTake = solve(s,i,p,j+2);
            bool take = firstMatch && solve(s,i+1,p,j);
            return take || notTake;
        }
        return firstMatch && solve(s,i+1,p,j+1);
    }
public:
    bool isMatch(string s, string p) {
        return solve(s,0,p,0);
    }
};

int main(){
    Solution obj;
    cout<<(obj.isMatch("aab","c*a*b")? "true" : "false");
    return 0;
}