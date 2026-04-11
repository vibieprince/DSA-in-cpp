#include<iostream>
#include<vector>
using namespace std;
bool isVowel(char ch){
    if(ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U')
        return true;
    return false;
}

string reverseString(string s){
    int i=0,j=s.length()-1;
    while(i<j)
        swap(s[i++],s[j--]);
    return s;
}

vector<string> reverseVowels(vector<string> s){
    vector<string> result;

    for(string &str : s){
        int len = str.length();
        if(isVowel(str[0]) && isVowel(str[len-1])){
            string newS = str.substr(1,len-2);
            string ans = string(1, str[0]) + reverseString(newS) + string(1, str[len-1]);
            result.push_back(ans);
        }
        else
            result.push_back(str);
    }
    return result;
}