// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

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

class info
{
public:
    int maxi;
    int mini;
    bool isBST;
    int sum;
};

info solve(TreeNode<int> *root, int &maxSize)
{
    if (!root)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, maxSize);
    info right = solve(root->right, maxSize);

    info currNode;

    currNode.sum = left.sum + right.sum + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(left.mini, root->data);

    if (left.isBST && right.isBST && root->data > left.maxi && root->data < right.mini)
    {
        currNode.isBST = true;
    }
    else
        currNode.isBST = false;

    if (currNode.isBST)
    {
        maxSize = max(maxSize, currNode.sum);
    }

    return currNode;
}

int largestBST(TreeNode<int> *root)
{
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}
