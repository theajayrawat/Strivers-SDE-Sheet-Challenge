// Time Complexity: O(N)
// Space Complexity: O(H)    “H”  is the height of binary tree

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
int gethght(TreeNode<int> *root, int &ans)
{
    if (!root)
        return 0;
    int lh = gethght(root->left, ans);
    int rh = gethght(root->right, ans);
    ans = max(ans, lh + rh);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Write Your Code Here.
    int ans = 0;
    gethght(root, ans);
    return ans;
}
