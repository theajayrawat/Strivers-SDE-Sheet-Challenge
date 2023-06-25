// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>
/************************************************************

    Following is the Tree node structure

        template <typename T>
    class TreeNode
    {
        public :
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long int findMaxSumPathHelper(TreeNode<int> *root, long long int &maxPathSum)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->val;
    }

    // Variable to store the maximum sum of the path from the current node to leaf in the left subtree.
    long long int maxSumLeftPath = findMaxSumPathHelper(root->left, maxPathSum);
    // Variable to store the maximum sum of the path from the current node to leaf in the right subtree.
    long long int maxSumRightPath = findMaxSumPathHelper(root->right, maxPathSum);

    // If the current node has both children, update the value of maxPathSum.
    if (root->left != NULL && root->right != NULL)
    {
        maxPathSum = max(maxPathSum, maxSumLeftPath + maxSumRightPath + root->val);
        return max(maxSumLeftPath, maxSumRightPath) + root->val;
    }
    else if (root->left == NULL)
    {
        return maxSumRightPath + root->val;
    }
    else
    {
        return maxSumLeftPath + root->val;
    }
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    // Variable to store the maximum sum of path between two leaves for the given tree.
    long long int maxPathSum = -1;
    findMaxSumPathHelper(root, maxPathSum);
    return maxPathSum;
}