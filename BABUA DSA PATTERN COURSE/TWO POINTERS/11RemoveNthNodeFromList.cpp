//  Uber   Apple   Amazon   Google   Facebook   Microsoft   Bloomberg   Walmart Global Tech  

// Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

// Example 1:


// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* temp = head;
    
    for(int i=0; i<n; i++)
        temp = temp->next;

    while(temp){
        prev = prev->next;
        temp = temp->next;
    }

    ListNode* nodeToDelete = prev->next;
    prev->next = prev->next->next;
    delete nodeToDelete;

    return dummy->next;
}

// Helper: Create linked list from vector
ListNode* buildList(const vector<int>& nums) {
    if(nums.empty()) return nullptr;

    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;

    for(int i = 1; i < nums.size(); i++) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}

// Helper: Print linked list
void printList(ListNode* head) {
    cout << "[";
    while(head) {
        cout << head->val;
        if(head->next) cout << ",";
        head = head->next;
    }
    cout << "]";
}

int main() {
    vector<int> nums;
    int x;

    // Read list values until EOF or newline
    while(cin >> x) {
        nums.push_back(x);
        if(cin.peek() == '\n') break;
    }

    int n;
    cin >> n;

    ListNode* head = buildList(nums);
    head = removeNthFromEnd(head, n);
    printList(head);

    return 0;
}
