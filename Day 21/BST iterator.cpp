// Time Complexity: O(H)
// Space Complexity: O(H)

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

class BSTiterator
{ 
    public:  
    stack<TreeNode<int>*> st;
    void pushall(TreeNode<int>* root){
        while(root){
            st.push(root);
            root=root->left; 
        }
    }
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        pushall(root);
    }

    int next()
    {
        // write your code here
        TreeNode<int>* node=st.top(); 
        st.pop();
        pushall(node->right); 
        return node->data;
    }

    bool hasNext()
    {
        // write your code here
        return !st.empty();
    }
};

/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/