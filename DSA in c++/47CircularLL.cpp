#include <iostream>
using namespace std;

class Node{
public:
  int data;
  Node* next;

  Node(int data){ // Constructor
    this->data = data;
    this->next = NULL;
  }

  ~Node(){ // Desctructor
    int val = this->data;
    if(this->next!=NULL){
        delete next;
        next = NULL;
    }
    cout<<"Memory freed for the Node with data : "<<val<<endl;
  }
};
void deleteNode(Node* &tail,int val){
    if(tail==NULL){ // Empty list
        cout<<"List is empty"<<endl;
        return;
    }
    Node* prev = tail;
    Node* temp = prev->next;
    while(temp->data!=val){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;

    // Single Node Linked List
    if(temp==prev)
      tail = NULL;

    // >= 2 Node Lined List
    else if(tail==temp) // More than 2 node
      tail = prev; // kisi se bhi point karwado farq nhi padta circular linked list hai
    temp->next = NULL;
    delete temp;
}
void insertNode(Node* &tail,int element,int data){
    if(tail==NULL){ //Empty list
        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else{ // Non-empty list
        Node *temp = tail;
        while(temp->data!=element)
            temp = temp->next;
        
        // Element found --> temp is representing element wala Node
        Node *newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void printList(Node* &tail){
    Node *temp = tail;
    if(tail==NULL){
        cout<<"List is Empty";
        return;
    }
    do{
        cout<<temp->data<<"-->";
        temp = temp->next;
    }while(temp!=tail);
}
int main(){
    Node* tail = NULL;
    insertNode(tail,5,3);
    insertNode(tail,3,7);
    insertNode(tail,7,35);
    cout<<tail->data<<endl;
    insertNode(tail,3,63);
    deleteNode(tail,3);
    insertNode(tail,63,10);
    printList(tail);
    return 0;
}