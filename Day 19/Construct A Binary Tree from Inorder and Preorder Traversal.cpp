// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int> *solve(vector<int> &inorder, vector<int> &preorder, unordered_map<int, int> &mp, int &i, int l, int r)
{
    if (l > r)
    {
        return NULL;
    }
    int ele = preorder[i++];
    int index = mp[ele];
    TreeNode<int> *node = new TreeNode<int>(ele);

    node->left = solve(inorder, preorder, mp, i, l, index - 1);
    node->right = solve(inorder, preorder, mp, i, index + 1, r);

    return node;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    //    Write your code here
    int n = inorder.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[inorder[i]] = i;
    }
    int i = 0;
    return solve(inorder, preorder, mp, i, 0, n - 1);
}