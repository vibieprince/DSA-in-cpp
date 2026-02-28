// Amazon Microsoft

// Given a linked list, delete n nodes after skipping m nodes of a linked list until the last of the linked list.
// Examples:

// Input: Linked List: 9->1->3->5->9->4->10->1, n = 1, m = 2

// Output: 9->1->5->9->10->1

// Explanation: Deleting 1 node after skipping 2 nodes each time, we have list as 9-> 1-> 5-> 9-> 10-> 1.
// Input: Linked List: 1->2->3->4->5->6, n = 1, m = 6

// Output: 1->2->3->4->5->6

// Explanation: After skipping 6 nodes for the first time , we will reach of end of the linked list, so, we will get the given linked list itself.
// Expected Time Complexity: O(n)
// Expected Space Complexity: O(1)

// Constraints:
// 1 <= size of linked list <= 1000
// 0 < n, m <= size of linked list

#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* linkdelete(Node* head, int n, int m) {
    // code here
    Node* curr = head;
    
    while(curr){
        // skip m nodes
        for(int i=1;i<m && curr;i++)
            curr = curr->next;
        
        if(!curr) return head;
        
        // delete n nodes
        Node* temp = curr->next;
        for(int i =0;i<n && temp;i++){
            Node* t = temp;
            temp = temp->next;
            delete t;
        }
        
        curr->next = temp;
        curr = temp;
    }
    
    return head;
}

Node* buildList(vector<int> &nums){
    if(nums.empty()) return nullptr;
    Node * head = new Node(nums[0]);
    Node* curr = head;
    for(int i=1;i<nums.size();i++){
        curr->next = new Node(nums[i]);
        curr = curr->next;
    }
    return head;
}

void printList(Node* head){
    if(!head) return;
    while(head){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL";
}

int main(){
    int n;
    vector<int> nums;
    while(cin>>n){
        nums.push_back(n);
        if(cin.peek()=='\n') break;
    }
    int n = nums.back(),m;
    nums.pop_back();
    m = nums.back();
    nums.pop_back();
    
    Node * head = buildList(nums);
    head = linkdelete(head,n,m);
    printList(head);
    return 0;
}