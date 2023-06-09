// Time Complexity: O(N)
// Space Complexity: O(1)

#include <bits/stdc++.h>
double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    vector<pair<double, pair<int, int>>> v;
    for (int i = 0; i < n; i++)
    {
        double d = (double)items[i].second / items[i].first;
        pair<double, pair<int, int>> p = make_pair(d, items[i]);
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    double ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i].second.first > w)
        {
            ans += w * v[i].first;
            break;
        }
        ans += v[i].second.second;
        w -= v[i].second.first;
    }
    return ans;
}