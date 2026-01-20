// Amazon Adobe Qualcomm

// Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the number of nodes in the loop, otherwise return 0.

// Note: Internally, pos(1 based index) is used to denote the position of the node that tail's next pointer is connected to. If pos = 0, it means the last node points to null, indicating there is no loop. Note that pos is not passed as a parameter.

// Examples:

// Input: pos = 2,
   
// Output: 4
// Explanation: There exists a loop in the linked list and the length of the loop is 4.

#include<iostream>
#include<vector>
using namespace std;

class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow = head;
        Node* fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow==fast)
                break;
        }
        
        if(!fast || !fast->next) return 0;
        
        slow = head;
        
        
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        int length = 0;
        
        do{
            fast = fast->next;
            length++;
        }while(slow != fast);
        
        return length;
    }
};

Node* createList(const vector<int>& arr) {
    if (arr.empty()) return NULL;

    Node* head = new Node(arr[0]);
    Node* curr = head;

    for (int i = 1; i < arr.size(); i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }

    return head;
}

// Helper: Create loop at position pos (0-based)
// pos = -1 means no loop
void createLoop(Node* head, int pos) {
    if (pos == -1) return;

    Node* loopNode = NULL;
    Node* temp = head;
    int idx = 0;

    while (temp->next) {
        if (idx == pos) loopNode = temp;
        temp = temp->next;
        idx++;
    }

    if (idx == pos) loopNode = temp;

    if (loopNode)
        temp->next = loopNode;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int pos;
    cin >> pos; // Position to form loop (-1 if no loop)

    Node* head = createList(arr);
    createLoop(head, pos);

    Solution sol;
    int result = sol.lengthOfLoop(head);

    cout << result << endl;

    return 0;
}