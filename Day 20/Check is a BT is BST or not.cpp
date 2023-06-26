// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
bool isBST(BinaryTreeNode<int> *root, BinaryTreeNode<int> *maxi, BinaryTreeNode<int> *mini)
{
    if (!root)
        return true;
    if (mini && root->data < mini->data)
        return false;
    if (maxi && root->data > maxi->data)
        return false;

    bool a = isBST(root->left, root, mini);
    bool b = isBST(root->right, maxi, root);

    return a && b;
}
bool validateBST(BinaryTreeNode<int> *root)
{
    // Write your code here
    return isBST(root, NULL, NULL);
}