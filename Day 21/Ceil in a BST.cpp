// Time Complexity: O(H)
// Space Complexity: O(H)

#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
void solve(BinaryTreeNode<int> *root, int x, int &ans)
{
    if (!root)
        return;
    else if (root->data >= x)
    {
        ans = min(ans, root->data);
        solve(root->left, x, ans);
    }
    else
        solve(root->right, x, ans);
}

int findCeil(BinaryTreeNode<int> *node, int x)
{
    // Write your code here.
    int ans = INT_MAX;
    solve(node, x, ans);
    return ans == INT_MAX ? -1 : ans;
}