// Time complexity: O(logN)
// Space complexity: O(N)

#include <bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n)
{

    // Write your code here
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        if (maxh.empty() || maxh.top() >= arr[i])
            maxh.push(arr[i]);
        else
            minh.push(arr[i]);

        if (maxh.size() > minh.size() + 1)
        {
            minh.push(maxh.top());
            maxh.pop();
        }
        else if (maxh.size() < minh.size())
        {
            maxh.push(minh.top());
            minh.pop();
        }

        if (minh.size() < maxh.size())
            v.push_back(maxh.top());
        else
            v.push_back((minh.top() + maxh.top()) / 2);
    }

    return v;
}
