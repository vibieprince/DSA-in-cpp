//  Zoho   Payu   Uber   eBay   Bolt   Bolt   Adobe   Cisco   Apple   PayTM   Google   PayPal   Zappos   Amazon   Yandex   Samsung   Accolite   SAP Labs   Flipkart   Farmeasy   Snapchat   Facebook   Bloomberg   Microsoft   MakeMyTrip   Codenation   MAQ Software   HCL Software   Goldman Sachs  

// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

// Example 1:

// Input: s = "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
// Example 2:

// Input: s = "Mr Ding"
// Output: "rM gniD"

#include<iostream>
#include<algorithm>
using namespace std;

string reverseWords(string s) {
    int j,i=0,n=s.length();
    while(i<n){
        j = i;
        while(j<n && s[j] != ' ')
            j++;
        reverse(s.begin()+i,s.begin()+j);
        i = j + 1;
    }
    return s;
}

int main(){
    string s;
    getline(cin,s);
    s = reverseWords(s);
    cout<<s;
}