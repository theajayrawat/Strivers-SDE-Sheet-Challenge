// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
void inorder(BinaryTreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    unordered_map<int, int> mp;
    vector<int> ans;
    inorder(root, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        int y = k - ans[i];
        if (mp.find(y) != mp.end())
            return true;
        mp[ans[i]] = i;
    }
    return false;
}