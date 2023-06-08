// Time Complexity: O(max(n,m))
// Space Complexity: O(1)

/****************************************************************

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

*****************************************************************/
int lengthOfNode(Node *head)
{
    int n = 0;

    while (head)
    {
        head = head->next;
        n++;
    }

    return n;
}
Node *findIntersection(Node *firstHead, Node *secondHead)
{
    // Write your code here
    int n = lengthOfNode(firstHead);
    int m = lengthOfNode(secondHead);
    int diff = n - m;

    if (diff > 0)
    {
        while (diff--)
            firstHead = firstHead->next;
    }
    else if (diff < 0)
    {
        diff = abs(diff);
        while (diff--)
            secondHead = secondHead->next;
    }

    while (firstHead)
    {
        if (firstHead == secondHead)
            return firstHead;

        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }

    return NULL;
}