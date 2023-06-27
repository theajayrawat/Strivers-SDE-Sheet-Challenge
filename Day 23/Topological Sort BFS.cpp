// Time complexity: O(V+E)
// Space complexity: O(V)
    
#include <bits/stdc++.h>
void dfs(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<int> &ans)
{
    visited[u] = true;
    for (int &v : adj[u])
    {
        if (!visited[v])
            dfs(adj, v, visited, ans);
    }
    ans.push_back(u);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    unordered_map<int, vector<int>> adj;
    vector<bool> visited(v, false);
    vector<int> ans;

    for (auto &vec : edges)
    {
        int u = vec[0];
        int v = vec[1];
        adj[u].push_back(v);
    }
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            dfs(adj, i, visited, ans);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}