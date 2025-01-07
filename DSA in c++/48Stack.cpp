#include <iostream>
#include<stack>
using namespace std;

class Stack{
public:
   // Parameters
   int top;
   int size;
   int *arr;

   // Constructor
   Stack(int size){
    this->size = size;
    arr = new int[size]; // Dynamic Memory allocation
    top = -1;
   }

   // Functions
   void push(int data){
    if(size-top>1){
        top++;
        arr[top] = data;
    }
    else
       cout<<"Stack Overflow"<<endl;
   }

   void pop(){
    if(top<0){
      cout<<"Stack Underflow"<<endl;
      return;
    }
    else
      top--;
   }

   int peek(){
    if(top<0)
       return -1;
    else
      return arr[top];
   }

   bool isEmpty(){
    if(top<0)
      return true;
    else
      return false;
   }

};
int main(){
    Stack st(5);
    st.push(56);
    st.push(20);
    st.push(21);
    st.push(29);
    st.push(24);
    st.push(586);
    st.push(384);

    cout<<st.peek()<<endl;

    if(st.isEmpty())
      cout<<"Stack is Empty";
    else
      cout<<"Stack is not Empty";
    /*
    // Creation
    stack<int> s;

    s.push(2);
    s.push(8); 
    s.pop();

    cout<<"Top of stack : "<<s.top()<<endl;
    if(s.empty())
      cout<<"Stack is Empty";
    else
      cout<<"Stack is not Empty"<<endl;
    cout<<"Size of stack is : "<<s.size()<<endl;
    */
    return 0;
}