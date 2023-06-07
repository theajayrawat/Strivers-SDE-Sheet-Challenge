// Time Complexity: O(N+M)
// Space Complexity: O(1)

#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    // Write your code here.
    Node<int> *dummy = new Node<int>(-1);
    Node<int> *head = dummy;

    while (first && second)
    {
        if (first->data < second->data)
        {
            head->next = first;
            first = first->next;
        }
        else
        {
            head->next = second;
            second = second->next;
        }
        head = head->next;
    }

    while (first)
    {
        head->next = first;
        first = first->next;
        head = head->next;
    }

    while (second)
    {
        head->next = second;
        second = second->next;
        head = head->next;
    }

    return dummy->next;
}
