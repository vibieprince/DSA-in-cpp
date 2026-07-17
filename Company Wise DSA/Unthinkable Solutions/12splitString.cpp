// Problem statement
// You are given a string ‘str’ of even length. Your task is to find out if we divide the ‘str’ from the middle, will both the substrings contain an equal number of vowels or not.

// For Example:
// You are given, ‘str’= ‘codingninjas’, when we split this string we get, ‘coding’ and ‘ninjas’ which both contain 2 vowels each. Hence the answer is ‘True’.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <=  10
// 1 <= |str| <= 10^6

// ‘str’ will contain upper and lower case characters of the English alphabet.
// |str| is even.
// Time Limit: 1 sec.
// Note :
// You do not need to print anything. It has already been taken care of. Just implement the given function. 
// Sample Input 1:
// 2
// codingninjas
// helloworld
// Sample Output 2:
// True
// False
// Explanation:
// For the first test case, ‘str’= ‘codingninjas’, when we split this string we get, ‘coding’ and ‘ninjas’ which both contain 2 vowels each. Hence the answer is ‘True’.

// For the second test case, ‘str’= ‘helloworld’, when we split this string we get ‘hello and ‘world’, which contain 2 and 1 vowels respectively. Hence the answer is ‘False’.
// Sample Input 2:
// 2
// Aa
// AbbaaA
// Sample Output 2:
// True
// False

#include<iostream>
using namespace std;

bool splitString(string &str){
    // Write your code here.
    int vowelLeft = 0,vowelRight=0,i=0,j=str.length()-1;
    string vowels = "aeiouAEIOU";
    while(i<j){
        if(vowels.find(str[i])!=string::npos) vowelLeft++;
        if(vowels.find(str[j])!=string::npos) vowelRight++;
        i++;
        j--; 
    }
    return vowelLeft == vowelRight;
}