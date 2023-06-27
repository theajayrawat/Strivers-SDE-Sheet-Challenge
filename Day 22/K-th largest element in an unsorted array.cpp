// Time Complexity: O(N)
// Space Complexity: O(K)

#include <bits/stdc++.h>
int kthLargest(vector<int> &arr, int size, int K)
{
    // Write your code here.
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto a : arr)
    {
        if (pq.size() < K)
            pq.push(a);
        else if (pq.size() == K && a >= pq.top())
        {
            pq.pop();
            pq.push(a);
        }
    }

    return pq.top();
}