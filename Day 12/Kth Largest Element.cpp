// Time Complexity : O(NlogK)
// Space Complexity: O(K)

#include <bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
// Write your code here.
#include <bits/stdc++.h>
    vector<int> kthSmallLarge(vector<int> & nums, int n, int k)
    {
        // Write your code here.
        vector<int> res;

        priority_queue<int> pq;

        priority_queue<int, vector<int>, greater<int>> pq1;

        for (int i = 0; i < n; i++)
        {

            pq.push(arr[i]);

            pq1.push(arr[i]);

            if (pq.size() > k)
                pq.pop();

            if (pq1.size() > k)
                pq1.pop();
        }

        return {pq.top(), pq1.top()};
    }