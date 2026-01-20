//  tcs   Adobe   Apple   Intel   Amazon   Facebook   Microsoft  

// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

 

// Example 1:

// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]
#include<vector>
#include<iostream>
using namespace std;

void reverseString(vector<char>& s) {
    int i=0,j=s.size()-1;
    while(i<j)
        swap(s[i++],s[j--]);
}

int main(){
    char c;
    vector<char> s;
    while(cin>>c)
        s.push_back(c);
    
    reverseString(s);
    
    cout<<"[";
    for(int i=0;i<s.size();i++){
        cout<<"\""<<s[i]<<"\"";
        if(i < s.size()-1)
            cout<<",";
    }
    cout<<"]";
}