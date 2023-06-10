// Time Complexity: O(N! X N)
// Space Complexity: O(1)

#include <bits/stdc++.h>
void solve(string &s, vector<string> &ans, int i)
{
    if (i == s.size())
    {
        ans.push_back(s);
        return;
    }

    for (int j = i; j < s.size(); j++)
    {
        swap(s[i], s[j]);
        solve(s, ans, i + 1);
        swap(s[i], s[j]);
    }
}
vector<string> findPermutations(string &s)
{
    // Write your code here.
    vector<string> ans;
    solve(s, ans, 0);
    return ans;
}
