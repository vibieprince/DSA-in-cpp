#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int n) {
        this->data = n;
        this->left = NULL;
        this->right = NULL;
    }
};

// Insert into BST
Node* insertIntoBST(Node* &root, int data) {
    if (!root) {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
        root->right = insertIntoBST(root->right, data);
    else
        root->left = insertIntoBST(root->left, data);
    
    return root;
}

// Take input from user until -1
void takeInput(Node* &root) {
    int data;
    cin >> data;
    while (data != -1) {
        insertIntoBST(root, data);
        cin >> data;
    }
}

// Level Order Traversal (BFS)
void levelOrderTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) q.push(NULL);
        } else {
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}

// Inorder Traversal
void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Find minimum value in BST
Node* minVal(Node* root) {
    Node* temp = root;
    while (temp && temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

// Find maximum value in BST
Node* maxVal(Node* root) {
    Node* temp = root;
    while (temp && temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}

// Delete a node from BST
Node* deleteFromBST(Node* root, int val) {
    if (!root) return NULL;

    if (root->data == val) {
        // 0 child
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }
        // 1 child
        if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if (root->right != NULL && root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // 2 children
        int mini = minVal(root->right)->data;
        root->data = mini;
        root->right = deleteFromBST(root->right, mini);
        return root;
    }
    else if (val < root->data) {
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

// Main function
int main() {
    Node* root = NULL;
    cout << "Enter data to create BST (-1 to end): ";
    takeInput(root);

    cout << "Printing our BST (Level Order):" << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "Inorder Traversal of BST: ";
    inorderTraversal(root);    
    cout << endl;

    if (root) {
        cout << "Minimum value in BST: " << minVal(root)->data << endl;
        cout << "Maximum value in BST: " << maxVal(root)->data << endl;
    }

    int val;
    cout << "Enter value to delete from BST: ";
    cin >> val;

    root = deleteFromBST(root, val);

    cout << "BST after deletion:" << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "Inorder Traversal of BST: ";
    inorderTraversal(root);    
    cout << endl;

    if (root) {
        cout << "Minimum value in BST: " << minVal(root)->data << endl;
        cout << "Maximum value in BST: " << maxVal(root)->data << endl;
    } else {
        cout << "BST is now empty." << endl;
    }

    return 0;
}
