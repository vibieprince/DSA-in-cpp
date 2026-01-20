//  Visa   Apple   Amazon   Google   LinkedIn   Microsoft  

// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

// Using two pointer O(n) O(n)
string reverseString(string s){
    int i=0,j=s.length()-1;
    while(i<j)
        swap(s[i++],s[j--]);
    return s;
}
string reverseWords(string s) {
    s = reverseString(s);
    string ans = "";
    int i = 0;
    while(i<s.length()){
        if(s[i]==' '){
            i++;
            continue;
        }
        string temp = "";
        while(i<s.length() && s[i] != ' ')
            temp += s[i++];
        if(!ans.empty()) ans += " ";
        ans += reverseString(temp);
    }
    return ans;
}

// Using Stringstream O(n) O(n)
string reverseWords(string s) {
    string word,ans = "";
    stringstream ss(s); // Gives me the next word separated by whitespace
    vector<string> words;

    while(ss>>word)
        words.push_back(word);
    
    for(int i=words.size()-1;i>=0;i--){
        ans += words[i];
        if(i!=0)
            ans += " ";
    }

    return ans;
}

// Two pointer appraoch but in-place O(1) O(n)
string reverseWords(string s) {
    reverse(begin(s),end(s));
    int j,idx = 0,n=s.length();
    for(int i=0;i<n;){
        if(s[i]==' '){
            i++;
            continue;
        }
        if (idx!=0) s[idx++] = ' ';
        j = i;
        while(j<n && s[j] != ' ')
            s[idx++] = s[j++];
        
        reverse(s.begin()+idx - (j-i),s.begin() + idx);
        i = j; // let's so the next iteration with the next word
    } 
    s.resize(idx); // resizes the original string to the last pointed end of string
    return s;
}

int main(){
    string s;
    getline(cin,s);
    s = reverseWords(s);
    cout<<s;
}