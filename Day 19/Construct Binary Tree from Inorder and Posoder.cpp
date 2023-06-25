// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>
/************************************************************

   Following is the TreeNode class structure

   class TreeNode<T>
   {
   public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
   };


 ************************************************************/
TreeNode<int> *solve(vector<int> &inOrder, vector<int> &postOrder, unordered_map<int, int> &mp, int &i, int l, int r)
{
    if (l > r)
    {
        return NULL;
    }
    int ele = postOrder[i--];
    int index = mp[ele];
    TreeNode<int> *node = new TreeNode<int>(ele);

    node->right = solve(inOrder, postOrder, mp, i, index + 1, r);
    node->left = solve(inOrder, postOrder, mp, i, l, index - 1);

    return node;
}
TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postOrder, vector<int> &inOrder)
{
    // Write your code here.
    int n = inOrder.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[inOrder[i]] = i;
    }
    int i = n - 1;
    return solve(inOrder, postOrder, mp, i, 0, n - 1);
}
