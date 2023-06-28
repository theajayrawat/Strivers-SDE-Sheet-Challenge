// Time Complexity: O(V*E)
// Space Complexity: O(V) 

#include <bits/stdc++.h>
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> dist(n + 1, 10e8);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 10e8 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    return dist[dest];
}