// Time complexity: O(N)
// Space complexity: O(N)

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
TreeNode<int> *solver(TreeNode<int> *root, int x, int y)
{
    if (!root)
        return NULL;
    if (root->data == x || root->data == y)
        return root;

    TreeNode<int> *left = solver(root->left, x, y);
    TreeNode<int> *right = solver(root->right, x, y);

    if (!left && right)
        return right;
    else if (!right && left)
        return left;
    else if (!left && !right)
        return NULL;
    else
        return root;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    //    Write your code here
    TreeNode<int> *lca = solver(root, x, y);
    return lca->data;
}