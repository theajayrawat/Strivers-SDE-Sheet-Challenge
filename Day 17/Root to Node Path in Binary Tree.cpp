// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>
/*
    template <typename T = int>
        class TreeNode
        {
                public:
                T data;
                TreeNode<T> *left;
                TreeNode<T> *right;

                TreeNode(T data)
                {
                        this->data = data;
                        left = NULL;
                        right = NULL;
                }

                ~TreeNode()
                {
                        if (left != NULL)
                        {
                                delete left;
                        }
                        if (right != NULL)
                        {
                                delete right;
                        }
                }
        };
*/
bool solve(TreeNode<int> *root, int x, vector<int> &v)
{

    if (root == NULL)
        return false;

    if (root->data == x)
    {

        v.push_back(x);

        return true;
    }

    if (root->left)
    {

        if (solve(root->left, x, v))
        {

            v.push_back(root->data);

            return true;
        }
    }

    if (root->right)
    {

        if (solve(root->right, x, v))
        {

            v.push_back(root->data);

            return true;
        }
    }

    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)

{

    vector<int> v;

    solve(root, x, v);

    reverse(v.begin(), v.end());

    return v;
}
