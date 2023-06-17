// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] > arr[i])
        {
            ans[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    return ans;
}