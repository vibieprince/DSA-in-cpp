#include<iostream>
using namespace std;
class CircularQueue{
    public:
    // Initialize your data structure.
    int *arr;
    int size;
    int front;
    int rear;
    CircularQueue(int n){
        // Write your code here.
        this->size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }
    bool isFull(){
        if((front==0 && rear == size-1)||(rear==(front-1)%size))
          return true;
        else
          return false;
    }
    bool isEmpty(){
        if(front==-1)
          return true;
        else
          return false;
    }
    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if(isFull())
           return false;
        else if(front==-1){
            front = rear = 0;
            arr[rear] = value;
        }
        else if(rear==size-1 && front !=0)
          rear = 0;
        else
          rear++;
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(front==-1)
          return -1;
        int ans = arr[front];
        if(front==rear) //Single element exist
           front = rear = -1;
        else if(front==size-1) //To maintain cyclic nature 
          front=0;
        else
           front++;
        return ans;
    }
};