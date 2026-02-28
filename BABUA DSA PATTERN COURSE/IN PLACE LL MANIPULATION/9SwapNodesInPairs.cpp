//  Adobe   Apple   Amazon   Facebook   Microsoft   Bloomberg  

// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

// Example 1:

// Input: head = [1,2,3,4]

// Output: [2,1,4,3]

// Explanation:



// Example 2:

// Input: head = []

// Output: []

// Example 3:

// Input: head = [1]

// Output: [1]

// Example 4:

// Input: head = [1,2,3]

// Output: [2,1,3]



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

ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* curr = head;
    ListNode* prev = dummy;

    while(curr && curr->next){
        ListNode* curr1 = curr->next;
        prev->next = curr1;
        curr->next = curr1->next;
        curr1->next =  curr;

        prev = curr;
        curr = curr->next;
    }
    return dummy->next;
}

ListNode* swapPairs2(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* temp = head->next;
    head->next = swapPairs(head->next->next);
    temp->next = head;
    return temp;
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

    ListNode * head = buildList(nums);
    head = swapPairs2(head);

    printList(head);
    return 0;
}