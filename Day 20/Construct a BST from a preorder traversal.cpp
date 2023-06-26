// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int> *solve(vector<int> &preorder, int mini, int maxi, int &i)
{
    if (i >= preorder.size())
        return NULL;
    if (preorder[i] < mini || preorder[i] > maxi)
        return NULL;
    TreeNode<int> *root = new TreeNode<int>(preorder[i++]);
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);
    return root;
}
TreeNode<int> *preOrderTree(vector<int> &preOrder)
{
    // Write your code here.
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preOrder, mini, maxi, i);
}