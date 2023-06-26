// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>
/************************************************************
    Following is the Binary Search Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int> *LCAinaBST(TreeNode<int> *root, TreeNode<int> *P, TreeNode<int> *Q)
{
    // Write your code here
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == P->data || root->data == Q->data)
    {
        return root;
    }

    TreeNode<int> *leftAns = LCAinaBST(root->left, P, Q);
    TreeNode<int> *rightAns = LCAinaBST(root->right, P, Q);

    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    else if (leftAns != NULL && rightAns == NULL)
        return leftAns;
    else if (leftAns == NULL && rightAns != NULL)
        return rightAns;
    else
        return NULL;
}
