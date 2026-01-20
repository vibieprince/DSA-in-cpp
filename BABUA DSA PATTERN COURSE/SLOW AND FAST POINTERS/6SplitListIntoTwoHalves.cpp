// Yahoo

// Given a Circular linked list. The task is split into two Circular Linked lists. If there are an odd number of nodes in the given circular linked list then out of the resulting two halved lists, the first list should have one node more than the second list.

// Examples :

// Input: LinkedList : 10->4->9
// Output: 10->4 , 9

// Explanation: After dividing linked list into 2 parts , the first part contains 10, 4 and second part contain only 9.


// The structure of linked list is the following
#include<iostream>
#include<vector>
using namespace std;

struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
};

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2

pair<Node *, Node *> splitList(struct Node *head) {
    // code here
    if(!head || head->next == head)
        return {head,NULL};
    
    Node* slow = head;
    Node* fast = head;
    
    while(fast->next != head && fast->next->next != head){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Node* head2 = slow->next;
    slow->next = head;
    
    Node* temp = head2;
    while(temp->next != head)
        temp = temp->next;
    temp->next = head2;
    
    return {head,head2};
}

Node* createCircularList(const vector<int>& arr) {
    if (arr.empty()) return NULL;

    Node* head = new Node(arr[0]);
    Node* curr = head;

    for (int i = 1; i < arr.size(); i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }

    curr->next = head; // Make it circular
    return head;
}

// Helper: Print circular list
void printCircular(Node* head) {
    if (!head) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    Node* head = createCircularList(arr);

    pair<Node*, Node*> result = splitList(head);

    cout << "First half: ";
    printCircular(result.first);

    cout << "Second half: ";
    printCircular(result.second);

    return 0;
}
