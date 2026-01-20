//  Amazon   Microsoft  

// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

// Do not modify the linked list.


// Definition for singly-linked list.
#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* buildList(const vector<int> &nums){
    if(nums.empty()) return nullptr;

    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;

    for(int i=1;i<nums.size();i++){
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }

    return head;
}

void createCycle(ListNode* head, int pos) {
    if(pos == -1) return; // no cycle

    ListNode* tail = head;
    ListNode* cycleNode = NULL;
    int idx = 0;

    while(tail->next) {
        if(idx == pos) cycleNode = tail;
        tail = tail->next;
        idx++;
    }

    if(idx == pos) cycleNode = tail;

    if(cycleNode)
        tail->next = cycleNode;
}

void printList(ListNode* head) {
    cout << "[";
    while(head) {
        cout << head->val;
        if(head->next) cout << ",";
        head = head->next;
    }
    cout << "]";
}

ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }

    if(!fast || !fast->next) return nullptr;
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int pos;
    cin >> pos;   // position where cycle should be created (-1 if no cycle)

    ListNode* head = buildList(arr);
    createCycle(head, pos);

    ListNode* result = detectCycle(head);

    if(result!=nullptr)
        cout<<result->val;
    else 
        cout<<"No Cycle";

    return 0;
}