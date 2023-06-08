// Time Complexity: O(N)
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
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int> *curr=head;
    LinkedListNode<int> *prev=NULL;

    while(curr){
        LinkedListNode<int> *temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }

    return prev;
}

LinkedListNode<int> *findMiddle(LinkedListNode<int> *head) {
    // Write your code here
    LinkedListNode<int> * slow = head;
    LinkedListNode<int> * fast = head;
    
    while(fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next; 
    }
    return slow;
}

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    LinkedListNode<int>* mid=findMiddle(head);
    mid=reverseLinkedList(mid);

    while(mid){
        if(mid->data!=head->data)
            return false;
        mid=mid->next;
        head=head->next;
    }

    return true;
}