// Online Assessment Neopat 

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

// Build tree from string
TreeNode* buildTree(string str) {
    if (str.size() == 0) return NULL;

    vector<string> nodes;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, ',')) {
        nodes.push_back(temp);
    }

    if (nodes[0] == "null") return NULL;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (nodes[i] != "null") {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < nodes.size() && nodes[i] != "null") {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// Find max width
int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;

    long long ans = 0;
    queue<pair<TreeNode*, long long>> q;

    q.push({root, 0});

    while (!q.empty()) {
        int size = q.size();
        long long minIndex = q.front().second; // avoid overflow
        long long first, last;

        for (int i = 0; i < size; i++) {
            auto curr = q.front();
            q.pop();

            long long index = curr.second - minIndex;

            if (i == 0) first = index;
            if (i == size - 1) last = index;

            if (curr.first->left)
                q.push({curr.first->left, 2 * index});

            if (curr.first->right)
                q.push({curr.first->right, 2 * index + 1});
        }

        ans = max(ans, last - first + 1);
    }

    return ans;
}

int main() {
    string input;
    cout << "Enter tree (comma separated): ";
    cin >> input;

    TreeNode* root = buildTree(input);

    cout << "Maximum Width: " << widthOfBinaryTree(root) << endl;

    return 0;
}