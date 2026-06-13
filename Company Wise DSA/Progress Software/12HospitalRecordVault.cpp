//  TCS   OYO   OLA   RBS   Hike   Visa   Zoho   Zeta   Uber   Dunzo   Optum   PayTM   Apple   Adobe   Yahoo   Amazon   Swiggy   Zomato   Amdocs   Oracle   Google   Intuit   Twilio   tiktok   Nvidia   VMware   Paypal   Shopee   Siemens   GoDaddy   Lenskart   JPMorgan   Sprinklr   Qualcomm   Facebook   Arcesium   Flipkart   Aliibaba   Palantir   Accolite   LinkedIn   Snapchat   Docusign   Cognizant   Microsoft   Bloomberg   ByteDance   Policbazar   Salesforce   Wells Fargo   Expedia Group   De Shaw India   Goldman Sachs   Morgan Stanley   Disney+ Hotstar   Publicis Sapient   Walmart Global Tech  

// A hospital's emergency ward maintains a Record Vault — a fixed-capacity cache of patient medical records that staff can retrieve in O(1) time. Because the vault has limited physical slots, whenever it is full and a new record must be admitted, the least recently accessed record is evicted to make room.

// You must design the RecordVault data structure with the following two operations, both running in O(1) average time:

// get(patientId) — Return the medical record value for patientId. If the patient's record is not currently in the vault, return -1. Accessing a record marks it as the most recently used. put(patientId, recordValue) — Insert or update the record for patientId with recordValue. If the vault is already at capacity and patientId is not already present, evict the least recently used record before inserting the new one. Updating an existing record also marks it as the most recently used. Input Format Line 1: integer capacity — the maximum number of records the vault can hold Line 2: integer Q — the total number of operations Lines 3 to Q+2: each line is either: get K — retrieve the record for patient ID K put K V — store/update record value V for patient ID K Output Format For each get operation, print the result on its own line. Print -1 if the record is not in the vault.

// Examples Example 1 Input:

// 2 11 put 1 10 put 2 20 get 1 put 3 30 get 2 get 1 put 4 40 get 1 get 3 get 4 get 2 Output:

// 10 -1 10 10 -1 40 -1 Explanation:

// put 1 10 → vault: [1:10] put 2 20 → vault: [1:10, 2:20] (full, capacity=2) get 1 → returns 10; marks patient 1 as most recent → vault order (LRU→MRU): [2, 1] put 3 30 → vault full; evict LRU = patient 2; insert 3 → vault: [1:10, 3:30] get 2 → patient 2 was evicted → returns -1 get 1 → returns 10; marks patient 1 as most recent → vault order: [3, 1] put 4 40 → vault full; evict LRU = patient 3; insert 4 → vault: [1:10, 4:40] get 1 → returns 10 get 3 → evicted → returns -1 get 4 → returns 40 get 2 → evicted → returns -1

// Example 2 Input 1 6 put 1 100 get 1 put 2 200 get 1 get 2 get 3 Output 100 -1 200 -1 Example 3 Input 3 8 put 1 1 put 2 2 put 3 3 get 2 put 4 4 get 1 get 4 get 2 Output 2 -1 4 2 Example 4 Input 2 7 put 5 50 put 6 60 put 5 55 get 5 get 6 put 7 70 get 5

// Output 55 60 55

// Example 5 Input 2 9 put 1 10 put 2 20 get 2 put 3 30 get 1 get 2 get 3 put 4 40 get 2 Output 20 -1 20 30 -1

// Example 6 Input 4 10 put 1 1 put 2 2 put 3 3 put 4 4 get 1 get 2 put 5 5 get 3 get 5 get 4 Output 1 2 -1 5 4
#include<iostream>
#include<unordered_map>
using namespace std;

struct Node{
    int K,V;
    Node* prev;
    Node* next;

    Node(int Key,int Val){
        K = Key;
        V = Val;
        prev = nullptr;
        next = nullptr;
    }
};

// Global vars
Node* head;
Node* tail;
int cap;
unordered_map<int,Node*> map;

void addNode(Node* node){
    node->next = head->next;
    head->next->prev = node;

    node->prev = head;
    head->next = node;
}

void deleteNode(Node* node){
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void put(int K,int V){
    if(map.find(K)!=map.end()){
        Node* node = map[K];
        deleteNode(node);
        map.erase(K);
        delete node;
    }
    if(map.size()==cap){
        Node* node = tail->prev;
        map.erase(node->K);
        deleteNode(node);
        delete node;
    }
    Node* newNode = new Node(K,V);
    addNode(newNode);
    map[K] = newNode;
}

void get(int K){
    if(map.find(K)==map.end()){
        cout<<-1<<" ";
        return;
    }

    Node* node = map[K];
    int ans = node->V;
    deleteNode(node);
    addNode(node);
    cout<<ans<<" ";
}
int main(){
    int operations;
    cin>>cap>>operations;

    head = new Node(-1,-1);
    tail = new Node(-1,-1);

    head->next = tail;
    tail->prev = head;

    while(operations--){
        string op;
        cin>>op;
        if(op=="put"){
            int K,V;
            cin>>K>>V;
            put(K,V);
        }
        else{
            int K;
            cin>>K;
            get(K);
        }
    }
    
    return 0;
}