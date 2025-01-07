#include <iostream>
using namespace std;
class Node{
public:
   int data;
   Node* next;
   Node* prev;

   // constructor
   Node(int data){
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
   }
   ~Node(){
    int val = this->data;
    if(next!=NULL){
        delete next;
        next = NULL;
    }
    cout<<"Memory free for node with data "<<val<<endl;
   }
};
void printNode(Node * head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int getLength(Node *head){
    int len = 0;
    Node *temp = head;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}
void insertAtHead(Node* &head,Node* &tail,int data){
    // If list is empty
    if(head==NULL){
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node *newNode = new Node(data); // Step 1
        newNode->next = head; // Step 2
        head->prev = newNode; // Step 3
        // newNode->prev = NULL; // No need of this statement, it's by default NULL because of our constructor
        head = newNode;
    }
}
void insertAtTail(Node* &head,Node* &tail,int data){
    if(tail==NULL){
        Node *temp =  new Node(data);
        tail = temp;
        head = temp;
    }
    else{
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        // newNode->next = NULL; // No need of this statement, it's by default NULL because of our constructor
        tail = newNode;  
    }
}
void insertAtPos(Node* &head,Node* &tail,int data,int pos){
    if(pos==1){
        insertAtHead(head,tail,data);
        return;
    }

    Node *temp = head;
    int i = 1;

    while(i<pos-1){
        temp = temp->next;
        i++;
    }
    if(temp->next==NULL)
       insertAtTail(head,tail,data);
    else{
       Node *newNode = new Node(data); // Step 1
       newNode->next = temp->next; // Step 2
       newNode->prev = temp; // Step 3
       temp->next->prev = newNode; // Step 4
       temp->next = newNode; // Step 5 
    }   
}
void deleteAtHead(Node* &head,Node* &tail){
    if(head==NULL){
       printf("No more Node exist");
       return;
    }
    Node* temp = head;
    temp->next->prev = NULL;
    head = temp->next;
    temp->next = NULL;
    delete temp;
}
void deleteAtTail(Node* &head,Node* &tail){
    Node* temp = tail;
    tail = tail->prev;
    temp->prev = NULL;
    tail->next = NULL;
    delete temp;
}
void deleteAtPos(Node* &head,Node* &tail,int pos){
    if(pos==1)
        return deleteAtHead(head,tail);
    Node* temp = head;
    Node* prev = NULL;

    int count = 1;

    while(count<pos){
        prev = temp;
        temp = temp->next;
        count++;
    }
    if(temp->next==NULL)
      return deleteAtTail(head,tail);
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->next = temp->prev = NULL;
    delete temp;
}
int main(){
    Node *head = NULL;
    Node *tail = NULL;
    printNode(head);
    cout<<getLength(head)<<endl;
    insertAtHead(head,tail,67);
    // insertAtTail(head,tail,89);
    // insertAtPos(head,tail,832,4);
    // insertAtPos(head,tail,832,1);
    // insertAtPos(head,tail,832,3);
    // insertAtTail(head,tail,48);
    printNode(head);
    deleteAtTail(head,tail);
    // deleteAtPos(head,tail,4);
    printNode(head);
    return 0;
}