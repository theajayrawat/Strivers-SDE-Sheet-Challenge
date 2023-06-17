// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>
int largestRectangle(vector<int> &heights)
{
    // Write your code here.
    int n = heights.size();
    stack<int> st;
    vector<int> next(n, n);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[i] < heights[st.top()])
        {
            next[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    vector<int> prev(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[i] < heights[st.top()])
        {
            prev[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    int max_ans = INT_MIN;
    for (int i = 0; i < n; i++)
        max_ans = max(max_ans, heights[i] * (next[i] - prev[i] - 1));
    return max_ans;
}