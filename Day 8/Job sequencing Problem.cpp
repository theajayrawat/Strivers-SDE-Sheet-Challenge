// Time Complexity: O(N*M)
// Space Complexity: O(M)

#include <bits/stdc++.h>
bool static cmp(vector<int> a, vector<int> b)
{
    return a[1] > b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(), jobs.end(), cmp);
    int n = jobs.size();
    int maxDeadline = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, jobs[i][0]);
    }

    vector<int> slot(maxDeadline + 1, -1);
    int jobProfit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i][0]; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                jobProfit += jobs[i][1];
                break;
            }
        }
    }

    return jobProfit;
}
