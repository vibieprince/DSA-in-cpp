// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:

// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    for(string &s : tokens){
        if(s=="+"){
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            stk.push(b+a);
        }
        else if(s=="-"){
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            stk.push(b-a);
        }
        else if(s=="*"){
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            stk.push(b*a);
        }
        else if(s=="/"){
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            stk.push(b/a);
        }
        else stk.push(stoi(s));
    }
    return stk.top();
}

int main(){
    vector<string> tokens;
    string s;
    while(cin>>s)
        tokens.push_back(s);

    int ans = evalRPN(tokens);
    cout<<ans;
}