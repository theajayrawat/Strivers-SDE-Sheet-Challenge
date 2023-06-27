// Time Complexity : O(N * N)
// Space Complexity : O(N)

#include <bits/stdc++.h>
bool isGraphBirpatite(vector<vector<int>> &edges)
{
    int n = edges.size();
    vector<int> adj[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j])
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<int> color(n, -1);
    color[0] = 0;

    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        for (auto i : adj[p])
        {
            if (color[i] == -1)
            {
                color[i] = 1 - color[p];
                q.push(i);
            }
            else if (color[i] == color[p])
                return false;
        }
    }

    return true;
}
