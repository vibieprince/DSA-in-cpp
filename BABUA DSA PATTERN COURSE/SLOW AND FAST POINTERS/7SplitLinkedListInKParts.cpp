//  Uber   Apple   Amazon   Oracle 

// Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

// The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

// The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

// Return an array of the k parts.

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

vector<ListNode*> splitListToParts(ListNode* head, int k) {
    // Firstly Get the length of your linked list
    ListNode* curr = head;
    int L = 0;
    while(curr){
        curr = curr->next;
        L++;
    }

    int remainingNodes = L%k;

    vector<ListNode*> result(k,NULL);

    curr = head;
    ListNode* prev = nullptr;

    for(int i=0;i<k;i++){
        result[i] = curr;
        for(int count = 1;count<=L/k + (remainingNodes > 0 ? 1 : 0);count++){
            prev = curr;
            curr = curr->next;
        }
        if(prev) prev->next = NULL;
        remainingNodes--;
    }
    return result;
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
    if(!head){
        cout<<"[]";
        return;
    }

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
    int k = nums.back();
    nums.pop_back();

    ListNode* head = buildList(nums);

    vector<ListNode*> result = splitListToParts(head,k);

    cout<<"[";
    for(int i=0;i<k;i++)
        printList(result[i]);
    cout<<"]";
    return 0; 
}