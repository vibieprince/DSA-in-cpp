//  OYO   TCS   Ola   Hike   Visa   Grab   HSBC   FICO   KPMG   CRED   Nike   Paytm   Adobe   Dunzo   Quikr   Groww   Cisco   Park+   WinZO   Amazon   VMWare   Oracle   Google   RIVIGO   Swiggy   Paypal   Thales   Amdocs   Adidas   RedBus   Spinny   Rapido   Samsung   DE Shaw   Walmart   Veritas   Lybrate   Spotify   Siemens   Protium   Rakuten   Infosys   Globant   Nagarro   99acres   BirdEye   Nagaaro   Chaayos   Accolite   Snapdeal   SAP Labs   Qualcomm   Barclays   Phone Pe   Hedonova   MobiKwik   HashedIn   Verifone   Osmosiss   Synopsys   Coinbase   Cloudera   Microsoft   Cognizant   Capgemini   Delhivery   Accenture   FourKites   Tata Cliq   Bloomberg   MX Player   Blackrock   MakeMyTrip   BNY Mellon   Salesforce   Freshworks   Born group   MindTickle   Wells Fargo   Informatica   Pegasystems   Ion Trading   Tekion Corp   Magicbricks   Bristlecone   F5 Networks   Shell india   Green apple   MAQ Software   EPAM Systems   Athenahealth   SLK SOFTWARE   Deutsche Bank   Goldman Sachs   Natwest Group   Expedia Group   Urban Company   Bharti Airtel   Morgan Stanley   Mahindra Comviva   American Express   Publicis Sapient   Rudder Analytics   Juniper Networks   Valuefy Solutions   Persistent Systems   Antino Labs Pvt Ltd   NetApp India Pvt Ltd   Symphony Talent, LLC   Wheelseye Technology   Indus Valley Partners   Hexaview Technologies   Unthinkable Solutions   Jio Platforms Limited   42gearMobilitySystems   Cadence Design Systems   Veridic Private Limited   Cleartrail Technologies   Truminds Software Systems   Nippon Audiotronix limited   Accion Labs Private Limited   Velocity Software Pvt. Ltd.   Oodles Technologies Pvt Ltd   Aricent Technologies Limited   Providence Global Center LLP   Sterlite Technologies Limited   MINDZITA (OPC) PRIVATE LIMITED   Strategic IP Information Pte Ltd.   John Deere India Pvt. Ltd. (JDTCI)   Happiest Minds Technologies Limited   IEO MAKERS FABLAB (OPC) PRIVATE LIMITED   Thoughts2Binary Consulting and Solutions  

// Given head, the head of a linked list, determine if the linked list has a cycle in it.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

 

 // Example 1:


// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

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

bool hasCycle(ListNode *head) {

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true;
    }

    return false;
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

    bool result = hasCycle(head);

    cout << (result ? "true" : "false") << endl;

    return 0;
}