// Adobe   Amazon   Facebook   Microsoft 
// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

// Example 1:


// Input: head = [1,2,6,3,4,5,6], val = 6
// Output: [1,2,3,4,5]
// Example 2:

// Input: head = [], val = 1
// Output: []
// Example 3:

// Input: head = [7,7,7,7], val = 7
// Output: []


// Definition for singly-linked list.
#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* buildList(vector<int> &nums){
    if(nums.empty()) return nullptr;
    ListNode * head = new ListNode(nums[0]);
    ListNode* curr = head;
    for(int i=1;i<nums.size();i++){
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}

ListNode* removeElements(ListNode* head, int val) {
    while(head && head->val == val){
        ListNode* del = head;
        head = head->next;
        delete del;
    }

    ListNode* temp = head;
    ListNode* prev = NULL;

    while(temp){
        if(temp->val==val){
            ListNode* del  = temp;
            prev->next = temp->next;
            temp = temp->next;
            delete del;
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

void printList(ListNode* head){
    if(!head) return;
    while(head){
        cout<<head->val<<"->";
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
    int val = nums.back();
    nums.pop_back();

    ListNode * head = buildList(nums);
    head = removeElements(head,val);
    printList(head);
    return 0;
}