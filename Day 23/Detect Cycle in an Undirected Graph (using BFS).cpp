// Time Complexity : O(V + E)
// Space Complexity : O(V + E)

#include <bits/stdc++.h>
bool dfs(int node, int parent, vector<int> &vis,
         unordered_map<int, list<int>> &adjlist)
{
    vis[node] = true;
    // store <source node, parent node>
    queue<pair<int, int>> q;
    q.push({node, -1});
    // traverse until queue is not empty
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        // go to all adjacent nodes
        for (auto adjacentNode : adjlist[node])
        {
            // if adjacent node is unvisited
            if (!vis[adjacentNode])
            {
                vis[adjacentNode] = true;
                q.push({adjacentNode, node});
            }
            // if adjacent node is visited and is not it's own parent node
            else if (parent != adjacentNode)
            {
                // yes it is a cycle
                return true;
            }
        }
    }
    // there's no cycle
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
