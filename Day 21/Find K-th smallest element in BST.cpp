// Time Complexity: O(min(K,N))
// Space Complexity: O(min(K,N))

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

int KthLargestNumber(TreeNode<int> *root, int &k)
{
    // Write your code here.
    if (root == NULL)
        return -1;

    int right = KthLargestNumber(root->right, k);
    if (right != -1)
        return right;
    k--;

    if (k == 0)
        return root->data;

    return KthLargestNumber(root->left, k);
}
