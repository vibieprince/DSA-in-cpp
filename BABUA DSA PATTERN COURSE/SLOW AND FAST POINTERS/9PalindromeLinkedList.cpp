//  Apple   Adobe   Yahoo   Amazon   Google   VMware   Intuit   Facebook   Microsoft   Bloomberg   ServiceNow  

// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

// Example 1:


// Input: head = [1,2,2,1]
// Output: true
// Example 2:


// Input: head = [1,2]
// Output: false

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

ListNode* reverseList(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* fwd = nullptr;

    while(curr){
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }

    return prev;
}

bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    fast = reverseList(slow);

    while(fast && head){
        if(fast->val != head->val)
            return false;
        head = head->next;
        fast = fast->next;
    }
    return true;
}

ListNode* buildList(vector<int> &nums){
    if(nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;

    for(int i=1;i<nums.size();i++){
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
    cout<<"]"<<endl;
}

int main(){
    int n;
    vector<int> nums;
    while(cin>>n){
        nums.push_back(n);
        if(cin.peek()=='\n') break;
    }

    ListNode* head = buildList(nums);

    printList(head);
    cout<<(isPalindrome(head) ? "Palindrome" : "Not a Palindrome");
}