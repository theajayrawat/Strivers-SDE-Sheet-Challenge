// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>

vector<int> nextGreater(vector<int> &arr, int n)
{
    // Write your code here
    stack<int> st;
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++)
    {
        int j = i % n;
        while (!st.empty() && arr[j] > arr[st.top()])
        {
            res[st.top()] = arr[j];
            st.pop();
        }
        st.push(j);
    }
    return res;
}