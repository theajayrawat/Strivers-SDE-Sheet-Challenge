// Time complexity: O(N)
// Space complexity: O(N)

#include <bits/stdc++.h>
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
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

***********************************************************/

bool identicalTrees(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    // Write your code here.
    if (root1 && !root2)
        return false;
    else if (!root1 && root2)
        return false;
    else if (!root1 && !root2)
        return true;

    int left = identicalTrees(root1->left, root2->left);
    int right = identicalTrees(root1->right, root2->right);

    return root1->data == root2->data && left && right;
}