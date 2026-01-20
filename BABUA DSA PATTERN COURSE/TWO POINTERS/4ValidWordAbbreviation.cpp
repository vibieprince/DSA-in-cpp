// Neetcode io question 

// A string can be shortened by replacing any number of non-adjacent, non-empty substrings with their lengths (without leading zeros).

// For example, the string "implementation" can be abbreviated in several ways, such as:

// "i12n" -> ("i mplementatio n")
// "imp4n5n" -> ("imp leme n tatio n")
// "14" -> ("implementation")
// "implemetation" -> (no substrings replaced)
// Invalid abbreviations include:

// "i57n" -> (i mplem entatio n, adjacent substrings are replaced.)
// "i012n" -> (has leading zeros)
// "i0mplementation" (replaces an empty substring)
// You are given a string named word and an abbreviation named abbr, return true if abbr correctly abbreviates word, otherwise return false.
// A substring is a contiguous non-empty sequence of characters within a string.

// Example 1:
// Input: word = "apple", abbr = "a3e"
// Output: true

// Example 2:
// Input: word = "international", abbr = "i9l"
// Output: false

// Example 3:
// Input: word = "abbreviation", abbr = "abbreviation"
// Output: true

#include<iostream>
using namespace std;
bool validWordAbbreviation(string word, string abbr) {
    int i=0,j=0;
    while(i<word.length() && j<abbr.length()){
        if(!isdigit(abbr[j])){
            if(word[i]!=abbr[j]) return false;
            i++;
            j++;
        }
        else{
            if(abbr[j]=='0') return false;
            int num = 0;
            while(j< abbr.length() && isdigit(abbr[j])){
                num = num * 10 + (abbr[j]-'0');
                j++;
            }
            i = i + num;
        }
    }
    return i == word.length() && j==abbr.length();
}

int main(){
    string word;
    string abbr;
    cin>>word>>abbr;
    cout<<(validWordAbbreviation(word,abbr) ? "true" : "false");
    return 0;
}