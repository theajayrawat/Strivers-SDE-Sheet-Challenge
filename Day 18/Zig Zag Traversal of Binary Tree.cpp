// Time complexity: O(N)
// Space complexity: O(N)

#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
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

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> ans;
    if (root == NULL)
        return ans;
    bool leftToRight = true;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        int qlen = q.size();
        vector<int> row(qlen);
        for (int i = 0; i < qlen; i++)
        {
            BinaryTreeNode<int> *curr = q.front();
            q.pop();
            int index = leftToRight ? i : qlen - i - 1;
            row[index] = curr->data;
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        leftToRight = !leftToRight;
        ans.insert(ans.end(), row.begin(), row.end());
    }
    return ans;
}
