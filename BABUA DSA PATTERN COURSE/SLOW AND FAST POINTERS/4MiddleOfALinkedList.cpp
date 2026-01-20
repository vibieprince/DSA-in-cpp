//  Adobe   Apple   Amazon   Google   Facebook   Qualcomm   Microsoft  

// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

 

// Example 1:


// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.
// Example 2:


// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.


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

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* buildList(vector<int>&nums){
    int n = nums.size();
    if(n<1) return nullptr;

    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;

    for(int i=1;i<n;i++){
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }

    return head;
}

void printList(ListNode* head){
    if(!head) return;
    cout<<"[";
    while(head){
        cout<<head->val;
        if(head->next) cout<<"->";
        head = head->next;
    }
    cout<<"]";
}

int main(){
    int n;
    vector<int> nums;
    while(cin>>n){
        nums.push_back(n);
        if(cin.peek()=='\n') break;
    }
    ListNode* head = buildList(nums);
    cout<<middleNode(head)->val<<endl;
    return 0;
}