// Time Complexity: O(N)
// Space Complexity: O(1)

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k)
{
    // Write your code here.
    Node *size = head;
    int n = 0;
    while (size)
    {
        size = size->next;
        n++;
    }
    if (k == 0 || n == 0)
        return head;
    k = k % n;
    if (k == 0)
        return head;
    Node *temp = head;
    k = n - k - 1;
    while (k--)
    {
        head = head->next;
    }
    Node *tail = head->next;
    head->next = NULL;
    Node *ans = tail;
    while (tail->next)
        tail = tail->next;
    tail->next = temp;
    return ans;
}