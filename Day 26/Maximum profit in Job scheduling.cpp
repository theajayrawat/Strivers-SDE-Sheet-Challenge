// Time Complexity: O(NlogN)
// Space Complexity: O(N)

#include <bits/stdc++.h>
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    priority_queue<int> p;

    unordered_map<int, vector<int>> mp;

    int mx = 0;

    for (int i = 0; i < jobs.size(); i++)
    {

        mx = max(mx, jobs[i][0]);

        mp[jobs[i][0]].push_back(jobs[i][1]);
    }

    int ans = 0;

    for (int i = mx; i > 0; i--)
    {

        for (auto &q : mp[i])
        {

            p.push(q);
        }

        if (p.size() == 0)
        {

            continue;
        }

        ans += p.top();

        p.pop();
    }

    return ans;
}
