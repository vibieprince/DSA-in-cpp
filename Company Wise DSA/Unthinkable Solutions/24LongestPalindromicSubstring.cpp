#include <bits/stdc++.h>
using namespace std;
int expand(string &str,int left,int right){
    while(left>=0 && right<str.length() && str[left]==str[right]){
        left--;
        right++;
    }
    return right-left-1; // length 0f palindrome
}
string longestPalinSubstring(string str) {
    if(str.empty()) return "";
    int start=0,end=0;
    for(int i=0;i<str.size();i++){
        int len1 = expand(str,i,i);
        int len2 = expand(str,i,i+1);

        int len = max(len1,len2);
        if(len>end-start+1){
            start = i - (len - 1)/2;
            end = i + len /2;
        }
    }
    return str.substr(start,end-start+1);
}