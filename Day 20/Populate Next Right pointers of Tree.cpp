// Time complexity: O(N)
// Space complexity: O(N)

#include <bits/stdc++.h>
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public :
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if (!root)
        return;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        int qSize = q.size();
        BinaryTreeNode<int> *rightNode = NULL;
        while (qSize--)
        {
            auto cur = q.front();
            q.pop();
            cur->next = rightNode;
            rightNode = cur;
            if (cur->right)
                q.push(cur->right);
            if (cur->left)
                q.push(cur->left);
        }
    }
}