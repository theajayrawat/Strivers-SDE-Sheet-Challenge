// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    // Write your code here
    int m, r;
    vector<int> freq(n, 0);

    for (int i = 0; i < n; i++)
    {
        freq[arr[i] - 1]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (freq[i] == 2)
        {
            r = i + 1;
        }
        if (freq[i] == 0)
        {
            m = i + 1;
        }
    }

    pair<int, int> p = make_pair(m, r);
    return p;
}