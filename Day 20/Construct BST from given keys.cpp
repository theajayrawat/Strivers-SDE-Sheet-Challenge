// Time Complexity: O(N)
// Space Complexity: O(log(N))

#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int> *BST(vector<int> &nums, int l, int h)
{
    if (l > h)
        return NULL;

    int mid = l + (h - l) / 2;
    TreeNode<int> *node = new TreeNode<int>(nums[mid]);
    node->left = BST(nums, l, mid - 1);
    node->right = BST(nums, mid + 1, h);

    return node;
}
TreeNode<int> *sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return BST(arr, 0, n - 1);
}