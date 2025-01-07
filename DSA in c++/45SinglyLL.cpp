#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;

    Node(int data){ // Constructor to create newNode
        this->data = data;
        this->next = NULL;
    }

    ~Node(){ // Destructor to delete a node
        int val = this->data; // data copied

        // memory freed
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory freed up for data "<<val<<endl;
    }
};
void insertAtBegin(Node* &head,int newData){
    // Create new node i.e allocate memory
    Node* newNode = new Node(newData);
    newNode->next = head;
    head = newNode; // head reflected backward to initial node
}
void printNode(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
void insertAtEnd(Node *&tail,int newData){
    Node *newNode = new Node(newData);
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}
void insertAtpos(Node* &tail,Node* &head,int pos,int data){
    // Insert at starting position
    if(pos==1){
      insertAtBegin(head,data);
      return;
    }

    Node *temp = head;
    int count = 1;
    while(count<pos-1){
        temp = temp->next;
        count++;
    }

    // Insert at ending position
    if(temp->next == NULL){
        insertAtEnd(tail,data);
        return;
    }
      
    // create a node for new data 
    Node * newNode = new Node(data);
    newNode->next = temp->next; // todo modo jodo
    temp->next = newNode;
}
void deleteNode(Node* &head,Node* &tail,int pos){
    // there's other way to delete first node
    if(pos==1){
        Node *temp = head;
        head = head->next;

        // free memory
        temp->next = NULL;
        delete temp;
    }
    else{
        Node *current = head;
        Node *previous = NULL;

        int count = 1;
        while(count < pos){
            previous = current;
            current = current->next;
            count++;
        }
        previous->next = current->next;
        current->next = NULL;
        delete current;
        if(previous->next==NULL)
          tail = previous;
    }
}
int main(){
    // Grow Shirnk at rutime 
    // No memory wastage
    // Insertion deletion easy
    // Dynamic data structure
    // No continuous storage needed
    // Singly LL ---> {data,next} -->NULL
    // Doubly LL ---> {prev,data,next} --->NULL
    // Circular LL ---> {Lastdata,next} ---> {Firstdata,next}
    // Circular Doubly LL ---> {prev,LastData,next} ---> {prev,Firstdata,next}

    // Created first node
    Node *node1 = new Node(10); // ---> 10 is the data of new node1 because of Node constructor
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;

    // head pointing to node1
    Node* head = node1;
    Node* tail = node1; // only for hamare fayde
    printNode(head);

    insertAtBegin(head,12);

    printNode(head);

    insertAtEnd(tail,19);
    insertAtEnd(tail,99);

    printNode(head);
    insertAtpos(tail,head,5,89);

    printNode(head);

    cout<<"Head --> "<<head->data<<endl;
    cout<<"Tail --> "<<tail->data<<endl;

    deleteNode(head,tail,1);

    printNode(head);
    cout<<"Head --> "<<head->data<<endl;
    cout<<"Tail --> "<<tail->data<<endl;
    return 0;
}