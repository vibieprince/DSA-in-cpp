// 20 : Valid Parentheses

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"

// Output: true

// Example 2:

// Input: s = "()[]{}"

// Output: true

// Example 3:

// Input: s = "(]"

// Output: false

// Example 4:

// Input: s = "([])"

// Output: true

// Example 5:

// Input: s = "([)]"

// Output: false

 

// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.
#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char ch : s){
            if(ch=='[' || ch=='{' || ch=='(')
                stk.push(ch);
            else if(!stk.empty()){
                int top = stk.top();
                if(ch==']' && top == '[' || ch=='}' && top =='{' || ch==')' && top=='(')
                    stk.pop();
                else return false;
            }
            else return false;
        }
        if(!stk.empty()) return false;
        return true;
    }
};

int main(){
    Solution obj;
    cout<<obj.isValid("[]{}")?"yes":"No";
    return 0;
}

