// Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

// Implement the MyQueue class:

// void push(int x) Pushes element x to the back of the queue.
// int pop() Removes the element from the front of the queue and returns it.
// int peek() Returns the element at the front of the queue.
// boolean empty() Returns true if the queue is empty, false otherwise.
// Notes:

// You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
// Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

// Input
// ["MyQueue", "push", "push", "peek", "pop", "empty"]
// [[], [1], [2], [], [], []]
// Output
// [null, null, null, 1, 1, false]

// Explanation
// MyQueue myQueue = new MyQueue();
// myQueue.push(1); // queue is: [1]
// myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
// myQueue.peek(); // return 1
// myQueue.pop(); // return 1, queue is [2]
// myQueue.empty(); // return false

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class MyQueue {
public:
    stack<int> s;
    MyQueue() {
        
    }
    void push(int x) {
        s.push(x);
    }
    int pop() {
        if(s.empty())
            return -1;
        if(s.size()==1){
            int top = s.top();
            s.pop();
            return top;
        }
        int top = s.top();
        s.pop();
        int front = pop();
        s.push(top);
        return front;
    }
    
    int peek() {
        if(s.empty())
            return -1;
        if(s.size()==1)
            return s.top();
        int top = s.top();
        s.pop();
        int front = peek();
        s.push(top);
        return front;   
    }
    
    bool empty() {
        if(s.size()==0)
            return true;
        else
           return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(){
    int n;
    cin >> n;
    
    MyQueue* myQueue = nullptr;
    vector<string> result;
    
    for(int i = 0; i < n; i++){
        string operation;
        // cout << "Enter operation " << (i+1) << " (MyQueue/push/pop/peek/empty): ";
        cin >> operation;
        
        if(operation == "MyQueue"){
            myQueue = new MyQueue();
            result.push_back("null");
        }
        else if(operation == "push"){
            int x;
            cout << "Enter value to push: ";
            cin >> x;
            myQueue->push(x);
            result.push_back("null");
        }
        else if(operation == "pop"){
            int popVal = myQueue->pop();
            result.push_back(to_string(popVal));
        }
        else if(operation == "peek"){
            int peekVal = myQueue->peek();
            result.push_back(to_string(peekVal));
        }
        else if(operation == "empty"){
            bool isEmpty = myQueue->empty();
            result.push_back(isEmpty ? "true" : "false");
        }
    }
    
    // Print output
    cout << "\nOutput: [";
    for(int i = 0; i < result.size(); i++){
        cout << result[i];
        if(i < result.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
    
    if(myQueue != nullptr)
        delete myQueue;
    
    return 0;
}