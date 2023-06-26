// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

void solve(BinaryTreeNode<int> *root, int key, int &pre, int &suc)
{
    if (root == nullptr)
    {
        return;
    }
    solve(root->left, key, pre, suc);
    if (root->data < key)
    {
        pre = root->data;
    }
    if (root->data > key and suc == -1)
    {
        suc = root->data;
    }
    solve(root->right, key, pre, suc);
}
pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    // Write your code here.
    int pre = -1;
    int suc = -1;
    if (!root)
        return {-1, -1};

    solve(root, key, pre, suc);
    return {pre, suc};
}