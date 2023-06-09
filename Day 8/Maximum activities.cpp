// Time Complexity: O(n log n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish)
{
    // Write your code here.
    int n = start.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i)
    {
        v.push_back(make_pair(finish[i], start[i]));
    }
    sort(v.begin(), v.end());
    int e = -1;
    int ans = 0;
    for (auto val : v)
    {
        if (val.second >= e)
        {
            ans++;
            e = val.first;
        }
    }
    return ans;
}