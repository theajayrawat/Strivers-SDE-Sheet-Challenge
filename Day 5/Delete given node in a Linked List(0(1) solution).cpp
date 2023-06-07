// Time Complexity: O(1)
// Space Complexity: O(1)

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

void deleteNode(LinkedListNode<int> *node)
{
    // Write your code here.
    LinkedListNode<int> *del = node->next;
    node->data = node->next->data;
    node->next = node->next->next;
    delete (del);
}