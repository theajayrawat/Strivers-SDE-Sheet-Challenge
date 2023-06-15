// Time Complexity: O((N * K) * log(K)) 
// Space Complexity: O(N * K)

#include <bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    // Write your code here.
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (auto i : kArrays)
    {
        for (auto j : i)
        {
            minHeap.push(j);
        }
    }

    vector<int> ans;
    while (minHeap.size())
    {
        ans.push_back(minHeap.top());
        minHeap.pop();
    }

    return ans;
}