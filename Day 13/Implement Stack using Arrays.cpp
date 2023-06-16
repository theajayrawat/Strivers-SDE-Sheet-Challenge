// Time Complexity: O(1)
// Space Complexity: O(N)

#include <bits/stdc++.h>
// Stack class.
class Stack
{

public:
    vector<int> arr;
    int size;
    int currSize;
    Stack(int capacity)
    {
        // Write your code here.
        size = capacity;
        currSize = 0;
    }

    void push(int num)
    {
        // Write your code here.
        if (currSize == size)
            return;
        arr.push_back(num);
        currSize++;
    }

    int pop()
    {
        // Write your code here.
        if (currSize == 0)
            return -1;
        int ans = arr[currSize - 1];
        arr.erase(arr.begin() + currSize - 1);
        currSize--;
        return ans;
    }

    int top()
    {
        // Write your code here.
        return currSize == 0 ? -1 : arr[currSize - 1];
    }

    int isEmpty()
    {
        // Write your code here.
        return currSize == 0 ? 1 : 0;
    }

    int isFull()
    {
        // Write your code here.
        return currSize == size;
    }
};