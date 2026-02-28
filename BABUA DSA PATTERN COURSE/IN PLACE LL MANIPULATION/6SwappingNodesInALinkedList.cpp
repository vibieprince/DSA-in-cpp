//  Amazon   Facebook   Bloomberg  

// You are given the head of a linked list, and an integer k.

// Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [1,4,3,2,5]
// Example 2:

// Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
// Output: [7,9,6,6,8,7,3,0,9,5]

#include<iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


int getLength(ListNode* head){
    int len = 0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}

ListNode* swapNodes(ListNode* head, int k) {
    int len = getLength(head);
    ListNode* first = head;

    for(int i=1;i<k;i++)
        first = first->next;

    ListNode* second = head;
    for(int i=1;i<len-k+1;i++)
        second = second->next;
    
    int temp = second->val;
    second->val = first->val;
    first->val = temp;
    
    return head;
}

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
    int k = nums.back();
    nums.pop_back();

    ListNode * head = buildList(nums);
    head = swapNodes(head,k);

    printList(head);
    return 0;
}