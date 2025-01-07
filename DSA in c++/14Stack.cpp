#include<iostream>
#include<stack>
// Stack --> Last in first out [LIFO]
using namespace std;
int main(){
    stack<string> s;
    s.push("Prince");
    s.push("Singh");

    cout<<"Top element : "<<s.top()<<endl; // SIngh
    s.pop();
    cout<<"Top element : "<<s.top()<<endl; // Prince
    
    cout<<"Size of stack : "<<s.size()<<endl;

    cout<<"Empty or not : "<<s.empty()<<endl;
}