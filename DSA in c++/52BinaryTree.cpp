#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root){
    int data;
    cout<<"Enter the data : "<<endl;
    cin>>data;

    root = new Node(data);
    if(data==-1)
       return NULL;
    cout<<"Enter data for left Node of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data for right Node of "<<data<<endl;
    root->right = buildTree(root->right);
    
    return root;
}

void levelOrderTraversal(Node*root){
    // Breadth First Search
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl; // purana level complete traverse ho chuka hai
            if(!q.empty()) // queue still have some child nodes
            q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
        
            if(temp->right)
                q.push(temp->right);
        }
    }
}

void inorderTraversal(Node *root){
    // Base Case
    if(root==NULL)
        return;
    
    // Recursive call
    inorderTraversal(root->left); // Left
    cout<<root->data<<" ";// Root
    inorderTraversal(root->right);// Right
}

void preorderTraversal(Node* root){
    // Base Case 
    if(root==NULL)
       return;
    
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root){
    // Base Case 
    if(root==NULL)
       return;
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

void morrisTraversal(Node* root) {
    Node* current = root;
    while (current != NULL) {
        if (!current->left) {
            // If there is no left child, print the current node's data and move to the right child
            cout << current->data << " ";
            current = current->right;
        } else {
            // Find the inorder predecessor of the current node
            Node* pred = current->left;
            while (pred->right != NULL && pred->right != current) {
                pred = pred->right;
            }

            // Make current the right child of the rightmost node in the left subtree
            if (pred->right == NULL) {
                pred->right = current;
                current = current->left;
            } else {
                // Revert the changes made, print the current node's data, and move to the right child
                pred->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}


void *buildFromLevelOrder(Node* &root){
    queue<Node*> q;
    cout<<"Enter data for root "<<endl;
    int data;
    cin>> data;
    root = new Node(data);
    q.push(root);
    

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        cout<<"Enter left Node for "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right Node for "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main(){
    Node *root = NULL;
    // root = buildTree(root);
    // 1 3 5 7 -1 -1 11 5 17 -1 -1 -1
    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    // inorderTraversal(root);
    // preorderTraversal(root);
    // postorderTraversal(root);
    return 0;
}