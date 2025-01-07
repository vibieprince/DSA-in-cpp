#include<iostream>
using namespace std;
class Queue {
public:
  int *arr;
  int size;
  int qfront=-1;
  int rear=-1;

  Queue(){
    size = 100001;
    arr = new int[size]; 
    qfront = -1;
    rear = -1;
  }

  bool isEmpty(){
    if(qfront==-1)
      return true;
    else
      return false;
  }

  void enqueue(int data){
    if(rear==size-1)
      return;
    else{
      if(qfront==-1)
        qfront=0;
      rear++;
      arr[rear] = data;
    }
  }

  int dequeue(){
    if(isEmpty())
      return -1;
    else{
      int val = arr[qfront];
      arr[qfront] = -1;
      qfront++;
      if(qfront>rear)
        qfront=rear=-1;
      return val;
    }
  }

  int front(){
      if(isEmpty())
        return -1;
      else 
        return arr[qfront];
  }
};
int main(){
  Queue q;
  // q.enqueue(56);
  q.enqueue(26);
  q.enqueue(67);
  q.enqueue(12);
  cout<<q.dequeue()<<endl;
  cout<<q.front()<<endl;
    /*
    // Creation
    queue<int> q;
    q.push(45);
    q.push(29);
    q.push(3);
    q.push(21);

    cout<<"Size of queue is "<<q.size()<<endl;
    q.pop();
    cout<<"Size of queue is "<<q.size()<<endl;
    if(q.empty())
      cout<<"Queue is empty"<<endl;
    else
      cout<<"Queue is not empty"<<endl;
    q.pop();
    cout<<"Front of Queue is "<<q.front()<<endl;
    q.pop();
    q.pop();
    if(q.empty())
      cout<<"Queue is empty"<<endl;
    else
      cout<<"Queue is not empty"<<endl;
    */

    return 0;
}