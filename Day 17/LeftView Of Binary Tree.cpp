// Time Complexity: O(N)
// Space Complexity: O(H)       (H -> Height of the Tree)

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
void recursion(TreeNode<int> *root, int level, vector<int> &res)
{
    if (root == NULL)
        return;
    if (res.size() < level)
        res.push_back(root->data);
    recursion(root->left, level + 1, res);
    recursion(root->right, level + 1, res);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> res;
    recursion(root, 1, res);
    return res;
}