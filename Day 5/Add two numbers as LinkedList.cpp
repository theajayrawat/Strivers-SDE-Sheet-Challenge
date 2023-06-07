// Time Complexity: O(max(m,n))
// Space Complexity: O(max(m,n))

/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    int carry = 0;

    while (num1 || num2 || carry)
    {
        int a = num1 == NULL ? 0 : num1->data;
        int b = num2 == NULL ? 0 : num2->data;
        int sum = a + b + carry;
        carry = sum / 10;

        Node *node = new Node(sum % 10);
        temp->next = node;
        temp = temp->next;

        if (num1)
            num1 = num1->next;
        if (num2)
            num2 = num2->next;
    }

    return dummy->next;
}
