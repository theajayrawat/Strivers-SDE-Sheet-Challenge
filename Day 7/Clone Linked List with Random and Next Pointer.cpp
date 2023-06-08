// Time Complexity: O(N)
// Space Complexity: O(1)

#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.

    LinkedListNode<int> *temp = head;
    // step 1
    while (temp)
    {
        LinkedListNode<int> *newNode = new LinkedListNode<int>(temp->data);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }
    // step 2
    LinkedListNode<int> *itr = head;
    while (itr)
    {
        itr->next->random = itr->random != NULL ? itr->random->next : NULL;
        itr = itr->next->next;
    }
    // step 3
    LinkedListNode<int> *dummy = new LinkedListNode<int>(0);
    itr = dummy;
    temp = head;
    while (temp)
    {
        itr->next = temp->next;
        itr = itr->next;
        temp->next = itr->next;
        temp = temp->next;
    }

    return dummy->next;
}
