// Problem Statement A telecommunications company has deployed a hierarchical network of relay stations arranged in a binary tree structure. Each relay station has a signal amplification value (which can be positive, zero, or negative — a negative value means the station introduces signal loss).

// A signal path is any sequence of stations where each consecutive pair shares a direct connection (parent-child edge). A path can start and end at any station; it does not need to pass through the root station. Each station may appear at most once in a single path.

// You are given the relay network as a binary tree. Find the maximum total signal amplification achievable by any path in the network.

// Note: A path must contain at least one station.

// Input Format Line 1: integer n — the total number of values in the BFS (level-order) encoding, including null placeholders Line 2: n space-separated values — integers or the string null, representing the BFS level-order encoding of the tree The BFS encoding uses null to represent absent children. The root is the first value. If a node is null, it has no children (its child positions in the encoding are skipped).

// Output Format Print a single integer — the maximum total signal amplification of any path in the network.

// Examples Example 1 Input:

// 7 -10 9 20 null null 15 7 Output: 42

// Explanation:

// The tree has root -10, left child 9, right child 20. Station 20 has left child 15 and right child 7. The optimal path is 15 → 20 → 7, giving amplification 15 + 20 + 7 = 42. Including root -10 would reduce the total, so the best path stays within the right subtree.

// Highlighted path: 15 → 20 → 7 = 42

// Example 2 Input 3 1 2 3 Output 6 Example 3 Input 1 5 Output 5 Example 4 Input 3 2 -1 -2 Output 2 Example 5 Input 7 1 2 3 4 5 6 7 Output 18 Example 6 Input 7 5 4 8 11 null 13 4 Output 41

// Constraints 1 <= number of nodes <= 3 × 10^4 -1000 <= station value <= 1000

#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

struct BinaryTree{
    int val;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int v){
        this->val = v;
        this->left = nullptr;
        this->right = nullptr;
    }
};

BinaryTree* buildTree(vector<string> &nodes){
    if(nodes.empty() || nodes[0]=="null")
        return nullptr;
    BinaryTree* root = new BinaryTree(stoi(nodes[0]));

    queue<BinaryTree*> q;
    q.push(root);
    
    int i = 1;
    while(!q.empty() && i < nodes.size()){
        BinaryTree* curr = q.front();
        q.pop();
        if(i<nodes.size() && nodes[i]!="null"){
            curr->left = new BinaryTree(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;
        if(i<nodes.size() && nodes[i] != "null"){
            curr->right = new BinaryTree(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int maxPath = INT_MIN;

int maxSignalBoost(BinaryTree* root){
    if(root==nullptr)
        return 0;

    int leftGain = max(0,maxSignalBoost(root->left));
    int rightGain = max(0,maxSignalBoost(root->right));

    maxPath = max(maxPath,leftGain+root->val+rightGain);
    return root->val + max(leftGain,rightGain);
}

int main(){
    int n;
    cin>>n;

    vector<string> nodes(n);
    for(int i=0;i<n;i++)
        cin>>nodes[i];

    BinaryTree* root = buildTree(nodes);
    maxSignalBoost(root);
    cout<<maxPath;
    return 0;
}