//  Ola   TCS   ION   IBM   Dell   Dunzo   Gojek   Adobe   Paytm   Cisco   Lumiq   Xperi   Nykaa   Park+   Wipro   Apple   Paypal   Oracle   Intuit   Myntra   Spinny   Adidas   JUSPAY   RedBus   Airtel   Amdocs   Rupeek   DeltaX   Forfit   Auzmor   Vocera   Amazon   Google   Samsung   Infosys   Gartner   Cashify   BirdEye   Coforge   Virtusa   Kulizaa   Fujitsu   Nagarro   Grappus   Netlink   Chaayos   Flipkart   Qualcomm   Lenskart   SAP Labs   Accolite   Conduent   MobiKwik   Infoedge   Hashedin   TravClan   Mindtree   Synopsys   Facebook   Cognizant   OLX Group   Capgemini   Delhivery   Mathworks   yellow.ai   Recrosoft   Delloitte   Blackrock   Microsoft   Freshworks   Innovaccer   Salesforce   Intel Labs   Bloomreach   Milkbasket   Allscripts   Microfocus   MakeMyTrip   BlackNgreen   Evalueserve   Tekion Corp   Incedo Inc.   1218 Global   Digital 1×1   ThoughtSpot   Quadrical AI   Schlumberger   Pristyn Care   Global Logic   ZS Associates   Natwest Group   Netcore cloud   Credit Suisse   Josh Software   DE Shaw India   Stigentech IT   Cloud Analogy   Exotel Techcom   Bank Of America   Larsen & Toubro   Newgen Software   Shrine Software   Publicis Sapient   General Electric   HCL Technologies   Adverb Solutions   Texas Instruments   HCODE Technologies   Rootstock Software   UnitedHealth Group   Tredence Analytics   Aditya Technologies   NetApp India Pvt Ltd   TIBCO Software India   Liberin Technologies   Hexaware Technologies   Indus Valley Partners   Unthinkable Solutions   Royal Bank of Scotland   Surya Software Systems   WatchGuard Technologies   Reliance Jio Infocomm Ltd   Sterlite Technologies Limited  

// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

// Example 1:


// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
// Example 2:

// Input: head = [5], left = 1, right = 1
// Output: [5]


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

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(!head || left==right)
        return head;
    
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* temp = dummy;
    for(int i=1;i<left;i++)
        temp = temp->next;
    
    ListNode* curr = temp->next;
    ListNode* fwd = nullptr;

    for(int i=0;i<right-left;i++){
        fwd = curr->next;
        curr->next = fwd->next;
        fwd->next = temp->next;
        temp->next = fwd;
    }

    return dummy->next;
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
    int right = nums.back();
    nums.pop_back();
    int left = nums.back();
    nums.pop_back();

    ListNode * head = buildList(nums);
    head = reverseBetween(head,left,right);

    printList(head);
    return 0;
}