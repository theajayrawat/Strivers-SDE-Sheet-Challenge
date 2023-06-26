// Time Complexity: O(min(K,N))
// Space Complexity: O(min(K,N))


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

int kthSmallest(TreeNode<int> *root, int &k)
{
    //	Write the code here.
    if (root == NULL)
        return -1;

    int left = kthSmallest(root->left, k);
    if (left != -1)
        return left;
    k--;
    if (k == 0)
        return root->data;

    return kthSmallest(root->right, k);
}