// Time Complexity : O(V + E)
// Space Complexity : O(V + E)

#include <bits/stdc++.h>
bool dfs(int node, int parent, vector<int> &vis, unordered_map<int, list<int>> &adjlist)
{
    vis[node] = true;
    // visit adjacent nodes
    for (auto adjacentNode : adjlist[node])
    {
        // unvisited adjacent node
        if (!vis[adjacentNode])
        {
            if (dfs(adjacentNode, node, vis, adjlist) == true)
                return true;
        }
        // visited node but not a parent node
        else if (adjacentNode != parent)
            return true;
    }
    return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    unordered_map<int, list<int>> adjlist;

    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i][0];

        int v = edges[i][1];

        adjlist[u].push_back(v);

        adjlist[v].push_back(u);
    }

    vector<int> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, vis, adjlist) == true)
                return "Yes";
        }
    }
    return "No";
}
