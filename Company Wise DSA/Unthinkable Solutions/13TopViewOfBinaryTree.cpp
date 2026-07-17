
#include<map>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T dat)
    {
        this->data = dat;
        left = NULL;
        right = NULL;
    }
};


vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    queue<pair<TreeNode<int>*,int>> q;
    map<int,int> m;
    q.push({root,0});

    while(!q.empty()){
        TreeNode<int>* front = q.front().first;
        int HD = q.front().second;

        if(m.find(HD)==m.end())
            m[HD] = front->data;

        q.pop();

        if(front->left)
            q.push({front->left,HD-1});
        if(front->right)
            q.push({front->right,HD+1});
    }

    vector<int> ans;
    for(auto &it : m)
        ans.push_back(it.second);

    return ans;
}
