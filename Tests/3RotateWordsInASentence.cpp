// You are given a sentence containing words separated by single spaces and an integer K.
// Your task is to rotate the words of the sentence to the left by K positions.
// If K is greater than the number of words, rotate efficiently.
// 🔁 What Does Rotation Mean?
// Example:
// Input sentence: "hello i am prince"
// K = 2

// Words are:
// [hello] [i] [am] [prince]
// After 1 left rotation:
// i am prince hello
// After 2 left rotations:
// am prince hello i

// So output is:
// "am prince hello i"
// 📥 Input Format
// First line: A string S

// Second line: Integer K
// 📤 Output Format
// Print the rotated sentence.
// 📌 Constraints
// 1 ≤ number of words ≤ 10^5
// 0 ≤ K ≤ 10^18
// Words contain only lowercase letters

#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

int main(){
    string str;
    getline(cin,str);

    int k;
    cin>>k;

    stringstream ss(str);
    vector<string> words;
    string word;

    while(ss>>word)
        words.push_back(word);
    
    int n = words.size();

    if(n==0)
        return 0;
    
    k = k % n;

    for(int i=k;i<n;i++)
        cout<<words[i]<<" ";
    
    for(int i=0;i<k;i++)
        cout<<words[i]<<" ";

}