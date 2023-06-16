// Time Complexity: O(1)
// Space Complexity: O(N)

#include <bits/stdc++.h>
class Queue
{
    int itr;
    vector<int> v;
    int frontt;

public:
    Queue()
    {
        // Implement the Constructor
        itr = 0;
        v.resize(0);
        frontt = 0;
    }
    /*----------------- Public Functions of Queue -----------------*/
    bool isEmpty()
    {
        // Implement the isEmpty() function
        return frontt > itr - 1;
    }
    void enqueue(int data)
    {
        // Implement the enqueue() function
        v.push_back(data);
        itr++;
    }
    int dequeue()
    {
        // Implement the dequeue() function
        return frontt <= itr - 1 ? v[frontt++] : -1;
    }
    int front()
    {
        // Implement the front() function
        return frontt <= itr - 1 ? v[frontt] : -1;
    }
};
