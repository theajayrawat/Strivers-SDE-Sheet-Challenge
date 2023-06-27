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

void inorder(BinaryTreeNode<int> *root, vector<int> &v)
{
    if (root == NULL)
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}
BinaryTreeNode<int> *BTtoDLL(BinaryTreeNode<int> *root)
{
    vector<int> v;
    inorder(root, v);
    BinaryTreeNode<int> *head = new BinaryTreeNode<int>(-1);
    BinaryTreeNode<int> *curr = head;
    BinaryTreeNode<int> *prev = NULL;
    for (auto &x : v)
    {
        BinaryTreeNode<int> *t = new BinaryTreeNode<int>(x);
        curr->right = t;
        curr->left = prev;
        prev = curr;
        curr = curr->right;
    }
    curr->right = NULL;
    return head->right;
}