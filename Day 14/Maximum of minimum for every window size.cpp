// Time Complexity: O(N)
//  Space Complexity: O(N)

#include <bits/stdc++.h>
vector<int> maxMinWindow(vector<int> a, int n)
{
    // Write your code here.
    stack<int> st;
    vector<int> next(n, n);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[i] < a[st.top()])
        {
            next[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    vector<int> prev(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && a[i] < a[st.top()])
        {
            prev[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    vector<int> ans(n, INT_MIN);
    for (int i = 0; i < n; i++)
    {
        int len = next[i] - prev[i] - 2;
        ans[len] = max(ans[len], a[i]);
    }

    for (int i = n - 2; i >= 1; i--)
        ans[i] = max(ans[i], ans[i + 1]);

    return ans;
}