// Time Complexity: O(N)
// Space Complexity: O(1)

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
int nodeLength(Node *head)
{
    int len = 0;

    while (head)
    {
        head = head->next;
        len++;
    }

    return len;
}
Node *removeKthNode(Node *head, int K)
{
    // Write your code here.
    int len = nodeLength(head);
    Node *temp = head;

    // head remove
    if (len == K)
    {
        temp = temp->next;
        return temp;
    }

    // tail remove
    if (K == 1)
    {
        len = len - 2;
        while (len--)
            temp = temp->next;

        temp->next = NULL;
        return head;
    }

    // other node
    len = len - K - 1;
    while (len--)
        temp = temp->next;

    Node *del = temp->next;
    temp->next = temp->next->next;

    delete (del);
    return head;
}
