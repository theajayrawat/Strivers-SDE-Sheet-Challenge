// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>
/************************************************************

Following is the Binary Tree node class

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int> ans;
    if (!root)
        return ans;
    map<int, vector<int>> nodes;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        root = q.front().first;
        int y = q.front().second;
        q.pop();
        nodes[y].push_back(root->data);
        if (root->left)
            q.push({root->left, y - 1});
        if (root->right)
            q.push({root->right, y + 1});
    }
    for (auto &it : nodes)
    {
        ans.insert(ans.end(), it.second.begin(), it.second.end());
    }
    return ans;
}