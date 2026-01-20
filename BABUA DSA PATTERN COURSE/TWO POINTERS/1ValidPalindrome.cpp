//  Apple   Adobe   Amazon   Yandex   Wayfair   Facebook   Microsoft   Bloomberg   American Express 


// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

 

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.


#include<iostream>
using namespace std;

bool isPalindrome(string s) {
    int i=0,j=s.length()-1;
    while(i<j){
        while(i<j && !isalnum(s[i]))
            i++;
        while(i<j && !isalnum(s[j]))
            j--;
        if(tolower(s[i])!=tolower(s[j])) return false;
        i++;
        j--;
    }       
    return true;
}

int main(){
    string s;
    getline(cin,s);
    cout<<(isPalindrome(s) ? "true" : "false")<<endl;
    return 0;
}