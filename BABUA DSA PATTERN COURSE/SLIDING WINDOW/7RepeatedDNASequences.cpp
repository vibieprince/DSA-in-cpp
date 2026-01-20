//  Amazon   LinkedIn  
// The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

// For example, "ACGAATTCCG" is a DNA sequence.
// When studying DNA, it is useful to identify repeated sequences within the DNA.

// Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

 

// Example 1:

// Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
// Output: ["AAAAACCCCC","CCCCCAAAAA"]
// Example 2:

// Input: s = "AAAAAAAAAAAAA"
// Output: ["AAAAAAAAAA"]

#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    if(s.length()<10) return {};
    // Approach 1
    unordered_set<string> seen;
    unordered_set<string> result;

    for(int i=0;i<=s.length()-10;i++){
        string dna = s.substr(i,10);
        if(seen.count(dna))
            result.insert(dna);
        seen.insert(dna);
    }

    return vector<string> (result.begin(),result.end());
}

vector<string> findRepeatedDnaSequences(string s) {
    // Approach 2 : Rabin karp string matching
    int k=10,n=s.length();
    if(n<10) return {};

    unordered_set<long long> seen;
    unordered_set<string> result;

    unordered_map<char,int> map = {{'A',0},{'C',1},{'G',2},{'T',3}};

    long long rep=0;
    long long base=1;

    for(int i=0;i<k-1;i++)
        base *= 4;
    
    for(int i=0;i<k;i++)
        rep = rep*4 + map[s[i]];

    seen.insert(rep);

    for(int i=k;i<n;i++){
        rep = rep - map[s[i-k]] * base;
        rep = rep * 4;
        rep = rep + map[s[i]];

        if(seen.count(rep))
            result.insert(s.substr(i-k+1,k));
            
        seen.insert(rep);
    }
    return vector<string> (result.begin(),result.end());
}